
QT       += core gui
QT       += core gui sql serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = supermarche
TEMPLATE = app

CONFIG += c++11

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
    arduino.cpp \
    arduino_capteur.cpp \
    arduino_tapis.cpp \
    arduinoo.cpp \
    caisses.cpp \
    caissevente.cpp \
    categorie.cpp \
    client.cpp \
    client_fidelite.cpp \
    cmdventes.cpp \
    commandes_achats.cpp \
    conge.cpp \
    connexion.cpp \
    dialog_new_caisse.cpp \
    dialog_update_caisse.cpp \
    fidelite.cpp \
    fournisseur.cpp \
    gestionfournisseurcmd.cpp \
    information.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp \
    prodcat.cpp \
    produit.cpp \
    tapis.cpp

HEADERS += \
    arduino.h \
    arduino_capteur.h \
    arduino_tapis.h \
    arduinoo.h \
    caisses.h \
    caissevente.h \
    categorie.h \
    client.h \
    client_fidelite.h \
    cmdventes.h \
    commandes_achats.h \
    conge.h \
    connexion.h \
    dialog_new_caisse.h \
    dialog_update_caisse.h \
    fidelite.h \
    fournisseur.h \
    gestionfournisseurcmd.h \
    information.h \
    mainwindow.h \
    personnel.h \
    prodcat.h \
    produit.h \
    tapis.h

FORMS += \
    arduino_capteur.ui \
    caissevente.ui \
    client_fidelite.ui \
    dialog_new_caisse.ui \
    dialog_update_caisse.ui \
    gestionfournisseurcmd.ui \
    mainwindow.ui \
    personnel.ui \
    prodcat.ui \
    tapis.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    res.qrc
