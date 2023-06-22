#ifndef SPONSORS_H
#define SPONSORS_H
#include <QString>
#include <QSqlQueryModel>
class Sponsors
{
private:
    int id_sponsor;
    QString nom_sp;
    QString nature;
public:
    Sponsors();
    Sponsors(int,QString,QString);
    int getid_sponsor();
    QString getnom_sp();
    QString getnature();

    void setid_sponsor(int);
    void setnom_sp(QString);
    void setnature(QString);
    QSqlQueryModel* afficher();
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* affichercombo();
    bool modifiernom(QString,QString);
    bool modifierid(QString,QString);
    bool modifiertype(QString,QString);
    QSqlQueryModel*  cherchesp(QVariant);
    QSqlQueryModel*  trier(QString);
};

#endif // SPONSORS_H
