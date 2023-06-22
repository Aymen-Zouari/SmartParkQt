#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "candidats.h"
#include <QMessageBox>
#include <QDebug>
#include <QTableWidget>
#include <QIntValidator>
#include <QFontDialog>
#include <QDate>
#include "valider.h"
#include <QTranslator>
#include <QDateTime>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "sponsors.h"
#include <QMessageBox>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QTabWidget>
#include<QTabWidget>
#include <QAbstractItemView>
#include <QStyledItemDelegate>
#include <QEvent>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QString>
#include <QDateEdit>
 #include "soutien.h"
#include "evenement.h"
#include <QSqlRecord>
#include <QBrush>
#include <Qt>
#include <QStyleFactory>
#include <QtDataVisualization>
#include <Q3DBars>
#include <QHBoxLayout>
#include <QtDataVisualization/qcategory3daxis.h>
#include <QtDataVisualization/qvalue3daxis.h>
#include <QtDataVisualization/qbardataproxy.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/q3dcamera.h>
#include <QtDataVisualization/qbar3dseries.h>
#include <QtDataVisualization/q3dtheme.h>
#include "graph.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSlider>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtGui/QScreen>
#include <QtGui/QFontDatabase>
#include "contact.h"
#include <QFile>
#include <QTextStream>
#include <QSystemTrayIcon>
#include <QFileDialog>
#include <QTextStream>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QMediaPlayer>
#include <QSlider>
#include <QSound>
#include <QSortFilterProxyModel>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include<QDirModel>
#include "qrcode.h"
#include "todolist.h"
#include "equipement.h"
#include "smtp.h"
#include <QIcon>
#include <QLabel>
#include "equipement.h"
#include "smtp.h"

#include <fstream>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QFile>
#include <QSortFilterProxyModel>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>

#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QTextStream>
#include<QWidget>
#include <QtSvg/QSvgRenderer>
#include<QDirModel>
#include "qrcode.h"
#include "todolist.h"
#include <QMovie>
#include "sponsors.h"
#include <QMessageBox>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QTabWidget>
#include<QTabWidget>
#include <QAbstractItemView>
#include <QStyledItemDelegate>
#include <QEvent>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QString>
#include <QDateEdit>
 #include "soutien.h"
#include "evenement.h"
#include <QSqlRecord>
#include <QBrush>
#include <Qt>
#include <QStyleFactory>
#include <QtDataVisualization>
#include <Q3DBars>
#include <QHBoxLayout>
#include <QtDataVisualization/qcategory3daxis.h>
#include <QtDataVisualization/qvalue3daxis.h>
#include <QtDataVisualization/qbardataproxy.h>
#include <QtDataVisualization/q3dscene.h>
#include <QtDataVisualization/q3dcamera.h>
#include <QtDataVisualization/qbar3dseries.h>
#include <QtDataVisualization/q3dtheme.h>
#include "graph.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSlider>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtGui/QScreen>
#include <QtGui/QFontDatabase>
#include "contact.h"
#include <QFile>
#include <QTextStream>
#include <QSystemTrayIcon>
#include <QPixmap>
#include <QImage>



 using namespace QtDataVisualization;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //music
    mMediaPlayer = new QMediaPlayer(this);


      const int  n=0;
    playerm = new QMediaPlayer(this);
    //playerm->setMedia(QUrl::fromLocalFile("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/harry-potter-theme-song.mp3"));
    playerm->setVolume(n);
    playerm->play();
    connect(playerm,&QMediaPlayer::positionChanged,[&](qint32 pos){
           ui->VolumeMediaDisplay->setValue(pos);
       });
       connect(playerm,&QMediaPlayer::durationChanged,[&](qint32 dur){
           ui->VolumeMediaDisplay->setMaximum(dur);
       });
    /*connect(playerm,&QMediaPlayer::positionChanged,this,&MainWindow::on_positionChanged);
    connect(playerm,&QMediaPlayer::durationChanged,this,&MainWindow::on_durationChanged);*/
    //QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Harry Potter Theme Song.wav");
//icon
    ui->pushButtonAjouter->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonAjouter_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonAjouter_3->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonAjouter_4->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonAjouter_5->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_ajouter_8->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonModifier->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonModifier_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonModifier_3->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonModifier_4->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonModifier_5->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonSupprimer->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonSupprimer_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonSupprimer_3->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonSupprimer_4->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonSupprimer_5->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_afficher->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_3->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_4->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_5->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_6->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_7->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_8->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_9->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_10->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_11->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_12->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_13->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_14->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_15->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_16->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_17->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_18->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_19->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_20->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_21->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_24->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_26->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_trier_8->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_imprimer->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButton_imprimer_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->rechercher_pushButton_8->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->recrut->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->spons->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->emp->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->fourn->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->eq->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->vis->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonChercher->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonChercher_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonChercher_3->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonChercher_4->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->pushButtonChercher_5->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->ajoutersp->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->supprimersp->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->modifiersp->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->ajouters->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->ajouterc->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->ouvrireajouter->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->afficheraceuille->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->actualitesaccuille->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->ajouteraceuille->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->ajoutere->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->chercherc->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->cherchersp->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->modifierc->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->supprimerc->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->supprimer_8->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->supprimer_10->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    //
    ui->rechercher_pushButton_8->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->ajouter_10->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->modifier_10->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->supprimer_10->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->tri_10->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->recherche->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->stat->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->statistiquesaceuille->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->labelButton->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->cameraButton->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->zoomToSelectedButton->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
    ui->theme->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->suprimmerc->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));

     //
     ui->pushButtonAfficher_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->pushButtonAfficher_3->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->SelectFileButton->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->SelectFileButton_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->decon->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->decon_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->decon_3->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->decon_4->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->decon_5->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->decon_6->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->Login_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->resetlogin_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));


     ui->rechercher_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->pushButton_25->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->modif_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->PDF_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->qr_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->pushButton_27->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->pb_supprimer_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->decon_7->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->sendBtn_3->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));
     ui->browseBtn_3->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));


     //icon music

     ui->PlayMedia->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/jouer"));
     ui->StopMedia->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/stop"));
     ui->PauseMedia->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/pause"));
     ui->OpenMedia->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-folder-48"));
     ui->PlayMedia->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/jouer"));


     ui->theme_2->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/settings"));
     ui->pushButton_22->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/icons8-magicien-48"));



//animation


    /* QLabel* logo = new QLabel(ui->logo);
     logo->setWindowFlags(Qt::FramelessWindowHint);
      logo->setMask((new QPixmap("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/unnamed.gif"))->mask());*/
     QMovie* movie=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/unnamed (1).gif");

     ui->logo->setMovie(movie);
     movie->setSpeed(500);
     movie->start();

     QPropertyAnimation *animation = new QPropertyAnimation(ui->logo2,"geometry");
             animation->setDuration(1200);
            // animation->setLoopCount(-2);
             animation->setStartValue(QRect(0, 0, 320,253));
             animation->setEndValue(QRect(1150,0, 320,253));

             animation->start();

QMovie* movie2=new QMovie("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/1abb2f20e969fcf5d7d633ac3b40f66f.gif");
ui->logo3->setMovie(movie2);

movie2->start();


    //teena
    ui->tab_candidat->setModel(Etmp.afficher());
    ui->tab_candidat_2->setModel(Etmp.afficher());
    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
      if (!file.open(QIODevice::ReadOnly))
      {
          QMessageBox::information(0,"info",file.errorString());
      }
      QTextStream in (&file);
     ui->textBrowser->setText(in.readAll());


     QFile file2("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");
       if (!file2.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file2.errorString());
       }
       QTextStream to (&file2);
      ui->textBrowser_2->setText(to.readAll());

      QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");
        if (!file3.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(0,"info",file3.errorString());
        }
        QTextStream too (&file2);
       ui->textBrowser_3->setText(too.readAll());



    //controle de saisie
ui->cin->setMaxLength(8);

ui->gsmm->setMaxLength(8);
ui->GSM->setMaxLength(8);
ui->cin->setValidator(new QIntValidator(0,99999999,this));
ui->GSM->setValidator(new QIntValidator(0,99999999,this));
ui->gsmm->setValidator(new QIntValidator(0,99999999,this));

ui->NOM->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->PRENOM->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->cin->setMaxLength(8);

ui->gsmm_2->setMaxLength(8);
ui->GSM_2->setMaxLength(8);
ui->cin_2->setValidator(new QIntValidator(0,99999999,this));
ui->GSM_2->setValidator(new QIntValidator(0,99999999,this));
ui->gsmm_2->setValidator(new QIntValidator(0,99999999,this));

ui->NOM_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->PRENOM_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));

ui->gsmm_3->setMaxLength(8);
ui->GSM_3->setMaxLength(8);
ui->cin_3->setValidator(new QIntValidator(0,99999999,this));
ui->GSM_3->setValidator(new QIntValidator(0,99999999,this));
ui->gsmm_3->setValidator(new QIntValidator(0,99999999,this));

ui->NOM_3->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->PRENOM_3->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));

ui->lineEdit->setMaxLength(8);
ui->lineEdit->setValidator(new QIntValidator(0,99999999,this));

ui->lineEdit_9->setValidator(new QIntValidator(0,99999999,this));
ui->lineEdit_9->setMaxLength(8);

ui->lineEdit_5->setValidator(new QIntValidator(0,99999999,this));
ui->lineEdit_5->setMaxLength(8);



ui->lineEdit_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_3->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_4->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));

ui->lineEdit_6->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_7->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_8->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));

ui->lineEdit_10->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_11->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
ui->lineEdit_12->setValidator(new QRegExpValidator( QRegExp("[A-Za-z- _]+"), this ));
/*-------------------------------------------Visiteurs---------------------------------------------------------------*/

ui->le_cin->setValidator(new QIntValidator(0,9999999, this));
ui->tab_vis->setModel(v.afficher());



//sami---------------------------------------
connect(ui->sendBtn_3, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->browseBtn_3, SIGNAL(clicked()), this, SLOT(browse()));

      ui->tableView_5->setModel(E.afficher());

}


MainWindow::~MainWindow()
{
    delete ui;
}








void MainWindow::on_pushButtonAjouter_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");

    int  CIN=ui->cin->text().toInt();

    QString ADRESSE=ui->ADRESSE->text();
     QString NOM=ui->NOM->text();
      QString PRENOM=ui->PRENOM->text();
      int GSM=ui->GSM->text().toInt();
       QString MAIL=ui->MAIL->text();
       QDate DATEN=ui->dateEdit->date();
       QString POSTE=ui->POSTE->text();
       QString SALAIRE=ui->SALAIRE->text();
       QString PRETS=ui->PRETS->text();
       QString EXP=ui->EXP->text();

    candidats C(CIN,ADRESSE,NOM,PRENOM,GSM,MAIL,DATEN,POSTE,SALAIRE,PRETS,EXP);
    if(CIN<=0||ADRESSE.isEmpty() || NOM.isEmpty() || PRENOM.isEmpty()|| GSM<=0 || MAIL.isEmpty() || POSTE.isEmpty()|| SALAIRE.isEmpty() || PRETS.isEmpty()|| EXP.isEmpty())
                         {
                             QMessageBox::critical(0,qApp->tr("Erreur"),qApp->tr("Le remplissage des champs vides est Obligatoire."),QMessageBox::Cancel);
                         }

    else
    {
bool test=C.ajouter();
QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file);
if(test)
{

    QString message2="Vous avez ajouté un candidat\n";
        cout << message2;
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser->setText(in.readAll());
    ui->tab_candidat->setModel(Etmp.afficher());//rafraishissement
    QMessageBox::information(nullptr, QObject::tr("Candidat ajouté"),
                QObject::tr("successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("Candidat non ajouté"),
                QObject::tr("failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}ui->stackedWidget_3->setCurrentIndex(1);
}


void MainWindow::on_pushButtonSupprimer_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int CIN = ui->tab_candidat->selectionModel()->currentIndex().data().toInt();
    bool test=Etmp.supprimer(CIN);
    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
    if(test)
    {

        QString message2="Vous avez supprimé un candidat\n";
            cout <<""<< message2;

            QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file.errorString());
           }
           QTextStream in (&file);
          ui->textBrowser->setText(in.readAll());
        ui->tab_candidat->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }




void MainWindow::on_pushButtonModifier_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats c;

        int CIN = ui->tab_candidat->selectionModel()->currentIndex().data().toInt();
        int GSM=ui->gsmm->text().toInt();

        QString ADRESSE=ui->adressem->text();


        QString MAIL=ui->mailm->text();


        QString POSTE=ui->postem->text();

        candidats C;
    bool test=C.modifier(CIN, GSM, ADRESSE, MAIL, POSTE);


    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
    if(test)
    {

        QString message2="Vous avez modifié un candidat\n";
            cout << message2;


            QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file.errorString());
           }
           QTextStream in (&file);
          ui->textBrowser->setText(in.readAll());
        ui->tab_candidat->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_pushButtonChercher_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
QString findText;
       QString text = ui->chercher->text();

   QTableView* table=ui->tab_candidat;
       if (text.isEmpty()) {
           QMessageBox::information(this, tr("Empty Field"),
               tr("Entrez le nom a rechercher."));
           ui->tab_candidat->setModel(Etmp.afficher());
           return;
       } else {
           findText = text;
           Etmp.recherche(table,findText);
}

}




void MainWindow::on_radioButton_croissant_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
                  ui->tab_candidat->setModel(Etmp.tri());

}


void MainWindow::on_radioButton_dcroissant_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
                  ui->tab_candidat->setModel(Etmp.trid());
}




void MainWindow::on_radioButton_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat->setModel(C.Filtrer2());
}

void MainWindow::on_radioButton_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat->setModel(C.Filtrer3());
}

void MainWindow::on_radioButton_4_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat->setModel(C.Filtrer1());
}




void MainWindow::on_radioButton_3_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat->setModel(C.Filtrer4());
}



//valider fr
void MainWindow::on_pushButton_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QSqlQuery query;

    int  CIN=ui->lineEdit->text().toInt();

    QString NOM=ui->lineEdit_2->text();
    QString PRENOM=ui->lineEdit_3->text();
   QString DESC=ui->lineEdit_4->text();
valider v(CIN,NOM,PRENOM,DESC);
bool test=v.ajouter();
QFile file2("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");//declaration d'un fichier
        if(!file2.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file2);
if(test)
{

    QString message2="\n CIN:";
    QString message3="\n NOM:";
    QString message4="\n PRENOM:";
    QString message5="\n DESCRIPTION:";
        cout << message2<<CIN;
        cout <<message3<<NOM;
        cout <<message4<<PRENOM;
        cout << message5<<DESC;
        QFile file2("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");
       if (!file2.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file2.errorString());
       }
       QTextStream to (&file2);
      ui->textBrowser_2->setText(to.readAll());


}}

/*void MainWindow::on_pushButton_clicked()
{

}*/


//return
void MainWindow::on_pushButton_4_clicked()
{
    QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_3->setCurrentIndex(0);
}






//ANG-----------------------------------------------------------------------------------------------------------------------------------



void MainWindow::on_pushButtonAjouter_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int  CIN=ui->cin_2->text().toInt();

    QString ADRESSE=ui->ADRESSE_2->text();
     QString NOM=ui->NOM_2->text();
      QString PRENOM=ui->PRENOM_2->text();
      int GSM=ui->GSM_2->text().toInt();
       QString MAIL=ui->MAIL_2->text();
       QDate DATEN=ui->dateEdit_2->date();
       QString POSTE=ui->POSTE_2->text();
       QString SALAIRE=ui->SALAIRE_2->text();
       QString PRETS=ui->PRETS_2->text();
       QString EXP=ui->EXP_2->text();

    candidats C(CIN,ADRESSE,NOM,PRENOM,GSM,MAIL,DATEN,POSTE,SALAIRE,PRETS,EXP);
    if(CIN<=0||ADRESSE.isEmpty() || NOM.isEmpty() || PRENOM.isEmpty()|| GSM<=0 || MAIL.isEmpty() || POSTE.isEmpty()|| SALAIRE.isEmpty() || PRETS.isEmpty()|| EXP.isEmpty())
                         {
                             QMessageBox::critical(0,qApp->tr("Erreur"),qApp->tr("The filling of empty fields is Obligatory."),QMessageBox::Cancel);
                         }

    else
    {
bool test=C.ajouter();
QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file);
if(test)
{

    QString message2="You had added a candidate\n";
        cout << message2;
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser_4->setText(in.readAll());
    ui->tab_candidat_2->setModel(Etmp.afficher());//rafraishissement
    QMessageBox::information(nullptr, QObject::tr("Candidat ajouté"),
                QObject::tr("successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("Candidat non ajouté"),
                QObject::tr("failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);



    }ui->stackedWidget_4->setCurrentIndex(1);}

void MainWindow::on_pushButtonSupprimer_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int CIN = ui->tab_candidat_2->selectionModel()->currentIndex().data().toInt();
    bool test=Etmp.supprimer(CIN);
    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
    if(test)
    {

        QString message2="You had deleted a candidate\n";
            cout <<""<< message2;

            QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file.errorString());
           }
           QTextStream in (&file);
          ui->textBrowser_4->setText(in.readAll());
        ui->tab_candidat_2->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }




void MainWindow::on_pushButtonModifier_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats c;

        int CIN = ui->tab_candidat_2->selectionModel()->currentIndex().data().toInt();
        int GSM=ui->gsmm_2->text().toInt();

        QString ADRESSE=ui->adressem_2->text();


        QString MAIL=ui->mailm_2->text();


        QString POSTE=ui->postem_2->text();

        candidats C;
    bool test=C.modifier(CIN, GSM, ADRESSE, MAIL, POSTE);


    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
    if(test)
    {

        QString message2="You had modified a candidate\n";
            cout << message2;


            QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file.errorString());
           }
           QTextStream in (&file);
          ui->textBrowser_4->setText(in.readAll());
        ui->tab_candidat_2->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_pushButtonChercher_2_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
QString findText;
       QString text = ui->chercher_2->text();

   QTableView* table=ui->tab_candidat_2;
       if (text.isEmpty()) {
           QMessageBox::information(this, tr("Empty Field"),
               tr("Entrez le nom a rechercher."));
           ui->tab_candidat_2->setModel(Etmp.afficher());
           return;
       } else {
           findText = text;
           Etmp.recherche(table,findText);
}

}




void MainWindow::on_radioButton_croissant_2_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
                  ui->tab_candidat_2->setModel(Etmp.tri());

}


void MainWindow::on_radioButton_dcroissant_2_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
                  ui->tab_candidat_2->setModel(Etmp.trid());
}




void MainWindow::on_radioButton_5_clicked()
{
   QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
   candidats C;



   ui->tab_candidat_2->setModel(C.Filtrer2());
}

void MainWindow::on_radioButton_6_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat_2->setModel(C.Filtrer3());
}

void MainWindow::on_radioButton_8_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat_2->setModel(C.Filtrer1());
}




void MainWindow::on_radioButton_7_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat_2->setModel(C.Filtrer4());
}
















// BOUTONS ang
void MainWindow::on_pushButton_11_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_2->setCurrentIndex(1);

}
//ml ang lel fr
void MainWindow::on_pushButton_12_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_9_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_4->setCurrentIndex(0);
}


//valider ang
void MainWindow::on_pushButton_7_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QSqlQuery query;

    int  CIN=ui->lineEdit_5->text().toInt();

    QString NOM=ui->lineEdit_6->text();
    QString PRENOM=ui->lineEdit_7->text();
   QString DESC=ui->lineEdit_8->text();
