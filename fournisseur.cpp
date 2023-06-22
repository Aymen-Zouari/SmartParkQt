#include "fournisseur.h"
#include"QMessageBox"
#include <QSqlQuery>
#include <QObject>
#include <QtDebug>
#include <QDateEdit>
Fournisseur::Fournisseur()
{
    code =0 ; code_fc =0 ; GSM =0;
    nom="" ; adresse=""  ; mail="" ; modep="" ;
}

Fournisseur::Fournisseur(int code,QString nom,QString adresse,int code_fc ,QDate date_fc,int GSM,QString mail,QString modep )
{ this->code=code; this->nom=nom ; this->adresse=adresse ; this->code_fc=code_fc ; this->date_fc=date_fc ; this->GSM=GSM ; this->mail=mail ; this->modep=modep ;}
    int Fournisseur::getcode(){return code;}
    QString Fournisseur::getnom(){return nom ;}
    QString Fournisseur::getadresse(){return adresse;}
    int Fournisseur::getcode_fc(){return code_fc;}
    QDate Fournisseur::getdate_fc(){return date_fc;}
    int Fournisseur::getGSM(){return GSM;}
    QString Fournisseur::getmail(){return mail ;}
    QString Fournisseur::getmodep(){return modep;}

    void Fournisseur::setcode(int code){this->code=code;}
    void Fournisseur::setnom( QString nom ){ this->nom=nom; }
    void Fournisseur::setadresse( QString adresse ){ this->adresse=adresse; }
    void Fournisseur::setcode_fc(int code_fc){ this->code_fc=code_fc; }
    void Fournisseur::setdate_fc(QDate date_fc){this->date_fc=date_fc; }
    void Fournisseur::setGSM(int GSM){this->GSM=GSM ; }
    void Fournisseur::setmail( QString mail){ this->mail=mail; }
    void Fournisseur::setmodep( QString modep){ this->modep=modep; }

    bool Fournisseur::ajouter()
    {
    QSqlQuery query;
    QString codestring=QString::number(code);
    QString code_fcstring=QString::number(code_fc);
    QString GSMstring=QString::number(GSM);
    query.prepare("INSERT INTO FOURNISSEUR (code,nom,adresse,code_fc,date_fc, GSM,mail,modep) "
                        "VALUES (:code,:nom,:adresse,:code_fc,:date_fc, :GSM,:mail,:modep)");
    query.bindValue(":code", codestring);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":code_fc", code_fcstring);
    query.bindValue(":date_fc", date_fc);
    query.bindValue(":GSM",GSMstring);
    query.bindValue(":mail",mail);
    query.bindValue(":modep",modep);
      return query.exec();

    }
    bool Fournisseur::supprimer(int code )
    {
    QSqlQuery query;
    QString res= QString::number(code);
    query.prepare("Delete from fournisseur where code = :code ");
    query.bindValue(":code", res);
    return    query.exec();
    }
    QSqlQueryModel * Fournisseur::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Fournisseur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("code_fc"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_fc"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("GSM"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("modep"));

        return model;
    }
    bool Fournisseur::modifier(int code)
    {
        QSqlQuery query;
        QString codestring=QString::number(code);
        QString code_fcstring=QString::number(code_fc);
        QString GSMstring=QString::number(GSM);

        query.prepare("UPDATE Fournisseur SET code=code,nom=:nom,adresse=:adresse,code_fc=:code_fc,date_fc=:date_fc ,GSM=:GSM,mail=:mail,modep=:modep WHERE code=:code");
        query.bindValue(":code", codestring);
        query.bindValue(":nom", nom);
        query.bindValue(":adresse",adresse);
        query.bindValue(":code_fc", code_fcstring);
        query.bindValue(":date_fc", date_fc);
        query.bindValue(":GSM",GSMstring);
        query.bindValue(":mail",mail);
        query.bindValue(":modep",modep);
        return    query.exec();
      //  if(query.exec())
        //{//QMessageBox::warning(this,"modifiction","modifictionnnnnnnnnnnnn");}



    }

   QSqlQueryModel * Fournisseur::recherche(QString rech){

       QSqlQueryModel * model= new QSqlQueryModel();
             //  QString recher="select *  from Fournisseur where NOM like '%"+rech+"%'or MAIL like '%"+rech+"%'or ADRESSE like '%"+rech+"%'";
             //  model->setQuery(recher);
       model->setQuery("select *  from Fournisseur where NOM like '%"+rech+"%'or MAIL like '%"+rech+"%'or ADRESSE like '%"+rech+"%'");
               return model;
    }
    QSqlQueryModel *Fournisseur::tri(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM Fournisseur ORDER BY nom ");
       q->exec();
       model->setQuery(*q);

       return model;
   }

    QSqlQueryModel *Fournisseur::trid(){

       QSqlQuery *q = new QSqlQuery();
       QSqlQueryModel *model = new QSqlQueryModel();
       q->prepare("SELECT * FROM Fournisseur ORDER BY nom DESC");
       q->exec();
       model->setQuery(*q);

       return model;
   }


