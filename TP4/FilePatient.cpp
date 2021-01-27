//
//  FilePatient.cpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 20/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#include "FilePatient.hpp"
#include "PersExcep.h"
#define $ FilePatient
#define removePatient this->patient.erase(this->patient.begin())
#define path "save.bin"

$::FilePatient() : patient() {}

$::FilePatient(FilePatient const& __alias) : patient(__alias.patient) {}

$::FilePatient(Personne const& debut){
    this->patient.push_back(debut);
}

$::FilePatient(unsigned int __initial_size) {
    while(true){
        try{
            patient.reserve(__initial_size);
            break;
        }
        catch(...){
            cout<<"Erreur, taille trop grande, veuillez saisir une taille valide !" << endl;
            cin >> __initial_size ;
        }
    }
    
}

void $::clear(){
    this->patient.clear();
}

// Setters
void $::setPatient(volatile const unsigned int __at,Personne const& newPatient){
    if (this->patient.size() <= __at)
        throw __bad_argument;
    
    this->patient.operator[](__at) = newPatient;
    
}

FilePatient& $::operator+=(Personne const& __added){
    try{
        this->patient.push_back(__added);
    }
    catch(exception const& e){
        cerr << e.what() << endl;
        cerr << "Le patient ne sera donc pas ajouté !" << endl;
    }
    
    return *this;
}
Personne $::operator--(){
    Personne sortie = this->patient[this->patient.size()-1];
    removePatient;
    return sortie;
}
Personne $::operator[](volatile const unsigned int __at)const{ // returns a copy
    return this->patient.operator[](__at);
}

$::compl FilePatient(){
    this->patient.clear();
}

FilePatient& $::operator=(FilePatient const& filePatient){
    this->patient = filePatient.patient;
    return *this;
}
bool $::operator==(FilePatient const& __eq){
    volatile unsigned int iterator(0);
    
    if (__eq.patient.size() != this->patient.size())
        return false;
    
    for(; iterator<patient.size()&&this->patient[iterator]==__eq.patient[iterator]&&this->patient[iterator].getName()==__eq.patient[iterator].getName() ; iterator++);
    
    return iterator==patient.size();
    
}
bool $::operator!=(FilePatient const& __not_eq){
    return !(*this==__not_eq);
}

bool $::testerVide()const{
    return this->patient.empty();
}
size_t $::nbPatient()const{
    return this->patient.size();
}

ostream& operator<<(ostream& stream,FilePatient const& file){
    stream << "File d'attente : ";
    for(unsigned int i=0 ; i<file.nbPatient() ; i++)
        stream << endl << file[i];
    
    return stream;
}

istream& operator>>(istream& stream,FilePatient& file){
    Personne pers;
    stream >> pers;
    file += pers;
    return stream;
}

bool FilePatient::load(ifstream& stream){
    try{
        Personne pers;
        while (stream.get() != '\n');
        while(!stream.eof()){
            stream >> pers;
            *this += pers;
        }
    }
    catch(exception& e){
        cerr << e.what() << endl;
        return false;
    }
    return true;
}

#undef $
#undef removePatient
#undef path
