#ifndef EMPLOI_H
#define EMPLOI_H



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
class EmploiDuTemps {
private:
    map<string, vector<string>> emploiEtudiants;
    map<string, vector<string>> emploiPersonnel;

public:
    // Création d'emplois du temps pour un étudiant
    void CreerEmploiEtudiant(const string& matricule, const vector<string>& cours) {
        emploiEtudiants[matricule] = cours;
    }

    // Création d'emplois du temps pour un membre du personnel
    void CreerEmploiPersonnel(const string& nom, const vector<string>& cours) {
        emploiPersonnel[nom] = cours;
    }

    // Modification de l'emploi du temps d'un étudiant
    void ModifierEmploiEtudiant(const string& matricule, const vector<string>& nouveauxCours) {
        emploiEtudiants[matricule] = nouveauxCours;
    }

    // Modification de l'emploi du temps d'un membre du personnel
    void ModifierEmploiPersonnel(const string& nom, const vector<string>& nouveauxCours) {
        emploiPersonnel[nom] = nouveauxCours;
    }

    // Consultation de l'emploi du temps d'un étudiant
    vector<string> ConsulterEmploiEtudiant(const string& matricule) {
        return emploiEtudiants[matricule];
    }

    // Consultation de l'emploi du temps d'un membre du personnel
    vector<string> ConsulterEmploiPersonnel(const string& nom) {
        return emploiPersonnel[nom];
    }
};

#endif