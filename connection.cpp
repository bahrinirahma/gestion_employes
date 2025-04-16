#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection()
{
    // Constructeur par défaut, rien à initialiser ici
}

Connection::~Connection()
{
    // Fermeture automatique lors de la destruction
    if (db.isOpen()) {
        db.close();
        qDebug() << "Connexion à la base de données fermée automatiquement.";
    }
}

bool Connection::createConnection()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("source");
    db.setUserName("system");
    db.setPassword("admin");

    if (!db.open()) {
        qDebug() << "❌ Erreur de connexion :" << db.lastError().text();
        qDebug() << "Détails :" << db.lastError().driverText();
        return false;
    }

    qDebug() << "✅ Connexion réussie à la base de données.";
    return true;
}

void Connection::closeConnection()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "✅ Connexion à la base de données fermée.";
    }
}
