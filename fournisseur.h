#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QInputDialog>
#include<QTableView>
#include <QSqlQueryModel>
#include <QDateEdit>
#include <QPlainTextEdit>
class Fournisseur
{
public:
    Fournisseur();
 Fournisseur(int,QString,QString,int , QDate,int,QString,QString );
  int getcode();
  QString getnom();
  QString getadresse();
  int getcode_fc();
   QDate getdate_fc();
  int getGSM();
  QString getmail();
  QString getmodep();

  void setcode(int);
  void setnom( QString);
  void setadresse( QString);
  void setcode_fc(int);
  void setdate_fc( QDate);
  void setGSM(int);
  void setmail( QString);
  void setmodep( QString);


  bool ajouter();
  QSqlQueryModel * afficher();
  bool supprimer(int);
  bool modifier(int);
    QSqlQueryModel * recherche(QString rech);
   QSqlQueryModel * tri();
   QSqlQueryModel * trid();

 private :
    int code , code_fc , GSM ;
     QDate  date_fc;
    QString nom , adresse , mail , modep ;



};

#endif // FOURNISSEUR_H
