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