valider v(CIN,NOM,PRENOM,DESC);
bool test=v.ajouter();
QFile file2("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");//declaration d'un fichier
        if(!file2.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file2);
if(test)
{

    QString message2="\n CIN:";
    QString message3="\n NAME:";
    QString message4="\n FIRST NAME:";
    QString message5="\n DESCRIPTION:";
        cout << message2<<CIN;
        cout <<message3<<NOM;
        cout <<message4<<PRENOM;
        cout << message5<<DESC;
        QFile file2("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");
       if (!file2.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file2.errorString());
       }
       QTextStream to (&file2);
      ui->textBrowser_3->setText(to.readAll());


}
}



//------------------------------------------------------------arabe------------------------------------------------------------------------------------------







void MainWindow::on_pushButton_13_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_15_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_14_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_16_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButtonAjouter_3_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int  CIN=ui->cin_3->text().toInt();

    QString ADRESSE=ui->ADRESSE_3->text();
     QString NOM=ui->NOM_3->text();
      QString PRENOM=ui->PRENOM_3->text();
      int GSM=ui->GSM_3->text().toInt();
       QString MAIL=ui->MAIL_3->text();
       QDate DATEN=ui->dateEdit_3->date();
       QString POSTE=ui->POSTE_3->text();
       QString SALAIRE=ui->SALAIRE_3->text();
       QString PRETS=ui->PRETS_3->text();
       QString EXP=ui->EXP_3->text();

    candidats C(CIN,ADRESSE,NOM,PRENOM,GSM,MAIL,DATEN,POSTE,SALAIRE,PRETS,EXP);
    if(CIN<=0||ADRESSE.isEmpty() || NOM.isEmpty() || PRENOM.isEmpty()|| GSM<=0 || MAIL.isEmpty() || POSTE.isEmpty()|| SALAIRE.isEmpty() || PRETS.isEmpty()|| EXP.isEmpty())
                         {
                             QMessageBox::critical(0,qApp->tr("Erreur"),qApp->tr("Le remplissage des champs vides est Obligatoire."),QMessageBox::Cancel);
                         }

    else
    {
bool test=C.ajouter();
QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
        if(!file3.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file3);
if(test)
{

    QString message2="تم إضافة مرشح\n";
        cout << message2;
        QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
       if (!file3.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file3.errorString());
       }
       QTextStream too (&file3);
      ui->textBrowser_6->setText(too.readAll());
    ui->tab_candidat_3->setModel(Etmp.afficher());//rafraishissement
    QMessageBox::information(nullptr, QObject::tr("Candidat ajouté"),
                QObject::tr("successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
else
    QMessageBox::critical(nullptr, QObject::tr("Candidat non ajouté"),
                QObject::tr("failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}ui->stackedWidget_5->setCurrentIndex(1);
}


void MainWindow::on_pushButton_10_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_5->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QSqlQuery query;

    int  CIN=ui->lineEdit_9->text().toInt();

    QString NOM=ui->lineEdit_10->text();
    QString PRENOM=ui->lineEdit_11->text();
   QString DESC=ui->lineEdit_12->text();
valider v(CIN,NOM,PRENOM,DESC);
bool test=v.ajouter();
QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");//declaration d'un fichier
        if(!file3.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file3);
if(test)
{

    QString message2="\n: بطاقة تعريف";
    QString message3="\n: الإسم";
    QString message4="\n: اللقب";
    QString message5="\n :وصف";
        cout << message2<<CIN;
        cout <<message3<<NOM;
        cout <<message4<<PRENOM;
        cout << message5<<DESC;
        QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Description.txt");
       if (!file3.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file3.errorString());
       }
       QTextStream too (&file3);
      ui->textBrowser_5->setText(too.readAll());


}
}

void MainWindow::on_pushButtonSupprimer_3_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int CIN = ui->tab_candidat_3->selectionModel()->currentIndex().data().toInt();
    bool test=Etmp.supprimer(CIN);
    QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file3.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file3);
    if(test)
    {

        QString message2="تم حذف مرشح\n";
            cout <<""<< message2;

            QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file3.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file3.errorString());
           }
           QTextStream in (&file3);
          ui->textBrowser_6->setText(in.readAll());
        ui->tab_candidat_3->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButtonModifier_3_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats c;

        int CIN = ui->tab_candidat_3->selectionModel()->currentIndex().data().toInt();
        int GSM=ui->gsmm_2->text().toInt();

        QString ADRESSE=ui->adressem_3->text();


        QString MAIL=ui->mailm_3->text();


        QString POSTE=ui->postem_3->text();

        candidats C;
    bool test=C.modifier(CIN, GSM, ADRESSE, MAIL, POSTE);


    QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");//declaration d'un fichier
            if(!file3.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file3);
    if(test)
    {

        QString message2="تم تعديل مرشح \n";
            cout << message2;


            QFile file3("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
           if (!file3.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file3.errorString());
           }
           QTextStream in (&file3);
          ui->textBrowser_6->setText(in.readAll());
        ui->tab_candidat_3->setModel(Etmp.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Candidat modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Candidat non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_pushButtonChercher_3_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString findText;
           QString text = ui->chercher_3->text();

       QTableView* table=ui->tab_candidat_3;
           if (text.isEmpty()) {
               QMessageBox::information(this, tr("Empty Field"),
                   tr("Entrez le nom a rechercher."));
               ui->tab_candidat_3->setModel(Etmp.afficher());
               return;
           } else {
               findText = text;
               Etmp.recherche(table,findText);
    }

}

void MainWindow::on_radioButton_croissant_3_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->tab_candidat_3->setModel(Etmp.tri());
}

void MainWindow::on_radioButton_dcroissant_3_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->tab_candidat_3->setModel(Etmp.trid());
}

void MainWindow::on_radioButton_12_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat_3->setModel(C.Filtrer1());
}

void MainWindow::on_radioButton_9_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat_3->setModel(C.Filtrer2());
}

void MainWindow::on_radioButton_10_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat_3->setModel(C.Filtrer3());
}

void MainWindow::on_radioButton_11_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    candidats C;



   ui->tab_candidat_3->setModel(C.Filtrer4());
}

void MainWindow::on_recrut_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
        ui->tab_candidat_2->setModel(Etmp.afficher());
        ui->tab_candidat->setModel(Etmp.afficher());
        ui->tab_candidat_3->setModel(Etmp.afficher());
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
          file.open(QIODevice::ReadOnly);
        QTextStream in (&file);
    ui->textBrowser_4->setText(in.readAll());
    ui->textBrowser_6->setText(in.readAll());
    ui->textBrowser->setText(in.readAll());
    ui->stackedWidget->setCurrentIndex(1);

}









//-------------------------------------------------------SPONSORS---------------------------------------------------------------------------------------



void MainWindow::on_ajoutersp_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
     QString nature=ui->typesp->currentText();/*currentSection() */
    QString nom_sp=ui->nomsp->text();

    Sponsors sp(0,nom_sp,nature);

    bool test=sp.ajouter();
    if(test)
    {


        ui->tablesp->setModel(sp.afficher());
        ui->spcombo1->setModel(sp.affichercombo());
        ui->spcombo2->setModel(sp.affichercombo());
        ui->spcombo1->setModel(sp.affichercombo());
        ui->ids->setModel(sp.affichercombo());
        ui->ids_2->setModel(sp.affichercombo());
        QDateTime q;
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                if(!file.open(QIODevice::Append))
        {
                    qCritical()<<"could not open file";
                    qCritical()<<file.errorString();
        }
                QTextStream stream(&file);
                       stream << q.currentDateTime().toString()+" un noveau sponsor est ajouter" << endl;
        file.close();
        QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                if(!file1.open(QIODevice::ReadOnly))
        {
                    qCritical()<<"could not open file";
                    qCritical()<<file1.errorString();

        }
                QTextStream stream1(&file1);
                ui->textBrowser_7->setText(stream1.readAll());

        file1.close();

        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery( "select SPONSORS_SEQ.nextval from dual ");
         QSqlQuery query(" ALTER SEQUENCE SPONSORS_SEQ INCREMENT BY -1");
        model->setQuery( "select SPONSORS_SEQ.nextval from dual ");
           ui->idsp->setText(QString :: number((model->data(model->index(0,0)).toInt())+1));
        QSqlQuery query1 (" ALTER SEQUENCE SPONSORS_SEQ INCREMENT BY 1");


        QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué\n"
                                                                        "click cancel to exit.")
                                                                            ,QMessageBox::Cancel);
    }
    else
    {
        QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("ajout non effectué\n""click cancel to exit."),QMessageBox::Cancel);
    }

}

void MainWindow::on_supprimersp_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
Sponsors sp;evenement e;soutien s;

    const QModelIndex &index=ui->tablesp->selectionModel()->currentIndex();
       if(index.column()<=2){ int id_sponsor  =( ui->tablesp->model()->data(ui->tablesp->model()->index(index.row(),0))).toInt();

            bool test=sp.supprimer(id_sponsor);
            if(test)
            {
                ui->tablesp->setModel(sp.afficher());
                ui->spcombo1->setModel(sp.affichercombo());
                ui->spcombo2->setModel(sp.affichercombo());
                ui->ids->setModel(sp.affichercombo());
                ui->ids_2->setModel(sp.affichercombo());
                   ui->spcombo1_2->setModel(sp.affichercombo());
                   ui->spcombo1_4->setModel(sp.affichercombo());
                   QDateTime q;
                   QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                           if(!file.open(QIODevice::Append))
                   {
                               qCritical()<<"could not open file";
                               qCritical()<<file.errorString();
                   }
                           QTextStream stream(&file);
                           QString id_string = QString :: number(id_sponsor);

                                  stream << q.currentDateTime().toString()+" sponsor avec id = "+id_string+" supprimer" << endl;
                   file.close();
                   QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                           if(!file1.open(QIODevice::ReadOnly))
                   {
                               qCritical()<<"could not open file";
                               qCritical()<<file1.errorString();

                   }
                           QTextStream stream1(&file1);
                           ui->textBrowser_7->setText(stream1.readAll());

                   file1.close();
                QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectué\n"
                                                                                "click cancel to exit.")
                                                                                    ,QMessageBox::Cancel);
            }
            else
            {
                QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("suppression non effectué\n""click cancel to exit."),QMessageBox::Cancel);
            }}
       if((index.column()<=7)&&(index.column()>2)){ int id_sponsor  =( ui->tablesp->model()->data(ui->tablesp->model()->index(index.row(),3))).toInt();

            bool test=s.supprimer(id_sponsor);
            if(test)
            {
                QDateTime q;
                QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                        if(!file.open(QIODevice::Append))
                {
                            qCritical()<<"could not open file";
                            qCritical()<<file.errorString();
                }
                        QTextStream stream(&file);
                        QString id_string = QString :: number(id_sponsor);

                               stream << q.currentDateTime().toString()+" le soutien numero "+id_string+" est supprimer"<< endl;
                file.close();
                QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                        if(!file1.open(QIODevice::ReadOnly))
                {
                            qCritical()<<"could not open file";
                            qCritical()<<file1.errorString();

                }
                        QTextStream stream1(&file1);
                        ui->textBrowser_7->setText(stream1.readAll());

                file1.close();
                ui->tablesp->setModel(sp.afficher());
                QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectué\n"
                                                                                "click cancel to exit.")
                                                                                    ,QMessageBox::Cancel);
            }
            else
            {
                QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("suppression non effectué\n""click cancel to exit."),QMessageBox::Cancel);
            }}
       if((index.column()<=14)&&(index.column()>7)){ int id_sponsor  =( ui->tablesp->model()->data(ui->tablesp->model()->index(index.row(),8))).toInt();

            bool test=e.supprimer(id_sponsor);
            if(test)
            {

                QDateTime q;
                QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                        if(!file.open(QIODevice::Append))
                {
                            qCritical()<<"could not open file";
                            qCritical()<<file.errorString();
                }
                        QTextStream stream(&file);
                        QString id_string = QString :: number(id_sponsor);

                               stream << q.currentDateTime().toString()+" l'evenement numero "+id_string+" est supprimer"<< endl;
                file.close();
                QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                        if(!file1.open(QIODevice::ReadOnly))
                {
                            qCritical()<<"could not open file";
                            qCritical()<<file1.errorString();

                }
                        QTextStream stream1(&file1);
                        ui->textBrowser_7->setText(stream1.readAll());

                file1.close();
                ui->tablesp->setModel(sp.afficher());

                QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectué\n"
                                                                                "click cancel to exit.")
                                                                                    ,QMessageBox::Cancel);
            }
            else
            {
                QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("suppression non effectué\n""click cancel to exit."),QMessageBox::Cancel);
            }}
}

void MainWindow::on_ouvrireajouter_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
  ui->tabWidget->setCurrentWidget(ui->tab_15);
}

void MainWindow::on_afficheraceuille_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
      ui->tabWidget->setCurrentWidget(ui->tab_14);
}

void MainWindow::on_pushButton_6_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
         ui->tabWidget->setCurrentWidget(ui->tab_16);
}

void MainWindow::on_actualitesaccuille_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
         ui->tabWidget->setCurrentWidget(ui->tab_17);
}

void MainWindow::on_statistiquesaceuille_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
         ui->tabWidget->setCurrentWidget(ui->tab_18);
}

void MainWindow::on_ajouteraceuille_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
         ui->tabWidget->setCurrentWidget(ui->tab_15);
}

void MainWindow::on_tablesp_clicked(const QModelIndex &index)
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if((index.column()==2)){ui->modifs->hide();ui->mod->show();ui->modifsp->hide();ui->modife->hide();ui->modifdate->hide();ui->modifid->hide();}
    else if((index.column()==4)) {ui->modifs->show();ui->mod->hide();ui->modifsp->hide();ui->modife->hide();ui->modifdate->hide();ui->modifid->hide();}
    else if((index.column()==10)) {ui->modifs->hide();ui->mod->hide();ui->modifsp->hide();ui->modife->show();ui->modifdate->hide();ui->modifid->hide();}
    else if((index.column()==14||(index.column()==7))) {ui->modifs->hide();ui->mod->hide();ui->modifsp->hide();ui->modife->hide();ui->modifdate->hide();ui->modifid->show();ui->modifid->setModel(sp.affichercombo());}
    else if((index.column()==6)||(index.column()==11)) {ui->modifs->hide();ui->mod->hide();ui->modifsp->hide();ui->modife->hide();ui->modifdate->show();ui->modifid->hide();ui->modifdate->setDate(ui->tablesp->selectionModel()->currentIndex().data().toDate());}
    else if((index.column()==0)||(index.column()==3)||(index.column()==8)){ui->modife->hide();ui->mod->hide();ui->modifs->hide();ui->modifsp->hide();ui->modifdate->hide();ui->modifid->hide();}
    else  {ui->modife->hide();ui->mod->hide();ui->modifs->hide();ui->modifsp->show();ui->modifdate->hide();ui->modifid->hide();ui->modifsp->setText(ui->tablesp->selectionModel()->currentIndex().data().toString());}

}
void MainWindow::on_modifiersp_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    const QModelIndex &index=ui->tablesp->selectionModel()->currentIndex();
    bool test=NULL;
    int ido= ui->tablesp->model()->data(ui->tablesp->model()->index(index.row(),0)).toInt();
    int ido1= ui->tablesp->model()->data(ui->tablesp->model()->index(index.row(),3)).toInt();
    int ido2= ui->tablesp->model()->data(ui->tablesp->model()->index(index.row(),8)).toInt();
    QString IDO=QString :: number(ido);
    QString IDO1=QString :: number(ido1);
    QString IDO2=QString :: number(ido2);
    QString curent;
    QDate curent1;
    QSqlQuery query;
soutien s;Sponsors sp;evenement e;
   /* if(index.column()==0){curent=ui->modifsp->text();test=sp.modifierid(curent,IDO);}*/
if(index.column()==1){
        curent=ui->modifsp->text();test=sp.modifiernom(curent,IDO);}
    else if(index.column()==2){
       curent=ui->mod->currentText(); test=sp.modifiertype(curent,IDO);}
   /* else if(index.column()==3){
curent=ui->modifsp->text(); test=s.modifiernum_sou(curent,IDO1);}*/
    else if(index.column()==4){
curent=ui->modifs->currentText(); test=s.modifiertype_sou(curent,IDO1);}
    else if(index.column()==5){
curent=ui->modifsp->text(); test=s.modifierquantite_sou(curent,IDO1);}
    else if(index.column()==6){
curent1=ui->modifdate->date(); test=s.modifierdate_sou(curent1,IDO1);}
    else if(index.column()==7){
curent=ui->modifid->currentText(); test=s.modifieridsp(curent,IDO1);}
    /*else if(index.column()==8){
curent=ui->modifsp->text(); test=e.modifiernum_eve(curent,IDO2);}*/
    else if(index.column()==9){
curent=ui->modifsp->text(); test=e.modifiernom_eve(curent,IDO2);}
    else if(index.column()==10){
curent=ui->modife->currentText(); test=e.modifiertype_eve(curent,IDO2);}
    else if(index.column()==11){
curent1=ui->modifdate->date(); test=e.modifierdate_eve(curent1,IDO2);}
    else if(index.column()==12){
curent=ui->modifsp->text(); test=e.modifiermontant_payee(curent,IDO2);}
    else if(index.column()==13){
curent=ui->modifsp->text(); test=e.modifiermontant_gagnee(curent,IDO2);}
    else if(index.column()==14){
curent=ui->modifid->currentText(); test=e.modifieridsp(curent,IDO2);}
if(test)
{
    if((index.column()==1)||(index.column()==2)){QDateTime q;
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                if(!file.open(QIODevice::Append))
        {
                    qCritical()<<"could not open file";
                    qCritical()<<file.errorString();
        }
                QTextStream stream(&file);


                       stream << q.currentDateTime().toString()+" le sponsor avec id = "+IDO+" est modiffier"<< endl;
        file.close();
        QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                if(!file1.open(QIODevice::ReadOnly))
        {
                    qCritical()<<"could not open file";
                    qCritical()<<file1.errorString();

        }
                QTextStream stream1(&file1);
                ui->textBrowser_7->setText(stream1.readAll());

        file1.close();}
    if((index.column()==4)||(index.column()==5)||(index.column()==6)||(index.column()==7)){QDateTime q;
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                if(!file.open(QIODevice::Append))
        {
                    qCritical()<<"could not open file";
                    qCritical()<<file.errorString();
        }
                QTextStream stream(&file);


                       stream << q.currentDateTime().toString()+" le soutien numero "+IDO1+" est moddifier"<< endl;
        file.close();
        QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                if(!file1.open(QIODevice::ReadOnly))
        {
                    qCritical()<<"could not open file";
                    qCritical()<<file1.errorString();

        }
                QTextStream stream1(&file1);
                ui->textBrowser_7->setText(stream1.readAll());

        file1.close();}
    if((index.column()==9)||(index.column()==10)||(index.column()==11)||(index.column()==12)||(index.column()==13)||(index.column()==14)){QDateTime q;
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                if(!file.open(QIODevice::Append))
        {
                    qCritical()<<"could not open file";
                    qCritical()<<file.errorString();
        }
                QTextStream stream(&file);


                       stream << q.currentDateTime().toString()+" le soutien numero "+IDO2+" est moddifier"<< endl;
        file.close();
        QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                if(!file1.open(QIODevice::ReadOnly))
        {
                    qCritical()<<"could not open file";
                    qCritical()<<file1.errorString();

        }
                QTextStream stream1(&file1);
                ui->textBrowser_7->setText(stream1.readAll());

        file1.close();}
    ui->tablesp->setModel(sp.afficher());



    QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("modification effectué\n"
                                                                    "click cancel to exit.")
                                                                        ,QMessageBox::Cancel);
}
else
{
    QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("modification non effectué\n""click cancel to exit."),QMessageBox::Cancel);
}

}


