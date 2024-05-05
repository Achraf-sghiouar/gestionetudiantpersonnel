#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h> //for getch()
#include <windows.h>//for system calls
#include <stdio.h>
#include <cwchar> 
#include "Etudiant.h"
using namespace std;
class teacher
{
 public:
 string fst_name;//first name of teacher
 string lst_name;//last name of teacher
 string qualification;//Qualification of teacher
 string exp;//Experiance of the person
 string pay;//Pay of the Teacher
 string subj;//subject whos he/she teach
 string lec;//Lecture per Week
 string addrs;//Adders of teacher home
 string cel_no;//Phone number 
 string blod_grp;//Bool Group 
 string serves;//Number of serves in School

};


void deleting_T()
{
    string line, name;
    cout << "Please Enter the name of record you want to delete: ";
    cin >> name;
    ifstream f2;
    ofstream temp;
    f2.open("teacher.txt");
    temp.open("temp.txt");
    while (getline(f2, line))
    {
        if (line != name)
            temp << line << endl;
    }
    cout << "The record with the name " << name << " has been deleted if it exsisted" << endl;
    f2.close();
    temp.close();
    remove("teacher.txt");
    rename("temp.txt", "teacher.txt");
}

