#include "evenement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QString>
#include <QObject>
#include <QSqlRelationalTableModel>
#include <QMessageBox>
evenement::evenement()
{
    num_eve=0;
     nom_eve="";
     type_eve="";

     montant_payee="";
     montant_gagnee="";
}
evenement::evenement(int idsp,int num_eve,QString nom_eve,QString type_eve,QDate date_eve,QString montant_payee,QString montant_gagnee)
{
    this->idsp=idsp;
this-> num_eve= num_eve;
this->nom_eve=nom_eve;
this->type_eve=type_eve;
this->date_eve=date_eve;
this->montant_payee=montant_payee;
this->montant_gagnee=montant_gagnee;
}
int evenement::getnum_eve(){return num_eve;}
QString evenement::getnom_eve(){return nom_eve;}
QString evenement::gettype_eve(){return type_eve;}
QDate evenement::getdate_eve(){return date_eve;}
QString evenement::getmontant_payee(){return montant_payee;}
QString evenement::getmontant_gagnee(){return montant_gagnee;}

void evenement::setnum_eve(int num_eve){this-> num_eve= num_eve;}
void evenement::setnom_eve(QString nom_eve){this->nom_eve=nom_eve;}
void evenement::settype_eve(QString type_eve){this->type_eve=type_eve;}
void evenement::setdate_eve(QDate date_eve){this->date_eve=date_eve;}
void evenement::setmontant_payee(QString montant_payee){this->montant_payee=montant_payee;}
void evenement::setmontant_gagnee(QString montant_gagnee){this->montant_gagnee=montant_gagnee;}
bool evenement::ajouter()
{
    QSqlQuery query;
   QString id_string = QString :: number(idsp);
        query.prepare("INSERT INTO EVENEMENT(  NOM_EVENEMENT, TYPE_EVENEMENT,DATE_EVENEMENT,MONTATNT_PAYEE,MONTANT_GAGNEE,ID) VALUES(  :NOM_EVENEMENT, :TYPE_EVENEMENT, :DATE_EVENEMENT, :MONTATNT_PAYEE, :MONTANT_GAGNEE, :ID)");
        query.bindValue(":NOM_EVENEMENT", nom_eve);
        query.bindValue(":TYPE_EVENEMENT", type_eve);
        query.bindValue(":DATE_EVENEMENT", date_eve);
       query.bindValue(":MONTATNT_PAYEE", montant_payee);
       query.bindValue(":MONTANT_GAGNEE", montant_gagnee);
       query.bindValue(":ID", id_string);
        return query.exec();

}
bool evenement::supprimer(int num_e)
{
    QSqlQuery query;
     QString num_string = QString :: number(num_e);
    query.prepare("Delete FROM EVENEMENT where NUM_EVENEMENT = :NUM_EVENEMENT");
    query.bindValue(":NUM_EVENEMENT", num_string);
    return query.exec();

}
bool evenement :: modifieridsp(QString curent,QString IDO)
{
        QSqlQuery query;
         query.prepare("Update EVENEMENT set ID = :ID  where NUM_EVENEMENT = :IDO2 ");
         query.bindValue(":ID", curent);
         query.bindValue(":IDO2", IDO);
        return query.exec();
}
bool evenement :: modifiernum_eve(QString curent,QString IDO)
{
        QSqlQuery query;
         query.prepare("Update EVENEMENT set NUM_EVENEMENT = :NUM_EVENEMENT  where NUM_EVENEMENT = :IDO2 ");
         query.bindValue(":NUM_EVENEMENT", curent);
         query.bindValue(":IDO2", IDO);
    return query.exec();
}
bool evenement:: modifiernom_eve(QString curent,QString IDO)
{
        QSqlQuery query;
         query.prepare("Update EVENEMENT set NOM_EVENEMENT = :NOM_EVENEMENT  where NUM_EVENEMENT = :IDO2 ");
         query.bindValue(":NOM_EVENEMENT", curent);
         query.bindValue(":IDO2", IDO);
    return query.exec();
}
bool evenement:: modifiertype_eve(QString curent,QString IDO)
{

    QSqlQuery query;
         query.prepare("Update EVENEMENT set TYPE_EVENEMENT = :TYPE_EVENEMENT  where NUM_EVENEMENT = :IDO2 ");
         query.bindValue(":TYPE_EVENEMENT", curent);
         query.bindValue(":IDO2", IDO);
         return query.exec();
}
bool evenement:: modifierdate_eve(QDate curent,QString IDO)
{

    QSqlQuery query;
         query.prepare("Update EVENEMENT set DATE_EVENEMENT = :DATE_EVENEMENT  where NUM_EVENEMENT = :IDO2 ");
         query.bindValue(":DATE_EVENEMENT", curent);
         query.bindValue(":IDO2", IDO);
    return query.exec();
}
bool evenement:: modifiermontant_payee(QString curent,QString IDO)
{

    QSqlQuery query;
         query.prepare("Update EVENEMENT set MONTATNT_PAYEE = :MONTATNT_PAYEE  where NUM_EVENEMENT = :IDO2 ");
         query.bindValue(":MONTATNT_PAYEE", curent);
         query.bindValue(":IDO2", IDO);
return query.exec();
}
bool evenement:: modifiermontant_gagnee(QString curent,QString IDO)
{

    QSqlQuery query;
         query.prepare("Update EVENEMENT set MONTANT_GAGNEE = :MONTANT_GAGNEE  where NUM_EVENEMENT = :IDO2 ");
         query.bindValue(":MONTANT_GAGNEE", curent);
         query.bindValue(":IDO2", IDO);
return query.exec();
}
