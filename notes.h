#ifndef NOTES_H
#define NOTES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "cours.h"
using namespace std;

class student ;

class Notes {
private:
 unordered_map< string,  unordered_map< string, double>> notes;

public:
    // Créer une nouvelle note pour un étudiant et un cours
    void CreerNote(const string& matricule, const string& nomCours, float note) {
        notes[matricule][nomCours] = note;
        sauvegarderNotes();
        cout << "Note ajoutée avec succès pour : " << matricule << " dans " << nomCours << endl;
    }

    // Modifier la note d'un étudiant pour un cours
    void ModifierNote(const string& matricule, const string& nomCours, float nouvelleNote) {
        if (notes.find(matricule) != notes.end() && notes[matricule].find(nomCours) != notes[matricule].end()) {
            notes[matricule][nomCours] = nouvelleNote;
            sauvegarderNotes();
            cout << "Note modifiee avec succès pour " << matricule << " dans " << nomCours << endl;
        } else {
            cout << "Aucune note trouvee pour " << matricule << " dans " << nomCours << endl;
        }
    }

    // Consulter la note d'un étudiant pour un cours
    void ConsulterNote(const string& matricule, const string& nomCours) {
        if (notes.find(matricule) != notes.end() && notes[matricule].find(nomCours) != notes[matricule].end()) {
            cout << "La note de " << matricule << " dans " << nomCours << " est : " << notes[matricule][nomCours] << endl;
        } else {
            cout << "Aucune note trouvée pour " << matricule << " dans " << nomCours << endl;
        }
    }

// Consulter les notes d'un étudiant spécifique
void ConsulterNotesEtudiant(const string& matricule) {
    if (notes.find(matricule) != notes.end()) {
        cout << "Notes de l'etudiant avec le matricule " << matricule << " : " << endl;
        for (const auto& pairCoursNote : notes[matricule]) {
            cout << " - " << pairCoursNote.first << " : " << pairCoursNote.second << endl;
        }
    } else {
        cout << "Aucune note trouvee pour l'etudiant avec le matricule " << matricule << endl;
    }
}


private:
    // Sauvegarder les notes dans un fichier (à adapter selon votre structure de sauvegarde)
    void sauvegarderNotes() {
        ofstream fichier("notes.txt");
        if (fichier.is_open()) {
            for (const auto& pairMatricule : notes) {
                for (const auto& pairCoursNote : pairMatricule.second) {
                    fichier << pairMatricule.first << " "
                            << pairCoursNote.first << " "
                            << pairCoursNote.second << endl;
                }
            }
            fichier.close();
        } else {
            cerr << "Erreur lors de l'ouverture du fichier notes.txt" << endl;
        }
    }
};

#endif // NOTES_H
