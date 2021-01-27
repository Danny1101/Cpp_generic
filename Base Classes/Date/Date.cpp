//
//  Date.cpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 12/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#include "Date.hpp"
#define $ Date

#define defaultDay 1
#define defaultMonth 1
#define defaultYear 1970

#define __INF_LOOP while(true)

$::Date(){ // Par défaut``
    this->jour = defaultDay;
    this->mois = defaultMonth;
    this->annee=defaultYear;
}

$::Date(unsigned int const jour,unsigned int const mois=1,unsigned int const annee=1970){
    if (jour < 1 || jour > 31)
        throw __out_of_range;
    
    if (mois < 1 || mois > 12)
        throw __out_of_range;
    
    this->jour = jour;
    this->mois = mois;
    this->annee = annee;
    
}

$::Date(Date const& alias){ // Copy constructor
    this->jour = alias.jour;
    this->mois = alias.mois;
    this->annee = alias.annee;
}

// Getters
unsigned int $::getJour(void)const{
    return this->jour;
}
unsigned int $::getMois(void)const{
    return this->mois;
}
unsigned int $::getAnnee(void)const{
    return this->annee;
}

// Setters
void $::setJour(volatile const unsigned int jour){
    if (jour < 1 || jour > 31)
        throw __out_of_range;
    this->jour = jour;
}
void $::setMois(volatile const unsigned int mois){
    if (mois < 1 || mois > 12)
        throw __out_of_range;
    this->mois = mois;
}
void $::setAnnee(volatile const unsigned int annee){
    this->annee = annee;
}

// Opérateurs Arithmétiques
Date& $::operator=(Date const& alias){
    this->jour = alias.jour;
    this->mois = alias.mois;
    this->annee = alias.annee;
    
    return *this;
}

// Opérateurs Logiques
bool $::operator >(Date const& alias)const{
    if (this->annee < alias.annee) // (*this) est né avant (alias)
        return true;
    
    if (this->annee > alias.annee)
        return false;
    
    if (this->mois < alias.mois) // (*this) est né avant (alias)
        return true;
    
    if (this->mois > alias.mois)
        return false;
    
    if (this->jour < alias.jour) // (*this) est né avant (alias)
        return true;
    
    else return false;
    
}

bool $::operator ==(Date const& alias)const{
    return ( this->annee==alias.annee && this->mois==alias.mois && this->jour==alias.jour );
}

bool $::operator >=(Date const& alias)const{
    return ( *this==alias && *this>alias );
}

bool $::operator !=(Date const& alias)const{
    return !( *this==alias );
}
bool $::operator <=(Date const& alias)const{
    return !( *this > alias );
}
bool $::operator <(Date const& alias)const{
    return !( *this <= alias && *this!= alias);
}

// Opérateur de flux

std::ostream& operator<< (std::ostream& flux, Date const& date){
    flux << date.toString();
    return flux;
}

std::istream& operator>>(std::istream& flux, Date& date){ // jj/mm/aa
    flux >> date.jour;
    if (date.jour < 1 || date.jour > 31)
        throw __out_of_range;
    flux.ignore();
    flux >> date.mois;
    if (date.mois < 1 || date.mois > 12)
        throw __out_of_range;
    flux.ignore();
    flux >> date.annee;
    if (date.annee < 1900)
        throw __out_of_range;
    flux.ignore();
    return flux;
}

// Méthode privée

std::string $::toString()const{ // jj/mm/aa
    string output;
    
    output = (jour>9)? ("") : ("0");
    output += std::to_string(this->jour);
    
    output += '/';
    
    output += (mois>9)? ("") : ("0");
    output += std::to_string(this->mois);
    
    output += '/';
    
    output += std::to_string(this->annee);
    
    return output;
}

#undef defaultDay
#undef defaultMonth
#undef defaultYear
#undef __INF_LOOP
#undef $
