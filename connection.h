#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection
{
public:
    Connection();
    ~Connection();              // Ajout du destructeur

    bool createConnection();    // Initialise et ouvre la connexion
    void closeConnection();     // Ferme la connexion si ouverte

private:
    QSqlDatabase db;            // Objet de gestion de la base de données
};

#endif // CONNECTION_H
