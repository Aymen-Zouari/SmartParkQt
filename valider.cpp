#include "valider.h"
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

valider::valider()
{
CIN=0;
    NOM="";
    PRENOM="";
    DESCRIPTION="";

}
valider::valider(int CIN,QString NOM,QString PRENOM,QString DESCRIPTION)
{

        this->CIN=CIN;
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->DESCRIPTION=DESCRIPTION;
}




int valider::get_CIN(){return CIN;}
QString valider::get_NOM(){return NOM;}
QString valider::get_PRENOM(){return PRENOM;}
QString valider::get_DESCRIPTION(){return DESCRIPTION;}

void valider::setCIN(int CIN ){this->CIN=CIN;}
void valider::setNOM(QString NOM ){this->NOM=NOM;}
void valider::setPRENOM(QString PRENOM ){this->PRENOM=PRENOM;}
void valider::setDESCRIPTION(QString DESCRIPTION ){this->DESCRIPTION=DESCRIPTION;}


 bool valider::ajouter()
 {
     QSqlQuery query;
QString CIN_string=QString::number(CIN);

     query.prepare("INSERT INTO DESCRIPTION (CIN,NOM,PRENOM,DESCRIPTION) "
                         "VALUES (:CIN,:NOM,:PRENOM,:DESCRIPTION)");

  query.bindValue(":CIN",CIN_string);
  query.bindValue(":NOM",NOM);
  query.bindValue(":PRENOM",PRENOM);
  query.bindValue(":DESCRIPTION",DESCRIPTION);
  if( query.exec() ) {

      return true;
  }
  return false;

  }


 QSqlQueryModel *valider::afficher()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from DESCRIPTION");

     return model;
 }

