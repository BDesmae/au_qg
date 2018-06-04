#include "connexionwindow.h"
#define q2c(string) string.toStdString()

ConnexionWindow::ConnexionWindow() : QWidget()
{
    userEmail = new QLineEdit;
    userPassword = new QLineEdit;
    userPassword->setEchoMode(QLineEdit::Password);
    connectButton = new QPushButton("Connect");
    connectButton->setCursor(Qt::PointingHandCursor);
    inscriptionButton = new QPushButton("Inscription");
    inscriptionButton->setCursor(Qt::PointingHandCursor);



    QFormLayout *mainLayout = new QFormLayout;



    mainLayout->addRow("e-mail",userEmail);
    mainLayout->addRow("password",userPassword);
    mainLayout->addWidget(connectButton);
    mainLayout->addWidget(inscriptionButton);

    setLayout(mainLayout);

    connect(connectButton, SIGNAL(clicked()), this, SLOT(auth()));
    connect(inscriptionButton, SIGNAL(clicked()), this, SLOT(openInscr()));
}

void ConnexionWindow::auth()
{
    //Open the database /////////////////////////////////////////////
    QSqlDatabase db;

    if(db.isOpen()){
        db = QSqlDatabase::database();
        std::cout<<"db connection already open\n";
    }else{
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setDatabaseName("ppeperso");
        db.setHostName("192.168.30.1");
        db.setUserName("user");
        db.setPassword("root");
        db.open();
        std::cout<<"db connection open\n";
    }

    //////////////////////////////////////////////////////////////////////////////////////////////


    //Prepare and exec Query//////////////////////////////////////////////////////////////////////
    QSqlQuery queryMdp;
    std::string mdpUser;
    queryMdp.prepare("SELECT mdp FROM users WHERE mdp = :mdpUser");
    queryMdp.bindValue(0,userPassword->text());
    if(queryMdp.exec())std::cout<<"req mdp ok\n";
    if(queryMdp.first()){
        mdpUser = queryMdp.value(0).toString().toStdString();
    }else{
        std::cout<<"req mdp pas ok";
    }
    //////////////////////////////////////////////////////////////////////////////////////////////
    if(userPassword->text().isEmpty()){
       QMessageBox::critical(this,"Erreur", "Please entre password");
    }else{
        if(userPassword->text().toStdString() == mdpUser){
            Window *monQcm = new Window();
            monQcm->show();
            this->close();
        }
        else{
           QMessageBox::critical(this,"Erreur", "Erreur\nIdentifiants incorrecte");
           return;
       }
    }
}


void ConnexionWindow::openInscr()
{
   InscriptionWindow *inscrWin = new InscriptionWindow();
   inscrWin->exec();
}
