#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>  
#include <windows.h> 

#include <stdio.h>
#include <cwchar>
#include "Etudiant.h"
#include "personnel.h"
#include "cours.h"
#include "notes.h"
#include "Absence.h"
#include "emptemps.h"
using namespace std;

main(void)
{
    // declaration des objets des classes
    student etudiant;
    Cours cour;
    PersonnelUni PersonnelUni;
    Notes notes;
    Absence absence;
    EmploiDuTemps emploi;
    // declaration des variables
    string matriculeEtudiant, matriculeNotes, nomCoursNotes;
    float note;
    int i = 0, j;
    char choice;
    int nbrabsence;
    bool exitMenu = false;

    while (1)
    {

        cout << "_______________________________________________________________________ " << endl;
        cout << "************************************************************************" << endl;
        cout << "|**                        Menu Principale                           **|" << endl;
        cout << "|**                                                                  **|" << endl;
        cout << "|**         +. Interface Etudiant ......................1            **|" << endl;
        cout << "|**         +. Interface Personnel uni..................2            **|" << endl;
        cout << "|**         +. Exit de Programme........................0            **|" << endl;
        cout << "|**                                                                  **|" << endl;
        cout << "|**                                                                  **|" << endl;
        cout << "_______________________________________________________________________ " << endl;
        cout << "************************************************************************" << endl;
        cout << "Votre Choix : ";
        cin >> choice;
        system("cls");

        switch (choice)
        {
        /* STUDENT */
        case '1':
        {

            while (!exitMenu)
            {

                cout << "_______________________________________________________________________ " << endl;
                cout << "************************************************************************" << endl;
                cout << "|**                      Interface EtudianT                          **|" << endl;
                cout << "|**                                                                  **|" << endl;
                cout << "|**         +. Inscription a un cours...................1            **|" << endl;
                cout << "|**         +. Consultation des Notes...................2            **|" << endl;
                cout << "|**         +. Consultation des absences................3            **|" << endl;
                cout << "|**         +. Retour...................................0            **|" << endl;
                cout << "|**                                                                  **|" << endl;
                cout << "|**                                                                  **|" << endl;
                cout << "_______________________________________________________________________ " << endl;
                cout << "************************************************************************" << endl;
                cout << "Votre Choix : ";
                cin >> choice;

                system("cls");

                switch (choice)
                {
                case '1': // Inscription à un cours
                {
                    // Saisie du nom de l'étudiant à inscrire
                    cout << "Entrez la matricule  de l'etudiant a inscrire : ";
                    cin >> matriculeEtudiant;
                    // Recherche de l'étudiant par son matricule
                    student *etudiantTrouve = cour.TrouverEtudiantParMatricule(matriculeEtudiant);

                    if (etudiantTrouve)
                    {
                        cour.InscrireEtudiant(etudiantTrouve);
                    }
                    else
                    {
                        cout << "Aucun etudiant trouve avec cete matricule  " << matriculeEtudiant << endl;
                    }
                    break;
                }

                case '2':
                {
                    // consultation des Notes Par etudiant
                    cout << "Entrez le matricule de l'étudiant : ";
                    cin >> matriculeNotes;
                    cout << "Entrez le nom du cours : ";
                    cin >> nomCoursNotes;
                    notes.ConsulterNote(matriculeNotes, nomCoursNotes);
                    break;
                    break;
                }
                case '3':
                {
                    cout << "entrer la matricule d'etudiant souhaite  pour consulter les absences" << endl;
                    cin >> matriculeEtudiant;
                    absence.ConsulterAbsencesEtudiant(matriculeEtudiant);
                }
                case '0':
                {
                    exitMenu = true;
                    break;
                }
                }
            }
            break;
        }

        case '2': // Interface Personnel uni
        {
            bool exitPersonnelMenu = false;

            while (!exitPersonnelMenu)
            {
                Menu :
                cout << "______________________________________________________________________ " << endl;
                cout << "***********************************************************************" << endl;
                cout << "|**                     Interface Personnel uni                     **|" << endl;
                cout << "|**                                                                 **|" << endl;
                cout << "|**         +. Gestion Personnel ........................1          **|" << endl;
                cout << "|**         +. Gestion des Etudiants ....................2          **|" << endl;
                cout << "|**         +. Gestion des Cours ........................3          **|" << endl;
                cout << "|**         +. Gestion des Notes ........................4          **|" << endl;
                cout << "|**         +. Gestion des Absences .....................5          **|" << endl;
                cout << "|**         +. Gestion des Emploi des temps .............6          **|" << endl;
                cout << "|**         +. Retour ...................................0          **|" << endl;
                cout << "|**                                                                 **|" << endl;
                cout << "______________________________________________________________________ " << endl;
                cout << "***********************************************************************" << endl;
                cout << "Votre Choix : ";
                cin >> choice;

                switch (choice)
                {
                case '1': // Gestion Personnel
                {
                    bool exitGestionPersonnelMenu = false;

                    while (!exitGestionPersonnelMenu)
                    {
                        cout << "_________________________________________________________________________ " << endl;
                        cout << "**************************************************************************" << endl;
                        cout << "|**              Gestion des employes universitaire                    **|" << endl;
                        cout << "|**                                                                    **|" << endl;
                        cout << "|**         +. Creer un nouveau employe ...................1           **|" << endl;
                        cout << "|**         +. Consulter les employes .....................2           **|" << endl;
                        cout << "|**         +. Chercher les employes ......................3           **|" << endl;
                        cout << "|**         +. Modifier un employes .......................4           **|" << endl;
                        cout << "|**         +. Supprimer un employes ......................5           **|" << endl;
                        cout << "|**         +. Retour ......................................0          **|" << endl;
                        cout << "|**                                                                    **|" << endl;
                        cout << "_________________________________________________________________________ " << endl;
                        cout << "**************************************************************************" << endl;
                        cout << "Votre Choix : ";
                        cin >> choice;

                        switch (choice)
                        {
                        case '1': // Créer un nouveau employé
                            PersonnelUni.AjouterPersonnel();
                            break;
                        case '2': // Consulter les employés
                            PersonnelUni.AfficherPerso();
                            break;
                        case '3': // Chercher les employés
                            PersonnelUni.searchPerso();
                            break;
                        case '4': // Modifier un employé
                            PersonnelUni.ModifierPerso();
                            break;
                        case '5': // Supprimer un employé

                        case '0': // Retour
                            exitGestionPersonnelMenu = true;
                            break;
                        default:
                            cout << "Choix invalide. Veuillez choisir à nouveau." << endl;
                            break;
                        }
                    }
                    break;
                }
                case '2':
                {
                    bool exitetudiantMenu = false;
                    while (!exitetudiantMenu)
                    {

                        cout << "_______________________________________________________________________ " << endl;
                        cout << "************************************************************************" << endl;
                        cout << "|**                      Gestions des étudiants                      **|" << endl;
                        cout << "|**                                                                  **|" << endl;
                        cout << "|**         +. Créer un nouveau étudiant ..................1         **|" << endl;
                        cout << "|**         +. Consulter les étudiants ....................2         **|" << endl;
                        cout << "|**         +. Chercher les étudiants .....................3         **|" << endl;
                        cout << "|**         +. Modifier un étudiant .......................4         **|" << endl;
                        cout << "|**         +. Supprimer un étudiant ......................5         **|" << endl;
                        cout << "|**         +. Retour .....................................0         **|" << endl;
                        cout << "|**                                                                  **|" << endl;
                        cout << "_______________________________________________________________________ " << endl;
                        cout << "************************************************************************" << endl;
                        cout << "Votre Choix : ";
                        cin >> choice;
                        switch (choice)
                        {
                        case '1':
                        {
                            etudiant.AjouterEtudiant();
                            break;
                        }

                        case '2':
                        {
                            etudiant.AfficherEtudiant();
                            break;
                        }
                        case '3':
                        {
                            etudiant.searchStudent();
                            break;
                        }
                        case '4':
                        {
                            etudiant.ModifierEtudiant();
                            break;
                        }
                        case '5':
                        {
                            etudiant.DeleteEtudiant();
                            break;
                        }
                        case '0':
                        {
                             exitetudiantMenu = true;
                            break;
                        }
                        default:
                            cout << "Choix invalide." << endl;
                        }
                    }
                    break;
                }

                case '3': // Gestion des Cours
                {
                    bool exitcoursMenu = false;
                    while (!exitcoursMenu)
                    {
                        system("cls");

                        cout << "_______________________________________________________________________ " << endl;
                        cout << "************************************************************************" << endl;
                        cout << "|**                      Gestion des cours                           **|" << endl;
                        cout << "|**                                                                  **|" << endl;
                        cout << "|**         +. Ajouter un cours........................1             **|" << endl;
                        cout << "|**         +. modifier un cours.......................2             **|" << endl;
                        cout << "|**         +. Attribuer un cours a un etudiant........3             **|" << endl;
                        cout << "|**         +. validation d'inscription d'un étudiant..4             **|" << endl;
                        cout << "|**         +. Retour..................................0             **|" << endl;
                        cout << "_______________________________________________________________________ " << endl;
                        cout << "************************************************************************" << endl;
                        cout << "Votre Choix : ";
                        cin >> choice;

                        switch (choice)
                        {
                        case '1':
                        {
                            cour.AjouterCours();
                            break;
                        }
                        case '2':
                        {
                            cour.ModifierCours();
                            break;
                        }
                        case '3':
                        {
                            // Attribution d'un cours à un personnel universitaire
                            PersonnelUni.coursEnseignes.push_back(&cour);
                            cout << "Les cours enseignes par " << PersonnelUni.Pnom << " sont :" << endl;
                            for (Cours *cours : PersonnelUni.coursEnseignes)
                            {
                                cout << cours->nomCours << " => (" << cours->departement << ")" << endl;
                            }
                            break;
                        }
                        case '4':
                        {
                            // L'enseignant veut valider l'inscription d'un étudiant
                            string matricule;
                            cout << "Entrez le matricule de l'étudiant à valider : ";
                            cin >> matricule;

                            student *etudiantAValider = cour.TrouverEtudiantParMatricule(matricule);

                            if (etudiantAValider)
                            {
                                cour.ValiderInscription(etudiantAValider);
                            }
                            else
                            {
                                cout << "Aucun étudiant trouvé avec le matricule :" << matricule << endl;
                            }
                            break;
                        }
                        case '0':
                        {
                             exitcoursMenu = true;
                            break;
                        }
                        }
                    }
                    break;
                }
                case '4': // Gestion des Notes
                {
                    while (1)
                    {

                        cout << "_______________________________________________________________________ " << endl;
                        cout << "************************************************************************" << endl;
                        cout << "|**                      Gestion des NOtes                           **|" << endl;
                        cout << "|**                                                                  **|" << endl;
                        cout << "|**         +. Ajouter une Note.........................1            **|" << endl;
                        cout << "|**         +. Modifier Une Note........................2            **|" << endl;
                        cout << "|**         +. Cons une note d'etudiant par un cours....3            **|" << endl;
                        cout << "|**         +. Retour...................................0            **|" << endl;
                        cout << "|**                                                                  **|" << endl;
                        cout << "|______________________________________________________________________|" << endl;
                        cout << " ********************************************************************** " << endl;

                        cout << "Votre Choix : ";
                        cin >> choice;
                        switch (choice)
                        {
                            // Ajouter une note
                        case '1':
                        {

                            cout << "Entrez le matricule de l'étudiant : ";
                            cin >> matriculeNotes;
                            cout << "Entrez le nom du cours : ";
                            cin >> nomCoursNotes;
                            cout << "Entrez la note : ";
                            cin >> note;
                            notes.CreerNote(matriculeNotes, nomCoursNotes, note);
                            break;
                        }
                        // Modifier une note
                        case '2':
                        {
                            cout << "Entrez le matricule de l'étudiant : ";
                            cin >> matriculeNotes;
                            cout << "Entrez le nom du cours : ";
                            cin >> nomCoursNotes;
                            cout << "Entrez la note : ";
                            cin >> note;

                            notes.ModifierNote(matriculeNotes, nomCoursNotes, note);
                            break;
                        }
                        // consulter une note d etudiant par un cours
                        case '3':
                        {
                            cout << "Entrez le matricule de l'étudiant : ";
                            cin >> matriculeNotes;
                            cout << "Entrez le nom du cours : ";
                            cin >> nomCoursNotes;
                            notes.ConsulterNote(matriculeNotes, nomCoursNotes);
                            break;
                        }
                        default:
                            cout << "Choix invalide." << endl;
                        }
                    }
                    break;
                }
                case '5': // Gestion des Absences
                {
                    bool exitabsenceMenu = false;
                    while (!exitabsenceMenu)
                    {
                        cout << "_______________________________________________________________________ " << endl;
                        cout << "************************************************************************" << endl;
                        cout << "|**                      Gestion des Absences                        **|" << endl;
                        cout << "|**                                                                  **|" << endl;
                        cout << "|**         +. Ajouter une absence ........................1         **|" << endl;
                        cout << "|**         +. Modifier Une absence........................2         **|" << endl;
                        cout << "|**         +. Cons une absence d'etudiant par un cours....3         **|" << endl;
                        cout << "|**         +. Cons une absence d'etudiant specifique......4         **|" << endl;
                        cout << "|**         +. Retour......................................0         **|" << endl;
                        cout << "|**                                                                  **|" << endl;
                        cout << "|______________________________________________________________________|" << endl;
                        cout << " ********************************************************************** " << endl;
                        cout << "Votre Choix : ";
                        cin >> choice;
                        switch (choice)
                        {
                            // ajouter une absence
                        case '1':
                        {

                            cout << "Entrez le matricule de l'étudiant : ";
                            cin >> matriculeNotes;
                            cout << "Entrez le nom du cours : ";
                            cin >> nomCoursNotes;
                            cout << "Entrez le nombre d absence : ";
                            cin >> nbrabsence;
                            absence.CreerAbsence(matriculeNotes, nomCoursNotes, nbrabsence);
                            break;
                        }
                            // Modifier une Absence
                        case '2':
                        {
                            cout << "Entrez le matricule de l'étudiant : ";
                            cin >> matriculeNotes;
                            cout << "Entrez le nom du cours : ";
                            cin >> nomCoursNotes;
                            cout << "Entrez le nombre d absence : ";
                            cin >> nbrabsence;
                            absence.ModifierAbsence(matriculeNotes, nomCoursNotes, nbrabsence);
                            break;
                        }
                            // consulter une Absence  d etudiant par un cours
                        case '3':
                        {
                            cout << "Entrez le matricule de l'étudiant : ";
                            cin >> matriculeNotes;
                            cout << "Entrez le nom du cours : ";
                            cin >> nomCoursNotes;
                            absence.ConsulterAbsence(matriculeNotes, nomCoursNotes);
                            break;
                        }
                        case '4':
                        {
                            cout << "entrer la matricule d'etudiant souhaite  pour consulter les absences" << endl;
                            cin >> matriculeEtudiant;
                            absence.ConsulterAbsencesEtudiant(matriculeEtudiant);
                        }
                        case '0':{
                             exitabsenceMenu = true;
                        }
                        default:
                            cout << "Choix invalide." << endl;
                        }
                    }
                    break;
                }
                case '6': // Gestion des Emploi des temps
                {
                    bool exitepmenu = false;
                    while (!exitepmenu)
                    {
                        cout << " _________________________________________________________________________ " << endl;
                        cout << " ************************************************************************* " << endl;
                        cout << "|**                Gestion des Emplois des temps                        **|" << endl;
                        cout << "|**                                                                     **|" << endl;
                        cout << "|**         +. Creer emploi pour un  etudiant ................1         **|" << endl;
                        cout << "|**         +. Creer emploi pour un  personnel ...............2         **|" << endl;
                        cout << "|**         +. Modifier emploi pour un etudiant ..............3         **|" << endl;
                        cout << "|**         +. Modifier emploi pour un personnel .............4         **|" << endl;
                        cout << "|**         +. Consulter emploi d' etudiant ..................5         **|" << endl;
                        cout << "|**         +. Consulter emploi d'un personnel ...............6         **|" << endl;
                        cout << "|**         +. Quitter .......................................0         **|" << endl;
                        cout << " _________________________________________________________________________ " << endl;
                        cout << " *************************************************************************" << endl;
                        cout << "Votre choix :";
                        cin >> choice;

                        switch (choice)
                        {
                        case '1':
                        {
                            string matricule;
                            cout << "Entrez le matricule de l'etudiant : ";
                            cin >> matricule;
                            int nbCours;
                            cout << "Entrez le nombre de cours : ";
                            cin >> nbCours;

                            vector<string> cours(nbCours);
                            cout << "Entrez les noms des cours : ";
                            for (int i = 0; i < nbCours; ++i)
                            {
                                cin >> cours[i];
                            }

                            emploi.CreerEmploiEtudiant(matricule, cours);
                            break;
                        }
                        case '2':
                        {
                            string nom;
                            cout << "Entrez le nom du personnel : ";
                            cin >> nom;

                            int nbCours;
                            cout << "Entrez le nombre de cours : ";
                            cin >> nbCours;

                            vector<string> cours(nbCours);
                            cout << "Entrez les noms des cours : ";
                            for (int i = 0; i < nbCours; ++i)
                            {
                                cin >> cours[i];
                            }

                            emploi.CreerEmploiPersonnel(nom, cours);
                            break;
                        }
                        case '3':
                        {
                            string matricule;
                            cout << "Entrez le matricule de l'etudiant : ";
                            cin >> matricule;

                            int nbCours;
                            cout << "Entrez le nombre de cours : ";
                            cin >> nbCours;

                            vector<string> cours(nbCours);
                            cout << "Entrez les nouveaux noms des cours : ";
                            for (int i = 0; i < nbCours; ++i)
                            {
                                cin >> cours[i];
                            }

                            emploi.ModifierEmploiEtudiant(matricule, cours);
                            break;
                        }
                        case '4':
                        {
                            string nom;
                            cout << "Entrez le nom du personnel : ";
                            cin >> nom;

                            int nbCours;
                            cout << "Entrez le nombre de cours : ";
                            cin >> nbCours;

                            vector<string> cours(nbCours);
                            cout << "Entrez les nouveaux noms des cours : ";
                            for (int i = 0; i < nbCours; ++i)
                            {
                                cin >> cours[i];
                            }

                            emploi.ModifierEmploiPersonnel(nom, cours);
                            break;
                        }
                        case '5':
                        {
                            string matricule;
                            cout << "Entrez le matricule de l'etudiant : ";
                            cin >> matricule;

                            vector<string> emploiEtudiant = emploi.ConsulterEmploiEtudiant(matricule);
                            cout << "Emploi du temps de l'etudiant :" << endl;
                            for (const auto &cours : emploiEtudiant)
                            {
                                cout << cours << endl;
                            }
                            break;
                        }
                        case '6':
                        {
                            string nom;
                            cout << "Entrez le nom du personnel : ";
                            cin >> nom;

                            vector<string> emploiPersonnel = emploi.ConsulterEmploiPersonnel(nom);
                            cout << "Emploi du temps du personnel :" << endl;
                            for (const auto &cours : emploiPersonnel)
                            {
                                cout << cours << endl;
                            }
                            break;
                        }
                        case '0':
                        {
                             exitepmenu = true;
                            break;
                        }
                        default:
                            cout << "Choix invalide. Veuillez saisir un choix valide." << endl;
                        }
                    }
                    break;
                }
                case '0': // Retour
                {
                    exitPersonnelMenu = true;
                    break;
                }
                default:
                    cout << "Choix invalide. Veuillez choisir à nouveau." << endl;
                    break;
                }
            }
            break;
        }


            // exit
        case '0':
        {
            cout << "Fin du programme." << endl;
            return 0;
        }

        default:
            cout << "Choix invalide." << endl;
            break;
        }
    }
    return 0;
}

