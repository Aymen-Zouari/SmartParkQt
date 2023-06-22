#include "staff.h"

staff::staff(QString cin ,QString nom ,QString prenom ,QString role,QString date)
{
    this->cin=cin ;
    this->nom=nom ;
    this->prenom=prenom;
    this->role=role ;
    this->date_de_naissance=date ;
}
bool staff::ajouter()
{
    QSqlQuery query;

    query.prepare("insert into STAF(CIN , NOM , PRENOM , ROLE, DATE_NAISSANCE) values(:cin , :nom , :prenom ,:role ,:date_naissance)");

    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":role",role);
    query.bindValue(":date_naissance",date_de_naissance);
    return query.exec();//exec() envoie la requete pour l'executer


}
QSqlQueryModel * staff::afficher ()
{
   QSqlQueryModel * model =new QSqlQueryModel();

//nom, prenom , cin , role , date_naissance
   model->setQuery("SELECT * FROM staf");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("role"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date de naissance"));
    return model ;

}


bool staff::supprimer(QString cin)
{
QSqlQuery query ;

query.prepare("Delete from staf where CIN= :cin");
query.bindValue(":cin",cin);
return query.exec();
}



 bool staff::modifier(QString cin ,QString nom,QString prenom,QString role,QString date_naissance)
 {
     QSqlQuery query ;
   //  QString id_string = QString::number(cin);
     query.prepare("update staf set nom=:nom,prenom=:prenom,role=:role,date_naissance=:date_naissance where cin=:cin");
     query.bindValue(":cin",cin);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":role",role);
     query.bindValue(":date_naissance",date_naissance);
     return query.exec();
}


 QSqlQueryModel * staff::tri()
 {
     QSqlQueryModel *model= new QSqlQueryModel;
     QSqlQuery *q=new QSqlQuery();
     q->prepare("select * from staf order by CIN asc");
     q->exec();
     model->setQuery(*q);
     return  model;
 }


 QSqlQueryModel *staff::rechercher(QString rech)
  {
      QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("select * from staf where CIN LIKE '"+rech+"%'");
      return model;
 }



