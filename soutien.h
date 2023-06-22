#ifndef SOUTIEN_H
#define SOUTIEN_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
class soutien
{
public:
    soutien();
    soutien(int  ,int ,QString ,int ,QDate );
    int getnum_sou();
    QString gettype_sou();
    double getquantite_sou();
    QDate getdate_sou();
    void setnum_sou(int);
    void settype_sou(QString);
    void setquantite_sou(double);
    void setdate_sou(QDate);
    void setnature(QString);
    QSqlQueryModel* afficher();
    bool ajouter();
    bool supprimer(int);
    bool  modifieridsp(QString,QString);
    bool  modifiernum_sou(QString,QString);
    bool  modifiertype_sou(QString,QString);
    bool  modifierquantite_sou(QString,QString);
    bool  modifierdate_sou(QDate,QString);
private :
    int idsp;
    int num_sou;
    QString type_sou;
    int quantite_sou;
    QDate date_sou;
};

#endif // SOUTIEN_H