void MainWindow::on_ajouters_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    Sponsors sp;
    int idsp=ui->spcombo1->currentText().toInt();;/*currentSection() */
   QString types=ui->types->currentText();
   int quantites=ui->quantites->text().toInt();
    QDate dates=ui->dates->date();
   soutien s(idsp,0,types,quantites,dates);

   bool test=s.ajouter();
   if(test)
   {

       QDateTime q;
       QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
               if(!file.open(QIODevice::Append))
       {
                   qCritical()<<"could not open file";
                   qCritical()<<file.errorString();
       }
               QTextStream stream(&file);
                      stream << q.currentDateTime().toString()+" un noveau soutien est ajouter" << endl;
       file.close();QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
       if(!file1.open(QIODevice::ReadOnly))
{
           qCritical()<<"could not open file";
           qCritical()<<file1.errorString();

}
       QTextStream stream1(&file1);
       ui->textBrowser_7->setText(stream1.readAll());

file1.close();
       ui->tablesp->setModel(sp.afficher());
       QSqlQueryModel* model=new QSqlQueryModel();
       model->setQuery( "select SOUTIEN_SEQ.nextval from dual ");
       QSqlQuery query2(" ALTER SEQUENCE SOUTIEN_SEQ INCREMENT BY -1");
       model->setQuery( "select SOUTIEN_SEQ.nextval from dual ");
          ui->idsp_2->setText(QString :: number((model->data(model->index(0,0)).toInt())+1));
        QSqlQuery query3 (" ALTER SEQUENCE SOUTIEN_SEQ INCREMENT BY 1");


       QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué\n"
                                                                       "click cancel to exit.")
                                                                           ,QMessageBox::Cancel);
   }
   else
   {
       QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("ajout non effectué\n""click cancel to exit."),QMessageBox::Cancel);
   }
}

void MainWindow::on_ajoutere_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    Sponsors sp;
   int idsp=ui->spcombo2->currentText().toInt();

   QString typee=ui->typeeve->currentText();
   QString nome=ui->nomeve->text();
    QDate datee=ui->dateeve->date();
    QString mg=ui->mg->text();
    QString mp=ui->mp->text();
   evenement e(idsp,0,nome,typee,datee,mg,mp);

   bool test=e.ajouter();
   if(test)
   {

       QDateTime q;
       QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
               if(!file.open(QIODevice::Append))
       {
                   qCritical()<<"could not open file";
                   qCritical()<<file.errorString();
       }
               QTextStream stream(&file);
                      stream << q.currentDateTime().toString()+" un noveau evenement est ajouter" << endl;
       file.close();QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
       if(!file1.open(QIODevice::ReadOnly))
{
           qCritical()<<"could not open file";
           qCritical()<<file1.errorString();

}
       QTextStream stream1(&file1);
       ui->textBrowser_7->setText(stream1.readAll());

file1.close();
       ui->tablesp->setModel(sp.afficher());
       QSqlQueryModel* model2=new QSqlQueryModel();
       model2->setQuery( "select EVENEMENT_SEQ.nextval from dual ");
       QSqlQuery query4(" ALTER SEQUENCE EVENEMENT_SEQ INCREMENT BY -1");
       model2->setQuery( "select EVENEMENT_SEQ.nextval from dual ");
          ui->idsp_3->setText(QString :: number((model2->data(model2->index(0,0)).toInt())+1));
       QSqlQuery query5 (" ALTER SEQUENCE EVENEMENT_SEQ INCREMENT BY 1");

       QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué\n"
                                                                       "click cancel to exit.")
                                                                           ,QMessageBox::Cancel);
   }
   else
   {
       QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("ajout non effectué\n""click cancel to exit."),QMessageBox::Cancel);
   }

}



void MainWindow::on_cherchersp_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QSqlQueryModel* model=new QSqlQueryModel();
    Sponsors sp; QVariant curent=ui->recherchetext->text();

    model=sp.cherchesp(curent);
    ui->tablesp->setModel(model);



}

void MainWindow::on_triersp_activated(const QString &arg1)
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    Sponsors sp;
            ui->tablesp->setModel(sp.trier(arg1));


}



void MainWindow::on_spcombo1_2_currentTextChanged(const QString &arg1)



{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    Q3DBars *widgetgraph = new Q3DBars();

    ui->container = QWidget::createWindowContainer(widgetgraph,ui->container,Qt::SubWindow);
    QSize screenSize = widgetgraph->screen()->size();
    ui->container->setMinimumSize(QSize(500, 700));
    ui->container->setMaximumSize(screenSize);
    ui->container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->container->setFocusPolicy(Qt::StrongFocus);
    ui->barStyleList->addItem(QStringLiteral("Bar"), int(QAbstract3DSeries::MeshBar));
    ui->barStyleList->addItem(QStringLiteral("Pyramid"), int(QAbstract3DSeries::MeshPyramid));
    ui->barStyleList->addItem(QStringLiteral("Cone"), int(QAbstract3DSeries::MeshCone));
    ui->barStyleList->addItem(QStringLiteral("Cylinder"), int(QAbstract3DSeries::MeshCylinder));
    ui->barStyleList->addItem(QStringLiteral("Bevel bar"), int(QAbstract3DSeries::MeshBevelBar));
    ui->barStyleList->addItem(QStringLiteral("Sphere"), int(QAbstract3DSeries::MeshSphere));
    ui->barStyleList->setCurrentIndex(4);
    ui->selectionModeList->addItem(QStringLiteral("None"), int(QAbstract3DGraph::SelectionNone));
    ui->selectionModeList->addItem(QStringLiteral("Bar"),int(QAbstract3DGraph::SelectionItem));
    ui->selectionModeList->addItem(QStringLiteral("Row"),int(QAbstract3DGraph::SelectionRow));
    ui->selectionModeList->addItem(QStringLiteral("Bar and Row"), int(QAbstract3DGraph::SelectionItemAndRow));
    ui->selectionModeList->addItem(QStringLiteral("Column"),int(QAbstract3DGraph::SelectionColumn));
    ui->selectionModeList->addItem(QStringLiteral("Bar and Column"),int(QAbstract3DGraph::SelectionItemAndColumn));
    ui->selectionModeList->addItem(QStringLiteral("Row and Column"),int(QAbstract3DGraph::SelectionRowAndColumn));
    ui->selectionModeList->addItem(QStringLiteral("Bar, Row and Column"),int(QAbstract3DGraph::SelectionItemRowAndColumn));
    ui->selectionModeList->addItem(QStringLiteral("Slice into Row"),int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionRow));
    ui->selectionModeList->addItem(QStringLiteral("Slice into Row and Item"),int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndRow));
    ui->selectionModeList->addItem(QStringLiteral("Slice into Column"),int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionColumn));
    ui->selectionModeList->addItem(QStringLiteral("Slice into Column and Item"),int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndColumn));
    ui->selectionModeList->addItem(QStringLiteral("Multi: Bar, Row, Col"),int(QAbstract3DGraph::SelectionItemRowAndColumn | QAbstract3DGraph::SelectionMultiSeries));
    ui->selectionModeList->addItem(QStringLiteral("Multi, Slice: Row, Item"),int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndRow | QAbstract3DGraph::SelectionMultiSeries));
    ui->selectionModeList->addItem(QStringLiteral("Multi, Slice: Col, Item"),int(QAbstract3DGraph::SelectionSlice | QAbstract3DGraph::SelectionItemAndColumn| QAbstract3DGraph::SelectionMultiSeries));
    ui->selectionModeList->setCurrentIndex(1);
    ui->rotationSliderX->setTickInterval(30);
    ui->rotationSliderX->setTickPosition(QSlider::TicksBelow);
    ui->rotationSliderX->setMinimum(-180);
    ui->rotationSliderX->setValue(0);
    ui->rotationSliderX->setMaximum(180);
    ui->rotationSliderY->setTickInterval(15);
    ui->rotationSliderY->setTickPosition(QSlider::TicksAbove);
    ui->rotationSliderY->setMinimum(-90);
    ui->rotationSliderY->setValue(0);
    ui->rotationSliderY->setMaximum(90);
    ui->fontSizeSlider->setTickInterval(10);
    ui->fontSizeSlider->setTickPosition(QSlider::TicksBelow);
    ui->fontSizeSlider->setMinimum(1);
    ui->fontSizeSlider->setValue(30);
    ui->fontSizeSlider->setMaximum(100);
    ui->axisLabelRotationSlider->setTickInterval(10);
    ui->axisLabelRotationSlider->setTickPosition(QSlider::TicksBelow);
    ui->axisLabelRotationSlider->setMinimum(0);
    ui->axisLabelRotationSlider->setValue(30);
    ui->axisLabelRotationSlider->setMaximum(90);
    QString curent=ui->spcombo1_4->currentText();

    for (int ra=ui->rangeList->count();ra>=0;ra--){ui->rangeList->removeItem(ra);}
    QSqlQueryModel* model55=new QSqlQueryModel();QSqlQuery query55;
   query55.prepare("SELECT * FROM EVENEMENT where ID= :curent");
   query55.bindValue(":curent", arg1);
   query55.exec();
   model55->setQuery(query55);
for (int stat=0;stat<=model55->rowCount();stat++)
          {int occ=0;
      QString date = model55->data(model55->index(stat,3)).toString();
      QString year55=date.mid(0,4);
for(int z=0;z<=ui->rangeList->count();z++){if (ui->rangeList->itemText(z)==year55){occ=occ+1;}}
      if(occ==0){
ui->rangeList->addItem(year55);}

  }


    ui->rangeList->addItem("all");

    GraphModifier *modifier = new GraphModifier(widgetgraph,arg1,curent);

    QObject::connect(ui->rotationSliderX, &QSlider::valueChanged, modifier, &GraphModifier::rotateX);
    QObject::connect(ui->rotationSliderY, &QSlider::valueChanged, modifier, &GraphModifier::rotateY);
    QObject::connect(ui->labelButton, &QPushButton::clicked, modifier,&GraphModifier::changeLabelBackground);
    QObject::connect(ui->cameraButton, &QPushButton::clicked, modifier,&GraphModifier::changePresetCamera);
    QObject::connect(ui->zoomToSelectedButton, &QPushButton::clicked, modifier,&GraphModifier::zoomToSelectedBar);
    QObject::connect(ui->backgroundCheckBox, &QCheckBox::stateChanged, modifier,&GraphModifier::setBackgroundEnabled);
    QObject::connect(ui->gridCheckBox, &QCheckBox::stateChanged, modifier,&GraphModifier::setGridEnabled);
    QObject::connect(ui->smoothCheckBox, &QCheckBox::stateChanged, modifier,&GraphModifier::setSmoothBars);
     if(ui->spcombo1_5->currentText()=="afficher"){
    QObject::connect(ui->seriesCheckBox, &QCheckBox::stateChanged, modifier,&GraphModifier::setSeriesVisibility);
     }
if(ui->spcombo1_5->currentText()=="comparer"){
    QObject::connect(ui->seriesCheckBox, &QCheckBox::stateChanged, modifier,&GraphModifier::setSeries3Visibility);
}


    QObject::connect(ui->spcombo1_5,SIGNAL(currentIndexChanged(int)), modifier,SLOT(affiche2(int)));
    QObject::connect(ui->reverseValueAxisCheckBox, &QCheckBox::stateChanged, modifier,&GraphModifier::setReverseValueAxis);
    QObject::connect(ui->reflectionCheckBox, &QCheckBox::stateChanged, modifier,&GraphModifier::setReflection);
    QObject::connect(modifier, &GraphModifier::backgroundEnabledChanged,ui->backgroundCheckBox, &QCheckBox::setChecked);
    QObject::connect(modifier, &GraphModifier::gridEnabledChanged,ui->gridCheckBox, &QCheckBox::setChecked);
    QObject::connect(ui->rangeList, SIGNAL(currentIndexChanged(int)), modifier,SLOT(changeRange(int)));
    QObject::connect(ui->barStyleList, SIGNAL(currentIndexChanged(int)), modifier,SLOT(changeStyle(int)));
    QObject::connect(ui->selectionModeList, SIGNAL(currentIndexChanged(int)), modifier,SLOT(changeSelectionMode(int)));
    QObject::connect(ui->themeList, SIGNAL(currentIndexChanged(int)), modifier,SLOT(changeTheme(int)));
    QObject::connect(ui->shadowQuality, SIGNAL(currentIndexChanged(int)), modifier,SLOT(changeShadowQuality(int)));
    QObject::connect(modifier, &GraphModifier::shadowQualityChanged, ui->shadowQuality,&QComboBox::setCurrentIndex);
    QObject::connect(widgetgraph, &Q3DBars::shadowQualityChanged, modifier,&GraphModifier::shadowQualityUpdatedByVisual);
    QObject::connect(ui->fontSizeSlider, &QSlider::valueChanged, modifier,&GraphModifier::changeFontSize);
    QObject::connect(ui->fontList, &QFontComboBox::currentFontChanged, modifier,&GraphModifier::changeFont);
    QObject::connect(modifier, &GraphModifier::fontSizeChanged, ui->fontSizeSlider,&QSlider::setValue);
    QObject::connect(modifier, &GraphModifier::fontChanged, ui->fontList,&QFontComboBox::setCurrentFont);
    QObject::connect(ui->axisTitlesVisibleCB, &QCheckBox::stateChanged, modifier, &GraphModifier::setAxisTitleVisibility);
    QObject::connect(ui->axisTitlesFixedCB, &QCheckBox::stateChanged, modifier,&GraphModifier::setAxisTitleFixed);
    QObject::connect(ui->axisLabelRotationSlider, &QSlider::valueChanged, modifier,&GraphModifier::changeLabelRotation);

ui->container->show();

}


void MainWindow::on_chercherc_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QSqlQueryModel* model=new QSqlQueryModel();
    contact c; QVariant curent=ui->recherchetextc->text();

    model=c.cherchesp(curent);
    ui->affc->setModel(model);

}

void MainWindow::on_ajouterc_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString nom=ui->nomc->text();/*currentSection() */
   QString prenom=ui->prenomc->text();
   int id= ui->ids->currentText().toInt();
   QString poste =ui->postec->currentText();
   int gsm= ui->gsmc->text().toInt();
   int fixe= ui->fixec->text().toInt();
   QString mail= ui->mailc->text();
contact c(nom,prenom,id,poste,gsm,fixe,mail);
   bool test=c.ajouter();
   if(test)
   {

       QDateTime q;
       QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
               if(!file.open(QIODevice::Append))
       {
                   qCritical()<<"could not open file";
                   qCritical()<<file.errorString();
       }
               QTextStream stream(&file);
                      stream << q.currentDateTime().toString()+" un noveau contact est ajouter" << endl;
       file.close();QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
       if(!file1.open(QIODevice::ReadOnly))
{
           qCritical()<<"could not open file";
           qCritical()<<file1.errorString();

}
       QTextStream stream1(&file1);
       ui->textBrowser_7->setText(stream1.readAll());

file1.close();
            ui->affc->setModel(c.afficher());
       QSqlQueryModel* model3=new QSqlQueryModel();
       model3->setQuery( "select CONTACT_SEQ.nextval from dual ");
        QSqlQuery query(" ALTER SEQUENCE CONTACT_SEQ INCREMENT BY -1");
       model3->setQuery( "select CONTACT_SEQ.nextval from dual ");
          ui->numcontact->setText(QString :: number((model3->data(model3->index(0,0)).toInt())+1));
       QSqlQuery query1 (" ALTER SEQUENCE CONTACT_SEQ INCREMENT BY 1");


       QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué\n"
                                                                       "click cancel to exit.")
                                                                           ,QMessageBox::Cancel);
   }
   else
   {
       QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("ajout non effectué\n""click cancel to exit."),QMessageBox::Cancel);
   }

}

void MainWindow::on_modifierc_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    const QModelIndex &index=ui->affc->selectionModel()->currentIndex();
    bool test=NULL;
    int ido= ui->affc->model()->data(ui->affc->model()->index(index.row(),0)).toInt();

    QString IDO=QString :: number(ido);

    QString curent;
    QSqlQuery query;
contact c;
   /* if(index.column()==0){curent=ui->modifc->text();test=sp.modifierid(curent,IDO);}*/
if(index.column()==1){
        curent=ui->modifc->text();test=c.modifiernom(curent,IDO);}
    else if(index.column()==2){
       curent=ui->modifc->text(); test=c.modifierprenom(curent,IDO);}
else if(index.column()==3){
curent=ui->ids_2->currentText(); test=c.modifierid(curent,IDO);}
    else if(index.column()==4){
curent=ui->postec_2->currentText(); test=c.modifierposte(curent,IDO);}
    else if(index.column()==5){
curent=ui->modifc->text(); test=c.modifiergsm(curent,IDO);}
    else if(index.column()==6){
curent=ui->modifc->text(); test=c.modifierfixe(curent,IDO);}
    else if(index.column()==7){
curent=ui->modifc->text(); test=c.modifiermail(curent,IDO);}
if(test)
{
       ui->affc->setModel(c.afficher());


       QDateTime q;
               QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                       if(!file.open(QIODevice::Append))
               {
                           qCritical()<<"could not open file";
                           qCritical()<<file.errorString();
               }
                       QTextStream stream(&file);


                              stream << q.currentDateTime().toString()+" le contact avec numero = "+IDO+" est modiffier"<< endl;
               file.close();QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
               if(!file1.open(QIODevice::ReadOnly))
       {
                   qCritical()<<"could not open file";
                   qCritical()<<file1.errorString();

       }
               QTextStream stream1(&file1);
               ui->textBrowser_7->setText(stream1.readAll());

       file1.close();
    QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("modification effectué\n"
                                                                    "click cancel to exit.")
                                                                        ,QMessageBox::Cancel);
}
else
{
    QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("modification non effectué\n""click cancel to exit."),QMessageBox::Cancel);
}

}

void MainWindow::on_supprimerc_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    contact c;

        const QModelIndex &index=ui->affc->selectionModel()->currentIndex();
int num  =( ui->affc->model()->data(ui->affc->model()->index(index.row(),0))).toInt();

                bool test=c.supprimer(num);
                if(test)
                {
                    QDateTime q;
                    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                            if(!file.open(QIODevice::Append))
                    {
                                qCritical()<<"could not open file";
                                qCritical()<<file.errorString();
                    }
                            QTextStream stream(&file);
                            QString id_string = QString :: number(num);

                                   stream << q.currentDateTime().toString()+" contact avec id = "+id_string+" supprimer" << endl;
                    file.close();QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                    if(!file1.open(QIODevice::ReadOnly))
            {
                        qCritical()<<"could not open file";
                        qCritical()<<file1.errorString();

            }
                    QTextStream stream1(&file1);
                    ui->textBrowser_7->setText(stream1.readAll());

            file1.close();
                    ui->affc->setModel(c.afficher());
                    QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectué\n"
                                                                                    "click cancel to exit.")
                                                                                        ,QMessageBox::Cancel);
                }
                else
                {
                    QMessageBox:: critical(nullptr,QObject::tr("Not ok"),QObject::tr("suppression non effectué\n""click cancel to exit."),QMessageBox::Cancel);
                }
}

