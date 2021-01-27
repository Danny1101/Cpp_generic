//
//  EtudVaca.cpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 02/12/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#include "EtudVaca.hpp"

#ifndef defaultNbHeures
#define defaultNbHeures 0
#endif

#define $ EtudVaca


$::EtudVaca() : Professeur(),Etudiant(),Personne(),nbHeures(defaultNbHeures) {}
$::EtudVaca(EtudVaca const& alias) : Professeur(alias),Etudiant(alias),Personne(alias),nbHeures(alias.nbHeures){}
$::EtudVaca(volatile unsigned short int const nb):Professeur(),Etudiant(),Personne(),nbHeures(nb) {}
$::EtudVaca(Personne const& personne,volatile unsigned short int const nb) : Personne(personne),Professeur(),Etudiant() ,nbHeures(nb){}

void $::setNbHeures(volatile unsigned short int const _new){
    nbHeures = _new;
}

unsigned short int $::getNbHeures(void)const{
    return this->nbHeures;
}

EtudVaca& $::operator=(EtudVaca const& etud){
    this->Professeur::operator=(etud);
    this->Etudiant::operator=(etud);
    this->nbHeures = etud.nbHeures;
    return *this;
}
/*Personne& operator+(Personne const&);
 Personne& operator+=(Personne const&);
 Personne& operator-(Personne const&);
 Personne& operator-=(Personne const&);*/

$::compl EtudVaca(){
    this->nbPersonneCree += 2;
    /*
     2 destructeurs de personnes seront activés, alors on incrémentera la valeur de nbPersonnesCree pour obtenir nbPersonnesCree+1-2 = nbPersonnesCree-au final :)
     */
}

// Contrôle du flux (stream)
string $::toString()const{
    return (this->Professeur::toString() + '\n' + this->Etudiant::toString() + '\n' + "Nombre d'heures : " + to_string(nbHeures) );
}

std::ostream& operator<<(ostream& stream,EtudVaca& etudVacat){
    stream << etudVacat.toString() << endl;
    return stream;
}


#undef $
#undef defaultNbHeures
