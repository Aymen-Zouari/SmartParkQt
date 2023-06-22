 #include "soutien.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QString>
#include <QObject>
#include <QSqlRelationalTableModel>
#include <QMessageBox>
soutien::soutien()
{
    num_sou=0;
   type_sou="";
    quantite_sou=0;

}
soutien::soutien(int idsp,int num_sou,QString type_sou,int quantite_sou,QDate date_sou)
{
    this->idsp=idsp;
    this->num_sou=num_sou;
    this->type_sou=type_sou;
    this->quantite_sou=quantite_sou;
    this->date_sou=date_sou;
}
int soutien::getnum_sou(){return num_sou;}
QString soutien::gettype_sou(){return type_sou;}
double soutien::getquantite_sou(){return quantite_sou;}
QDate soutien::getdate_sou(){return date_sou;}

void soutien::setnum_sou(int num_sou){this->num_sou=num_sou;}
void soutien::settype_sou(QString type_sou){this->type_sou=type_sou;}
void soutien::setquantite_sou(double quantite_sou){this->quantite_sou=quantite_sou;}
void soutien::setdate_sou(QDate date_sou){this->date_sou=date_sou;}

bool soutien::ajouter()
{
    QSqlQuery query;
   QString id_string = QString :: number(idsp);
   QString quantite_sou_string = QString :: number(quantite_sou);
        query.prepare("INSERT INTO SOUTIEN(  TYPES_SOUTIEN, QUANTITE_SOUTIEN,DATE_SOUTIEN,ID) VALUES(  :TYPES_SOUTIEN, :QUANTITE_SOUTIEN, :DATE_SOUTIEN,:ID_SPON)");
        query.bindValue(":TYPES_SOUTIEN", type_sou);
        query.bindValue(":QUANTITE_SOUTIEN", quantite_sou_string);
        query.bindValue(":DATE_SOUTIEN", date_sou);
       query.bindValue(":ID_SPON", id_string);
        return query.exec();

}
bool soutien::supprimer(int num_s)
{
    QSqlQuery query;
     QString num_string = QString :: number(num_s);
    query.prepare("Delete FROM SOUTIEN where NUM_SOUTIEN = :NUM_SOUTIEN");
    query.bindValue(":NUM_SOUTIEN", num_string);
    return query.exec();

}
bool soutien :: modifieridsp(QString curent,QString IDO)
{

    QSqlQuery query;
             query.prepare("Update SOUTIEN set ID = :ID  where NUM_SOUTIEN = :IDO1 ");
             query.bindValue(":ID", curent);
             query.bindValue(":IDO1", IDO);
    return query.exec();
}
bool soutien:: modifiernum_sou(QString curent,QString IDO)
{

    QSqlQuery query;
         query.prepare("Update SOUTIEN set NUM_SOUTIEN = :NUM_SOUTIEN  where NUM_SOUTIEN = :IDO1 ");
         query.bindValue(":NUM_SOUTIEN", curent);
         query.bindValue(":IDO1", IDO);
return query.exec();
}
bool soutien :: modifiertype_sou(QString curent,QString IDO)
{

    QSqlQuery query;
             query.prepare("Update SOUTIEN set TYPES_SOUTIEN = :TYPES_SOUTIEN  where NUM_SOUTIEN = :IDO1 ");
             query.bindValue(":TYPES_SOUTIEN", curent);
             query.bindValue(":IDO1", IDO);
return query.exec();
}
bool soutien:: modifierquantite_sou(QString curent,QString IDO)
{

    QSqlQuery query;
             query.prepare("Update SOUTIEN set QUANTITE_SOUTIEN = :QUANTITE_SOUTIEN  where NUM_SOUTIEN = :IDO1 ");
             query.bindValue(":QUANTITE_SOUTIEN", curent);
             query.bindValue(":IDO1", IDO);
return query.exec();
}
bool soutien:: modifierdate_sou(QDate curent,QString IDO)
{

    QSqlQuery query;
             query.prepare("Update SOUTIEN set DATE_SOUTIEN = :DATE_SOUTIEN  where NUM_SOUTIEN = :IDO1 ");
             query.bindValue(":DATE_SOUTIEN", curent);
             query.bindValue(":IDO1", IDO);
return query.exec();
}
