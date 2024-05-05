#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h> //for getch()
#include <windows.h>//for system calls
#include <stdio.h>
#include <cwchar> 
#include "Etudiant.h"
using namespace std;


class MenuPrincipale{
    public:
    void afficherMenu(){
         /* SCHOOL MANAGEMENT */
    int i = 0, j;
    char choice;
    student etudiant;
    string find;
    string srch;
    student studentData;
    teacher tech[50];

    while (1)
    {

        cout << "\n                            \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf";
        cout << "\n                            \xb3 achraf Principale \xb3";
        cout << "\n                            \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9";
        cout << "\n";

        cout << "\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb";
        cout << "\n               \xba                                                \xba";
        cout << "\n               \xba    Interface Etudiant ......................1  \xba";
        cout << "\n               \xba    Personnal universitaire..................2  \xba";
        cout << "\n               \xba    Retour.................................. 4  \xba";
        cout << "\n               \xba                                                \xba";
        cout << "\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
        cout << "\n ";
        cout << "Votre Choix : ";
        cin >> choice;

        system("cls");

        switch (choice)
        {
        /* STUDENT */
        case '1':
        {
            while (1)
            {

                cout << "\n                            \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf";
                cout << "\n                            \xb3 Gestion des Etudiants \xb3";
                cout << "\n                            \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9";
                cout << "\n";

                cout << "\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb";
                cout << "\n               \xba                                                \xba";
                cout << "\n               \xba    Etudiant information.....................1  \xba";
                cout << "\n               \xba    Absence  ................................2  \xba";
                cout << "\n               \xba    Empoli Du temps..........................3  \xba";
                cout << "\n               \xba    Note.....................................4  \xba";
                cout << "\n               \xba    Retour...................................0  \xba";
                cout << "\n               \xba                                                \xba";
                cout << "\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
                cout << "\n ";
                cout << "Votre Choix : ";
                cin >> choice;

                system("cls");

                switch (choice)
                {

                case '1':
                {
                    while (1)
                    {

                        cout << "\n                            \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf";
                        cout << "\n                            \xb3 Etudiants Informations \xb3";
                        cout << "\n                            \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9";
                        cout << "\n";

                        cout << "\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb";
                        cout << "\n               \xba                                                \xba";
                        cout << "\n               \xba    Creer un nouveau etudiant................1  \xba";
                        cout << "\n               \xba    Consulter les etudiants..................2  \xba";
                        cout << "\n               \xba    Chercher les etudiants...................3  \xba";
                        cout << "\n               \xba    modifier un etudiant.....................4  \xba";
                        cout << "\n               \xba    Supprimer un etudiant....................5  \xba";
                        cout << "\n               \xba    Retour...................................0  \xba";
                        cout << "\n               \xba                                                \xba";
                        cout << "\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
                        cout << "\n ";
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

                        default:
                            cout << "Choix invalide." << endl;
                        }
                    }
                }
                }
                
            }
            /* TEACHERS */
        case '2':
        {
            while (1)
            {
                system("cls");

                cout << "\t\t\tTEACHERS INFORMATION AND BIODATA SECTION\n\n\n";
                cout << "Enter your choice: " << endl;
                cout << "1.Create new entry\n";
                cout << "2.Find and display\n";
                cout << "3.Delete a previous entry\n";
                cout << "4.Jump to main\n";
                cin >> choice;
                switch (choice)
                {
                case '1':
                {
                    ofstream t1("teacher.txt", ios::app);
                    for (i = 0; choice != 'n' && choice != 'N'; i++)
                    {
                        if ((choice == 'y') || (choice == 'Y') || (choice == '1'))
                        {
                            cout << "Enter First name: ";
                            cin >> tech[i].fst_name;
                            cout << "Enter Last name:: ";
                            cin >> tech[i].lst_name;
                            cout << "Enter qualification: ";
                            cin >> tech[i].qualification;
                            cout << "Enter experiance(year): ";
                            cin >> tech[i].exp;
                            cout << "Enter number of year in this School: ";
                            cin >> tech[i].serves;
                            cout << "Enter Course of teacher: ";
                            cin >> tech[i].subj;
                            cout << "Enter Lecture(per Week): ";
                            cin >> tech[i].lec;
                            cout << "Enter pay: ";
                            cin >> tech[i].pay;
                            cout << "Enter Phone Number: ";
                            cin >> tech[i].cel_no;
                            cout << "Enter Blood Group: ";
                            cin >> tech[i].blod_grp;

                            t1 << tech[i].fst_name << endl
                               << tech[i].lst_name << endl
                               << tech[i].qualification << endl
                               << tech[i].exp << endl
                               << tech[i].serves << endl
                               << tech[i].subj << endl
                               << tech[i].lec
                               << endl
                               << tech[i].pay << endl
                               << tech[i].cel_no << endl
                               << tech[i].blod_grp << endl;
                            cout << "Do you want to enter data: ";
                            cin >> choice;
                        }
                    }
                    system("cls");
                    t1.close();
                }

                    continue;
                case '2':
                {
                    ifstream t2("teacher.txt");
                    cout << "Enter name to be displayed: ";
                    cin >> find;
                    cout << endl;
                    int notFound = 0;
                    for (j = 0; ((j < i) || (!t2.eof())); j++)
                    {
                        getline(t2, tech[j].fst_name);
                        if (tech[j].fst_name == find)
                        {
                            notFound = 1;
                            cout << "First name: " << tech[j].fst_name << endl;
                            getline(t2, tech[j].lst_name);
                            cout << "Last name: " << tech[j].lst_name << endl;
                            getline(t2, tech[j].qualification);
                            cout << "Qualification: " << tech[j].qualification << endl;
                            getline(t2, tech[j].exp);
                            cout << "Experience: " << tech[j].exp << endl;
                            getline(t2, tech[j].serves);
                            cout << " number of year in this School: " << tech[j].serves << endl;

                            getline(t2, tech[j].subj);
                            cout << "Subject whos teach: " << tech[j].subj << endl;

                            getline(t2, tech[j].lec);
                            cout << "Enter Lecture(per Week): " << tech[j].lec << endl;
                            getline(t2, tech[j].pay);
                            cout << "pay: " << tech[j].pay << endl;

                            getline(t2, tech[j].addrs);
                            cout << "Address: " << tech[j].addrs << endl;

                            getline(t2, tech[j].cel_no);
                            cout << "Phone Number: " << tech[j].cel_no << endl;

                            getline(t2, tech[j].blod_grp);
                            cout << "Bool Group: " << tech[j].blod_grp << endl;
                        }
                    }
                    t2.close();
                    if (notFound == 0)
                    {
                        cout << "No Record Found" << endl;
                    }
                    cout << "Press any key two times to proceed";
                    getch();
                    getch();
                } // case 2
                    continue;
                case '3':
                {
                    deleting_T();
                } // case 3
                    continue;
                case '4':
                {
                    break;
                } // case 4
                }
                break;
            }
            continue;
        }

        case '3':
        {
            break;
        }
        }
        break;
        }
        
    }
    }
};