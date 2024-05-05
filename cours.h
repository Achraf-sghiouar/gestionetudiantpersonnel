#ifndef COURS_H
#define COURS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "personnel.h"

using namespace std;
class student ;
class Cours {
public:
    string nomCours;
    string departement;
    string niveauEtudes;
    PersonnelUni* professeur;
    vector<student*> etudiantsInscrits;

    void AjouterCours() {
        cout << "Entrer le Nom du cours : ";
        cin >> nomCours;
        cout << "Entrer le departement du cours : ";
        cin >> departement;
        cout << "Entrer le niveau d'etudes : ";
        cin >> niveauEtudes;
        cout << endl;

        ofstream fichier("Cours.txt", ios::app);

        if (fichier.is_open()) {
            fichier << nomCours << " "
                    << departement << " "
                    << niveauEtudes << endl;

            fichier.close();
            cout << "Cours ajouté avec succès !" << endl;
        } else {
            cerr << "Erreur lors de l'ouverture du fichier Cours.txt" << endl;
        }
    }

    void ModifierCours() {
        cout << "Entrez le département du cours que vous voulez modifier: ";
        string departementRecherche;
        cin.ignore(); // Pour vider le buffer du saut de ligne
        getline(cin, departementRecherche);

        ifstream fichierIn("Cours.txt");
        ofstream fichierOut("Cours_temp.txt");

        if (fichierIn && fichierOut) {
            string ligne;
            while (getline(fichierIn, ligne)) {
                stringstream ss(ligne);
                Cours cours;
                ss >> cours.nomCours >> cours.departement >> cours.niveauEtudes;
                if (cours.departement == departementRecherche) {
                    cout << "Modifier le Nom du cours: ";
                    getline(cin, cours.nomCours);
                    cout << "Modifier le departement: ";
                    getline(cin, cours.departement);
                    cout << "Modifier le niveau d'etudes: ";
                    getline(cin, cours.niveauEtudes);
                }
                fichierOut << cours.nomCours << " "
                           << cours.departement << " "
                           << cours.niveauEtudes << endl;
            }
            fichierIn.close();
            fichierOut.close();
            remove("Cours.txt");
            rename("Cours_temp.txt", "Cours.txt");
            cout << "Modification terminée !" << endl;
        } else {
            cerr << "Erreur lors de l'ouverture des fichiers." << endl;
        }
    }

    student* TrouverEtudiantParMatricule(const string& matricule) {
        for (student* etudiant : etudiantsInscrits) {
            if (etudiant->Smatricule == matricule) {
                return etudiant;
            }
        }
        return nullptr;
    }

    void InscrireEtudiant(student* etudiant) {
        // Vérifier si l'étudiant est déjà inscrit
        if (find(etudiantsInscrits.begin(), etudiantsInscrits.end(), etudiant) != etudiantsInscrits.end()) {
            cout << etudiant->Snom << " est déjà inscrit au cours " << nomCours << endl;
        } else {
            etudiantsInscrits.push_back(etudiant);
            cout << etudiant->Snom << " inscrit au cours " << nomCours << endl;
        }
    }

    void DesinscrireEtudiant(student* etudiant) {
        auto it = find(etudiantsInscrits.begin(), etudiantsInscrits.end(), etudiant);

        if (it != etudiantsInscrits.end()) {
            etudiantsInscrits.erase(it);
            cout << etudiant->Snom << " désinscrit du cours " << nomCours << endl;
        } else {
            cout << "Erreur : " << etudiant->Snom << " n'est pas inscrit au cours " << nomCours << endl;
        }
    }

    void ValiderInscription(student* etudiant) {
        auto it = find(etudiantsInscrits.begin(), etudiantsInscrits.end(), etudiant);

        if (it != etudiantsInscrits.end()) {
            (*it)->statutInscription = "Validé";
            cout << "L'inscription de " << (*it)->Snom << " a été validée pour le cours " << nomCours << endl;
        } else {
            cout << "Erreur : " << etudiant->Snom << " n'est pas inscrit au cours " << nomCours << endl;
        }
    }
};

#endif
