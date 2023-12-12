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

    /**
     * Constructeur de la classe TCPClient.
     *
     * @param activity L'activité MainActivity associée.
     */
    public TCPClient(MainActivity activity) {
        executorService = Executors.newSingleThreadExecutor();
        mainActivity = activity;
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
                        // Lire les deux premiers bytes pour obtenir la taille du message.
                        byte[] sizeBuffer = new byte[2];
                        int bytesRead = inputStream.read(sizeBuffer);
                        // Vérifier si les deux bytes ont été correctement lus.
                        if (bytesRead != 2) {
                            throw new IOException("Taille du message incorrecte");
                        }
                        int messageSize = ((sizeBuffer[0] & 0xFF) << 8) | (sizeBuffer[1] & 0xFF);

                        // Lire le message proprement dit en fonction de la taille obtenue.
                        byte[] messageBuffer = new byte[messageSize];
                        bytesRead = inputStream.read(messageBuffer);

                        // Vérifier si la taille du message lu correspond à la taille attendue.
                        if (bytesRead != messageSize) {
                            throw new IOException("Message reçu incomplet");
                        }

                        // Traiter le message reçu.
                        message_type messageType = message_type.parseFrom(messageBuffer);
                        int messageID = messageType.getId();
                        processReceivedMessage(messageID,messageType);
                    }
                } catch (IOException e) {
                    // Gérer les exceptions d'entrée/sortie.
                    e.printStackTrace();
                }
            }
        });
        listeningThread.start();
    }

    // Cette méthode traite les messages reçus en fonction de leur ID.
    private void processReceivedMessage(int messageID, message_type messageType) {
        // Utilisez les champs de l'objet message pour obtenir l'ID et les données
        try{
            // Utiliser un switch pour traiter différemment les messages en fonction de leur ID.
            switch(messageID) {
                case 0x04:
                    battery_level batlevel = battery_level.parseFrom(messageType.getPayload());                // Désérialiser le message en un objet 'battery_level'.
                    int data = batlevel.getLevel();             // Mettre à jour l'interface utilisateur.
                    mainActivity.updateTextView(messageID, data);
                    break;
                case 0x06:
                    status_explo statusExplo = status_explo.parseFrom(messageType.getPayload());
                    int status = statusExplo.getStatus();
                    mainActivity.updateTextView(messageID, status);
                    break;
                case 0x08:
                    position pos = position.parseFrom(messageType.getPayload());
                    int axeX = pos.getX();
                    int axeY = pos.getY();
                    mainActivity.updateTextView(axeX, axeY);
                    break;
                default:
                    // Cas par défaut si l'ID ne correspond à aucun cas connu.
                    break;
            }
        } catch (InvalidProtocolBufferException e) {
            // Gérer les exceptions liées à la désérialisation Protobuf.
            e.printStackTrace();
        }
    }


    // Cette méthode envoie un message en fonction de l'ID et des données spécifiées.
    public void sendMessage(int messageID, int data) {
        executorService.execute(new Runnable() {
            @Override
            public void run() {
                // Vérifier si le flux de sortie est disponible.
                if (outputStream != null) {
                    try {
                        ByteBuffer header = ByteBuffer.allocate(2);
                        byte[] sizeBuffer = new byte[2];
                        // Utiliser un switch pour traiter l'envoi différemment en fonction de l'ID.
                        switch(messageID) {
                            case 0x01:
                                arret_urgence arretUrgence = arret_urgence.newBuilder().setState(data).build();// Construire et sérialiser un message 'arret_urgence'.
                                Log.d("SendMessage", "PB: state = " + arretUrgence.getState());

                                byte[] infoArretUrgence = arretUrgence.toByteArray();
                                Log.i("SendMessage", "Message envoyé (hex): " + Arrays.toString(infoArretUrgence));

                                message_type messageArreturengce = message_type.newBuilder().setId(messageID).setPayload(ByteString.copyFrom(infoArretUrgence)).build();

                                int sizeUrg = messageArreturengce.getSerializedSize();
                                sizeBuffer[0] = (byte)((sizeUrg >> 8) & 0xFF);
                                sizeBuffer[1] = (byte)(sizeUrg & 0xFF);
                                Log.d("SendMessage", "PB: taille = " + sizeUrg);

                                outputStream.write(sizeBuffer);
                                outputStream.write(messageArreturengce.toByteArray());
                                break;
                            case 0x03:
                                stop_marco stopMarco = stop_marco.newBuilder().setState(data).build();
                                byte[] infoStopMarco = stopMarco.toByteArray();
                                message_type messageStopMarco = message_type.newBuilder().setId(messageID).setPayload(ByteString.copyFrom(infoStopMarco)).build();
                                int sizeStop = messageStopMarco.getSerializedSize();
                                sizeBuffer[0] = (byte)((sizeStop >> 8) & 0xFF);
                                sizeBuffer[1] = (byte)(sizeStop & 0xFF);
                                outputStream.write(sizeBuffer);
                                outputStream.write(messageStopMarco.toByteArray());
                                break;
                            case 0x05:
                                deplacement_manuel deplacementManuel = deplacement_manuel.newBuilder().setDirection(data).build();
                                byte[] infoMoovMan = deplacementManuel.toByteArray();
                                message_type messageDeplacementManuel = message_type.newBuilder().setId(messageID).setPayload(ByteString.copyFrom(infoMoovMan)).build();
                                int sizeMoovMan = messageDeplacementManuel.getSerializedSize();
                                sizeBuffer[0] = (byte)((sizeMoovMan >> 8) & 0xFF);
                                sizeBuffer[1] = (byte)(sizeMoovMan & 0xFF);
                                outputStream.write(sizeBuffer);
                                outputStream.write(messageDeplacementManuel.toByteArray());

                                break;
                            case 0x07:
                                set_explo_algo setExploAlgo = set_explo_algo.newBuilder().setAlgo(data).build();
                                byte[] infoSetExplo = setExploAlgo.toByteArray();
                                message_type messageSetExploAlgo = message_type.newBuilder().setId(messageID).setPayload(ByteString.copyFrom(infoSetExplo)).build();
                                int sizeSetExplo = messageSetExploAlgo.getSerializedSize();
                                sizeBuffer[0] = (byte)((sizeSetExplo >> 8) & 0xFF);
                                sizeBuffer[1] = (byte)(sizeSetExplo & 0xFF);
                                outputStream.write(sizeBuffer);
                                outputStream.write(messageSetExploAlgo.toByteArray());
                                break;
                            default:
                                // Cas par défaut si l'ID ne correspond à aucun cas connu.
                                break;
                        }
                        outputStream.flush();
                        header.clear();
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
