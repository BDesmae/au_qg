#ifndef FEN_H
#define FEN_H

#include <QPushButton>
#include <QWidget>
#include <QSqlDatabase>
#include <QtSql>
#include <QApplication>
#include <iostream>
#include <string>
#include <QDialog>

class QGroupBox;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);

public slots:
    void resultat();


private:
    QGroupBox *groupType();
    QGroupBox *groupSaveur();
    QGroupBox *groupDegre();
    QPushButton *pushButtonValider();
    QPushButton *pushButtonFermer();
    QButtonGroup *groupeType, *groupeSaveur, *groupeDegre;
    //QSqlDatabase bdd;


};


#endif
