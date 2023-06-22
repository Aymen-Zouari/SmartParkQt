#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QInputDialog>
#include <QMainWindow>
#include "candidats.h"
#include "sponsors.h"
#include "contact.h"
#include "graph.h"
#include "fournisseur.h"
#include "visiteur.h"
#include "staff.h"
#include <QVector>
#include "equipement.h"
#include "smtp.h"
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QDialog>
#include "connection.h"
#include "ui_mainwindow.h"
#include "todolist.h"
#include <QMediaPlayer>
#include "arduinosp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
int traduction(int);
private slots:

    void on_pushButtonAjouter_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonChercher_clicked();










    void on_radioButton_croissant_clicked();

    void on_radioButton_dcroissant_clicked();





    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_2_clicked();

   // void on_pushButton_clicked();


    void on_pushButton_4_clicked();

   // void on_pushButton_5_clicked();





    void on_pushButtonAjouter_2_clicked();

    void on_pushButtonSupprimer_2_clicked();

    void on_pushButtonModifier_2_clicked();

    void on_pushButtonChercher_2_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_croissant_2_clicked();

    void on_radioButton_dcroissant_2_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_12_clicked();

  //  void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();



    void on_pushButton_7_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButtonAjouter_3_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_pushButtonSupprimer_3_clicked();

    void on_pushButtonModifier_3_clicked();

    void on_pushButtonChercher_3_clicked();

    void on_radioButton_croissant_3_clicked();

    void on_radioButton_dcroissant_3_clicked();

    void on_radioButton_12_clicked();

    void on_radioButton_9_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_11_clicked();

    void on_recrut_clicked();
   // ---------------------spons-------------------------

    void on_ajoutersp_clicked();


        void on_supprimersp_clicked();

        void on_ouvrireajouter_clicked();

        void on_afficheraceuille_clicked();

        void on_pushButton_6_clicked();

        void on_actualitesaccuille_clicked();

        void on_statistiquesaceuille_clicked();

        void on_ajouteraceuille_clicked();



        void on_modifiersp_clicked();


        void on_tablesp_clicked(const QModelIndex &index);

        void on_ajouters_clicked();

        void on_ajoutere_clicked();


        void on_cherchersp_clicked();

        void on_triersp_activated(const QString &arg1);


        void on_spcombo1_2_currentTextChanged(const QString &arg1);



        void on_chercherc_clicked();

        void on_ajouterc_clicked();

        void on_modifierc_clicked();

        void on_supprimerc_clicked();

        void on_trierc_currentTextChanged(const QString &arg1);

        void on_affc_clicked(const QModelIndex &index);



        void on_tradu_currentTextChanged(const QString &arg1);

        void on_suprimmerc_clicked();

        void on_tradu_2_currentTextChanged(const QString &arg1);

        void on_tradu_3_currentTextChanged(const QString &arg1);

        void on_tradu_4_currentTextChanged(const QString &arg1);

        void on_tradu_5_currentTextChanged(const QString &arg1);

        void on_tradu_6_activated(const QString &arg1);


        void on_spons_clicked();

        void on_pushButton_clicked();

        void on_pushButton_3_clicked();

        void on_fourn_clicked();

        //-------------------------------FOURNISS----------------------------------------------

        void on_pushButtonAjouter_4_clicked();

            void on_pushButtonSupprimer_4_clicked();

            void on_pushButtonModifier_4_clicked();

            void on_pushButtonAfficher_2_clicked();

            void on_radioButton_croissant_4_clicked();

            void on_radioButton_decroissant_clicked();

            void on_pushButtonChercher_4_clicked();


          //  void on_pushButton_imprimer_clicked(); //

            void on_SelectFileButton_clicked();

            void on_pushButton_imprimer_clicked();

            void on_pushButton_8_clicked();



            void on_pushButtonAjouter_5_clicked();

            void on_pushButtonModifier_5_clicked();

            void on_pushButtonSupprimer_5_clicked();

            void on_pushButtonAfficher_3_clicked();

            void on_pushButtonChercher_5_clicked();

            void on_pushButton_17_clicked();

            void on_pushButton_19_clicked();

            void on_pushButton_18_clicked();



            void on_pushButton_20_clicked();


            //--------------------------------------------Visiteurs-----------------------------
            void on_ajouter_10_clicked();

            void on_supprimer_10_clicked();

            void on_modifier_10_clicked();

            void on_tri_10_clicked();

            void on_recherche_clicked();

            void on_stat_clicked();



            void on_vis_clicked();

            void on_pushButton_21_clicked();

            void on_Applytheme_2_clicked();

            void on_cancel_2_clicked();

            void on_theme_clicked();

           // void on_labelButton_clicked();

            void on_emp_clicked();

            void on_pushButton_26_clicked();



            //----------------ranim--------------------------

            void on_pushButton_ajouter_8_clicked();



            //void on_tableView_activated(const QModelIndex &index);

           // void on_supprimer_clicked();

            void on_supprimer_8_clicked();

            void on_modifier_8_clicked();

            //void on_pushButton_clicked();

            void on_tableView_activated(const QModelIndex &index);

           // void on_pushButton_100_clicked();

            void on_rechercher_pushButton_clicked();

             void on_pushButton_trier_8_clicked();

 void on_Login_2_clicked();

 void on_decon_clicked();
 void on_decon_2_clicked();
 void on_decon_3_clicked();
 void on_decon_4_clicked();
 void on_decon_5_clicked();
 void on_decon_6_clicked();

 void on_resetlogin_2_clicked();



 //------------------------------------------------SAMI-----------------------



 void on_modif_2_clicked();

 void on_pb_supprimer_2_clicked();

 void on_tableView_5_activated(const QModelIndex &index);

 void on_rechercher_2_clicked();



 void on_PDF_2_clicked();
 void on_ASC_2_clicked();
 void on_DESC_2_clicked();


 void sendMail_2();
 void mailSent_2(QString);
 void browse_2();

 void on_qr_2_clicked();

 void on_pushButton_27_clicked();


 void on_pushButton_25_clicked();

 void on_decon_7_clicked();



 //void on_horizontalSlider_sliderMoved(int position);

 //void on_horizontalSlider_2_sliderMoved(int position);

 //void on_start_clicked();

 //void on_stop_clicked();

 //void on_positionChanged(qint64 position);

 //void on_durationChanged(qint64 position);

 void on_theme_2_clicked();

 void on_pushButton_22_clicked();

 void on_MuteMedia_clicked();

 void on_StopMedia_clicked();
 void on_PauseMedia_clicked();
 void on_PlayMedia_clicked();
 void on_VolumeMediaControl_valueChanged(int value);

 void on_OpenMedia_clicked();

