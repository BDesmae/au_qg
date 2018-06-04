#ifndef INSCRIPTIONWINDOW_H
#define INSCRIPTIONWINDOW_H
#include <QtWidgets>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <QObject>
#include <QSqlError>

class InscriptionWindow : public QDialog
{
    Q_OBJECT

public:
    InscriptionWindow();

private slots:
    void registerUser();

private:
    QGroupBox *boxInfo;
    QFormLayout *formInfo;
    QVBoxLayout *inscrMainLayout;
    QLineEdit *userEmail, *userName, *userPassword ;
    QPushButton *regiser, *cancel;

};

#endif // INSCRIPTIONWINDOW_H
