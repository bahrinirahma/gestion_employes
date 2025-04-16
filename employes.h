#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(int id, QString prenom, QString nom, QString email, QDate dateEmbauche, QString poste, double salaire);

    bool ajouter();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel* afficher();
    QSqlQueryModel* chercherEmployeParId(int id);  // Recherche par ID
    QSqlQueryModel* trier(const QString& critere, const QString& ordre);

private:
    int id;
    QString prenom;
    QString nom;
    QString email;
    QDate dateEmbauche;
    QString poste;
    double salaire;
};

#endif // EMPLOYE_H