//arduino

 void on_suiv_clicked();

 void on_pred_clicked();

 void on_motpred_clicked();
 void update();

 void on_modsuiv_clicked();


private:
    Ui::MainWindow *ui;
    Sponsors sp;
    int *ido ();
    int *id();
    QString *nom();
    QString *nature();
    contact c;
Visiteur v;
    candidats Etmp;
    Fournisseur f;
QMediaPlayer* player;
    staff s ;
    equipement E;
    equipement TMP;
    QStringList files;
    CToDoList *app;
QMediaPlayer *mMediaPlayer;
    QMediaPlayer* playerm;



    //arduino
    QByteArray data; // variable contenant les données reçues
    Arduinosp A;
    int controle1=0;
    int controle2=0;
    int controle3=0;
    QVector<QVector<QVector<QMovie*>>> ff;
    QVector<QVector<QMovie*>> f1;
    QVector<QVector<QMovie*>> f2;
    QVector<QVector<QMovie*>> f3;
    QVector<QMovie*> f11;
    QVector<QMovie*> f12;
    QVector<QMovie*> f13;
    QVector<QMovie*> f21;
    QVector<QMovie*> f22;
    QVector<QMovie*> f23;
    QVector<QMovie*> f31;
    QVector<QMovie*> f32;
    QVector<QMovie*> f33;
    QMovie *a11=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/a11");
    QMovie *a12=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/a12");
    QMovie *a13=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/a13");
    QMovie *a21=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/a21");
    QMovie *a22=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/a22");
    QMovie *a23=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/a23");
    QMovie *a31=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/a31");
    QMovie *a32=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/a32");
    QMovie *a33=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/a33");
    QMovie *b11=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/b11");
    QMovie *b12=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/b12");
    QMovie *b13=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/b13");
    QMovie *b21=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/b21");
    QMovie *b22=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/b22");
    QMovie *b23=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/b23");
    QMovie *b31=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/b31");
    QMovie *b32=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/b32");
    QMovie *b33=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/b33");
    QMovie *c11=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/c11");
    QMovie *c12=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/c12");
    QMovie *c13=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/c13");
    QMovie *c21=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/c21");
    QMovie *c22=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/c22");
    QMovie *c23=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/c23");
    QMovie *c31=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/c31");
    QMovie *c32=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/c32");
    QMovie *c33=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/c33");
    QMovie *initiale=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/00");
};

#endif // MAINWINDOW_H
