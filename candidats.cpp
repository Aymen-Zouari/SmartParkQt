#include "candidats.h"
#include <QSqlQuery>
#include <QObject>
#include <QtDebug>
#include <QDateEdit>


candidats::candidats()
{
POSTE="";
SALAIRE="";
PRETS="";
EXP="";
ADRESSE="";
NOM="";
PRENOM="";
CIN=0;
MAIL="";
GSM=0;
}
candidats::candidats(int CIN,QString ADRESSE,QString NOM,QString PRENOM,int GSM,QString MAIL,QDate DATEN,QString POSTE,QString SALAIRE,QString PRETS,QString EXP )
{
  this->ADRESSE=ADRESSE;
    this->POSTE=POSTE;
    this->SALAIRE=SALAIRE;
    this->PRETS=PRETS;
   this->DATEN=DATEN;
    this->EXP=EXP;
  this->NOM=NOM;
  this->PRENOM=PRENOM;
    this->CIN=CIN;
    this->MAIL=MAIL;
  this->GSM=GSM;
}
QString candidats::get_NOM(){return  NOM;}
QString candidats::get_PRENOM(){return PRENOM;}
QString candidats::get_MAIL(){return MAIL;}
QString candidats::get_ADRESSE(){return  ADRESSE;}
QString candidats::get_POSTE(){return  POSTE;}
QString candidats::get_SALAIRE(){return  SALAIRE;}
QString candidats::get_PRETS(){return  PRETS;}
QDate candidats::get_DATEN(){return  DATEN;}
QString candidats::get_EXP(){return  EXP;}
int candidats::get_CIN(){return  CIN;}
int candidats::get_GSM(){return  GSM;}

void  candidats::setADRESSE(QString ADRESSE ){this->ADRESSE=ADRESSE;}
void  candidats::setNOM(QString NOM){this->NOM=NOM;}
void  candidats::setPRENOM(QString PRENOM){this->PRENOM=PRENOM;}
void  candidats::setCIN( int CIN){this->CIN=CIN;}
void  candidats::setMAIL(QString MAIL) {this->MAIL=MAIL;}
void  candidats::setGSM(int GSM) {this->GSM=GSM;}
void  candidats::setPOSTE(QString POSTE ){this->POSTE=POSTE;}
void  candidats::setSALAIRE(QString SALAIRE ){this->SALAIRE=SALAIRE;}
void  candidats::setPRETS(QString PRETS ){this->PRETS=PRETS;}
void  candidats::setDATEN(QDate DATEN ){this->DATEN=DATEN;}
void  candidats::setEXP(QString EXP ){this->EXP=EXP;}


bool candidats::ajouter()
{
QSqlQuery query;
QString CIN_string=QString::number(CIN);
QString GSM_string=QString::number(GSM);

query.prepare("INSERT INTO CANDIDATS (CIN,NOM,PRENOM,ADRESSE,MAIL,GSM,DATEN,POSTE,SALAIRE,PRETS,EXP) "
                    "VALUES (:CIN, :NOM,:PRENOM,:ADRESSE,:MAIL,:GSM,:DATEN,:POSTE,:SALAIRE,:PRETS,:EXP)");
query.bindValue(":ADRESSE", ADRESSE);
query.bindValue(":NOM", NOM);
query.bindValue(":PRENOM", PRENOM);
query.bindValue(":CIN", CIN_string );
query.bindValue(":MAIL", MAIL);
query.bindValue(":GSM",GSM_string);
query.bindValue(":DATEN", DATEN);
query.bindValue(":POSTE", POSTE);
query.bindValue(":SALAIRE", SALAIRE);
query.bindValue(":PRETS", PRETS);
query.bindValue(":EXP", EXP);
if( query.exec() ) {

    return true;
}
return false;

}




bool candidats::supprimer(int CIN )
{
QSqlQuery query;
QString res= QString::number(CIN);
query.prepare("Delete from candidats where CIN = :CIN ");
query.bindValue(":CIN", res);
if(query.exec()==true){

return query.exec();}
if(CIN==NULL){return false;}

}




QSqlQueryModel * candidats::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from candidats");
/*model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("GSM"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATEN"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("POSTE"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("SALAIRE"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("PRETS"));
model->setHeaderData(10, Qt::Horizontal, QObject::tr("EXP"));
*/


    return model;
}


bool candidats::modifier(int CIN,int GSM,QString ADRESSE,QString MAIL,QString POSTE )
{
    QSqlQuery query;
    QString res=QString::number(CIN);
    QString ress=QString::number(GSM);
    query.prepare("UPDATE candidats SET CIN=CIN,ADRESSE=:ADRESSE,MAIL=:MAIL,GSM=:GSM,POSTE=:POSTE WHERE CIN=:CIN");
    query.bindValue(":ADERESSE", ADRESSE);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":CIN", CIN );
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":GSM",GSM);
    query.bindValue(":DATEN", DATEN);
    query.bindValue(":POSTE", POSTE);
    query.bindValue(":SALAIRE", SALAIRE);
    query.bindValue(":PRETS", PRETS);
    query.bindValue(":EXP", EXP);


    if(query.exec()==true){

    return query.exec();}
    if(CIN!=NULL){return false;}

}


void candidats::recherche(QTableView* table,QString NOM){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from candidats  where NOM='"+NOM+"'");
    query->bindValue(":NOM",NOM);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}


 QSqlQueryModel *candidats::tri(){

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM candidats ORDER BY NOM ");
    q->exec();
    model->setQuery(*q);

    return model;
}

 QSqlQueryModel *candidats::trid(){

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM candidats ORDER BY NOM DESC");
    q->exec();
    model->setQuery(*q);

    return model;
}


QSqlQueryModel *candidats::Filtrer1(){

     QSqlQueryModel * model= new QSqlQueryModel();
         QString filtre="select *  from candidats where EXP='0ans' OR EXP='0ans'  OR EXP='1ans' OR EXP='2ans' OR EXP='3ans' OR EXP='4ans'OR EXP='5ans'";
         model->setQuery(filtre);
         return model;
 }

QSqlQueryModel *candidats::Filtrer2(){

     QSqlQueryModel * model= new QSqlQueryModel();
         QString filtre="select *  from candidats where EXP='6ans' OR EXP='7ans'  OR EXP='8ans' OR EXP='9ans' OR EXP='10ans' ";
         model->setQuery(filtre);
         return model;
 }

QSqlQueryModel *candidats::Filtrer3(){

     QSqlQueryModel * model= new QSqlQueryModel();
         QString filtre="select *  from candidats where  EXP='11ans'  OR EXP='12ans' OR EXP='13ans' OR EXP='14ans' OR EXP='15ans'";
         model->setQuery(filtre);
         return model;
 }

QSqlQueryModel *candidats::Filtrer4(){

     QSqlQueryModel * model= new QSqlQueryModel();
         QString filtre="select *  from candidats where EXP='16ans' OR EXP='17ans'  OR EXP='18ans' OR EXP='19ans' OR EXP='20ans' ";
         model->setQuery(filtre);
         return model;
 }
