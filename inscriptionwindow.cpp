#include "inscriptionwindow.h"
#define q2c(string) string.toStdString()
InscriptionWindow::InscriptionWindow()
{
    boxInfo = new QGroupBox("Informations");
    formInfo = new QFormLayout;
    inscrMainLayout = new QVBoxLayout;

    userEmail = new QLineEdit;
    userName = new QLineEdit;
    userPassword = new QLineEdit;
    userPassword->setEchoMode(QLineEdit::Password);

    regiser = new QPushButton("register");
    regiser->setCursor(Qt::PointingHandCursor);
    cancel = new QPushButton("cancel");
    cancel->setCursor(Qt::PointingHandCursor);

    formInfo->addRow("name : "    , userName);
    formInfo->addRow("e-mail : "  , userEmail);
    formInfo->addRow("password : ", userPassword);

    boxInfo->setLayout(formInfo);
    inscrMainLayout->addWidget(boxInfo);
    inscrMainLayout->addWidget(regiser);
    inscrMainLayout->addWidget(cancel);

    setLayout(inscrMainLayout);

    connect(cancel, SIGNAL(clicked()), this, SLOT(accept()));
    connect(regiser, SIGNAL(clicked()), this, SLOT(registerUser()));
}

void InscriptionWindow::registerUser()
{
    if(userEmail->text().isEmpty() | userName->text().isEmpty()  | userPassword->text().isEmpty()){
        QMessageBox::critical(this,"Erreur", "Erreur\n Information required");
        return;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("ppeperso");
    db.setHostName("192.168.30.1");
    db.setUserName("user");
    db.setPassword("root");
    db.open();

    if(db.isOpen()){
        std::cout<<"db inscription ouverte\n";
    }

    QSqlQuery query;

    query.prepare("INSERT INTO users(pseudo, mdp, mail) VALUES(:pseudo, :mdp, :mail)");
    query.bindValue(":pseudo",userName->text());
    query.bindValue(":mdp",userPassword->text());
    query.bindValue(":mail",userEmail->text());

    if(query.exec()){
        std::cout<<"Query Inscr Ok\n";
        accept();
    }else{
        std::cout<<q2c(query.lastError().text());
    }

}
