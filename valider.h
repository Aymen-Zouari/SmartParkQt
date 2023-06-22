#ifndef VALIDER_H
#define VALIDER_H
#include <QString>
#include <QSqlQueryModel>

class valider
{
int CIN;
    QString NOM,PRENOM,DESCRIPTION;
public:
    valider();
    valider(int ,QString,QString,QString);

    int get_CIN();
    QString get_NOM();
QString get_PRENOM();
QString get_DESCRIPTION();
void setCIN(int);
void setPRENOM(QString);
   void  setNOM(QString);
   void  setDESCRIPTION(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
QSqlQueryModel * rechercher(QString );

};

#endif // VALIDER_H
