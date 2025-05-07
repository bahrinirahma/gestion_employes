#ifndef GESTIONTACHES_H
#define GESTIONTACHES_H



#include "tache.h"
#include "employes.h"
#include <QList>

class GestionTaches {
public:
    static bool assignerTacheAuto(const Tache& tache, Employe& employe); // suggère une attribution selon compétences
    static QSqlQueryModel* afficherAttributions();

};


#endif // GESTIONTACHES_H
