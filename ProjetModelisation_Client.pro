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

HEADERS += Arete.h
HEADERS += Erreur.h
HEADERS += GElement.h
HEADERS += Graphe.h
HEADERS += InfoArete.h
HEADERS += InfoSommet.h
HEADERS += PElement.h
HEADERS += Point2D.h
HEADERS += Sommet.h
HEADERS += TestUnitaire.h

SOURCES += main.cpp
SOURCES += GElement.cpp
SOURCES += InfoArete.cpp
SOURCES += InfoSommet.cpp
SOURCES += Point2D.cpp
