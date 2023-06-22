#include "equipement.h"
#include <QSqlQuery>

equipement::equipement()
{
code=0;
etat=0;
adresse="";
tarif=0;
remise=0;
}
equipement::equipement(int code,int etat,QString adresse,int tarif,int remise)
{this->code=code;this->etat=etat;this->adresse=adresse; this->tarif=tarif ;this->remise=remise;}

int equipement::getcode(){return code;};
int equipement::getetat() {return etat;}
QString equipement::getadresse(){return adresse;}
int equipement::gettarif() {return tarif;}
int equipement::getremise() {return remise;}

void equipement::setcode(int code){this->code=code;}
void equipement::setetat(int etat){this->etat=etat;}
void equipement::setadresse(QString adresse){this->adresse=adresse;}
void equipement::settarif(int tarif){this->tarif=tarif;}
void equipement::setremise(int remise){this->remise=remise;}


bool equipement::ajouter()
{

    QSqlQuery query;
    QString code_string= QString::number(code);
          query.prepare("INSERT INTO EQUIPEMENT (CODE_EQ,ETAT,ADRESSE, CONDITIONS, REMISE) "
                        "VALUES (:CODE_EQ,:ETAT,:ADRESSE, :CONDITIONS, :REMISE)");
          query.bindValue(":CODE_EQ", code_string);
          query.bindValue(":ETAT", etat);
          query.bindValue(":ADRESSE", adresse);
          query.bindValue(":CONDITIONS", tarif);
          query.bindValue(":REMISE", remise);

         return query.exec();

}





QSqlQueryModel* equipement::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel;

          model->setQuery("SELECT * FROM EQUIPEMENT");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("tarif"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("remise"));

   return model;
}




bool equipement::supprimer(int code)
{
    QSqlQuery query;
      QString res=QString::number(code);
      query.prepare("Delete from EQUIPEMENT where CODE_EQ=:CODE_EQ ");
      query.bindValue(":CODE_EQ",res); //affectation et association des val
      return query.exec();

}





bool equipement::modifier(int code,int etat,QString adresse, int tarif, int remise)
{
    bool test=false;
    QSqlQuery query;

    QString Code_string= QString::number(code);
    QString Etat= QString::number(etat);
    QString Tarif_string= QString::number(tarif);
    QString Remise_string= QString::number(remise);

      query.prepare("UPDATE EQUIPEMENT SET CODE_EQ=:CODE_EQ,ETAT=:ETAT,ADRESSE=:ADRESSE,CONDITIONS=:CONDITIONS,REMISE=:REMISE WHERE CODE_EQ=:CODE_EQ");

      query.bindValue(":CODE_EQ", code);
      query.bindValue(":ETAT", Etat);
      query.bindValue(":ADRESSE", adresse);
      query.bindValue(":CONDITIONS", Tarif_string);
      query.bindValue(":REMISE", Remise_string);
      query.exec();
      test =true;
    return test ;
    return query.exec();
}


QSqlQueryModel* equipement::chercher_eq(QString text)
{
QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
   {
     query.prepare("SELECT * FROM EQUIPEMENT where CODE_EQ like '"+text+"'");
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("ETAT"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("CONDITIONS"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("REMISE"));
     }

    return model;

}

QSqlQueryModel * equipement::tri_tarif_asc()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EQUIPEMENT order by CONDITIONS asc ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("CONDITIONS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("REMISE"));


    return model;
}
QSqlQueryModel * equipement::tri_tarif_desc()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EQUIPEMENT order by CONDITIONS desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("CONDITIONS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("REMISE"));


    return model;
}
