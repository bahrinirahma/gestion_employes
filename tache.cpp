#include "tache.h"

Tache::Tache() {}

Tache::Tache(int id, const QString& description, const QString& competence, int duree)
    : id(id), description(description), competence(competence), duree(duree) {}

int Tache::getId() const { return id; }
QString Tache::getDescription() const { return description; }
QString Tache::getCompetence() const { return competence; }
int Tache::getDuree() const { return duree; }

