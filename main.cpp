#include <QApplication>

#include "fen.h"
#include "connexionwindow.h"
#include "inscriptionwindow.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Window window;
    ConnexionWindow connexionWindow;
    connexionWindow.show();
    //window.show();


    return app.exec();
}
