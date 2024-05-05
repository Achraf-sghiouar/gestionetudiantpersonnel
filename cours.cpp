#include "cours.h"

// Implémentation des fonctions de la classe GestionCours

Cours* GestionCours::creerCours(const string& nomCours, const string& departement, const string& niveauEtudes) {
    Cours* nouveauCours = new Cours;
    nouveauCours->nomCours = nomCours;
    nouveauCours->departement = departement;
    nouveauCours->niveauEtudes = niveauEtudes;
    listeCours.push_back(nouveauCours);
    return nouveauCours;
}

void GestionCours::affecterEnseignant(Cours* cours, Enseignant* enseignant) {
    cours->enseignantResponsable = enseignant;
}

void GestionCours::afficherCoursParDepartement(const string& departement) {
    cout << "Cours disponibles dans le département " << departement << ":" << endl;
    for (Cours* cours : listeCours) {
        if (cours->departement == departement) {
            cout << "- " << cours->nomCours << endl;
        }
    }
}

void GestionCours::afficherCoursParNiveauEtudes(const string& niveauEtudes) {
    cout << "Cours disponibles au niveau " << niveauEtudes << ":" << endl;
    for (Cours* cours : listeCours) {
        if (cours->niveauEtudes == niveauEtudes) {
            cout << "- " << cours->nomCours << endl;
        }
    }
}

void GestionCours::inscrireEtudiant(Cours* cours, Etudiant* etudiant) {
    cours->etudiantsInscrits.push_back(etudiant);
}

void GestionCours::validerInscriptions(Cours* cours, Enseignant* enseignant) {
    if (cours->enseignantResponsable == enseignant) {
        cours->inscriptionsValidees = true;
        cout << "Les inscriptions au cours " << cours->nomCours << " ont été validées par " << enseignant->nom << " " << enseignant->prenom << endl;
    } else {
        cout << "Vous n'êtes pas l'enseignant responsable de ce cours." << endl;
    }
}