void MainWindow::on_trierc_currentTextChanged(const QString &arg1)
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    contact c;
            ui->affc->setModel(c.trier(arg1));
}

void MainWindow::on_affc_clicked(const QModelIndex &index)
{
    if((index.column()==1)||(index.column()==2)||(index.column()==5)||(index.column()==6)||(index.column()==7)){ui->modifc->setText(ui->affc->model()->data(index).toString());ui->modifc->show();ui->ids_2->hide();ui->postec_2->hide();}
    else if((index.column()==3)) {ui->modifc->hide();ui->ids_2->show();ui->postec_2->hide();}
    else if((index.column()==4)) {ui->modifc->hide();ui->ids_2->hide();ui->postec_2->show();}

}


void MainWindow::on_tradu_currentTextChanged(const QString &arg1)
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if(arg1=="Français"){ui->afficheraceuille->setText("afficher");ui->ajouteraceuille->setText("ajouter");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("actualite");ui->statistiquesaceuille->setText("statistique");ui->pushButton_3->setText("retourner");
    ui->label_63->setText("trier par");ui->ouvrireajouter->setText("ajouter");ui->supprimersp->setText("supprimer");ui->modifiersp->setText("modifier");ui->cherchersp->setText("chercher");
    ui->label_64->setText("sponsors");ui->label_66->setText("identifiant");ui->label_67->setText("nom");ui->label_68->setText("type de sponsor");ui->label_65->setText("soutiens");ui->label_69->setText("identifiant sponsors");ui->label_70->setText("numero de soutiens");ui->label_71->setText("type soutien");ui->label_72->setText("quantite de soutien");ui->label_73->setText("date de soutien");ui->ajouters->setText("ajouter soutien");ui->ajoutersp->setText("ajouter sponsor");ui->label_74->setText("evenement");ui->label_76->setText("identifiant sponsor");ui->label_75->setText("numer evenement");ui->label_77->setText("type evenement");ui->label_78->setText("nom evenement");ui->label_79->setText("date evenement");ui->label_80->setText("montant gagnee");ui->label_81->setText("montant payee");ui->ajoutere->setText("ajouter evenement");
    ui->label_82->setText("trier par");ui->label_83->setText("numero contact");ui->label_84->setText("nom");ui->label_85->setText("prenom");ui->label_86->setText("identifiant sponsor");ui->label_87->setText("poste");ui->label_88->setText("gsm");ui->label_89->setText("fixe");ui->label_90->setText("mail");ui->ajouterc->setText("ajouter");ui->supprimerc->setText("supprimer");ui->modifierc->setText("modifier");ui->chercherc->setText("chercher");
    ui->suprimmerc->setText("supprimer");
    ui->label_98->setText("rotation horizontale");ui->label_99->setText("rotation verticale");ui->labelButton->setText("changer label syle");ui->cameraButton->setText("changer camera set");ui->zoomToSelectedButton->setText("zoom de bare de selection");ui->backgroundCheckBox->setText("afficher background");ui->gridCheckBox->setText("afficher grille");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("afficher reflection");ui->seriesCheckBox->setText("afficher montant payee");ui->reverseValueAxisCheckBox->setText("inverser les axces");ui->axisTitlesVisibleCB->setText("axe titre visible");ui->axisTitlesFixedCB->setText("axe titre fixe");ui->label_100->setText("afficher ans");ui->label_97->setText("changer la style de bar");ui->label_96->setText("changer mode de selection");ui->label_95->setText("changer theme");ui->label_94->setText("ajuster l'ombre ");ui->label_93->setText("changer le font");ui->label_92->setText("ajuster la taille de font");ui->label_91->setText("axe label rotation");}
    if(arg1=="العربية"){ui->afficheraceuille->setText("الاضهار");ui->ajouteraceuille->setText("اضافة");ui->pushButton_6->setText("العلاقات");ui->actualitesaccuille->setText("الحدث");ui->statistiquesaceuille->setText("احصاء");ui->pushButton_3->setText("العودة");
        ui->label_63->setText("الترتيب حسب");ui->ouvrireajouter->setText("يضيف");ui->supprimersp->setText("لحذف");ui->modifiersp->setText("للتعديل");ui->cherchersp->setText("للبحث");
        ui->label_64->setText("الرعاة");ui->label_66->setText("المعرف");ui->label_67->setText("الاسم");ui->label_68->setText("نوع الراعي");ui->label_65->setText("دعم");ui->label_69->setText("معرف الراعي");ui->label_70->setText("عدد الدعم");ui->label_71->setText("نوع الدعم");ui->label_72->setText("كمية الدعم");ui->label_73->setText("تاريخ الدعم");ui->ajouters->setText("اضافة الدعم");ui->ajoutersp->setText("اضافة راعي");ui->label_74->setText("حدث");ui->label_76->setText("معرف الراعي");ui->label_75->setText("رقم الحدث");ui->label_77->setText("نوع الحدث");ui->label_78->setText("اسم الحدث");ui->label_79->setText("تاريخ الحدث");ui->label_80->setText("المبلغ المكتسب");ui->label_81->setText("المبلغ المدفوع");ui->ajoutere->setText("إضافة حدث");
        ui->label_82->setText("الترتيب حسب");ui->label_83->setText("رقم الاتصال");ui->label_84->setText("اسم");ui->label_85->setText("اللقب");ui->label_86->setText("معرف الراعي");ui->label_87->setText("مهنة");ui->label_88->setText("الجوال");ui->label_89->setText("القار");ui->label_90->setText("البريد");ui->ajouterc->setText("اضافة");ui->supprimerc->setText("حذف");ui->modifierc->setText("تعديل");ui->chercherc->setText("بحث");
        ui->suprimmerc->setText("حذف");
        ui->label_98->setText("دوران أفقي");ui->label_99->setText("الدوران العمودي");ui->labelButton->setText("تغيير نمط التسمية");ui->cameraButton->setText("تغيير زاوية الكاميرا");ui->zoomToSelectedButton->setText("تكبير شريط التحديد");ui->backgroundCheckBox->setText("عرض الخلفية");ui->gridCheckBox->setText("اظهر الخطوط");ui->smoothCheckBox->setText("شريط سلس");ui->reflectionCheckBox->setText("تظهر انعكاس");ui->seriesCheckBox->setText("عرض المبلغ المدفوع");ui->reverseValueAxisCheckBox->setText("عكس المحاور");ui->axisTitlesVisibleCB->setText("محور العنوان المرئي");ui->axisTitlesFixedCB->setText("محور عنوان ثابت");ui->label_100->setText("عرض سنوات");ui->label_97->setText("تغيير نمط الشريط");ui->label_96->setText("تغيير وضع الاختيار");ui->label_95->setText("غير الخلفية");ui->label_94->setText("ضبط الظل");ui->label_93->setText("تفعل التغيير");ui->label_92->setText("ضبط حجم الخط");ui->label_91->setText("دوران تسمية المحور");}
    if(arg1=="English"){ui->afficheraceuille->setText("show");ui->ajouteraceuille->setText("add");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("news");ui->statistiquesaceuille->setText("statistics");ui->pushButton_3->setText("return");
        ui->label_63->setText("sort by");ui->ouvrireajouter->setText("add");ui->supprimersp->setText("delete");ui->modifiersp->setText("modify");ui->cherchersp->setText("search");
        ui->label_64->setText("sponsors");ui->label_66->setText("identifiant");ui->label_67->setText("name");ui->label_68->setText("type of sponsor");ui->label_65->setText("soutiens");ui->label_69->setText("sponsors id");ui->label_70->setText("number of supports");ui->label_71->setText("support type");ui->label_72->setText("support quantity");ui->label_73->setText("support date");ui->ajouters->setText("support add");ui->ajoutersp->setText("add sponsor");ui->label_74->setText("event");ui->label_76->setText("sponsor id");ui->label_75->setText("event number");ui->label_77->setText("event type");ui->label_78->setText("event name");ui->label_79->setText("event date");ui->label_80->setText("amount earned");ui->label_81->setText("amount paid");ui->ajoutere->setText("add event");
        ui->label_82->setText("sort by");ui->label_83->setText("contact number");ui->label_84->setText("name");ui->label_85->setText("first name");ui->label_86->setText("sponsors id");ui->label_87->setText("job");ui->label_88->setText("gsm");ui->label_89->setText("fixe");ui->label_90->setText("mail");ui->ajouterc->setText("add");ui->supprimerc->setText("delete");ui->modifierc->setText("modify");ui->chercherc->setText("reaserch");
        ui->suprimmerc->setText("delete");
        ui->label_98->setText("horizontal rotation");ui->label_99->setText("vertical rotation");ui->labelButton->setText("change label style");ui->cameraButton->setText("change camera set");ui->zoomToSelectedButton->setText("zoom to bare  selection");ui->backgroundCheckBox->setText("show background");ui->gridCheckBox->setText("show grill");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("show reflection");ui->seriesCheckBox->setText("show amount paid");ui->reverseValueAxisCheckBox->setText("inverse axces");ui->axisTitlesVisibleCB->setText("axe title visible");ui->axisTitlesFixedCB->setText("axe title fix");ui->label_100->setText("show years");ui->label_97->setText("change bar style ");ui->label_96->setText("change selection mode");ui->label_95->setText("change theme");ui->label_94->setText("adjust shadow ");ui->label_93->setText("change font");ui->label_92->setText("ajuste font size");ui->label_91->setText("axis label rotation");}
}

void MainWindow::on_suprimmerc_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
            if(!file.open(QIODevice::Append))
    {
                qCritical()<<"could not open file";
                qCritical()<<file.errorString();
    }
            file.remove();
    file.close();
    QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
                   if(!file1.open(QIODevice::ReadOnly))
           {
                       qCritical()<<"could not open file";
                       qCritical()<<file1.errorString();

           }
                   QTextStream stream1(&file1);
                   ui->textBrowser_7->setText(stream1.readAll());

           file1.close();
}

void MainWindow::on_tradu_2_currentTextChanged(const QString &arg1)
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if(arg1=="Français"){ui->afficheraceuille->setText("afficher");ui->ajouteraceuille->setText("ajouter");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("actualite");ui->statistiquesaceuille->setText("statistique");ui->pushButton_3->setText("retourner");
    ui->label_63->setText("trier par");ui->ouvrireajouter->setText("ajouter");ui->supprimersp->setText("supprimer");ui->modifiersp->setText("modifier");ui->cherchersp->setText("chercher");
    ui->label_64->setText("sponsors");ui->label_66->setText("identifiant");ui->label_67->setText("nom");ui->label_68->setText("type de sponsor");ui->label_65->setText("soutiens");ui->label_69->setText("identifiant sponsors");ui->label_70->setText("numero de soutiens");ui->label_71->setText("type soutien");ui->label_72->setText("quantite de soutien");ui->label_73->setText("date de soutien");ui->ajouters->setText("ajouter soutien");ui->ajoutersp->setText("ajouter sponsor");ui->label_74->setText("evenement");ui->label_76->setText("identifiant sponsor");ui->label_75->setText("numer evenement");ui->label_77->setText("type evenement");ui->label_78->setText("nom evenement");ui->label_79->setText("date evenement");ui->label_80->setText("montant gagnee");ui->label_81->setText("montant payee");ui->ajoutere->setText("ajouter evenement");
    ui->label_82->setText("trier par");ui->label_83->setText("numero contact");ui->label_84->setText("nom");ui->label_85->setText("prenom");ui->label_86->setText("identifiant sponsor");ui->label_87->setText("poste");ui->label_88->setText("gsm");ui->label_89->setText("fixe");ui->label_90->setText("mail");ui->ajouterc->setText("ajouter");ui->supprimerc->setText("supprimer");ui->modifierc->setText("modifier");ui->chercherc->setText("chercher");
    ui->suprimmerc->setText("supprimer");
    ui->label_98->setText("rotation horizontale");ui->label_99->setText("rotation verticale");ui->labelButton->setText("changer label syle");ui->cameraButton->setText("changer camera set");ui->zoomToSelectedButton->setText("zoom de bare de selection");ui->backgroundCheckBox->setText("afficher background");ui->gridCheckBox->setText("afficher grille");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("afficher reflection");ui->seriesCheckBox->setText("afficher montant payee");ui->reverseValueAxisCheckBox->setText("inverser les axces");ui->axisTitlesVisibleCB->setText("axe titre visible");ui->axisTitlesFixedCB->setText("axe titre fixe");ui->label_100->setText("afficher ans");ui->label_97->setText("changer la style de bar");ui->label_96->setText("changer mode de selection");ui->label_95->setText("changer theme");ui->label_94->setText("ajuster l'ombre ");ui->label_93->setText("changer le font");ui->label_92->setText("ajuster la taille de font");ui->label_91->setText("axe label rotation");}
    if(arg1=="العربية"){ui->afficheraceuille->setText("الاضهار");ui->ajouteraceuille->setText("اضافة");ui->pushButton_6->setText("العلاقات");ui->actualitesaccuille->setText("الحدث");ui->statistiquesaceuille->setText("احصاء");ui->pushButton_3->setText("العودة");
        ui->label_63->setText("الترتيب حسب");ui->ouvrireajouter->setText("يضيف");ui->supprimersp->setText("لحذف");ui->modifiersp->setText("للتعديل");ui->cherchersp->setText("للبحث");
        ui->label_64->setText("الرعاة");ui->label_66->setText("المعرف");ui->label_67->setText("الاسم");ui->label_68->setText("نوع الراعي");ui->label_65->setText("دعم");ui->label_69->setText("معرف الراعي");ui->label_70->setText("عدد الدعم");ui->label_71->setText("نوع الدعم");ui->label_72->setText("كمية الدعم");ui->label_73->setText("تاريخ الدعم");ui->ajouters->setText("اضافة الدعم");ui->ajoutersp->setText("اضافة راعي");ui->label_74->setText("حدث");ui->label_76->setText("معرف الراعي");ui->label_75->setText("رقم الحدث");ui->label_77->setText("نوع الحدث");ui->label_78->setText("اسم الحدث");ui->label_79->setText("تاريخ الحدث");ui->label_80->setText("المبلغ المكتسب");ui->label_81->setText("المبلغ المدفوع");ui->ajoutere->setText("إضافة حدث");
        ui->label_82->setText("الترتيب حسب");ui->label_83->setText("رقم الاتصال");ui->label_84->setText("اسم");ui->label_85->setText("اللقب");ui->label_86->setText("معرف الراعي");ui->label_87->setText("مهنة");ui->label_88->setText("الجوال");ui->label_89->setText("القار");ui->label_90->setText("البريد");ui->ajouterc->setText("اضافة");ui->supprimerc->setText("حذف");ui->modifierc->setText("تعديل");ui->chercherc->setText("بحث");
        ui->suprimmerc->setText("حذف");
        ui->label_98->setText("دوران أفقي");ui->label_99->setText("الدوران العمودي");ui->labelButton->setText("تغيير نمط التسمية");ui->cameraButton->setText("تغيير زاوية الكاميرا");ui->zoomToSelectedButton->setText("تكبير شريط التحديد");ui->backgroundCheckBox->setText("عرض الخلفية");ui->gridCheckBox->setText("اظهر الخطوط");ui->smoothCheckBox->setText("شريط سلس");ui->reflectionCheckBox->setText("تظهر انعكاس");ui->seriesCheckBox->setText("عرض المبلغ المدفوع");ui->reverseValueAxisCheckBox->setText("عكس المحاور");ui->axisTitlesVisibleCB->setText("محور العنوان المرئي");ui->axisTitlesFixedCB->setText("محور عنوان ثابت");ui->label_100->setText("عرض سنوات");ui->label_97->setText("تغيير نمط الشريط");ui->label_96->setText("تغيير وضع الاختيار");ui->label_95->setText("غير الخلفية");ui->label_94->setText("ضبط الظل");ui->label_93->setText("تفعل التغيير");ui->label_92->setText("ضبط حجم الخط");ui->label_91->setText("دوران تسمية المحور");}
    if(arg1=="English"){ui->afficheraceuille->setText("show");ui->ajouteraceuille->setText("add");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("news");ui->statistiquesaceuille->setText("statistics");ui->pushButton_3->setText("return");
        ui->label_63->setText("sort by");ui->ouvrireajouter->setText("add");ui->supprimersp->setText("delete");ui->modifiersp->setText("modify");ui->cherchersp->setText("search");
        ui->label_64->setText("sponsors");ui->label_66->setText("identifiant");ui->label_67->setText("name");ui->label_68->setText("type of sponsor");ui->label_65->setText("soutiens");ui->label_69->setText("sponsors id");ui->label_70->setText("number of supports");ui->label_71->setText("support type");ui->label_72->setText("support quantity");ui->label_73->setText("support date");ui->ajouters->setText("support add");ui->ajoutersp->setText("add sponsor");ui->label_74->setText("event");ui->label_76->setText("sponsor id");ui->label_75->setText("event number");ui->label_77->setText("event type");ui->label_78->setText("event name");ui->label_79->setText("event date");ui->label_80->setText("amount earned");ui->label_81->setText("amount paid");ui->ajoutere->setText("add event");
        ui->label_82->setText("sort by");ui->label_83->setText("contact number");ui->label_84->setText("name");ui->label_85->setText("first name");ui->label_86->setText("sponsors id");ui->label_87->setText("job");ui->label_88->setText("gsm");ui->label_89->setText("fixe");ui->label_90->setText("mail");ui->ajouterc->setText("add");ui->supprimerc->setText("delete");ui->modifierc->setText("modify");ui->chercherc->setText("reaserch");
        ui->suprimmerc->setText("delete");
        ui->label_98->setText("horizontal rotation");ui->label_99->setText("vertical rotation");ui->labelButton->setText("change label style");ui->cameraButton->setText("change camera set");ui->zoomToSelectedButton->setText("zoom to bare  selection");ui->backgroundCheckBox->setText("show background");ui->gridCheckBox->setText("show grill");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("show reflection");ui->seriesCheckBox->setText("show amount paid");ui->reverseValueAxisCheckBox->setText("inverse axces");ui->axisTitlesVisibleCB->setText("axe title visible");ui->axisTitlesFixedCB->setText("axe title fix");ui->label_100->setText("show years");ui->label_97->setText("change bar style ");ui->label_96->setText("change selection mode");ui->label_95->setText("change theme");ui->label_94->setText("adjust shadow ");ui->label_93->setText("change font");ui->label_92->setText("ajuste font size");ui->label_91->setText("axis label rotation");}
}

