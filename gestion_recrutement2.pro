CONFIG += c++11
QT       += core gui sql

QT       += core gui  serialport
QT+=svg
QT += sql
CONFIG +=console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += datavisualization
QT += widgets
CONFIG += c++11
TARGET = LoginApp
TEMPLATE = app
QT       += core gui charts
QT       += core gui multimedia multimediawidgets
QT       += core gui network
QT       += core gui printsupport

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduinosp.cpp \
    candidats.cpp \
    connection.cpp \
    contact.cpp \
    equipement.cpp \
    evenement.cpp \
    fournisseur.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    qrcode.cpp \
    qrcodegeneratordemo.cpp \
    qrcodegeneratorworker.cpp \
    qrwidget.cpp \
    smtp.cpp \
    soutien.cpp \
    sponsors.cpp \
    staff.cpp \
    todolist.cpp \
    valider.cpp \
    visiteur.cpp

HEADERS += \
    arduinosp.h \
    candidats.h \
    connection.h \
    contact.h \
    equipement.h \
    evenement.h \
    fournisseur.h \
    graph.h \
    mainwindow.h \
    mainwindow2.h \
    qcustomplot.h \
    qrcode.h \
    qrwidget.h \
    smtp.h \
    soutien.h \
    sponsors.h \
    staff.h \
    todolist.h \
    valider.h \
    visiteur.h

FORMS += \
    mainwindow.ui
DISTFILES += \
    Historique


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Traduction.qrc

qtPrepareTool(LRELEASE, lrelease)
 for(tsfile, TRANSLATIONS) {
     qmfile = $$shadowed($$tsfile)
     qmfile ~= s,\\.ts$,.qm,
     qmdir = $$dirname(qmfile)
     !exists($$qmdir) {
         mkpath($$qmdir)|error("Aborting.")
     }
     command = $$LRELEASE -removeidentical $$tsfile -qm  $$qmfile
     system($$command)|error("Failed to run: $$command")
     TRANSLATIONS_FILES += $$qmfile
 }

QT += printsupport


