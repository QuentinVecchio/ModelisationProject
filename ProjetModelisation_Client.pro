#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T02:19:37
#
#-------------------------------------------------

QT       += core gui widgets
QT += widgets network
QT += xml
QT += qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetIA_Client
TEMPLATE = app

HEADERS += Arete.h \
    Fonctions.h \
    GElement.h \
    Graphe.h \
    InfoArete.h \
    InfoSommet.h \
    PElement.h \
    Sommet.h \
    TestUnitaire.h \
    InfoGraphe.h

SOURCES += main.cpp \
    GElement.cpp \
    InfoArete.cpp \
    InfoSommet.cpp \
    InfoGraphe.cpp