void MainWindow::on_tradu_3_currentTextChanged(const QString &arg1)
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if(arg1=="Français"){ui->afficheraceuille->setText("afficher");ui->ajouteraceuille->setText("ajouter");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("actualite");ui->statistiquesaceuille->setText("statistique");ui->pushButton_3->setText("retourner");
    ui->label_63->setText("trier par");ui->ouvrireajouter->setText("ajouter");ui->supprimersp->setText("supprimer");ui->modifiersp->setText("modifier");ui->cherchersp->setText("chercher");
    ui->label_64->setText("sponsors");ui->label_66->setText("identifiant");ui->label_67->setText("nom");ui->label_68->setText("type de sponsor");ui->label_65->setText("soutiens");ui->label_69->setText("identifiant sponsors");ui->label_70->setText("numero de soutiens");ui->label_71->setText("type soutien");ui->label_72->setText("quantite de soutien");ui->label_73->setText("date de soutien");ui->ajouters->setText("ajouter soutien");ui->ajoutersp->setText("ajouter sponsor");ui->label_74->setText("evenement");ui->label_76->setText("identifiant sponsor");ui->label_75->setText("numer evenement");ui->label_77->setText("type evenement");ui->label_78->setText("nom evenement");ui->label_79->setText("date evenement");ui->label_80->setText("montant gagnee");ui->label_81->setText("montant payee");ui->ajoutere->setText("ajouter evenement");
    ui->label_82->setText("trier par");ui->label_83->setText("numero contact");ui->label_84->setText("nom");ui->label_85->setText("prenom");ui->label_86->setText("identifiant sponsor");ui->label_87->setText("poste");ui->label_88->setText("gsm");ui->label_89->setText("fixe");ui->label_90->setText("mail");ui->ajouterc->setText("ajouter");ui->supprimerc->setText("supprimer");ui->modifierc->setText("modifier");ui->chercherc->setText("chercher");
    ui->suprimmerc->setText("supprimer");
    ui->label_98->setText("rotation horizontale");ui->label_99->setText("rotation verticale");ui->labelButton->setText("changer label syle");ui->cameraButton->setText("changer camera set");ui->zoomToSelectedButton->setText("zoom de bare de selection");ui->backgroundCheckBox->setText("afficher background");ui->gridCheckBox->setText("afficher grille");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("afficher reflection");ui->seriesCheckBox->setText("afficher montant payee");ui->reverseValueAxisCheckBox->setText("inverser les axces");ui->axisTitlesVisibleCB->setText("axe titre visible");ui->axisTitlesFixedCB->setText("axe titre fixe");ui->label_100->setText("afficher ans");ui->label_97->setText("changer la style de bar");ui->label_96->setText("changer mode de selection");ui->label_95->setText("changer theme");ui->label_94->setText("ajuster l'ombre ");ui->label_93->setText("changer le font");ui->label_92->setText("ajuster la taille de font");ui->label_91->setText("axe label rotation");}
    if(arg1=="العربية"){ui->afficheraceuille->setText("الاضهار");ui->ajouteraceuille->setText("اضافة");ui->pushButton_6->setText("العلاقات");ui->actualitesaccuille->setText("الحدث");ui->statistiquesaceuille->setText("احصاء");ui->pushButton_3->setText("العودة");
        ui->label_63->setText("الترتيب حسب");ui->ouvrireajouter->setText("يضيف");ui->supprimersp->setText("لحذف");ui->modifiersp->setText("للتعديل");ui->cherchersp->setText("للبحث");
        ui->label_64->setText("الرعاة");ui->label_66->setText("المعرف");ui->label_67->setText("الاسم");ui->label_68->setText("نوع الراعي");ui->label_65->setText("دعم");ui->label_69->setText("معرف الراعي");ui->label_70->setText("عدد الدعم");ui->label_71->setText("نوع الدعم");ui->label_72->setText("كمية الدعم");ui->label_73->setText("تاريخ الدعم");ui->ajouters->setText("اضافة الدعم");ui->ajoutersp->setText("اضافة راعي");ui->label_74->setText("حدث");ui->label_76->setText("معرف الراعي");ui->label_75->setText("رقم الحدث");ui->label_77->setText("نوع الحدث");ui->label_78->setText("اسم الحدث");ui->label_79->setText("تاريخ الحدث");ui->label_80->setText("المبلغ المكتسب");ui->label_81->setText("المبلغ المدفوع");ui->ajoutere->setText("إضافة حدث");
        ui->label_82->setText("الترتيب حسب");ui->label_83->setText("رقم الاتصال");ui->label_84->setText("اسم");ui->label_85->setText("اللقب");ui->label_86->setText("معرف الراعي");ui->label_87->setText("مهنة");ui->label_88->setText("الجوال");ui->label_89->setText("القار");ui->label_90->setText("البريد");ui->ajouterc->setText("اضافة");ui->supprimerc->setText("حذف");ui->modifierc->setText("تعديل");ui->chercherc->setText("بحث");
        ui->suprimmerc->setText("حذف");
        ui->label_98->setText("دوران أفقي");ui->label_99->setText("الدوران العمودي");ui->labelButton->setText("تغيير نمط التسمية");ui->cameraButton->setText("تغيير زاوية الكاميرا");ui->zoomToSelectedButton->setText("تكبير شريط التحديد");ui->backgroundCheckBox->setText("عرض الخلفية");ui->gridCheckBox->setText("اظهر الخطوط");ui->smoothCheckBox->setText("شريط سلس");ui->reflectionCheckBox->setText("تظهر انعكاس");ui->seriesCheckBox->setText("عرض المبلغ المدفوع");ui->reverseValueAxisCheckBox->setText("عكس المحاور");ui->axisTitlesVisibleCB->setText("محور العنوان المرئي");ui->axisTitlesFixedCB->setText("محور عنوان ثابت");ui->label_100->setText("عرض سنوات");ui->label_97->setText("تغيير نمط الشريط");ui->label_96->setText("تغيير وضع الاختيار");ui->label_95->setText("غير الخلفية");ui->label_94->setText("ضبط الظل");ui->label_93->setText("تفعل التغيير");ui->label_92->setText("ضبط حجم الخط");ui->label_91->setText("دوران تسمية المحور");}
    if(arg1=="English"){ui->afficheraceuille->setText("show");ui->ajouteraceuille->setText("add");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("news");ui->statistiquesaceuille->setText("statistics");ui->pushButton_3->setText("return");
        ui->label_63->setText("sort by");ui->ouvrireajouter->setText("add");ui->supprimersp->setText("delete");ui->modifiersp->setText("modify");ui->cherchersp->setText("search");
        ui->label_64->setText("sponsors");ui->label_66->setText("identifiant");ui->label_67->setText("name");ui->label_68->setText("type of sponsor");ui->label_65->setText("soutiens");ui->label_69->setText("sponsors id");ui->label_70->setText("number of supports");ui->label_71->setText("support type");ui->label_72->setText("support quantity");ui->label_73->setText("support date");ui->ajouters->setText("support add");ui->ajoutersp->setText("add sponsor");ui->label_74->setText("event");ui->label_76->setText("sponsor id");ui->label_75->setText("event number");ui->label_77->setText("event type");ui->label_78->setText("event name");ui->label_79->setText("event date");ui->label_80->setText("amount earned");ui->label_81->setText("amount paid");ui->ajoutere->setText("add event");
        ui->label_82->setText("sort by");ui->label_83->setText("contact number");ui->label_84->setText("name");ui->label_85->setText("first name");ui->label_86->setText("sponsors id");ui->label_87->setText("job");ui->label_88->setText("gsm");ui->label_89->setText("fixe");ui->label_90->setText("mail");ui->ajouterc->setText("add");ui->supprimerc->setText("delete");ui->modifierc->setText("modify");ui->chercherc->setText("reaserch");
        ui->suprimmerc->setText("delete");
        ui->label_98->setText("horizontal rotation");ui->label_99->setText("vertical rotation");ui->labelButton->setText("change label style");ui->cameraButton->setText("change camera set");ui->zoomToSelectedButton->setText("zoom to bare  selection");ui->backgroundCheckBox->setText("show background");ui->gridCheckBox->setText("show grill");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("show reflection");ui->seriesCheckBox->setText("show amount paid");ui->reverseValueAxisCheckBox->setText("inverse axces");ui->axisTitlesVisibleCB->setText("axe title visible");ui->axisTitlesFixedCB->setText("axe title fix");ui->label_100->setText("show years");ui->label_97->setText("change bar style ");ui->label_96->setText("change selection mode");ui->label_95->setText("change theme");ui->label_94->setText("adjust shadow ");ui->label_93->setText("change font");ui->label_92->setText("ajuste font size");ui->label_91->setText("axis label rotation");}

}

void MainWindow::on_tradu_4_currentTextChanged(const QString &arg1)
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if(arg1=="Français"){ui->afficheraceuille->setText("afficher");ui->ajouteraceuille->setText("ajouter");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("actualite");ui->statistiquesaceuille->setText("statistique");ui->pushButton_3->setText("retourner");
    ui->label_63->setText("trier par");ui->ouvrireajouter->setText("ajouter");ui->supprimersp->setText("supprimer");ui->modifiersp->setText("modifier");ui->cherchersp->setText("chercher");
    ui->label_64->setText("sponsors");ui->label_66->setText("identifiant");ui->label_67->setText("nom");ui->label_68->setText("type de sponsor");ui->label_65->setText("soutiens");ui->label_69->setText("identifiant sponsors");ui->label_70->setText("numero de soutiens");ui->label_71->setText("type soutien");ui->label_72->setText("quantite de soutien");ui->label_73->setText("date de soutien");ui->ajouters->setText("ajouter soutien");ui->ajoutersp->setText("ajouter sponsor");ui->label_74->setText("evenement");ui->label_76->setText("identifiant sponsor");ui->label_75->setText("numer evenement");ui->label_77->setText("type evenement");ui->label_78->setText("nom evenement");ui->label_79->setText("date evenement");ui->label_80->setText("montant gagnee");ui->label_81->setText("montant payee");ui->ajoutere->setText("ajouter evenement");
    ui->label_82->setText("trier par");ui->label_83->setText("numero contact");ui->label_84->setText("nom");ui->label_85->setText("prenom");ui->label_86->setText("identifiant sponsor");ui->label_87->setText("poste");ui->label_88->setText("gsm");ui->label_89->setText("fixe");ui->label_90->setText("mail");ui->ajouterc->setText("ajouter");ui->supprimerc->setText("supprimer");ui->modifierc->setText("modifier");ui->chercherc->setText("chercher");
    ui->suprimmerc->setText("supprimer");
    ui->label_98->setText("rotation horizontale");ui->label_99->setText("rotation verticale");ui->labelButton->setText("changer label syle");ui->cameraButton->setText("changer camera set");ui->zoomToSelectedButton->setText("zoom de bare de selection");ui->backgroundCheckBox->setText("afficher background");ui->gridCheckBox->setText("afficher grille");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("afficher reflection");ui->seriesCheckBox->setText("afficher montant payee");ui->reverseValueAxisCheckBox->setText("inverser les axces");ui->axisTitlesVisibleCB->setText("axe titre visible");ui->axisTitlesFixedCB->setText("axe titre fixe");ui->label_100->setText("afficher ans");ui->label_97->setText("changer la style de bar");ui->label_96->setText("changer mode de selection");ui->label_95->setText("changer theme");ui->label_94->setText("ajuster l'ombre ");ui->label_93->setText("changer le font");ui->label_92->setText("ajuster la taille de font");ui->label_91->setText("axe label rotation");}
    if(arg1=="العربية"){ui->afficheraceuille->setText("الاضهار");ui->ajouteraceuille->setText("اضافة");ui->pushButton_6->setText("العلاقات");ui->actualitesaccuille->setText("الحدث");ui->statistiquesaceuille->setText("احصاء");ui->pushButton_3->setText("العودة");
        ui->label_63->setText("الترتيب حسب");ui->ouvrireajouter->setText("يضيف");ui->supprimersp->setText("لحذف");ui->modifiersp->setText("للتعديل");ui->cherchersp->setText("للبحث");
        ui->label_64->setText("الرعاة");ui->label_66->setText("المعرف");ui->label_67->setText("الاسم");ui->label_68->setText("نوع الراعي");ui->label_65->setText("دعم");ui->label_69->setText("معرف الراعي");ui->label_70->setText("عدد الدعم");ui->label_71->setText("نوع الدعم");ui->label_72->setText("كمية الدعم");ui->label_73->setText("تاريخ الدعم");ui->ajouters->setText("اضافة الدعم");ui->ajoutersp->setText("اضافة راعي");ui->label_74->setText("حدث");ui->label_76->setText("معرف الراعي");ui->label_75->setText("رقم الحدث");ui->label_77->setText("نوع الحدث");ui->label_78->setText("اسم الحدث");ui->label_79->setText("تاريخ الحدث");ui->label_80->setText("المبلغ المكتسب");ui->label_81->setText("المبلغ المدفوع");ui->ajoutere->setText("إضافة حدث");
        ui->label_82->setText("الترتيب حسب");ui->label_83->setText("رقم الاتصال");ui->label_84->setText("اسم");ui->label_85->setText("اللقب");ui->label_86->setText("معرف الراعي");ui->label_87->setText("مهنة");ui->label_88->setText("الجوال");ui->label_89->setText("القار");ui->label_90->setText("البريد");ui->ajouterc->setText("اضافة");ui->supprimerc->setText("حذف");ui->modifierc->setText("تعديل");ui->chercherc->setText("بحث");
        ui->suprimmerc->setText("حذف");
        ui->label_98->setText("دوران أفقي");ui->label_99->setText("الدوران العمودي");ui->labelButton->setText("تغيير نمط التسمية");ui->cameraButton->setText("تغيير زاوية الكاميرا");ui->zoomToSelectedButton->setText("تكبير شريط التحديد");ui->backgroundCheckBox->setText("عرض الخلفية");ui->gridCheckBox->setText("اظهر الخطوط");ui->smoothCheckBox->setText("شريط سلس");ui->reflectionCheckBox->setText("تظهر انعكاس");ui->seriesCheckBox->setText("عرض المبلغ المدفوع");ui->reverseValueAxisCheckBox->setText("عكس المحاور");ui->axisTitlesVisibleCB->setText("محور العنوان المرئي");ui->axisTitlesFixedCB->setText("محور عنوان ثابت");ui->label_100->setText("عرض سنوات");ui->label_97->setText("تغيير نمط الشريط");ui->label_96->setText("تغيير وضع الاختيار");ui->label_95->setText("غير الخلفية");ui->label_94->setText("ضبط الظل");ui->label_93->setText("تفعل التغيير");ui->label_92->setText("ضبط حجم الخط");ui->label_91->setText("دوران تسمية المحور");}
    if(arg1=="English"){ui->afficheraceuille->setText("show");ui->ajouteraceuille->setText("add");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("news");ui->statistiquesaceuille->setText("statistics");ui->pushButton_3->setText("return");
        ui->label_63->setText("sort by");ui->ouvrireajouter->setText("add");ui->supprimersp->setText("delete");ui->modifiersp->setText("modify");ui->cherchersp->setText("search");
        ui->label_64->setText("sponsors");ui->label_66->setText("identifiant");ui->label_67->setText("name");ui->label_68->setText("type of sponsor");ui->label_65->setText("soutiens");ui->label_69->setText("sponsors id");ui->label_70->setText("number of supports");ui->label_71->setText("support type");ui->label_72->setText("support quantity");ui->label_73->setText("support date");ui->ajouters->setText("support add");ui->ajoutersp->setText("add sponsor");ui->label_74->setText("event");ui->label_76->setText("sponsor id");ui->label_75->setText("event number");ui->label_77->setText("event type");ui->label_78->setText("event name");ui->label_79->setText("event date");ui->label_80->setText("amount earned");ui->label_81->setText("amount paid");ui->ajoutere->setText("add event");
        ui->label_82->setText("sort by");ui->label_83->setText("contact number");ui->label_84->setText("name");ui->label_85->setText("first name");ui->label_86->setText("sponsors id");ui->label_87->setText("job");ui->label_88->setText("gsm");ui->label_89->setText("fixe");ui->label_90->setText("mail");ui->ajouterc->setText("add");ui->supprimerc->setText("delete");ui->modifierc->setText("modify");ui->chercherc->setText("reaserch");
        ui->suprimmerc->setText("delete");
        ui->label_98->setText("horizontal rotation");ui->label_99->setText("vertical rotation");ui->labelButton->setText("change label style");ui->cameraButton->setText("change camera set");ui->zoomToSelectedButton->setText("zoom to bare  selection");ui->backgroundCheckBox->setText("show background");ui->gridCheckBox->setText("show grill");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("show reflection");ui->seriesCheckBox->setText("show amount paid");ui->reverseValueAxisCheckBox->setText("inverse axces");ui->axisTitlesVisibleCB->setText("axe title visible");ui->axisTitlesFixedCB->setText("axe title fix");ui->label_100->setText("show years");ui->label_97->setText("change bar style ");ui->label_96->setText("change selection mode");ui->label_95->setText("change theme");ui->label_94->setText("adjust shadow ");ui->label_93->setText("change font");ui->label_92->setText("ajuste font size");ui->label_91->setText("axis label rotation");}

}

