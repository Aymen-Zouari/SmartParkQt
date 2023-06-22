#include "sponsors.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QString>
#include <QObject>
#include <QSqlRelationalTableModel>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QMainWindow>
Sponsors::Sponsors()
{
    id_sponsor=1;
    nom_sp="";
    nature="";
}

Sponsors::Sponsors(int id_sponsor,QString nom_sp,QString nature)
{
    this->id_sponsor=id_sponsor;
    this->nom_sp=nom_sp;
    this->nature=nature;


}


int Sponsors::getid_sponsor(){return id_sponsor;}
QString Sponsors::getnom_sp(){return nom_sp;}
QString Sponsors::getnature(){return nature;}


void Sponsors::setid_sponsor(int id_sponsor){this->id_sponsor=id_sponsor;}
void Sponsors::setnom_sp(QString nom_sp){this->nom_sp=nom_sp;}
void Sponsors::setnature(QString nature){this->nature=nature;}


bool Sponsors::ajouter()
{
    QSqlQuery query;
        query.prepare("INSERT INTO sponsors ( NOM_SPONSOR, NATURE) VALUES ( :NOM_SPONSOR, :NATURE)");
        query.bindValue(":NOM_SPONSOR", nom_sp);
        query.bindValue(":NATURE", nature);
        return query.exec();

}
QSqlQueryModel* Sponsors::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM sponsors Left Join soutien ON sponsors.id_spon = soutien.id Left JOIN evenement ON sponsors.id_spon = EVENEMENT.id");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom du sponsor"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("nature du sponsor"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero du soutien"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("type du soutien"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite du soutien"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("date du soutien"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("id de sponsor"));
         model->setHeaderData(8, Qt::Horizontal, QObject::tr("numero d'evenement"));
         model->setHeaderData(9, Qt::Horizontal, QObject::tr("nom d'evenement"));
         model->setHeaderData(10, Qt::Horizontal, QObject::tr("type d'evenement"));
         model->setHeaderData(11, Qt::Horizontal, QObject::tr("date d'evenement"));
         model->setHeaderData(12, Qt::Horizontal, QObject::tr("montant payeé"));
         model->setHeaderData(13, Qt::Horizontal, QObject::tr("montant gagneé"));
         model->setHeaderData(14, Qt::Horizontal, QObject::tr("id de sponsor"));
    return model;
}
QSqlQueryModel* Sponsors::affichercombo()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT ID_SPON FROM sponsors ");


    return model;
}
bool Sponsors::supprimer(int id_sponsor)
{
    QSqlQuery query;
     QString id_string = QString :: number(id_sponsor);
     query.prepare("Delete FROM SOUTIEN where ID = :ID_SPON");
     query.bindValue(":ID_SPON", id_string);
     query.exec();
     query.prepare("Delete FROM EVENEMENT where ID = :ID_SPON");
     query.bindValue(":ID_SPON", id_string);
     query.exec();
    query.prepare("Delete FROM sponsors where ID_SPON = :ID_SPON");
    query.bindValue(":ID_SPON", id_string);
    return query.exec();

}

bool Sponsors :: modifiernom(QString curent,QString IDO)
{
        QSqlQuery query;
         query.prepare("Update sponsors set NOM_SPONSOR = :NOM_SPONSOR  where ID_SPON = :IDO ");
         query.bindValue(":NOM_SPONSOR", curent);
         query.bindValue(":IDO", IDO);
return query.exec();
}
bool Sponsors :: modifierid(QString curent,QString IDO)
{
QSqlQuery query;
 query.prepare("Update sponsors set ID_SPON = :id_string  where ID_SPON = :IDO ");
 query.bindValue(":id_string", curent);
 query.bindValue(":IDO", IDO);
return query.exec();
}
bool Sponsors :: modifiertype(QString curent,QString IDO)
{

    QSqlQuery query;
     query.prepare("Update sponsors set NATURE = :NATURE  where ID_SPON = :IDO ");
     query.bindValue(":NATURE", curent);
     query.bindValue(":IDO", IDO);
return query.exec();
}
QSqlQueryModel* Sponsors :: cherchesp(QVariant curent)
{
    QSqlQuery query;QSqlQueryModel* model=new QSqlQueryModel();QString curent1;int curent2;
    if((curent.toInt() != 0)){
   curent2=curent.toInt(); query.prepare("SELECT * FROM ( sponsors Left Join soutien ON sponsors.id_spon = soutien.id Left JOIN evenement ON sponsors.id_spon = EVENEMENT.id) where evenement.id = :curent or sponsors.id_spon = :curent or soutien.num_soutien = :curent or soutien.id = :curent or evenement.num_evenement = :curent");query.bindValue(":curent", curent2);}
    else{curent1=curent.toString();query.prepare("SELECT * FROM ( sponsors Left Join soutien ON sponsors.id_spon = soutien.id Left JOIN evenement ON sponsors.id_spon = EVENEMENT.id) where sponsors.nom_sponsor = :curent or evenement.montant_gagnee= :curent or evenement.montatnt_payee = :curent or evenement.nom_evenement = :curent or sponsors.nature = :curent or soutien.quantite_soutien = :curent or soutien.types_soutien = :curent or evenement.type_evenement= :curent");query.bindValue(":curent", curent1);}
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom du sponsor"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nature du sponsor"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero du soutien"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type du soutien"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite du soutien"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("date du soutien"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("id de sponsor"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("numero d'evenement"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("nom d'evenement"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("type d'evenement"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("date d'evenement"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("montant payeé"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("montant gagneé"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("id de sponsor"));
    return model;
}
QSqlQueryModel* Sponsors :: trier(QString curent)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    if(curent==""){
   model->setQuery("SELECT * FROM (sponsors Left Join soutien ON sponsors.id_spon = soutien.id Left JOIN evenement ON sponsors.id_spon = EVENEMENT.id)");}
    if(curent=="ordre alphabetique croissant"){
   model->setQuery("SELECT * FROM ( sponsors Left Join soutien ON sponsors.id_spon = soutien.id Left JOIN evenement ON sponsors.id_spon = EVENEMENT.id)ORDER BY NOM_SPONSOR ASC ");}
    if(curent=="ordre alphabetiques decroissant"){
   model->setQuery("SELECT * FROM ( sponsors Left Join soutien ON sponsors.id_spon = soutien.id Left JOIN evenement ON sponsors.id_spon = EVENEMENT.id)ORDER BY NOM_SPONSOR DESC ");}
    if(curent=="identifiant croissant"){
   model->setQuery("SELECT * FROM ( sponsors Left Join soutien ON sponsors.id_spon = soutien.id Left JOIN evenement ON sponsors.id_spon = EVENEMENT.id)ORDER BY ID_SPON ASC ");}
    if(curent=="identifiant decroissant"){
   model->setQuery("SELECT * FROM ( sponsors Left Join soutien ON sponsors.id_spon = soutien.id Left JOIN evenement ON sponsors.id_spon = EVENEMENT.id)ORDER BY ID_SPON DESC ");}
    if(curent=="type"){
   model->setQuery("SELECT * FROM ( sponsors Left Join soutien ON sponsors.id_spon = soutien.id Left JOIN evenement ON sponsors.id_spon = EVENEMENT.id)ORDER BY NATURE ASC ");}

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom du sponsor"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nature du sponsor"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero du soutien"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type du soutien"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite du soutien"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("date du soutien"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("id de sponsor"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("numero d'evenement"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("nom d'evenement"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("type d'evenement"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("date d'evenement"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("montant payeé"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("montant gagneé"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("id de sponsor"));
     return model;
}
/*ORDER BY Country ASC, CustomerName DESC;*/
