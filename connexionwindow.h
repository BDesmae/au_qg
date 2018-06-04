#ifndef CONNEXIONWINDOW_H
#define CONNEXIONWINDOW_H

#include <QApplication>
#include <QWidget>
#include <iostream>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QFormLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <string>
#include <QVariant>
#include "inscriptionwindow.h"
#include "fen.h"

class ConnexionWindow : public QWidget
{
    Q_OBJECT

public:
    ConnexionWindow();
public slots:
    void auth();
    void openInscr();
private :
    QLineEdit *userEmail, *userPassword;
    QPushButton *connectButton, *inscriptionButton;
};

#endif // CONNEXIONWINDOW_H
