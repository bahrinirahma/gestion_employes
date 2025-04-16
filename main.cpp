#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Création de l'objet de connexion à la base de données
    Connection c;

    if (!c.createConnection()) {
        QMessageBox::critical(nullptr, "Connexion à la base de données",
                              "Échec de la connexion à la base de données.",
                              QMessageBox::Ok);
        return -1; // Quitter si la connexion échoue
    }

    QMessageBox::information(nullptr, "Connexion réussie",
                             "Connexion à la base de données établie avec succès.",
                             QMessageBox::Ok);

    MainWindow w;
    w.show();

    return app.exec();
}
