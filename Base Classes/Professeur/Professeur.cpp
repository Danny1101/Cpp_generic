//
//  Professeur.cpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 30/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#include "Professeur.hpp"
#define defaultFilliere Filiere::SEII
#define super Personne::
#define defaultEtablissement "Pas d'établissement assigné"
#define $ Professeur

// Constructors
$::Professeur() : Personne() , filiere(defaultFilliere) , etablissement(defaultEtablissement) {} // Par défaut
$::Professeur(Professeur const& prof) : Personne(prof) , filiere(prof.filiere) , etablissement(prof.etablissement) {} // Copy constructor
$::Professeur(Professeur const& prof,Filiere const& fil, string const etab) : Personne(prof), filiere(fil) , etablissement(etab) {}
$::Professeur(Personne const& personne) : Personne(personne) , filiere(defaultFilliere) , etablissement(defaultEtablissement) {}

$::compl Professeur(){
    super nbPersonneCree--;
}

// Getters
Personne $::getPersonne(void)const{
    return static_cast<Personne>(*this);
}
Filiere $::getFiliere(void)const{
    return this->filiere;
}
string $::getEtablissement(void)const{
    return this->etablissement;
}

// Setters
void $::setPersonne(Personne const& pers){
    super operator=(pers);
}
void $::setFiliere(Filiere const& filiere){
    this->filiere=filiere;
}
void $::setEtablissement(string const nom){
    etablissement=nom;
}

// Opérateurs arithmétiques
Professeur& $::operator=(Professeur const& etud){
    super operator=(etud);
    this->filiere = etud.filiere;
    this->etablissement = etud.etablissement;
    return *this;
}

// Contrôle du flux (stream)
string $::toString()const{
    string output;
    
    output = super toString();
    output += "\nMatière : ";
    switch (this->filiere) {
        case Filiere::SEII:
            output += "Systèmes embarqués et informatique industrielle";
            break;
            
        case Filiere::INFO:
            output += "Génie informatique";
            break;
            
        case Filiere::MECA:
            output += "Génie mécanique";
            break;
            
        case Filiere::INDUS:
            output += "Génie industriel";
            break;
            
        case Filiere::GTR:
            output += "Génie des télécommunications et réseaux";
            break;
            
        default:
            throw __unkown_error;
            break;
    }
    
    output += "\nÉtablissement : " + etablissement;
    
    return output;
}

std::ostream& operator<< (std::ostream& stream, Professeur const& prof){
    stream << prof.toString() << endl;
    return stream;
}
std::istream& operator>>(istream& stream,Professeur& prof){
    Personne temp;
    unsigned short int enume;
    stream >> temp;
    stream >> enume;
    
    switch (enume) {
        case 1:
            prof.setFiliere(Filiere::SEII);
            break;
        case 2:
            prof.setFiliere(Filiere::INFO);
            break;
        case 3:
            prof.setFiliere(Filiere::MECA);
            break;
        case 4:
            prof.setFiliere(Filiere::INDUS);
            break;
        case 5:
            prof.setFiliere(Filiere::GTR);
            break;
            
        default:
            throw __bad_argument;
            break;
    }
    prof.setPersonne(temp);
    stream >> prof.etablissement;
    return stream;
}

#undef $
#undef defaultFilliere
#undef super
#undef defaultEtablissement
