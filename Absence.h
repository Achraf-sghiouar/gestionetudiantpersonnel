#ifndef ABSENCE_H
#define ABSENCE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include "cours.h"

using namespace std ;
class student ;
class Absence {
private:
 map<string, map<string, int>> absences;  // <matricule, <nomCours, nombreAbsences>>

public:
    // Créer une nouvelle absence pour un étudiant et un cours
    void CreerAbsence(const string& matricule, const string& nomCours, int nombreAbsences) {
        absences[matricule][nomCours] = nombreAbsences;
        sauvegarderAbsences();
     cout << "Absence ajoutée avec succès pour " << matricule << " dans " << nomCours << endl;
    }

    // Modifier le nombre d'absences d'un étudiant pour un cours
    void ModifierAbsence(const string& matricule, const string& nomCours, int nouveauNombreAbsences) {
        if (absences.find(matricule) != absences.end() && absences[matricule].find(nomCours) != absences[matricule].end()) {
            absences[matricule][nomCours] = nouveauNombreAbsences;
            sauvegarderAbsences();
         cout << "Absence modifiée avec succès pour " << matricule << " dans " << nomCours << endl;
        } else {
         cout << "Aucune absence trouvee pour " << matricule << " dans " << nomCours << endl;
        }
    }

    // Consulter le nombre d'absences d'un étudiant pour un cours
    void ConsulterAbsence(const string& matricule, const string& nomCours) {
        if (absences.find(matricule) != absences.end() && absences[matricule].find(nomCours) != absences[matricule].end()) {
         cout << "Le nombre d'absences de " << matricule << " dans " << nomCours << " est : " << absences[matricule][nomCours] << endl;
        } else {
         cout << "Aucune absence trouvée pour " << matricule << " dans " << nomCours << endl;
        }
    }
// Consulter les absences d'un étudiant spécifique
void ConsulterAbsencesEtudiant(const string& matricule) {
    if (absences.find(matricule) != absences.end()) {
        cout << "Absences de l'étudiant avec le matricule " << matricule << " : " << endl;
        for (const auto& pairCoursAbsence : absences[matricule]) {
        cout << " - " << pairCoursAbsence.first << " : " << pairCoursAbsence.second << endl;
        }
    } else {
     cout << "Aucune absence trouvée pour l'étudiant avec le matricule " << matricule << endl;
    }
}

private:
    // Sauvegarder les absences dans un fichier (à adapter selon votre structure de sauvegarde)
    void sauvegarderAbsences() {
     ofstream fichier("absences.txt");
        if (fichier.is_open()) {
            for (const auto& pairMatricule : absences) {
                for (const auto& pairCoursAbsence : pairMatricule.second) {
                    fichier << pairMatricule.first << " "
                            << pairCoursAbsence.first << " "
                            << pairCoursAbsence.second << endl;
                }
            }
            fichier.close();
        } else {
         cerr << "Erreur lors de l'ouverture du fichier absences.txt" << endl;
        }
    }
};

#endif // ABSENCE_H
