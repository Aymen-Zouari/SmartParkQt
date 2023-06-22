#include "visiteur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
using namespace QtCharts;

Visiteur::Visiteur()
{
type="";prenom="";nom="";age=0;cin=0;tel=0;
}

Visiteur::Visiteur(QString type,QString prenom,QString nom,int age,int cin,int tel)
{this->type=type;this->prenom=prenom;this->nom=nom;this->age=age;this->cin=cin;this->tel=tel;}
QString Visiteur::gettype(){return type;}
QString Visiteur::getprenom(){return prenom;}
QString Visiteur::getnom(){return nom;}
int Visiteur::getage(){return age;}
int Visiteur::getcin(){return cin;}
int Visiteur::gettel(){return tel;}
void Visiteur::setprenom(QString prenom){this->prenom=prenom;}
void Visiteur::setnom(QString nom){this->nom=nom;}
void Visiteur::setage(int age){this->age=age;}
void Visiteur::setcin(int cin){this->cin=cin;}
void Visiteur::settel(int tel){this->tel=tel;}
bool Visiteur::ajouter()
{
    QSqlQuery query;
    QString age_string= QString::number(age);
    QString cin_string= QString::number(cin);
    QString tel_string= QString::number(tel);
          query.prepare("INSERT INTO VISITEUR(TYPE,PRENOM,NOM,AGE,CIN,TEL) "
                        "VALUES (:TYPE,:PRENOM,:NOM,:AGE,:CIN,:TEL)");
          query.bindValue(":TYPE",type);
          query.bindValue(":PRENOM",prenom);
          query.bindValue(":NOM", nom);
          query.bindValue(":AGE",age_string);
          query.bindValue(":CIN",cin_string);
          query.bindValue(":TEL",tel_string);
          return query.exec();
}
bool Visiteur::supprimer(int cin)
{
    QSqlQuery query;
         query.prepare("Delete  from Visiteur where cin=:CIN");
          query.bindValue(0,cin);
   return query.exec();
}
QSqlQueryModel*Visiteur::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel ();
       model->setQuery("SELECT * FROM Visiteur");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL"));
 return model;
}


bool Visiteur::modifier(QString type,QString prenom,QString nom,int age,int cin,int tel)
     {
      QSqlQuery query;
      QString res2= QString::number(age);
      QString res3= QString::number(cin);
      QString res4= QString::number(tel);

     query.prepare("Update Visiteur SET TYPE=:TYPE PRENOM=:PRENOM,NOM=:NOM,AGE=:AGE,TEL=:TEL WHERE CIN=:CIN ");
     query.bindValue(":TYPE", type);
     query.bindValue(":PRENOM", prenom);
     query.bindValue(":NOM", nom);
     query.bindValue(":AGE", res2);
     query.bindValue(":CIN", res3);
     query.bindValue(":TEL", res4);
     return    query.exec();
     }

QSqlQueryModel * Visiteur::recherche(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString recher="select *  from Visiteur where TYPE like '%"+rech+"%'or PRENOM like '%"+rech+"%'or NOM like '%"+rech+"%'or AGE like '%"+rech+"%'or CIN like '%"+rech+"%'or TEL like '%"+rech+"%'";
     model->setQuery(recher);
    return model;
}



QSqlQueryModel* Visiteur::tri()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from Visiteur order by PRENOM");
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL"));

   return model;

}

