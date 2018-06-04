#include <QtWidgets>

#include "fen.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(groupType(), 0, 0);
    grid->addWidget(groupSaveur(), 1, 0);
    grid->addWidget(groupDegre(), 2, 0);
    grid->addWidget(pushButtonValider(), 3, 0);
    grid->addWidget(pushButtonFermer(), 4, 0);
    setLayout(grid);

    setWindowTitle(tr("Au QG !"));
    resize(480, 320);


}

QGroupBox *Window::groupType()
{
    QGroupBox *groupBoxType = new QGroupBox(tr("Question 1"));

    QLabel *quest1 = new QLabel("Quel type de bière préférez-vous ?");
    QRadioButton *radioBlanche = new QRadioButton(tr("Blanche"));
    QRadioButton *radioBlonde = new QRadioButton(tr("Blonde"));
    QRadioButton *radioBrune = new QRadioButton(tr("Brune"));
    QRadioButton *radioNoire = new QRadioButton(tr("Noire"));
    QRadioButton *radioRouge = new QRadioButton(tr("Rouge"));
    QRadioButton *radioAmbree = new QRadioButton(tr("Ambrée"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(quest1);
    vbox->addWidget(radioBlanche);
    vbox->addWidget(radioBlonde);
    vbox->addWidget(radioBrune);
    vbox->addWidget(radioNoire);
    vbox->addWidget(radioRouge);
    vbox->addWidget(radioAmbree);
    vbox->addStretch(1);
    groupBoxType->setLayout(vbox);

   groupeType = new QButtonGroup;


    QList<QRadioButton *> allButtonsType = groupBoxType->findChildren<QRadioButton *>();
    for(int i = 0; i < allButtonsType.size(); i++)
    {
        groupeType->addButton(allButtonsType[i],i);
    }

    return groupBoxType;
}

QGroupBox *Window::groupSaveur()
{
    QGroupBox *groupBoxSaveur = new QGroupBox(tr("Question 2"));

    QLabel *quest2 = new QLabel("Quel(s) saveur(s) préférez-vous ?");
    QRadioButton *radioDouce = new QRadioButton(tr("Les douces"));
    QRadioButton *radioAmere = new QRadioButton(tr("Les amères"));
    QRadioButton *radioAcide = new QRadioButton(tr("Les acides"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(quest2);
    vbox->addWidget(radioDouce);
    vbox->addWidget(radioAmere);
    vbox->addWidget(radioAcide);
    vbox->addStretch(1);
    groupBoxSaveur->setLayout(vbox);

    groupeSaveur = new QButtonGroup;


     QList<QRadioButton *> allButtonsSaveur = groupBoxSaveur->findChildren<QRadioButton *>();
     for(int i = 0; i < allButtonsSaveur.size(); i++)
     {
         groupeSaveur->addButton(allButtonsSaveur[i],i);
     }

    return groupBoxSaveur;
}

QGroupBox *Window::groupDegre()
{
    QGroupBox *groupBoxDegre = new QGroupBox(tr("Question 3"));

    QLabel *quest3 = new QLabel("Quel marge de degré d'alcool préférez-vous ?");
    QRadioButton *radioLegere = new QRadioButton(tr("légère (jusqu'à 5°"));
    QRadioButton *radioMoyenne = new QRadioButton(tr("moyenne (entre 5 et 7°)"));
    QRadioButton *radioForte = new QRadioButton(tr("forte (entre 7 et 10°)"));
    QRadioButton *radioTresforte = new QRadioButton(tr("très forte (plus de 10°)"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(quest3);
    vbox->addWidget(radioLegere);
    vbox->addWidget(radioMoyenne);
    vbox->addWidget(radioForte);
    vbox->addWidget(radioTresforte);
    vbox->addStretch(1);
    groupBoxDegre->setLayout(vbox);

    groupeDegre = new QButtonGroup;


     QList<QRadioButton *> allButtonsDegre = groupBoxDegre->findChildren<QRadioButton *>();
     for(int i = 0; i < allButtonsDegre.size(); i++)
     {
         groupeDegre->addButton(allButtonsDegre[i],i);
     }

    return groupBoxDegre;
}

QPushButton *Window::pushButtonValider()
{
    QPushButton *valider = new QPushButton(tr("Valider"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(valider);
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(resultat()));
    return valider;
}
QPushButton *Window::pushButtonFermer()
{
    QPushButton *fermer = new QPushButton(tr("Fermer"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(fermer);
    QObject::connect(fermer, SIGNAL(clicked()), qApp, SLOT(quit()));

    return fermer;
}

void Window::resultat()
{
    int typeBiere = 0;
    int saveurBiere = 0;
    int degreBiere = 0;

    typeBiere = groupeType->checkedId();
    saveurBiere = groupeSaveur->checkedId();
    degreBiere = groupeDegre->checkedId();

    QSqlDatabase bdd = QSqlDatabase::addDatabase("QMYSQL");
    bdd.setHostName("192.168.30.1");
    bdd.setDatabaseName("ppeperso");
    bdd.setUserName("user");
    bdd.setPassword("root");

    if(bdd.open()) {
        std::cout<< "Ok - ouverture de la base de donnee \n";
    }else{
        std::cout<< "raté \n";
    }

    QSqlQuery requete;
    requete.prepare("SELECT liste_biere FROM biere where id_saveur = :id_saveur AND id_type = :id_type AND id_degre = :id_degre");
    requete.bindValue(0,saveurBiere+1);
    requete.bindValue(1, typeBiere+1);
    requete.bindValue(2, degreBiere+1);

    if(requete.exec()){
        std::cout<<"query ok \n";
    }

    if (requete.first()){

        QMessageBox::information(this, "Résultats", requete.value(0).toString());

    }


}


