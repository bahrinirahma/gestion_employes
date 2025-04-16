#include "employes.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QDate>

Employe::Employe() {}

Employe::Employe(int id, QString prenom, QString nom, QString email, QDate dateEmbauche, QString poste, double salaire)
    : id(id), prenom(prenom), nom(nom), email(email), dateEmbauche(dateEmbauche), poste(poste), salaire(salaire) {}

bool Employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYEES (EMPLOYEE_ID, FIRST_NAME, LAST_NAME, EMAIL, HIRE_DATE, JOB_ID, SALARY) "
                  "VALUES (:id, :prenom, :nom, :email, :date, :poste, :salaire)");
    query.bindValue(":id", id);
    query.bindValue(":prenom", prenom);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":date", dateEmbauche);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);

    if (!query.exec()) {
        qDebug() << "Erreur SQL dans ajouter() :" << query.lastError().text();
        return false;
    }
    return true;
}

bool Employe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYEES WHERE EMPLOYEE_ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL dans supprimer() :" << query.lastError().text();
        return false;
    }
    return true;
}

bool Employe::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYEES SET FIRST_NAME = :prenom, LAST_NAME = :nom, EMAIL = :email, HIRE_DATE = :date, JOB_ID = :poste, SALARY = :salaire WHERE EMPLOYEE_ID = :id");
    query.bindValue(":id", id);
    query.bindValue(":prenom", prenom);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":date", dateEmbauche);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);

    if (!query.exec()) {
        qDebug() << "Erreur SQL dans modifier() :" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel *Employe::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYEES");
    return model;
}

QSqlQueryModel* Employe::chercherEmployeParId(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM EMPLOYEES WHERE EMPLOYEE_ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche par ID :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(query); // Lier le modèle à la requête
    return model;
}

QSqlQueryModel* Employe::trier(const QString& critere, const QString& ordre)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString colonne;

    if (critere == "ID Employee")
        colonne = "EMPLOYEE_ID";
    else if (critere == "First name")
        colonne = "FIRST_NAME";
    else if (critere == "Hire date")
        colonne = "HIRE_DATE";
    else
        colonne = "EMPLOYEE_ID";  // fallback par défaut

    QString requete = QString("SELECT * FROM EMPLOYEES ORDER BY %1 %2")
                          .arg(colonne, ordre == "Ascending" ? "ASC" : "DESC");

    model->setQuery(requete);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors du tri :" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}
