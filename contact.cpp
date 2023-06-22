#include "contact.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QString>
#include <QObject>
#include <QSqlRelationalTableModel>
#include <QMessageBox>
#include <QSqlTableModel>

contact::contact()
{
     numero=0;
    nom="";
    prenom="";
    id=0;
     poste="";
    gsm=0;
    fixe=0;
    mail="";
}
contact::contact(QString nom,QString prenom,int id,QString poste,int gsm,int fixe,QString mail)
{

   this->nom=nom;
   this->prenom=prenom;
   this->id=id;
   this-> poste=poste;
   this->gsm=gsm;
   this->fixe=fixe;
   this->mail=mail;
}
bool contact::ajouter()
{
    QString id_string = QString :: number(id);
    QString gsm_string = QString :: number(gsm);
    QString fixe_string = QString :: number(fixe);
    QSqlQuery query;
        query.prepare("INSERT INTO CONTACT ( NOM, PRENOM, ID, POSTE, GSM, FIXE, MAIL) VALUES ( :NOM, :PRENOM, :ID, :POSTE, :GSM ,:FIXE ,:MAIL)");
        query.bindValue(":NOM", nom);
        query.bindValue(":PRENOM", prenom);
        query.bindValue(":ID", id_string);
        query.bindValue(":POSTE", poste);
        query.bindValue(":GSM", gsm_string);
        query.bindValue(":FIXE", fixe_string);
        query.bindValue(":MAIL", mail);
        return query.exec();

}
QSqlQueryModel* contact::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM CONTACT");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("id de sponsor"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("gsm"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("fixe"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("mail"));

    return model;
}
bool contact::supprimer(int numero)
{
    QSqlQuery query;
     QString numero_string = QString :: number(numero);
    query.prepare("Delete FROM CONTACT where NUM_C = :NUM_C");
    query.bindValue(":NUM_C", numero_string);
    return query.exec();

}
QSqlQueryModel* contact :: cherchesp(QVariant curent)
{
    QSqlQuery query;QSqlQueryModel* model=new QSqlQueryModel();QString curent1;int curent2;
    if((curent.toInt() != 0)){
   curent2=curent.toInt(); query.prepare("SELECT * FROM CONTACT where NUM_C = :curent or ID = :curent or GSM = :curent or FIXE = :curent");query.bindValue(":curent", curent2);}
    else{curent1=curent.toString();query.prepare("SELECT * FROM CONTACT where NOM = :curent or PRENOM= :curent or POSTE = :curent or MAIL = :curent");query.bindValue(":curent", curent1);}
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id de sponsor"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("gsm"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("fixe"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("mail"));
    return model;
}
QSqlQueryModel* contact :: trier(QString curent)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    if(curent==""){
   model->setQuery("SELECT * FROM CONTACT");}
    if(curent=="ordre alphabetique croissant"){
   model->setQuery("SELECT * FROM CONTACT ORDER BY NOM, PRENOM ASC ");}
    if(curent=="ordre alphabetiques decroissant"){
   model->setQuery("SELECT * FROM CONTACT ORDER BY NOM, PRENOM DESC ");}
    if(curent=="identifiant sponsor croissant"){
   model->setQuery("SELECT * FROM CONTACT ORDER BY ID ASC ");}
    if(curent=="identifiant sponsor decroissant"){
   model->setQuery("SELECT * FROM CONTACT ORDER BY ID DESC ");}
    if(curent=="poste"){
   model->setQuery("SELECT * FROM CONTACT ORDER BY POSTE ASC ");}
    if(curent=="numero contact croissant"){
   model->setQuery("SELECT * FROM CONTACT ORDER BY NUM_C ASC ");}
    if(curent=="numero contact decroissant"){
   model->setQuery("SELECT * FROM CONTACT ORDER BY NUM_C DESC ");}

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id de sponsor"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("gsm"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("fixe"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("mail"));
     return model;
}
bool contact :: modifiernom(QString curent,QString IDO)
{

    QSqlQuery query;
     query.prepare("Update CONTACT set NOM = :NOM  where NUM_C = :NUM_C ");
     query.bindValue(":NOM", curent);
     query.bindValue(":NUM_C", IDO);
return query.exec();
}
bool contact :: modifierprenom(QString curent,QString IDO)
{

    QSqlQuery query;
     query.prepare("Update CONTACT set PRENOM = :PRENOM  where NUM_C = :NUM_C ");
     query.bindValue(":PRENOM", curent);
     query.bindValue(":NUM_C", IDO);
return query.exec();
}
bool contact :: modifierid(QString curent,QString IDO)
{

    QSqlQuery query;
     query.prepare("Update CONTACT set ID = :ID  where NUM_C = :NUM_C ");
     query.bindValue(":ID", curent);
     query.bindValue(":NUM_C", IDO);
return query.exec();
}
bool contact :: modifierposte(QString curent,QString IDO)
{

    QSqlQuery query;
     query.prepare("Update CONTACT set POSTE = :POSTE  where NUM_C = :NUM_C ");
     query.bindValue(":POSTE", curent);
     query.bindValue(":NUM_C", IDO);
return query.exec();
}
bool contact :: modifiergsm(QString curent,QString IDO)
{

    QSqlQuery query;
     query.prepare("Update CONTACT set GSM = :GSM  where NUM_C = :NUM_C ");
     query.bindValue(":GSM", curent);
     query.bindValue(":NUM_C", IDO);
return query.exec();
}
bool contact :: modifierfixe(QString curent,QString IDO)
{

    QSqlQuery query;
     query.prepare("Update CONTACT set FIXE = :FIXE  where NUM_C = :NUM_C ");
     query.bindValue(":FIXE", curent);
     query.bindValue(":NUM_C", IDO);
return query.exec();
}
bool contact :: modifiermail(QString curent,QString IDO)
{

    QSqlQuery query;
     query.prepare("Update CONTACT set MAIL = :MAIL  where NUM_C = :NUM_C ");
     query.bindValue(":NATURE", curent);
     query.bindValue(":NUM_C", IDO);
return query.exec();
}
