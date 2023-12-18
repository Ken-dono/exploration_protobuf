package com.example.exploprotobuf;

import android.util.Log;

import com.google.protobuf.ByteString;
import com.google.protobuf.InvalidProtocolBufferException;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class TCPClient {
    private static final int SERVER_PORT = 12345; // Port du serveur

    private ExecutorService executorService;
    private Socket socket;
    private OutputStream outputStream;
    private MainActivity mainActivity;

    private InputStream inputStream;
    private boolean isListening;
    private ProtoBuff protoBuff;

    /**
     * Constructeur de la classe TCPClient.
     *
     * @param activity L'activité MainActivity associée.
     */
    public TCPClient(MainActivity activity) {
        executorService = Executors.newSingleThreadExecutor();
        mainActivity = activity;
        protoBuff = new ProtoBuff();
    }

    /**
     * Établit une connexion avec M_EMB à l'adresse IP spécifiée.
     *
     * @param ipAddress L'adresse IP de M_EMB.
     */
    public void connect(String ipAddress) {
        executorService.execute(new Runnable() {
            @Override
            public void run() {
                try {
                    socket = new Socket(ipAddress, SERVER_PORT);
                    outputStream = socket.getOutputStream();
                    inputStream = socket.getInputStream();
                    isListening = true;
                    startListening();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    /**
     * Démarre un thread d'écoute pour les données provenant de M_EMB.
     */
    // Cette méthode démarre un thread séparé pour écouter les messages entrants.
    private void startListening() {
        Thread listeningThread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    while (isListening) {
                        byte[] sizeBuffer = new byte[2];
                        int bytesRead = inputStream.read(sizeBuffer);
                        if (bytesRead != 2) {
                            throw new IOException("Taille du message incorrecte");
                        }
                        int messageSize = ((sizeBuffer[0] & 0xFF) << 8) | (sizeBuffer[1] & 0xFF);
                        byte[] messageBuffer = new byte[messageSize];
                        bytesRead = inputStream.read(messageBuffer);
                        if (bytesRead != messageSize) {
                            throw new IOException("Message reçu incomplet");
                        }
                        message_type messageType = message_type.parseFrom(messageBuffer);
                        int messageID = messageType.getId();
                        protoBuff.processMessage(messageID, messageType.getPayload().toByteArray(), mainActivity);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        listeningThread.start();
    }

    public void sendMessage(int messageID, int data) {
        executorService.execute(new Runnable() {
            @Override
            public void run() {
                if (outputStream != null) {
                    try {
                        message_type message = protoBuff.PackMessage(messageID, data);
                        if (message != null) {
                            ByteBuffer header = ByteBuffer.allocate(2);
                            int size = message.getSerializedSize();
                            header.put((byte) ((size >> 8) & 0xFF));
                            header.put((byte) (size & 0xFF));
                            outputStream.write(header.array());
                            outputStream.write(message.toByteArray());
                            outputStream.flush();
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        });
    }

    /**
     * Déconnecte M_CTRL de M_EMB.
     */
    public void disconnect() {
        executorService.shutdown();
        isListening = false;
        try {
            if (socket != null)
                socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
