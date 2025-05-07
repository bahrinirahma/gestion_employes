#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(int id, QString prenom, QString nom, QString email, QDate dateEmbauche, QString poste, double salaire, QString competences);

    bool ajouter();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel* afficher();
    QSqlQueryModel* chercherEmployeParId(int id);  // Recherche par ID
    QSqlQueryModel* trier(const QString& critere, const QString& ordre);
    QSqlQueryModel* chercherParSalaire(double salaireMain);
    static void afficherStatistiques();
    QString getPoste() const { return poste; }
    QString getCompetences() const { return competences; }
    bool estDisponible() const { return disponibilite; }
    void ajouterHistorique(const QString &action);

private:
    int id;
    QString prenom;
    QString nom;
    QString email;
    QDate dateEmbauche;
    QString poste;
    double salaire;
    QString competences;  // Champ pour les compétences
    bool disponibilite;
};

#endif // EMPLOYE_H
