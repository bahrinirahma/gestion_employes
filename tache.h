#ifndef TACHE_H
#define TACHE_H



#include <QString>

class Tache {
public:
    Tache();
    Tache(int id, const QString& description, const QString& competence, int duree);

    int getId() const;
    QString getDescription() const;
    QString getCompetence() const;
    int getDuree() const;

private:
    int id;
    QString description;
    QString competence;
    int duree; // durée estimée en heures
};

#endif // TACHE_H
