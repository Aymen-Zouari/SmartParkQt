#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQueryModel>
#include "qcustomplot.h"


class equipement
{
public:
    equipement(); // constructeure par defaut
     equipement(int,int,QString,int,int);  // constructeure parametre

     int getcode();
         int getremise();
         int getetat();
         QString getadresse();
         int gettarif();

         void setcode(int);
         void setremise(int);
         void setetat(int);
         void setadresse(QString);
         void settarif(int);


         bool ajouter();
         QSqlQueryModel* chercher_eq(QString text);
         QSqlQueryModel* afficher();
         bool supprimer(int);
         bool modifier(int code,int etat,QString adresse,int tarif, int remise);
         QSqlQueryModel *tri_tarif_asc();
         QSqlQueryModel *tri_tarif_desc();

private:
         int code,tarif,remise,etat;
         QString adresse;
};





#endif // EQUIPEMENT_H