void MainWindow::on_tradu_5_currentTextChanged(const QString &arg1)
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if(arg1=="Français"){ui->afficheraceuille->setText("afficher");ui->ajouteraceuille->setText("ajouter");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("actualite");ui->statistiquesaceuille->setText("statistique");
    ui->label->setText("trier par");ui->ouvrireajouter->setText("ajouter");ui->supprimersp->setText("supprimer");ui->modifiersp->setText("modifier");ui->cherchersp->setText("chercher");
    ui->label_2->setText("sponsors");ui->label_4->setText("identifiant");ui->label_5->setText("nom");ui->label_3->setText("soutiens");ui->label_7->setText("identifiant sponsors");ui->label_8->setText("numero de soutiens");ui->label_9->setText("type soutien");ui->label_10->setText("quantite de soutien");ui->label_11->setText("date de soutien");ui->ajouters->setText("ajouter soutien");ui->ajoutersp->setText("ajouter sponsor");ui->label_12->setText("evenement");ui->label_14->setText("identifiant sponsor");ui->label_13->setText("numer evenement");ui->label_15->setText("type evenement");ui->label_16->setText("nom evenement");ui->label_17->setText("date evenement");ui->label_18->setText("montant gagnee");ui->label_19->setText("montant payee");ui->ajoutere->setText("ajouter evenement");
    ui->label_30->setText("trier par");ui->label_31->setText("numero contact");ui->label_32->setText("nom");ui->label_33->setText("prenom");ui->label_34->setText("identifiant sponsor");ui->label_69->setText("poste");ui->label_70->setText("gsm");ui->label_71->setText("fixe");ui->label_72->setText("mail");ui->ajouterc->setText("ajouter");ui->supprimerc->setText("supprimer");ui->modifierc->setText("modifier");ui->chercherc->setText("chercher");
    ui->suprimmerc->setText("supprimer");
    ui->label_27->setText("rotation horizontale");ui->label_28->setText("rotation verticale");ui->labelButton->setText("changer label syle");ui->cameraButton->setText("changer camera set");ui->zoomToSelectedButton->setText("zoom de bare de selection");ui->backgroundCheckBox->setText("afficher background");ui->gridCheckBox->setText("afficher grille");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("afficher reflection");ui->seriesCheckBox->setText("afficher montant payee");ui->reverseValueAxisCheckBox->setText("inverser les axces");ui->axisTitlesVisibleCB->setText("axe titre visible");ui->axisTitlesFixedCB->setText("axe titre fixe");ui->label_29->setText("afficher ans");ui->label_26->setText("changer la style de bar");ui->label_25->setText("changer mode de selection");ui->label_24->setText("changer theme");ui->label_23->setText("ajuster l'ombre ");ui->label_22->setText("changer le font");ui->label_21->setText("ajuster la taille de font");ui->label_20->setText("axe label rotation");}
    if(arg1=="العربية"){ui->afficheraceuille->setText("الاضهار");ui->ajouteraceuille->setText("اضافة");ui->pushButton_6->setText("العلاقات");ui->actualitesaccuille->setText("الحدث");ui->statistiquesaceuille->setText("احصاء");
        ui->label->setText("الترتيب حسب");ui->ouvrireajouter->setText("يضيف");ui->supprimersp->setText("لحذف");ui->modifiersp->setText("للتعديل");ui->cherchersp->setText("للبحث");
        ui->label_2->setText("الرعاة");ui->label_4->setText("المعرف");ui->label_5->setText("الاسم");ui->label_3->setText("دعم");ui->label_7->setText("معرف الراعي");ui->label_8->setText("عدد الدعم");ui->label_9->setText("نوع الدعم");ui->label_10->setText("كمية الدعم");ui->label_11->setText("تاريخ الدعم");ui->ajouters->setText("اضافة الدعم");ui->ajoutersp->setText("اضافة راعي");ui->label_12->setText("حدث");ui->label_14->setText("معرف الراعي");ui->label_13->setText("رقم الحدث");ui->label_15->setText("نوع الحدث");ui->label_16->setText("اسم الحدث");ui->label_17->setText("تاريخ الحدث");ui->label_18->setText("المبلغ المكتسب");ui->label_19->setText("المبلغ المدفوع");ui->ajoutere->setText("إضافة حدث");
        ui->label_30->setText("الترتيب حسب");ui->label_31->setText("رقم الاتصال");ui->label_32->setText("اسم");ui->label_33->setText("اللقب");ui->label_34->setText("معرف الراعي");ui->label_69->setText("مهنة");ui->label_70->setText("الجوال");ui->label_71->setText("القار");ui->label_72->setText("البريد");ui->ajouterc->setText("اضافة");ui->supprimerc->setText("حذف");ui->modifierc->setText("تعديل");ui->chercherc->setText("بحث");
        ui->suprimmerc->setText("حذف");
        ui->label_27->setText("دوران أفقي");ui->label_28->setText("الدوران العمودي");ui->labelButton->setText("تغيير نمط التسمية");ui->cameraButton->setText("تغيير زاوية الكاميرا");ui->zoomToSelectedButton->setText("تكبير شريط التحديد");ui->backgroundCheckBox->setText("عرض الخلفية");ui->gridCheckBox->setText("اظهر الخطوط");ui->smoothCheckBox->setText("شريط سلس");ui->reflectionCheckBox->setText("تظهر انعكاس");ui->seriesCheckBox->setText("عرض المبلغ المدفوع");ui->reverseValueAxisCheckBox->setText("عكس المحاور");ui->axisTitlesVisibleCB->setText("محور العنوان المرئي");ui->axisTitlesFixedCB->setText("محور عنوان ثابت");ui->label_29->setText("عرض سنوات");ui->label_26->setText("تغيير نمط الشريط");ui->label_25->setText("تغيير وضع الاختيار");ui->label_24->setText("غير الخلفية");ui->label_23->setText("ضبط الظل");ui->label_22->setText("تفعل التغيير");ui->label_21->setText("ضبط حجم الخط");ui->label_20->setText("دوران تسمية المحور");}
    if(arg1=="English"){ui->afficheraceuille->setText("show");ui->ajouteraceuille->setText("add");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("news");ui->statistiquesaceuille->setText("statistics");
        ui->label->setText("sort by");ui->ouvrireajouter->setText("add");ui->supprimersp->setText("delete");ui->modifiersp->setText("modify");ui->cherchersp->setText("search");
        ui->label_2->setText("sponsors");ui->label_4->setText("identifiant");ui->label_5->setText("name");ui->label_3->setText("soutiens");ui->label_7->setText("sponsors id");ui->label_8->setText("number of supports");ui->label_9->setText("support type");ui->label_10->setText("support quantity");ui->label_11->setText("support date");ui->ajouters->setText("support add");ui->ajoutersp->setText("add sponsor");ui->label_12->setText("event");ui->label_14->setText("sponsor id");ui->label_13->setText("event number");ui->label_15->setText("event type");ui->label_16->setText("event name");ui->label_17->setText("event date");ui->label_18->setText("amount earned");ui->label_19->setText("amount paid");ui->ajoutere->setText("add event");
        ui->label_30->setText("sort by");ui->label_31->setText("contact number");ui->label_32->setText("name");ui->label_33->setText("first name");ui->label_34->setText("sponsors id");ui->label_69->setText("job");ui->label_70->setText("gsm");ui->label_71->setText("fixe");ui->label_72->setText("mail");ui->ajouterc->setText("add");ui->supprimerc->setText("delete");ui->modifierc->setText("modify");ui->chercherc->setText("reaserch");
        ui->suprimmerc->setText("delete");
        ui->label_27->setText("horizontal rotation");ui->label_28->setText("vertical rotation");ui->labelButton->setText("change label style");ui->cameraButton->setText("change camera set");ui->zoomToSelectedButton->setText("zoom to bare  selection");ui->backgroundCheckBox->setText("show background");ui->gridCheckBox->setText("show grill");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("show reflection");ui->seriesCheckBox->setText("show amount paid");ui->reverseValueAxisCheckBox->setText("inverse axces");ui->axisTitlesVisibleCB->setText("axe title visible");ui->axisTitlesFixedCB->setText("axe title fix");ui->label_29->setText("show years");ui->label_26->setText("change bar style ");ui->label_25->setText("change selection mode");ui->label_24->setText("change theme");ui->label_23->setText("adjust shadow ");ui->label_22->setText("change font");ui->label_21->setText("ajuste font size");ui->label_20->setText("axis label rotation");}

}

void MainWindow::on_tradu_6_activated(const QString &arg1)
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if(arg1=="Français"){ui->afficheraceuille->setText("afficher");ui->ajouteraceuille->setText("ajouter");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("actualite");ui->statistiquesaceuille->setText("statistique");ui->pushButton_3->setText("retourner");
    ui->label_63->setText("trier par");ui->ouvrireajouter->setText("ajouter");ui->supprimersp->setText("supprimer");ui->modifiersp->setText("modifier");ui->cherchersp->setText("chercher");
    ui->label_64->setText("sponsors");ui->label_66->setText("identifiant");ui->label_67->setText("nom");ui->label_68->setText("type de sponsor");ui->label_65->setText("soutiens");ui->label_69->setText("identifiant sponsors");ui->label_70->setText("numero de soutiens");ui->label_71->setText("type soutien");ui->label_72->setText("quantite de soutien");ui->label_73->setText("date de soutien");ui->ajouters->setText("ajouter soutien");ui->ajoutersp->setText("ajouter sponsor");ui->label_74->setText("evenement");ui->label_76->setText("identifiant sponsor");ui->label_75->setText("numer evenement");ui->label_77->setText("type evenement");ui->label_78->setText("nom evenement");ui->label_79->setText("date evenement");ui->label_80->setText("montant gagnee");ui->label_81->setText("montant payee");ui->ajoutere->setText("ajouter evenement");
    ui->label_82->setText("trier par");ui->label_83->setText("numero contact");ui->label_84->setText("nom");ui->label_85->setText("prenom");ui->label_86->setText("identifiant sponsor");ui->label_87->setText("poste");ui->label_88->setText("gsm");ui->label_89->setText("fixe");ui->label_90->setText("mail");ui->ajouterc->setText("ajouter");ui->supprimerc->setText("supprimer");ui->modifierc->setText("modifier");ui->chercherc->setText("chercher");
    ui->suprimmerc->setText("supprimer");
    ui->label_98->setText("rotation horizontale");ui->label_99->setText("rotation verticale");ui->labelButton->setText("changer label syle");ui->cameraButton->setText("changer camera set");ui->zoomToSelectedButton->setText("zoom de bare de selection");ui->backgroundCheckBox->setText("afficher background");ui->gridCheckBox->setText("afficher grille");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("afficher reflection");ui->seriesCheckBox->setText("afficher montant payee");ui->reverseValueAxisCheckBox->setText("inverser les axces");ui->axisTitlesVisibleCB->setText("axe titre visible");ui->axisTitlesFixedCB->setText("axe titre fixe");ui->label_100->setText("afficher ans");ui->label_97->setText("changer la style de bar");ui->label_96->setText("changer mode de selection");ui->label_95->setText("changer theme");ui->label_94->setText("ajuster l'ombre ");ui->label_93->setText("changer le font");ui->label_92->setText("ajuster la taille de font");ui->label_91->setText("axe label rotation");}
    if(arg1=="العربية"){ui->afficheraceuille->setText("الاضهار");ui->ajouteraceuille->setText("اضافة");ui->pushButton_6->setText("العلاقات");ui->actualitesaccuille->setText("الحدث");ui->statistiquesaceuille->setText("احصاء");ui->pushButton_3->setText("العودة");
        ui->label_63->setText("الترتيب حسب");ui->ouvrireajouter->setText("يضيف");ui->supprimersp->setText("لحذف");ui->modifiersp->setText("للتعديل");ui->cherchersp->setText("للبحث");
        ui->label_64->setText("الرعاة");ui->label_66->setText("المعرف");ui->label_67->setText("الاسم");ui->label_68->setText("نوع الراعي");ui->label_65->setText("دعم");ui->label_69->setText("معرف الراعي");ui->label_70->setText("عدد الدعم");ui->label_71->setText("نوع الدعم");ui->label_72->setText("كمية الدعم");ui->label_73->setText("تاريخ الدعم");ui->ajouters->setText("اضافة الدعم");ui->ajoutersp->setText("اضافة راعي");ui->label_74->setText("حدث");ui->label_76->setText("معرف الراعي");ui->label_75->setText("رقم الحدث");ui->label_77->setText("نوع الحدث");ui->label_78->setText("اسم الحدث");ui->label_79->setText("تاريخ الحدث");ui->label_80->setText("المبلغ المكتسب");ui->label_81->setText("المبلغ المدفوع");ui->ajoutere->setText("إضافة حدث");
        ui->label_82->setText("الترتيب حسب");ui->label_83->setText("رقم الاتصال");ui->label_84->setText("اسم");ui->label_85->setText("اللقب");ui->label_86->setText("معرف الراعي");ui->label_87->setText("مهنة");ui->label_88->setText("الجوال");ui->label_89->setText("القار");ui->label_90->setText("البريد");ui->ajouterc->setText("اضافة");ui->supprimerc->setText("حذف");ui->modifierc->setText("تعديل");ui->chercherc->setText("بحث");
        ui->suprimmerc->setText("حذف");
        ui->label_98->setText("دوران أفقي");ui->label_99->setText("الدوران العمودي");ui->labelButton->setText("تغيير نمط التسمية");ui->cameraButton->setText("تغيير زاوية الكاميرا");ui->zoomToSelectedButton->setText("تكبير شريط التحديد");ui->backgroundCheckBox->setText("عرض الخلفية");ui->gridCheckBox->setText("اظهر الخطوط");ui->smoothCheckBox->setText("شريط سلس");ui->reflectionCheckBox->setText("تظهر انعكاس");ui->seriesCheckBox->setText("عرض المبلغ المدفوع");ui->reverseValueAxisCheckBox->setText("عكس المحاور");ui->axisTitlesVisibleCB->setText("محور العنوان المرئي");ui->axisTitlesFixedCB->setText("محور عنوان ثابت");ui->label_100->setText("عرض سنوات");ui->label_97->setText("تغيير نمط الشريط");ui->label_96->setText("تغيير وضع الاختيار");ui->label_95->setText("غير الخلفية");ui->label_94->setText("ضبط الظل");ui->label_93->setText("تفعل التغيير");ui->label_92->setText("ضبط حجم الخط");ui->label_91->setText("دوران تسمية المحور");}
    if(arg1=="English"){ui->afficheraceuille->setText("show");ui->ajouteraceuille->setText("add");ui->pushButton_6->setText("contact");ui->actualitesaccuille->setText("news");ui->statistiquesaceuille->setText("statistics");ui->pushButton_3->setText("return");
        ui->label_63->setText("sort by");ui->ouvrireajouter->setText("add");ui->supprimersp->setText("delete");ui->modifiersp->setText("modify");ui->cherchersp->setText("search");
        ui->label_64->setText("sponsors");ui->label_66->setText("identifiant");ui->label_67->setText("name");ui->label_68->setText("type of sponsor");ui->label_65->setText("soutiens");ui->label_69->setText("sponsors id");ui->label_70->setText("number of supports");ui->label_71->setText("support type");ui->label_72->setText("support quantity");ui->label_73->setText("support date");ui->ajouters->setText("support add");ui->ajoutersp->setText("add sponsor");ui->label_74->setText("event");ui->label_76->setText("sponsor id");ui->label_75->setText("event number");ui->label_77->setText("event type");ui->label_78->setText("event name");ui->label_79->setText("event date");ui->label_80->setText("amount earned");ui->label_81->setText("amount paid");ui->ajoutere->setText("add event");
        ui->label_82->setText("sort by");ui->label_83->setText("contact number");ui->label_84->setText("name");ui->label_85->setText("first name");ui->label_86->setText("sponsors id");ui->label_87->setText("job");ui->label_88->setText("gsm");ui->label_89->setText("fixe");ui->label_90->setText("mail");ui->ajouterc->setText("add");ui->supprimerc->setText("delete");ui->modifierc->setText("modify");ui->chercherc->setText("reaserch");
        ui->suprimmerc->setText("delete");
        ui->label_98->setText("horizontal rotation");ui->label_99->setText("vertical rotation");ui->labelButton->setText("change label style");ui->cameraButton->setText("change camera set");ui->zoomToSelectedButton->setText("zoom to bare  selection");ui->backgroundCheckBox->setText("show background");ui->gridCheckBox->setText("show grill");ui->smoothCheckBox->setText("smooth bar");ui->reflectionCheckBox->setText("show reflection");ui->seriesCheckBox->setText("show amount paid");ui->reverseValueAxisCheckBox->setText("inverse axces");ui->axisTitlesVisibleCB->setText("axe title visible");ui->axisTitlesFixedCB->setText("axe title fix");ui->label_100->setText("show years");ui->label_97->setText("change bar style ");ui->label_96->setText("change selection mode");ui->label_95->setText("change theme");ui->label_94->setText("adjust shadow ");ui->label_93->setText("change font");ui->label_92->setText("ajuste font size");ui->label_91->setText("axis label rotation");}

}





















void MainWindow::on_spons_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->spcombo1_2->setModel(sp.affichercombo());
    ui->spcombo1_4->setModel(sp.affichercombo());
    ui->tablesp->setModel(sp.afficher());
    ui->affc->setModel(c.afficher());
    ui->spcombo1->setModel(sp.affichercombo());
    ui->spcombo2->setModel(sp.affichercombo());
    ui->ids->setModel(sp.affichercombo());
    ui->ids_2->setModel(sp.affichercombo());
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQueryModel* model1=new QSqlQueryModel();
    QSqlQueryModel* model2=new QSqlQueryModel();
    model->setQuery( "select SPONSORS_SEQ.nextval from dual ");
     QSqlQuery query(" ALTER SEQUENCE SPONSORS_SEQ INCREMENT BY -1");
    model->setQuery( "select SPONSORS_SEQ.nextval from dual ");
       ui->idsp->setText(QString :: number((model->data(model->index(0,0)).toInt())+1));
    QSqlQuery query1 (" ALTER SEQUENCE SPONSORS_SEQ INCREMENT BY 1");
    model1->setQuery( "select SOUTIEN_SEQ.nextval from dual ");
    QSqlQuery query2(" ALTER SEQUENCE SOUTIEN_SEQ INCREMENT BY -1");
    model1->setQuery( "select SOUTIEN_SEQ.nextval from dual ");
       ui->idsp_2->setText(QString :: number((model1->data(model1->index(0,0)).toInt())+1));
     QSqlQuery query3 (" ALTER SEQUENCE SOUTIEN_SEQ INCREMENT BY 1");
    model2->setQuery( "select EVENEMENT_SEQ.nextval from dual ");
    QSqlQuery query4(" ALTER SEQUENCE EVENEMENT_SEQ INCREMENT BY -1");
    model2->setQuery( "select EVENEMENT_SEQ.nextval from dual ");
       ui->idsp_3->setText(QString :: number((model2->data(model2->index(0,0)).toInt())+1));
    QSqlQuery query5 (" ALTER SEQUENCE EVENEMENT_SEQ INCREMENT BY 1");
    QSqlQueryModel* model6=new QSqlQueryModel();
    model6->setQuery( "select CONTACT_SEQ.nextval from dual ");
     QSqlQuery query6(" ALTER SEQUENCE CONTACT_SEQ INCREMENT BY -1");
    model6->setQuery( "select CONTACT_SEQ.nextval from dual ");
       ui->numcontact->setText(QString :: number((model6->data(model6->index(0,0)).toInt())+1));
    QSqlQuery query7 (" ALTER SEQUENCE CONTACT_SEQ INCREMENT BY 1");
    ui->textBrowser_7->setFontPointSize(14);

    ui->modifs->hide();
    ui->mod->hide();
    ui->modifsp->hide();
    ui->modife->hide();
    ui->modifc->hide();ui->ids_2->hide();ui->postec_2->hide();
    QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
        if(!file1.open(QIODevice::ReadOnly))
    {
            qCritical()<<"could not open file";
            qCritical()<<file1.errorString();

    }
        QTextStream stream1(&file1);

    ui->textBrowser_7->setText(stream1.readAll());
    file1.close();




    QSystemTrayIcon *notif=new  (QSystemTrayIcon);
    QSqlQueryModel* model9=new QSqlQueryModel();QSqlQuery query9;QDate q1;
    query9.prepare("SELECT * FROM EVENEMENT  where DATE_EVENEMENT > :date ORDER BY DATE_EVENEMENT ASC");
    query9.bindValue(":date",q1.currentDate());
    query9.exec();
    model9->setQuery(query9);

    if(model9->data(model9->index(0,3))!=NULL){notif->setVisible(true);
        notif->showMessage("notification","l'evenement prochain est le :"+model9->data(model9->index(0,3)).toString());}
    else {notif->setVisible(true);
        notif->showMessage("notification","il ny'a pas d'eveenemt prochain");}
    A.connect_arduinosp();
         QObject::connect(A.getserialsp(),SIGNAL(readyRead()),this,SLOT(update()));
    f11.insert(0,a11);f11.insert(1,a12);f11.insert(2,a13);
    f12.insert(0,a21);f12.insert(1,a22);f12.insert(2,a23);
    f13.insert(0,a31);f13.insert(1,a32);f13.insert(2,a33);
    f21.insert(0,b11);f21.insert(1,b12);f21.insert(2,b13);
    f22.insert(0,b21);f22.insert(1,b22);f22.insert(2,b23);
    f23.insert(0,b31);f23.insert(1,b32);f23.insert(2,b33);
    f31.insert(0,c11);f31.insert(1,c12);f31.insert(2,c13);
    f32.insert(0,c21);f32.insert(1,c22);f32.insert(2,c23);
    f33.insert(0,c31);f33.insert(1,c32);f33.insert(2,c33);
    f1.insert(0,f11);f1.insert(1,f12);f1.insert(2,f13);
    f2.insert(0,f21);f2.insert(1,f22);f2.insert(2,f23);
    f3.insert(0,f31);f3.insert(1,f32);f3.insert(2,f33);
    ff.insert(0,f1);ff.insert(1,f2);ff.insert(2,f3);

    ui->pub->setMovie(initiale);
    initiale->start();
        ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(0);
}




//-------------------------------------------------Fournisseurs--------------------------------------------------------------------------------
void MainWindow::on_fourn_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->tableView_2->setModel(f.afficher());
    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");
      if (!file.open(QIODevice::ReadOnly))
      {
          QMessageBox::information(0,"info",file.errorString());
      }
      QTextStream in (&file);
     ui->textBrowser_8->setText(in.readAll());

