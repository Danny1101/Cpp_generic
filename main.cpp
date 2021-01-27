//
//  main.cpp
//  cpp s1 SI
//
//  Created by Adam Boukhssimi on 25/09/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "fperson.h"

#include "Base Classes/Personne/Personne.hpp"
#include "Base Classes/Professeur/Professeur.hpp"
#include "Base Classes/Etudiant/Etudiant.hpp"
#include "Base Classes/EtudVaca/EtudVaca.hpp"

#ifdef Personne_h
unsigned int nbPersonnesActuelles(void);
#define nbPersonnesActuelles  left << setw(51) << "Nombre de personnes actuelles crées : " << nbPersonnesActuelles()
#endif

using namespace std;

int main(void){
    vector<Personne> vect;
//    vect.push_back(Personne("lkdsflskdf",10,9,2000));
//
//    fperson::save(a);
//    cout << "Enregistré !" << endl;
    
    vect = fperson::load();
    
    for (unsigned int i=0; i<vect.size(); i++)
        cout << vect[i] << endl;
    
    return 8;
}










