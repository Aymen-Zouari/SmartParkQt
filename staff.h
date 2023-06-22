#ifndef STAFF_H
#define STAFF_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class staff
{
    QString nom ,prenom ,role,date_de_naissance,cin;

public:
    //constructeurs
    staff(){} ;
    staff (QString ,QString,QString,QString,QString);

    //getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getrole(){return role;}
    QString getdate_naissance(){return date_de_naissance;}
    QString getcin(){return cin;}
    //stters
    void setNom(QString n ){this->nom=n;}
    void setPrenom(QString p){this->prenom=p;}
    void setrole(QString f){this->role=f;}
    void setdate_naissance(QString d){this->date_de_naissance=d;}
    void setcin(QString cin){this->cin=cin;}
    //fonctionnalites de base relatives a l'entité employé
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString );
    bool modifier(QString ,QString,QString,QString,QString);

   QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();


};

#endif // STAFF_H
