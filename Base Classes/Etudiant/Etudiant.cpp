//
//  Etudiant.cpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 30/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#include "Etudiant.hpp"
#define defaultFiliere Filiere::SEII
#define defaultNote 0
#define $ Etudiant
#define super Personne::

$::Etudiant() : Personne() , filiere(defaultFiliere) , note(defaultNote) {}
$::Etudiant(Etudiant const& __alias) : Personne(__alias){ // Copy constructor
    this->filiere = __alias.filiere;
    this->note = __alias.note;
}
$::Etudiant(Personne const& pers,Filiere const& fil,volatile float _note) : Personne(pers) , filiere(fil) {
    if (note < 0)
        throw __bad_argument;
    this->note = _note;
}

$::Etudiant(Personne const& pers) : Personne(pers), filiere(defaultFiliere) , note(defaultNote) {}

// Getters
Personne $::getPersonne(void)const{
    return static_cast<Personne>(*this);
}
Filiere $::getFiliere(void)const{
    return this->filiere;
}
float $::getNote(void)const{
    return this->note;
}

$::compl Etudiant(){
    super nbPersonneCree--;
}

// Setters
void $::setPersonne(Personne const& pers){
    this->Personne::operator=(pers);
}
void $::setFiliere(Filiere const& filiere){
    this->filiere = filiere;
}
void $::setNote(volatile float note){
    if (note < 0)
        throw __bad_argument;
    this->note = note;
        
}

// Opérateurs arithmétiques
Etudiant& $::operator=(Etudiant const& etud){
    super operator=(etud);
    this->note = etud.note;
    this->filiere = etud.filiere;
    return *this;
}

// Contrôle du flux (stream)
string $::toString()const{
    string output;
    
    output = super toString();
    output += "\nFilière : ";
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
    
    output += "\nNote : " + to_string(note);
    
    return output;
}

std::ostream& operator<< (std::ostream& stream, Etudiant const& etudiant){
    stream << etudiant.toString() << endl;
    return stream;
}
std::istream& operator>>(istream& stream,Etudiant& etudiant){
    Personne temp;
    unsigned short int enume;
    stream >> temp;
    stream >> enume;
    
    switch (enume) {
        case 1:
            etudiant.setFiliere(Filiere::SEII);
            break;
        case 2:
            etudiant.setFiliere(Filiere::INFO);
            break;
        case 3:
            etudiant.setFiliere(Filiere::MECA);
            break;
        case 4:
            etudiant.setFiliere(Filiere::INDUS);
            break;
        case 5:
            etudiant.setFiliere(Filiere::GTR);
            break;
            
        default:
            throw __bad_argument;
            break;
    }
    etudiant.setPersonne(temp);
    stream >> etudiant.note;
    return stream;
}

#undef super
#undef $
#undef defaultNote
#undef defaultFiliere
