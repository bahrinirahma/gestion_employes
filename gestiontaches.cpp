#include "gestiontaches.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool GestionTaches::assignerTacheAuto(const Tache& tache, Employe& employe)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYEES WHERE JOB_ID = :poste AND COMPETENCES LIKE :competence AND DISPONIBILITE = 1");
    query.bindValue(":poste", employe.getPoste());
    query.bindValue(":competence", "%" + tache.getCompetence() + "%");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'attribution automatique :" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int employeId = query.value("EMPLOYEE_ID").toInt();
        QSqlQuery insert;
        insert.prepare("INSERT INTO ATTRIBUTIONS (EMPLOYEE_ID, TACHE_ID, DATE_ATTRIBUTION, ETAT) VALUES (:empId, :tacheId, CURRENT_DATE, 'attribuée')");
        insert.bindValue(":empId", employeId);
        insert.bindValue(":tacheId", tache.getId());

        if (!insert.exec()) {
            qDebug() << "Erreur lors de l'insertion d'une attribution :" << insert.lastError().text();
            return false;
        }
        return true;
    }
    return false;
}
QSqlQueryModel* GestionTaches::afficherAttributions() {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Exécution de la requête pour obtenir les attributions
    QSqlQuery query;
    query.prepare("SELECT * FROM attributions");  // Exemple de requête
    if (query.exec()) {
        model->setQuery(query);
    } else {
        // Gestion de l'erreur SQL ici
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return nullptr;
    }

    return model;
}