ui->code->setValidator(new QIntValidator(0,99999999,this));
ui->GSM_4->setValidator(new QIntValidator(0,99999999,this));
ui->GSM_5->setValidator(new QIntValidator(0,99999999,this));
ui->mail->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0-9_@.]{0,64}"), this ));
ui->mail_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0-9_@.]{0,64}"), this ));
ui->nom->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0]{0,10}"), this ));
    ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_pushButtonAjouter_4_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int code=ui->code->text().toInt();
    QString nom=ui->nom->text();
     QString adresse=ui->adresse->text();
     int code_fc=ui->code_fc->text().toInt();
      QDate date_fc=ui->dateEdit->date();
       int GSM=ui->GSM_4->text().toInt();
       QString mail=ui->mail->text();
       QString modep=ui->modecomboBox->currentText();

       Fournisseur F(code,nom,adresse,code_fc,date_fc, GSM, mail,modep);
       if(code<=0||nom.isEmpty() || adresse.isEmpty() || mail.isEmpty() ||modep.isEmpty())
                                {
                                    QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides Pour continuez."),QMessageBox::Cancel);
                                }
       else
       {
   bool test=F.ajouter();
   QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");//declaration d'un fichier
           if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
               return;

           QTextStream cout(&file);
   if(test)
   {

       QString message2="Vous avez ajouté un fournisseur\n";
           cout << message2;
           QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");
          if (!file.open(QIODevice::ReadOnly))
          {
              QMessageBox::information(0,"info",file.errorString());
          }
          QTextStream in (&file);
         ui->textBrowser_8->setText(in.readAll());
       ui->tableView->setModel(f.afficher());//rafraishissement
       QMessageBox::information(nullptr, QObject::tr("Ajout effectué"),
                   QObject::tr("successful.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Ajout non effectué"),
                   QObject::tr("failed.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }
   }



void MainWindow::on_pushButtonSupprimer_4_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
  int  code=ui->codecomboBox_2->currentText().toInt();
    bool test=f.supprimer(code);
    QMessageBox msgBox;
    QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");//declaration d'un fichier
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
    if(test)
    {

        QString message2="Vous avez supprimé un fournisseur\n";
            cout << message2;
            QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::information(0,"info",file.errorString());
           }
           QTextStream in (&file);
          ui->textBrowser_8->setText(in.readAll());
        ui->tableView->setModel(f.afficher());//rafraishissement
        QMessageBox::information(nullptr, QObject::tr("Suppression effectué"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Suppression non effectué"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }






void MainWindow::on_pushButtonModifier_4_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int code=ui->codecomboBox_2->currentText().toInt();
    QString nom=ui->nom->text();
     QString adresse=ui->adresse2->text();
     int code_fc=ui->code_fc->text().toInt();
       QDate date_fc=ui->dateEdit->date();
       int GSM=ui->GSM2->text().toInt();
       QString mail=ui->mail2->text();
       QString modep=ui->modecomboBox->currentText();

    Fournisseur F(code,nom,adresse,code_fc,date_fc, GSM, mail,modep);
bool test=F.modifier(code);
QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");//declaration d'un fichier
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file);
if(test)
{

    QString message2="Vous avez modifié un fournisseur\n";
        cout << message2;
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser_8->setText(in.readAll());
    ui->tableView->setModel(f.afficher());//rafraishissement
    QMessageBox::information(nullptr, QObject::tr("modification effectué"),
                QObject::tr("successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modification non effectué"),
                QObject::tr("failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButtonAfficher_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
     ui->tableView->setModel(f.afficher());
     QSqlQueryModel * model= new QSqlQueryModel;
                          model->setQuery("SELECT code FROM Fournisseur");
                      ui->codecomboBox->setModel(model);
                      ui->codecomboBox_2->setModel(model);
}




void MainWindow::on_radioButton_croissant_4_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
   ui->tableView->setModel(f.tri());
}

void MainWindow::on_radioButton_decroissant_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
ui->tableView->setModel(f.trid());
}

void MainWindow::on_pushButtonChercher_4_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    Fournisseur F;

              QString nom=ui->chercher->text();

              ui->tableView->setModel(F.recherche(nom));
}


 /* void MainWindow::on_pushButton_imprimer_clicked()
    {
    QString strStream;
                  QTextStream out(&strStream);

                  const int rowCount = ui->tableView->model()->rowCount();
                  const int columnCount = ui->tableView->model()->columnCount();
                  QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                  out <<"<html>\n"
                        "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                      << "<title> LISTE DES FORMATIONS<title>\n "
                      << "</head>\n"
                      "<body bgcolor=#ffffff link=#5000A0>\n"
                      "<h1 style=\"text-align: center;\"><strong> ***LISTE DES FORRMATIONS *** "+TT+"</strong></h1>"
                      "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                        "</br> </br>";
                  // headers
                  out << "<thead><tr bgcolor=#d6e5ff>";
                  for (int column = 0; column < columnCount; column++)
                      if (!ui->tableView->isColumnHidden(column))
                          out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                  out << "</tr></thead>\n";

                  // data table
                  for (int row = 0; row < rowCount; row++) {
                      out << "<tr>";
                      for (int column = 0; column < columnCount; column++) {
                          if (!ui->tableView->isColumnHidden(column)) {
                              QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                              out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                          }
                      }
                      out << "</tr>\n";
                  }
                  out <<  "</table>\n"
                      "</body>\n"
                      "</html>\n";

                  QTextDocument *document = new QTextDocument();
                  document->setHtml(strStream);

                  QPrinter printer;

                  QPrintDialog *test = new QPrintDialog(&printer, NULL);
                  if (test->exec() == QDialog::Accepted) {
                      document->print(&printer);
                  }

                  delete document;

} */

void MainWindow::on_SelectFileButton_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString fileContent;

      QString filename= QFileDialog::getOpenFileName(this, "Choose File");


     if(filename.isEmpty())
         return;

     QFile file(filename);

     if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
         return;

     QTextStream in(&file);

     fileContent= in.readAll();

     file.close();

     ui->textEdit->clear();
     ui->textEdit->setPlainText(fileContent);
}

void MainWindow::on_pushButton_imprimer_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tableView->model()->rowCount();
        const int columnCount = ui->tableView->model()->columnCount();
                        QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                        out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("strTitle")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                           //     "<align='right'> " << datefich << "</align>"



                            "<center> <H1>Liste des Fournisseurs "+TT+" </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                        out << "<thead><tr bgcolor=#FF2E01> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                           if (!ui->tableView->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->tableView->isColumnHidden(column)) {
                                    QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));


                                }
                            }
                            out << "</tr>\n";
                        }
                        out <<  "</table> </center>\n";
    out << "<tr>\n"

                            "</body>\n"
                            "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
            QPrinter *printer=new  QPrinter(QPrinter::PrinterResolution);
            printer->setOutputFormat(QPrinter::PdfFormat);
            printer->setPaperSize(QPrinter::A4);
            printer->setOutputFileName(fileName);

            QTextDocument doc;
            doc.setHtml(strStream);
            doc.setPageSize(printer->pageRect().size()); // This is necessary if you want to hide the page number
            doc.print(printer);

            QPrinter *p=new QPrinter();
            QPrintDialog dialog(p,this);
            if(dialog.exec()== QDialog::Rejected)
            {
                return;
            }


    }

void MainWindow::on_pushButton_8_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_6->setCurrentIndex(1);
}


 /*ENGLISH §§§§§*/


void MainWindow::on_pushButtonAjouter_5_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int code_2=ui->code_2->text().toInt();
    QString nom_2=ui->nom_2->text();
     QString adresse_2=ui->adresse_2->text();
     int code_fc_2=ui->code_fc_2->text().toInt();
      QDate date_fc_2=ui->dateEdit_2->date();
       int GSM_5=ui->GSM_5->text().toInt();
       QString mail_2=ui->mail_2->text();
       QString modep=ui->modecomboBox_2->currentText();

       Fournisseur F(code_2,nom_2,adresse_2,code_fc_2,date_fc_2, GSM_5, mail_2,modep);
       if(code_2<=0||nom_2.isEmpty() || adresse_2.isEmpty() || mail_2.isEmpty() ||modep.isEmpty())
                                {
                                    QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("veillez remplir les champs vides Pour continuez."),QMessageBox::Cancel);
                                }
       else
       {
   bool test=F.ajouter();
   QFile file("C:/Users/hp/Desktop/Atelier_Connexion/Historique.txt");//declaration d'un fichier
           if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
               return;

           QTextStream cout(&file);
   if(test)
   {

       QString message2="Vous avez ajouté un fournisseur\n";
           cout << message2;
           QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");
          if (!file.open(QIODevice::ReadOnly))
          {
              QMessageBox::information(0,"info",file.errorString());
          }
          QTextStream in (&file);
         ui->textBrowser_9->setText(in.readAll());
       ui->tableView->setModel(f.afficher());//rafraishissement
       QMessageBox::information(nullptr, QObject::tr("Ajout effectué"),
                   QObject::tr("successful.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Ajout non effectué"),
                   QObject::tr("failed.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }
}



void MainWindow::on_pushButtonModifier_5_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int code_2=ui->code_2->text().toInt();
    QString nom_2=ui->nom_2->text();
     QString adresse_2=ui->adresse_2->text();
     int code_fc_2=ui->code_fc_2->text().toInt();
      QDate date_fc_2=ui->dateEdit_2->date();
       int GSM_5=ui->GSM_5->text().toInt();
       QString mail_2=ui->mail_2->text();
       QString modep=ui->modecomboBox_2->currentText();

       Fournisseur F(code_2,nom_2,adresse_2,code_fc_2,date_fc_2, GSM_5, mail_2,modep);

bool test=F.modifier(code_2);
QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");//declaration d'un fichier
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file);
if(test)
{

    QString message2="Vous avez modifié un fournisseur\n";
        cout << message2;
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");
       if (!file.open(QIODevice::ReadOnly))
       {
           QMessageBox::information(0,"info",file.errorString());
       }
       QTextStream in (&file);
      ui->textBrowser_9->setText(in.readAll());
    ui->tableView->setModel(f.afficher());//rafraishissement
    QMessageBox::information(nullptr, QObject::tr("modification effectué"),
                QObject::tr("successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modification non effectué"),
                QObject::tr("failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButtonSupprimer_5_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int  code_2=ui->codecomboBox_4->currentText().toInt();
      bool test=f.supprimer(code_2);
      QMessageBox msgBox;
      QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");//declaration d'un fichier
              if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                  return;

              QTextStream cout(&file);
      if(test)
      {

          QString message2="Vous avez supprimé un fournisseur\n";
              cout << message2;
              QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/HistoriqueF.txt");
             if (!file.open(QIODevice::ReadOnly))
             {
                 QMessageBox::information(0,"info",file.errorString());
             }
             QTextStream in (&file);
            ui->textBrowser_9->setText(in.readAll());
          ui->tableView_2->setModel(f.afficher());//rafraishissement
          QMessageBox::information(nullptr, QObject::tr("Suppression effectué"),
                      QObject::tr("successful.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      else
          QMessageBox::critical(nullptr, QObject::tr("Suppression non effectué"),
                      QObject::tr("failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButtonAfficher_3_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->tableView_2->setModel(f.afficher());
    QSqlQueryModel * model= new QSqlQueryModel;
                         model->setQuery("SELECT code FROM Fournisseur");
                     ui->modecomboBox_2->setModel(model);
                     ui->codecomboBox_4->setModel(model);
}

void MainWindow::on_pushButtonChercher_5_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    Fournisseur F;

              QString code_2=ui->chercher_2->text();

              ui->tableView_2->setModel(F.recherche(code_2));
}


void MainWindow::on_pushButton_17_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_6->setCurrentIndex(2);
}

void MainWindow::on_pushButton_19_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_6->setCurrentIndex(0);
}

void MainWindow::on_pushButton_18_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget_6->setCurrentIndex(0);
}

void MainWindow::on_pushButton_20_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(0);
}




//----------------------------------------------------------------------Visiteurs-------------------------------------------
void MainWindow::on_ajouter_10_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString type=ui->type->currentText();
    QString prenom=ui->le_prenom->text();
    QString nom=ui->le_nom->text();
    int age=ui->le_age->text().toInt();
    int cin=ui->le_cin->text().toInt();
    int tel=ui->le_tel->text().toInt();
Visiteur V(type,prenom,nom,age,cin,tel);
bool test=V.ajouter();
QMessageBox msgBox;
if (test)
   { msgBox.setText("Ajout avec succes.");
ui->tab_vis->setModel(v.afficher());}
else
    msgBox.setText("Echec d'ajout.");
    msgBox.exec();
}

void MainWindow::on_supprimer_10_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
Visiteur V1; V1.setcin(ui->le_cin_a_supp->text().toInt());
bool test=V1.supprimer(V1.getcin());
QMessageBox msgBox;
if (test)
   { msgBox.setText("Suppression avec succes.");
ui->tab_vis->setModel(v.afficher());}
else
    msgBox.setText("Echec de la suppression .");
    msgBox.exec();
}

void MainWindow::on_modifier_10_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString type=ui->type->currentText();
    QString prenom= ui->prenom->text();
    QString nom= ui->nom->text();
    int age = ui->age ->text().toInt();
    int cin = ui->cin ->text().toInt();
    int tel = ui->tel ->text().toInt();
    Visiteur V(type,prenom,nom,age,cin,tel);
      bool test=v.modifier(type,prenom,nom,age,cin,tel);
      if (test)
      {
             ui->tab_vis->setModel(v.afficher());
          QMessageBox :: information (nullptr, QObject ::tr("OK"),
                       QObject ::tr("modifier effectué\n"
                                    "click cancel to exit"),
                  QMessageBox:: Cancel);

  }
      else
      {
          QMessageBox::critical(nullptr,QObject::tr("not ok"),
                               QObject::tr("try again.\n"
                                           "click cancel to exit."),QMessageBox::Cancel);
      }
}


void MainWindow::on_tri_10_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
     ui->tab_vis->setModel(v.tri());
}


void MainWindow::on_recherche_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
           QString rech=ui->rechcin->text();
             bool test=v.recherche(rech);
             QMessageBox msgBox;
             if (test)
              { msgBox.setText("exist .");
              ui->tab_vis->setModel(v.recherche(rech));}
             else
                 msgBox.setText(" not exist .");
                 msgBox.exec();

}



void MainWindow::on_stat_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from VISITEUR where TYPE='BEBE' ");
         int v1=model->rowCount();
         model->setQuery("select * from VISITEUR where TYPE='ENFANT' ");
         int v2=model->rowCount();
         model->setQuery("select * from VISITEUR where TYPE='JEUNE' ");
         int v3=model->rowCount();
         model->setQuery("select * from VISITEUR where TYPE='ADULT' ");
         int v4=model->rowCount();
         int total=v1+v2+v3+v4;
         QString a = QString("BEBE "+QString::number((v1*100)/total,'f',2)+"%" );
         QString b = QString("ENFANT"+QString::number((v2*100)/total,'f',2)+"%" );
         QString c = QString("JEUNE"+QString::number((v3*100)/total,'f',2)+"%" );
         QString d = QString("ADULT"+QString::number((v4*100)/total,'f',2)+"%" );
         QPieSeries *series = new QPieSeries();
         series->append(a,v1);
         series->append(b,v2);
         series->append(c,v3);
         series->append(d,v4);
         if (v1!= 0)
         {
             QPieSlice *slice = series->slices().at(0);
             slice->setLabelVisible();
             slice->setPen(QPen());
         }
         if (v2!=0)
         {
                  // Add label, explode and define brush for 2nd slice
                  QPieSlice *slice1 = series->slices().at(1);
                  //slice1->setExploded();
                  slice1->setLabelVisible();
         }
         if(v3!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice2 = series->slices().at(2);
                  //slice1->setExploded();
                  slice2->setLabelVisible();
         }
         if(v4!=0)
         {
                  // Add labels to rest of slices
                  QPieSlice *slice3 = series->slices().at(3);
                  //slice1->setExploded();
                  slice3->setLabelVisible();
         }
                 // Create the chart widget
                 QChart *chart = new QChart();
                 // Add data to chart with title and hide legend
                 chart->addSeries(series);
                 chart->setTitle("pourcentage des visiteurs "+ QString::number(total));
                 chart->legend()->hide();
                 // Used to display the chart
                 QChartView *chartView = new QChartView(chart);
                 chartView->setRenderHint(QPainter::Antialiasing);
                 chartView->resize(1000,500);
                 chartView->show();
}



void MainWindow::on_vis_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_21_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(0);
}


//theme--------------------------------------------------------------------
void MainWindow::on_Applytheme_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");


    QString item;
        item=ui->listheme->currentItem()->text();
        if(item=="Midnight Sky")
        {
            QFile file("C:\\Users\\aymen\\OneDrive\\Documents\\gestion_recrutement2\\stylesheets\\Takezo.qss");
            file.open(QFile::ReadOnly);
            QString styleSheet = QLatin1String(file.readAll());
            //MainWindow.setStyleSheet(styl);
            qApp->setStyleSheet(styleSheet);
        }
        if(item=="Summer Citrus")
        {
            QFile file("C:\\Users\\aymen\\OneDrive\\Documents\\gestion_recrutement2\\stylesheets\\Irrorater.qss");
            file.open(QFile::ReadOnly);
            QString styleSheet = QLatin1String(file.readAll());
            //MainWindow.setStyleSheet(styl);
            qApp->setStyleSheet(styleSheet);
        }
        if(item=="Hackerman")
        {
            QFile file("C:\\Users\\aymen\\OneDrive\\Documents\\gestion_recrutement2\\stylesheets\\Hookmark.qss");
            file.open(QFile::ReadOnly);
            QString styleSheet = QLatin1String(file.readAll());
            //MainWindow.setStyleSheet(styl);
            qApp->setStyleSheet(styleSheet);
        }
        if(item=="Violet")
        {
            QFile file("C:\\Users\\aymen\\OneDrive\\Documents\\gestion_recrutement2\\stylesheets\\Wstartpage.qss");
            file.open(QFile::ReadOnly);
            QString styleSheet = QLatin1String(file.readAll());
            //MainWindow.setStyleSheet(styl);
            qApp->setStyleSheet(styleSheet);
        }
        if(item=="Dark")
        {
            QFile file("C:\\Users\\aymen\\OneDrive\\Documents\\gestion_recrutement2\\stylesheets\\Combinear.qss");
            file.open(QFile::ReadOnly);
            QString styleSheet = QLatin1String(file.readAll());
            //MainWindow.setStyleSheet(styl);
            qApp->setStyleSheet(styleSheet);
        }


}











































void MainWindow::on_cancel_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_theme_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(5);
}


//---------------------------------------------------------------------------Empl--------------------------------------

