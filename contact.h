#ifndef CONTACT_H
#define CONTACT_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class contact
{
public:
    contact();
    contact(QString,QString,int,QString,int,int,QString);
    QSqlQueryModel* afficher();
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* affichercombo();
    bool modifiernom(QString,QString);
    bool modifierprenom(QString,QString);
    bool modifierid(QString,QString);
    bool modifierposte(QString,QString);
    bool modifiergsm(QString,QString);
    bool modifierfixe(QString,QString);
    bool modifiermail(QString,QString);
    QSqlQueryModel*  cherchesp(QVariant);
    QSqlQueryModel*  trier(QString);
private:
    int numero;
    QString nom;
    QString prenom;
    int id;
    QString poste;
    int gsm;
    int fixe;
    QString mail;

};

#endif // CONTACT_H
