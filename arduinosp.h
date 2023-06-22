#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QDebug>


class Arduinosp
{
public:     //méthodes de la classe Arduino
    Arduinosp();
    int connect_arduinosp(); // permet de connecter le PC à Arduino
    int close_arduinosp(); // permet de femer la connexion
    int write_to_arduinosp( QByteArray ); // envoyer des données vers arduino
    QByteArray read_from_arduinosp();  //recevoir des données de la carte Arduino
    QSerialPort* getserialsp();   // accesseur
    QString getarduinosp_port_name();
private:
QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
//et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
static const quint16 arduino_uno_vendor_id=9025;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data;  // contenant les données lues à partir d'Arduino
};



#endif // ARDUINO_H
