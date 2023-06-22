#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
class evenement
{
public:
    evenement();
   evenement(int ,int ,QString ,QString ,QDate ,QString ,QString );
    int getnum_eve();
    QString getnom_eve();
    QString gettype_eve();
    QDate getdate_eve();
    QString getmontant_payee();
    QString getmontant_gagnee();
    void setnum_eve(int);
    void setnom_eve(QString);
    void settype_eve(QString);
    void setdate_eve(QDate);
    void setmontant_payee(QString);
    void setmontant_gagnee(QString);
    void setnature(QString);
    QSqlQueryModel* afficher();
    bool ajouter();
    bool supprimer(int);
    bool  modifieridsp(QString ,QString );
    bool  modifiernum_eve(QString ,QString);
    bool  modifiernom_eve(QString ,QString );
    bool  modifiertype_eve(QString ,QString );
    bool  modifierdate_eve(QDate,QString);
    bool  modifiermontant_payee(QString,QString);
    bool  modifiermontant_gagnee(QString ,QString);

private:
    int idsp;
    int num_eve;
    QString nom_eve;
    QString type_eve;
    QDate date_eve;
    QString montant_payee;
    QString montant_gagnee;

};

#endif // EVENEMENT_H
