QT       += core gui sql charts serialport
QT += charts

QT += pdf
QT += core gui sql charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# SOURCES
SOURCES += \
    connection.cpp \
    employes.cpp \
    gestiontaches.cpp \
    main.cpp \
    mainwindow.cpp \
    tache.cpp

# HEADERS
HEADERS += \
    connection.h \
    employes.h \
    gestiontaches.h \
    mainwindow.h \
    tache.h

# Fichier d'interface graphique (UI)
FORMS += \
    mainwindow.ui

# Définir les modules Qt Charts et SerialPort explicitement
QT_CONFIG += charts serialport

# Règles par défaut pour le déploiement
unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