void MainWindow::on_emp_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_ajouter_8_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    //recuperation des informtions
    QString cin=ui->lineEdit_ID->text();
    //
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString role=ui->lineEdit_fonction->text();
    QString datedenaissance=ui->lineEdit_datedenaissance->text();
    staff S(cin,nom,prenom,role,datedenaissance);

    bool test1=S.ajouter();
    //cin=ui->tableView->selectionBehavior();
   // bool test2=S.supprimer(cin);
   // bool test2=S.supprimer(ui->tableView->selectionBehavior());
    if (test1) //si requete executée ==>QMessageBox::information
    {


        ui->tableView->setModel(S.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout avec succes .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("insert failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_supprimer_8_clicked()
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    //int cin =ui->lineEdit_2->text().toInt ;
      QString cin=ui->lineEdit_17->text();
    bool test =s.supprimer(cin);
    if (test)
    {
        ui->tab_staff->setModel(s.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer"),
                                 QObject::tr("suppression avec succes .\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                 }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("supprimer"),
                                 QObject::tr("delete failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_modifier_8_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    staff S ;
  QString cin=ui->lineedit_iden->text();
 QString nom=ui->lineEdit_NOM->text();
 QString prenom=ui->lineEdit_PRENOM->text();
 QString role=ui->lineEdit_FONCTION->text();
 QString date_naissance=ui->lineEdit_DATE->text();
 staff S1(cin,nom,prenom,role,date_naissance);
 //bool test= S.modifier(id,nom,prenom,fonction,date_naissance);
  bool test;
  test= S1.modifier( cin , nom, prenom,role, date_naissance);
 if (test)
     //[☺]
    {
     ui->tableView->setModel(S1.afficher());
     QMessageBox::information(nullptr, QObject::tr("MODIFIER"),
                                   QObject::tr("MODIFICATION avec succes .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

     }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                                   QObject::tr("UPDATE failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_tableView_activated(const QModelIndex &index)
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString val=ui->tableView->model()->data(index).toString();

    QSqlQuery qry ;



     qry.prepare("SELECT nom, prenom , cin , role , date_naissance FROM staf");
    if (qry.exec())
    {


       QMessageBox::information(nullptr, QObject::tr("select"),
                    QObject::tr("selection avec succes .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("error"),
                    QObject::tr("select failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void MainWindow::on_pushButton_trier_8_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
   staff *f = new staff();
           ui->tab_staff->setModel(f->tri());
}













void MainWindow::on_rechercher_pushButton_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString rech =ui->lineEdit_3->text();
           ui->tab_staff->setModel(s.rechercher(rech));
}

//-------------------------------------LOGIN------------------------------------
void MainWindow::on_Login_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if((ui->loginLineEdit_2->text()=="aymen")&&(ui->motDePasseLineEdit_2->text()=="esprit"))
    {
        ui->tab_candidat_2->setModel(Etmp.afficher());
        ui->tab_candidat->setModel(Etmp.afficher());
        ui->tab_candidat_3->setModel(Etmp.afficher());
        QFile file("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Historique.txt");
          file.open(QIODevice::ReadOnly);
        QTextStream in (&file);
    ui->textBrowser_4->setText(in.readAll());
    ui->textBrowser_6->setText(in.readAll());
    ui->textBrowser->setText(in.readAll());
    ui->stackedWidget->setCurrentIndex(1);

    }
    if ((ui->loginLineEdit_2->text()=="eya")&&(ui->motDePasseLineEdit_2->text()=="esprit"))
        ui->stackedWidget->setCurrentIndex(3);
    if ((ui->loginLineEdit_2->text()=="ghaith")&&(ui->motDePasseLineEdit_2->text()=="esprit")){
        ui->spcombo1_2->setModel(sp.affichercombo());
        ui->spcombo1_4->setModel(sp.affichercombo());
        ui->tablesp->setModel(sp.afficher());
        ui->affc->setModel(c.afficher());
        ui->spcombo1->setModel(sp.affichercombo());
        ui->spcombo2->setModel(sp.affichercombo());
        ui->ids->setModel(sp.affichercombo());
        ui->ids_2->setModel(sp.affichercombo());
        QSqlQueryModel* model=new QSqlQueryModel();
        QSqlQueryModel* model1=new QSqlQueryModel();
        QSqlQueryModel* model2=new QSqlQueryModel();
        model->setQuery( "select SPONSORS_SEQ.nextval from dual ");
         QSqlQuery query(" ALTER SEQUENCE SPONSORS_SEQ INCREMENT BY -1");
        model->setQuery( "select SPONSORS_SEQ.nextval from dual ");
           ui->idsp->setText(QString :: number((model->data(model->index(0,0)).toInt())+1));
        QSqlQuery query1 (" ALTER SEQUENCE SPONSORS_SEQ INCREMENT BY 1");
        model1->setQuery( "select SOUTIEN_SEQ.nextval from dual ");
        QSqlQuery query2(" ALTER SEQUENCE SOUTIEN_SEQ INCREMENT BY -1");
        model1->setQuery( "select SOUTIEN_SEQ.nextval from dual ");
           ui->idsp_2->setText(QString :: number((model1->data(model1->index(0,0)).toInt())+1));
         QSqlQuery query3 (" ALTER SEQUENCE SOUTIEN_SEQ INCREMENT BY 1");
        model2->setQuery( "select EVENEMENT_SEQ.nextval from dual ");
        QSqlQuery query4(" ALTER SEQUENCE EVENEMENT_SEQ INCREMENT BY -1");
        model2->setQuery( "select EVENEMENT_SEQ.nextval from dual ");
           ui->idsp_3->setText(QString :: number((model2->data(model2->index(0,0)).toInt())+1));
        QSqlQuery query5 (" ALTER SEQUENCE EVENEMENT_SEQ INCREMENT BY 1");
        QSqlQueryModel* model6=new QSqlQueryModel();
        model6->setQuery( "select CONTACT_SEQ.nextval from dual ");
         QSqlQuery query6(" ALTER SEQUENCE CONTACT_SEQ INCREMENT BY -1");
        model6->setQuery( "select CONTACT_SEQ.nextval from dual ");
           ui->numcontact->setText(QString :: number((model6->data(model6->index(0,0)).toInt())+1));
        QSqlQuery query7 (" ALTER SEQUENCE CONTACT_SEQ INCREMENT BY 1");
        ui->textBrowser_7->setFontPointSize(14);

        ui->modifs->hide();
        ui->mod->hide();
        ui->modifsp->hide();
        ui->modife->hide();
        ui->modifc->hide();ui->ids_2->hide();ui->postec_2->hide();
        QFile file1("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/historique1.txt");
            if(!file1.open(QIODevice::ReadOnly))
        {
                qCritical()<<"could not open file";
                qCritical()<<file1.errorString();

        }
            QTextStream stream1(&file1);

        ui->textBrowser_7->setText(stream1.readAll());
        file1.close();




        QSystemTrayIcon *notif=new  (QSystemTrayIcon);
        QSqlQueryModel* model9=new QSqlQueryModel();QSqlQuery query9;QDate q1;
        query9.prepare("SELECT * FROM EVENEMENT  where DATE_EVENEMENT > :date ORDER BY DATE_EVENEMENT ASC");
        query9.bindValue(":date",q1.currentDate());
        query9.exec();
        model9->setQuery(query9);

        if(model9->data(model9->index(0,3))!=NULL){notif->setVisible(true);
            notif->showMessage("notification","l'evenement prochain est le :"+model9->data(model9->index(0,3)).toString());}
        else {notif->setVisible(true);
            notif->showMessage("notification","il ny'a pas d'eveenemt prochain");}
        A.connect_arduinosp();
             QObject::connect(A.getserialsp(),SIGNAL(readyRead()),this,SLOT(update()));
        f11.insert(0,a11);f11.insert(1,a12);f11.insert(2,a13);
        f12.insert(0,a21);f12.insert(1,a22);f12.insert(2,a23);
        f13.insert(0,a31);f13.insert(1,a32);f13.insert(2,a33);
        f21.insert(0,b11);f21.insert(1,b12);f21.insert(2,b13);
        f22.insert(0,b21);f22.insert(1,b22);f22.insert(2,b23);
        f23.insert(0,b31);f23.insert(1,b32);f23.insert(2,b33);
        f31.insert(0,c11);f31.insert(1,c12);f31.insert(2,c13);
        f32.insert(0,c21);f32.insert(1,c22);f32.insert(2,c23);
        f33.insert(0,c31);f33.insert(1,c32);f33.insert(2,c33);
        f1.insert(0,f11);f1.insert(1,f12);f1.insert(2,f13);
        f2.insert(0,f21);f2.insert(1,f22);f2.insert(2,f23);
        f3.insert(0,f31);f3.insert(1,f32);f3.insert(2,f33);
        ff.insert(0,f1);ff.insert(1,f2);ff.insert(2,f3);

        ui->pub->setMovie(initiale);
        initiale->start();
        ui->stackedWidget->setCurrentIndex(2);}
    if ((ui->loginLineEdit_2->text()=="sami")&&(ui->motDePasseLineEdit_2->text()=="esprit")){
        ui->stackedWidget->setCurrentIndex(8);
    ui->tableView_5->setModel(E.afficher());}
    if ((ui->loginLineEdit_2->text()=="ranim")&&(ui->motDePasseLineEdit_2->text()=="esprit"))
        ui->stackedWidget->setCurrentIndex(6);
    if ((ui->loginLineEdit_2->text()=="ahmed")&&(ui->motDePasseLineEdit_2->text()=="esprit"))
        ui->stackedWidget->setCurrentIndex(4);
    //login cas chef de service
    if ((ui->loginLineEdit_2->text()=="chefservice")&&(ui->motDePasseLineEdit_2->text()=="esprit"))
    {

         ui->stackedWidget->setCurrentIndex(0);
    }


}

void MainWindow::on_decon_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_decon_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_decon_3_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_decon_4_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_decon_5_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_decon_6_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_resetlogin_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->loginLineEdit_2->clear();
    ui->motDePasseLineEdit_2->clear();
}



//-----------------------------SAMI---------------------






void MainWindow::on_pushButton_25_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int code=ui->code_4->text().toInt();
    int etat=ui->etat_2->text().toInt();
    QString adresse =ui->adresse_4->text();
    int tarif=ui->tarif_2->text().toInt();
     int remise=ui->remise_2->text().toInt();

    equipement E(code,etat,adresse,tarif,remise);



    bool test=E.ajouter();
    QMessageBox msgBox;

    if (test)
       { msgBox.setText("Ajout avec succes.");
         ui->tableView->setModel(E.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();

}

//modifier
void MainWindow::on_modif_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    int code=ui->code_4->text().toInt();
    int etat=ui->etat_2->text().toInt();
    QString adresse =ui->adresse_4->text();
    int tarif=ui->tarif_2->text().toInt();
     int remise=ui->remise_2->text().toInt();

QMessageBox msgBox;
    bool test=E.modifier(code,etat,adresse,tarif,remise);
    if (test)
        msgBox.setText("modification avec succes.");
    else
        msgBox.setText("Echec de modification");
        msgBox.exec();
    ui->tableView_5->setModel(E.afficher());
}

//supprimer

void MainWindow::on_pb_supprimer_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    equipement E1;
    E1.setcode(ui->code_4->text().toInt());
    bool test=E1.supprimer(E1.getcode());

    QMessageBox msgBox;

    if (test)
        msgBox.setText("Suppression avec succes.");
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
        ui->tableView_5->setModel(E1.afficher());
}

//afficher
void MainWindow::on_tableView_5_activated(const QModelIndex &index)
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString val=ui->tableView_5->model()->data(index).toString();
    QSqlQuery qry;
       qry.prepare("SELECT * from EQUIPEMENT where CODE_EQ='"+val+"' ");
       if(qry.exec())
       {
           while(qry.next())
           {


               ui->code_4->setText(qry.value(0).toString());
               ui->etat_2->setText(qry.value(1).toString());
               ui->adresse_4->setText(qry.value(2).toString());
               ui->tarif_2->setText(qry.value(3).toString());
               ui->remise_2->setText(qry.value(4).toString());
           }
       }
       ui->code->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString());
}

//rechercher

void MainWindow::on_rechercher_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString choix;
            choix=ui->li_rechercher_2->text();
            QString li_rechercher=ui->li_rechercher_2->text();
            ui->tableView->setModel(E.chercher_eq(li_rechercher));
}



//pdf

void MainWindow::on_PDF_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString strStream;
            QTextStream out(&strStream);
                            const int rowCount = ui->tableView_5->model()->rowCount();
                            const int columnCount = ui->tableView_5->model()->columnCount();
                            QString TT = QDate::currentDate().toString("yyyy/MM/dd");



                            out <<  "<html>\n"
                                "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                <<  QString("<title>%1</title>\n").arg("strTitle")
                                <<  "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                    "<h1 style=\"text-align: center;\">"
                                    "<strong>                                                      "+TT+" </ strong>"


                               //     "<align='right'> " << datefich << "</align>"
                                    "<img src='C:/Users/muham/Desktop/smart_park/smart_park/logo.png' width='100' height='100'>\n"
                                "<center> <H1> Liste des equipement </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";


                            // headers
                            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tableView->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tableView_5->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tableView->isColumnHidden(column)) {
                                        QString data = ui->tableView->model()->data(ui->tableView_5->model()->index(row, column)).toString().simplified();
                                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                    }
                                }
                                out << "</tr>\n";
                            }
                            out <<  "</table> </center>\n"
                                "</body>\n"
                                "</html>\n";


                            QTextDocument *document = new QTextDocument();
                            document->setHtml(strStream);
                            QPrinter printer;

                            QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                            if (dialog->exec() == QDialog::Accepted) {
                                document->print(&printer);
                            }


                            delete document;
}

void MainWindow::on_ASC_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
     ui->tableView_5->setModel(TMP.tri_tarif_asc());
}

void MainWindow::on_DESC_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
      ui->tableView_5->setModel(TMP.tri_tarif_desc());
}



void  MainWindow::browse_2()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    //files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file_3->setText( fileListString );

}


void   MainWindow::sendMail_2()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    Smtp* smtp = new Smtp("sami.ghorbal@esprit.tn",ui->mail_pass_3->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("sami.ghorbal@esprit.tn", ui->rcpt_3->text() , ui->subject_3->text(),ui->msg_3->toPlainText(), files );
    else
        smtp->sendMail("sami.ghorbal@esprit.tn", ui->rcpt_3->text() , ui->subject_3->text(),ui->msg_3->toPlainText());
}
void   MainWindow::mailSent_2(QString status)
{
QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt_3->clear();
    ui->subject_3->clear();
    ui->file_3->clear();
    ui->msg_3->clear();
    ui->mail_pass_3->clear();
}



void MainWindow::on_qr_2_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if(ui->tableView->currentIndex().row()==-1)
                   QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                            QObject::tr("Veuillez Choisir un animal du Tableau.\n"
                                                        "Click Ok to exit."), QMessageBox::Ok);
               else
               {

                    int  Code=ui->tableView_5->model()->data(ui->tableView_5->model()->index(ui->tableView_5->currentIndex().row(),0)).toInt();
                    const QrCode qr = QrCode::encodeText(std::to_string(Code).c_str(), QrCode::Ecc::LOW);
                    std::ofstream myfile;
                    myfile.open ("qrcode.svg") ;
                    myfile << qr.toSvgString(1);
                    myfile.close();
                    QSvgRenderer svgRenderer(QString("qrcode.svg"));
                    QPixmap pix( QSize(90, 90) );
                    QPainter pixPainter( &pix );
                    svgRenderer.render( &pixPainter );
                    ui->QRCODE_4->setPixmap(pix);
               }
}

void MainWindow::on_pushButton_27_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    app=new CToDoList();
    app->show();

}


void MainWindow::on_decon_7_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(7);
}



/*void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
playerm->setPosition(position);
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
playerm->setVolume(position);
}

void MainWindow::on_start_clicked()
{
   playerm->setMedia(QUrl::fromLocalFile("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Harry Potter Theme Song.wav"));
   playerm->play();
   qDebug()<< playerm ->errorString();
}

void MainWindow::on_stop_clicked()
{
  playerm->stop();
}

void MainWindow::on_positionChanged(qint64 position)
{

ui->horizontalSlider->setValue(position);
}

void MainWindow::on_durationChanged(qint64 position)
{
ui->horizontalSlider_2->setMaximum(position);

}*/

void MainWindow::on_theme_2_clicked()//parametre
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_22_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_MuteMedia_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    if(ui->MuteMedia->text()=="Mute")
    {
        mMediaPlayer->setMuted(true);
        ui->MuteMedia->setText("Unmute");
        ui->MuteMedia->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/audio"));
    }else{
        mMediaPlayer->setMuted(false);
        ui->MuteMedia->setText("Mute");
        ui->MuteMedia->setIcon(QIcon("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/mute"));
    }

}

void MainWindow::on_StopMedia_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    mMediaPlayer->stop();
}

void MainWindow::on_PauseMedia_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    mMediaPlayer->pause();
}

void MainWindow::on_PlayMedia_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    mMediaPlayer->play();
}


void MainWindow::on_VolumeMediaControl_valueChanged(int value)
{
    ui->VolumeMediaDisplay->setValue(value);
    mMediaPlayer->setVolume(value);

}

void MainWindow::on_OpenMedia_clicked()
{QSound::play("C:/Users/aymen/OneDrive/Documents/gestion_recrutement2/Magic Mouse Click Sound Effect.wav");
    QString filename = QFileDialog::getOpenFileName(this,"OpenMedia");
    if(filename.isEmpty())
    {
        return;
    }
    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mMediaPlayer->setVolume(ui->VolumeMediaControl->value());
    on_PlayMedia_clicked();
}


void MainWindow::on_suiv_clicked()
{
    A.write_to_arduinosp( "c" );
    if(controle2>0){controle2--;}
    ui->pub->clear();
    ui->pub->setMovie(ff.value(controle1).value(controle2).value(controle3));
    ff.value(controle1).value(controle2).value(controle3)->start();
}

void MainWindow::on_pred_clicked()
{
    A.write_to_arduinosp( "d" );
    if(controle2<2){controle2++;}
    ui->pub->clear();
    ui->pub->setMovie(ff.value(controle1).value(controle2).value(controle3));
    ff.value(controle1).value(controle2).value(controle3)->start();
}

void MainWindow::on_motpred_clicked()
{
       A.write_to_arduinosp( "a" );
       if(controle3>0){controle3--;}
       ui->pub->clear();
       ui->pub->setMovie(ff.value(controle1).value(controle2).value(controle3));
       ff.value(controle1).value(controle2).value(controle3)->start();
}

void MainWindow::on_modsuiv_clicked()
{
           A.write_to_arduinosp( "b" );
           if(controle3<2){controle3++;}
           ui->pub->clear();
           ui->pub->setMovie(ff.value(controle1).value(controle2).value(controle3));
           ff.value(controle1).value(controle2).value(controle3)->start();
}
void MainWindow::update()
{
 data=A.read_from_arduinosp();
 if((data=="a")||(data=="b")){if((data=="a"||controle2<2||controle3<2)){controle2++;controle3++;}else if((data=="b"||controle2>0||controle3>0)){controle2--;controle3--;}
 }
 else{
 QSqlQuery query;QSqlQueryModel* model=new QSqlQueryModel();
  query.prepare("SELECT NOM_SPONSOR FROM sponsors  where ID_SPON= :IDO ");
  query.bindValue(":IDO", data.toInt());
 query.exec();
  model->setQuery(query);
  if(model->data(model->index(0,0)).toString()=="coca cola"){A.write_to_arduinosp( "1" );controle1=0;ui->idp->setText(data);ui->nmp->setText("coca cola");}
    else if(model->data(model->index(0,0)).toString()=="bolt"){A.write_to_arduinosp( "2" );controle1=1;ui->idp->setText(data);ui->nmp->setText("bolt");}
     else if(model->data(model->index(0,0)).toString()=="asus"){A.write_to_arduinosp( "3" );controle1=2;ui->idp->setText(data);ui->nmp->setText("asus");}}
 ui->pub->clear();
 ui->pub->setMovie(ff.value(controle1).value(controle2).value(controle3));
 ff.value(controle1).value(controle2).value(controle3)->start();
}

