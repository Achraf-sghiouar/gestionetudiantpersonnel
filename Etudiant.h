

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <conio.h> //for getch()
#include <windows.h>//for system calls
#include <stdio.h>
#include <cwchar> //for fontsize+fontstyle
using namespace std;


class student
{
 public:
 string Snom;
 string Smatricule;
 string filiere;
string statutInscription;

void AjouterEtudiant() {
    
 cout << "Entrer le nom ";
    cin >> Snom;
    cout << "Entrer la matricule ";
    cin >> Smatricule;
    cout << "Enter Filliere: ";
    cin >> filiere;
    cout << endl ;
     

    // Enregistrement dans le fichier
    ofstream fichier("etudiant.txt", ios::app); 

    if (fichier.is_open()) {
        fichier << Snom << " "
                << Smatricule << " "
                << filiere <<  endl;

        fichier.close();
        cout << "etudiant ajoutée avec succès  !" << endl;
    } else {
        cerr << "Erreur lors de l'ouverture du fichier etudiant.txt" << endl;
    }
}

// Afficher un étudiant
void AfficherEtudiant(){
    ifstream fichier("etudiant.txt",ios::app);
    if (fichier.is_open())
    {
      string ligne;
        while (getline(fichier, ligne))
        {
          cout << ligne <<  endl;
         
        }

        fichier.close();
    }
    else
    {
      cerr << "Erreur lors de l'ouverture du fichier etudiant.txt" <<endl;
    }
    cin.ignore();
    cin.get();
}
// chercher un etudiant
void searchStudent()
{
    ifstream fichier("etudiant.txt");
    string nomRecherche;

    cout << "Entrer le nom de l' etudiant à rechercher : ";
    cin >> nomRecherche;
    cout << endl;

    string nom, matricule, filliere;
    bool trouve = false;

    while (fichier >> nom >> matricule >> filliere)
    {
        if (nom == nomRecherche)
        {
            trouve = true;
            cout << "Nom : " << nom << endl;
            cout << "Matricule : " << matricule << endl;
            cout << "Filiere : " << filliere << endl
                 << endl;
        }
    }

    fichier.close();

    if (!trouve)
    {
        cout << "Aucun étudiant trouvé avec le nom " << nomRecherche << endl;
    }
    cin.ignore();
    cin.get();
}
void ModifierEtudiant(){
    cout << "Entrez le matricule de l'etudiant que vous voulez modifier: ";
    string matricule;
    cin >> matricule;

    ifstream fichierIn("etudiant.txt");
    ofstream fichierOut("etudiant_temp.txt");

    if (fichierIn && fichierOut) {
        string ligne;
        while (getline(fichierIn, ligne)) {
            stringstream ss(ligne);
            student etudiant;
            ss >> etudiant.Snom >> etudiant.Smatricule >> etudiant.filiere;
            if (etudiant.Smatricule == matricule) {
                cout << "Nouveau nom: ";
                cin >> etudiant.Snom;
                cout << "Nouveau matricule: ";
                cin >> etudiant.Smatricule;
                cout << "Nouvelle filiere: ";
                cin >> etudiant.filiere;
            }
            fichierOut << etudiant.Snom << " "
                       << etudiant.Smatricule << " "
                       << etudiant.filiere << endl;
        }
        fichierIn.close();
        fichierOut.close();
        remove("etudiant.txt");
        rename("etudiant_temp.txt", "etudiant.txt");
        cout << "Modification terminée !" << endl;
    } else {
        cerr << "Erreur lors de l'ouverture des fichiers." << endl;
    }

}
 void DeleteEtudiant()
{
    string line, name;
    cout << "Entree le nom : ";
    cin >> name;
    ifstream f2;
    ofstream temp;
    f2.open("etudiant.txt");
    temp.open("temp.txt");
    while (getline(f2, line))
    {
        if (line != name)
            temp << line << endl;
    }
    cout << "Le nom selectionne : " << name << "est supprimme si il existe" << endl;
    f2.close();
    temp.close();
    remove("etudiant.txt");
    rename("temp.txt", "etudiant.txt");
   cin.ignore();
    cin.get();
}

// methodes s 'inscrire à un cours
//  void SInscrireAuCours(Cours& cours) {
//         cours.InscrireEtudiant(*this); // Utiliser une référence pour s'inscrire au cours
//     }
};


