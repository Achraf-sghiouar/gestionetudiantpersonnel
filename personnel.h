#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h> 
#include <windows.h>
#include <stdio.h>
#include <cwchar> 
#include <vector>

using namespace std;

class Cours ;

class PersonnelUni
{
 public:
string Pnom ;
int numeroDemp;
string TypePer ;
string Departement;
vector<Cours*> coursEnseignes;  // Pointeur vers les cours enseignés par le personnel

void AjouterPersonnel() {

    cout << "Entrer le nom du personnel uni : ";
    cin >> Pnom;
    cout << "Entrer le numero de personnel uni :";
    cin >> numeroDemp;
    cout << "Enter le type de personnel uni : ";
    cin >> TypePer;
    cout << "Enter le Departement de personnel uni : ";
    cin >> Departement;
    cout << endl;

    // Enregistrement dans le fichier
    ofstream fichier("Personnel.txt", ios::app); 

    if (fichier.is_open()) {
        fichier << Pnom << " "
                << numeroDemp << " "
                << TypePer << " "
                << Departement << endl;
               

        fichier.close();
        cout << TypePer <<  "ajoutée avec succès !" << endl;
    } else {
        cerr << "Erreur lors de l'ouverture du fichier Personnel.txt" << endl;
    }
}

void AfficherPerso()
{
    ifstream fichier("Personnel.txt", ios::app);
    if (fichier.is_open())
    {
        string ligne;
        while (getline(fichier, ligne))
        {
            cout << ligne << endl;
        }    
            fichier.close();
    }
    else
    {
        cerr << "Erreur lors de l'ouverture du fichier personnel.txt" << endl;
    }
        cin.ignore();
        cin.get();
}
void searchPerso()
{
    ifstream fichier("Personnel.txt");
    string nomRecherche;

    cout << "Entrer le nom de personnel à rechercher : ";
    cin >> nomRecherche;
    cout << endl;

    string nom, numeroDemp, TypePer, Departement;
    bool trouve = false;

    while (fichier >> nom >>numeroDemp >> TypePer >> Departement)
    {
        if (nom == nomRecherche)
        {
            trouve = true;
            cout << "Nom : " << nom << endl;
            cout << "numero d employe : " << numeroDemp << endl;
            cout << "Type personnel uni : " << TypePer << endl;
            cout << "Departement : " << Departement << endl
                 << endl;
        }
    }

    fichier.close();

    if (!trouve)
    {
        cout << "Aucun Personnel trouvé avec le nom " << nomRecherche << endl;
    }
    cin.ignore();
    cin.get();
}

void ModifierPerso(){
    cout << "Entrez le matricule du personnel que vous voulez modifier: ";
    int numeroDemp;
    cin >> numeroDemp;

    ifstream fichierIn("etudiant.txt");
    ofstream fichierOut("etudiant_temp.txt");

    if (fichierIn && fichierOut) {
        string ligne;
        while (getline(fichierIn, ligne)) {
           stringstream ss(ligne);
           PersonnelUni PersonnelUni ;
             ss >> PersonnelUni.Pnom >> PersonnelUni.numeroDemp >> PersonnelUni.Departement;
             if (PersonnelUni.numeroDemp == numeroDemp) {
               cout << "Modifier le  nom: ";
               cin >> PersonnelUni.Pnom;
               cout << "modifier le numero employe: ";
               cin >> PersonnelUni.numeroDemp;
               cout << "modifier le type d employe: ";
               cin >> PersonnelUni.TypePer;
               cout << "modifier le  departement: ";
               cin >> PersonnelUni.Departement;
            }
            fichierOut << PersonnelUni.Pnom << " "
                       << PersonnelUni.numeroDemp << " "
                       << PersonnelUni.TypePer << " "
                       << PersonnelUni.Departement << endl;
        }
        fichierIn.close();
        fichierOut.close();
        remove("Personnel.txt");
        rename("Personnel_temp.txt", "Personnel.txt");
        cout << "Modification terminée !" << endl;
    } else {
        cerr << "Erreur lors de l'ouverture des fichiers." << endl;
    }

}
  void AttribuerCours(Cours* cours) {
        coursEnseignes.push_back(cours);
    }
};
#endif 