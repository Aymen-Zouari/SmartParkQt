#ifndef EMPLOYE_H
#define EMPLOYE_H

#include<QSqlQueryModel>
class Employe
{
public:

    class Employe
    {
        QString nom ,prenom ,fonction ;
        int ID  ;
    public:
        //constructeurs
        Employe(){} ;
        Employee (int ,QString,QString,QString);
        //getters
        QString getNom(){return nom;}
        QString getPrenom(){return prenom;}
        QString getFonction(){return fonction;}
        int getID(){return ID;}
        //stters
        void setNom(QString n ){nom=n;}
        void setPrenom(QString p){prenom=p;}
        void setFonction(QString f){fonction=f;}
        void setID(int id){this->ID=id;}
        //fonctionnalites de base relatives a l'entité employé
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int );
    };

    Employe();
};

#endif // EMPLOYE_H
