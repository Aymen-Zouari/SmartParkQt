#ifndef CANDIDATS_H
#define CANDIDATS_H
#include <QString>
#include <QSqlQuery>
#include <QInputDialog>
#include<QTableView>
#include <QSqlQueryModel>
#include <QDateEdit>

#include <QPlainTextEdit>
class candidats
{public:
    candidats();
    candidats(int,QString,QString,QString,int,QString,QDate,QString,QString,QString,QString);
    QString  get_ADRESSE();
    QString  get_SALAIRE();
    QString  get_POSTE();
    QString  get_EXP();
    QDate  get_DATEN();
    QString  get_PRETS();
    QString get_NOM();
    QString get_PRENOM();
    int get_CIN();
    int get_GSM();
    QString get_MAIL();


    void  setADRESSE(QString);
    void  setNOM(QString);
    void  setPRENOM(QString);
    void  setCIN( int);
    void setMAIL(QString);
    void  setGSM(int);
  void  setSALAIRE(QString);
    void  setPOSTE(QString);
    void  setDATEN(QDate);
    void  setPRETS(QString);
    void  setEXP(QString);


    bool testmail(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,QString,QString);
    void recherche(QTableView* table,QString);
     QSqlQueryModel * tri();
     QSqlQueryModel * trid();
     QSqlQueryModel * Filtrer1(  );
     QSqlQueryModel * Filtrer2(  );
     QSqlQueryModel * Filtrer3(  );
     QSqlQueryModel * Filtrer4(  );



private:
    QString NOM,PRENOM,MAIL,ADRESSE,SALAIRE,POSTE,PRETS,EXP;
    QDate DATEN;
    int CIN,GSM;
};



#endif // CANDIDATS_H
