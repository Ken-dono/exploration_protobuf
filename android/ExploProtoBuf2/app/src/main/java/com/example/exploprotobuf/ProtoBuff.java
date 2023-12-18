package com.example.exploprotobuf;

import com.google.protobuf.ByteString;
import com.google.protobuf.InvalidProtocolBufferException;

public class ProtoBuff {

    public message_type PackMessage(int messageID, int data) {
        switch (messageID) {
            case 0x01:
                arret_urgence arretUrgence = arret_urgence.newBuilder().setState(data).build();// Construire et sérialiser un message 'arret_urgence'.
                byte[] infoArretUrgence = arretUrgence.toByteArray();
                message_type messageArreturengce = message_type.newBuilder().setId(messageID).setPayload(ByteString.copyFrom(infoArretUrgence)).build();
                return messageArreturengce;
            case 0x03:
                stop_marco stopMarco = stop_marco.newBuilder().setState(data).build();
                byte[] infoStopMarco = stopMarco.toByteArray();
                message_type messageStopMarco = message_type.newBuilder().setId(messageID).setPayload(ByteString.copyFrom(infoStopMarco)).build();
                return messageStopMarco;
            case 0x05:
                deplacement_manuel deplacementManuel = deplacement_manuel.newBuilder().setDirection(data).build();
                byte[] infoMoovMan = deplacementManuel.toByteArray();
                message_type messageDeplacementManuel = message_type.newBuilder().setId(messageID).setPayload(ByteString.copyFrom(infoMoovMan)).build();
                return messageDeplacementManuel;
            case 0x07:
                set_explo_algo setExploAlgo = set_explo_algo.newBuilder().setAlgo(data).build();
                byte[] infoSetExplo = setExploAlgo.toByteArray();
                message_type messageSetExploAlgo = message_type.newBuilder().setId(messageID).setPayload(ByteString.copyFrom(infoSetExplo)).build();
                return messageSetExploAlgo;
            default:
                return null;
        }
    }

    public void processMessage(int messageID, byte[] messageData, MainActivity mainActivity) {
        try {
            switch (messageID) {
                case 0x04:
                    battery_level batlevel = battery_level.parseFrom(messageData);
                    int data = batlevel.getLevel();
                    mainActivity.updateTextView(messageID, data); //Utilisation données reçu
                    break;
                case 0x06:
                    status_explo statusExplo = status_explo.parseFrom(messageData);
                    int status = statusExplo.getStatus();
                    mainActivity.updateTextView(messageID, status); //Utilisation données reçu
                    break;
                case 0x08:
                    position pos = position.parseFrom(messageData);
                    int axeX = pos.getX();
                    int axeY = pos.getY();
                    mainActivity.updateTextView(axeX, axeY); //Utilisation données reçu
                    break;
                default:
                    break;
            }
        } catch (InvalidProtocolBufferException e) {
            e.printStackTrace();
        }
    }
}
