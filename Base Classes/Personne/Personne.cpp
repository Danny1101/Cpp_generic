//
//  Personne.cpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 12/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#include "Personne.hpp"
#define $ Personne

#define defaultName "Unnamed"

using std::string;

unsigned int Personne::nbPersonneCree=0;

unsigned int Personne::getNbPersonnesCrees(void)const{
    return this->nbPersonneCree;
}

unsigned int nbPersonnesActuelles(void){
    return Personne::nbPersonneCree;
}

// Constructors
$::Personne(){ // Par défaut
    this->nom = defaultName;
    nbPersonneCree++;
    // Birthday set as default
}
$::Personne(Personne const& alias){ // Copy constructor
    this->nom = alias.nom;
    this->birthday = alias.birthday;
    nbPersonneCree++;
}

$::Personne(string const nom,Date const& birthday){
    this->nom = nom;
    this->birthday = birthday;
    nbPersonneCree++;
}

$::Personne(string const nom,uint const jour,uint const mois,uint const annee){
    this->nom = nom;
    this->birthday.setJour(jour);
    this->birthday.setMois(mois);
    this->birthday.setAnnee(annee);
    nbPersonneCree++;
}

// Getters
Date $::getBirthday(void)const{
    return this->birthday;
}
string $::getName(void)const{
    return this->nom;
}

uint $::getJour(void)const{
    return this->birthday.getJour();
}
uint $::getMois(void)const{
    return this->birthday.getMois();
}
uint $::getAnnee(void)const{
    return this->birthday.getAnnee();
}

// Setters
void $::setBirthday(Date const& alias){
    this->birthday = alias;
}
void $::setName(string const nom){
    this->nom = nom;
}

void $::setJour(uint const jour){
    this->birthday.setJour(jour);
}
void $::setMois(uint const mois){
    this->birthday.setMois(mois);
}
void $::setAnnee(uint const annee){
    this->birthday.setAnnee(annee);
}

// Opérateurs arithmétiques
Personne& $::operator=(Personne const& alias){
    this->nom = nom;
    this->birthday = alias.birthday;
    return *this;
}
/*Personne& operator+(Personne const&);
 Personne& operator+=(Personne const&);
 Personne& operator-(Personne const&);
 Personne& operator-=(Personne const&);*/

// Opérateurs Logiques
bool $::operator>(Personne const& alias)const{
    return this->birthday > alias.birthday;
}
bool $::operator >=(Personne const& alias)const{
    return this->birthday >= alias.birthday;
}
bool $::operator ==(Personne const& alias)const{
    return this->birthday == alias.birthday;
}
bool $::operator !=(Personne const& alias)const{
    return this->birthday != alias.birthday;
}
bool $::operator <=(Personne const& alias)const{
    return this->birthday <= alias.birthday;
}
bool $::operator <(Personne const& alias)const{
    return this->birthday <= alias.birthday;
}

// Contrôle du flux (stream)
std::ostream& operator<<(std::ostream& stream, Personne const& personne){
    stream << setw(50) << left << "Nom :" << personne.getName() << endl;
    stream << setw(50) << "Date de naissance : Le " << personne.getBirthday();
    return stream;
}

istream& operator>>(istream& stream,Personne& pers){
    stream >> pers.nom;
    stream.ignore(); // \n
    stream >> pers.birthday;
    return stream;
}

string $::toString()const{
    string sortie;
    sortie = "Nom : " + this->nom + '\n';
    sortie += "Date de naissance : Le " + this->getBirthday().toString();
    return sortie;
}

Personne::compl Personne(){
    nbPersonneCree--;
}

#undef defaultName
#undef $
