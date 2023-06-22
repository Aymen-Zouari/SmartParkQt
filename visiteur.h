#ifndef VISITEUR_H
#define VISITEUR_H
#include<QString>
#include<QSqlQueryModel>
class Visiteur
{
public:
    Visiteur();
    Visiteur(QString,QString,QString,int,int,int);
    QString gettype();
    QString getprenom();
    QString getnom();
    int getage();
    int getcin();
    int gettel();
    void settype(QString);
    void setprenom(QString);
    void setnom(QString);
    void setage(int);
    void setcin(int);
    void settel(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(QString,QString,QString,int,int,int);
    QSqlQueryModel * recherche(QString rech);
    QSqlQueryModel *tri();
private :
  QString  type,prenom,nom;
  int age,cin,tel;
};

#endif // VISITEUR_H
