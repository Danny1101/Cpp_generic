//
//  Ecole.cpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 19/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#include "Ecole.hpp"
#define $ Ecole

// Constructeurs
$::Ecole():Equipe() {}
$::Ecole(Ecole const& __alias){
    this->Equipe::operator=(__alias);
    this->type = __alias.type;
}
$::Ecole(Equipe const& eq):Equipe(eq){
    this->type.push_back(is::Pers);
}
$::Ecole(string const nom) : Equipe(nom) {};

$::Ecole(string const nom,Etudiant const& __e) : Equipe(nom,__e){
    this->type.push_back(is::Etud);
}

$::Ecole(string const nom,Professeur const& prof) : Equipe(nom,prof){
    this->type.push_back(is::Prof);
}

$::Ecole(string const nom,EtudVaca const& etudVaca) : Equipe(nom,etudVaca.Professeur::getPersonne()){
    this->type.push_back(is::EtudVacat);
}

string $::getNom(void)const{
    return this->Equipe::getNom();
}

size_t $::getPersSize(is const type)const{
    size_t output(0);
    
    for (unsigned int i=0; i<this->type.size(); i++)
        if(this->type[i] == type)
            output++;
    
    return output;
    
}
#define getType(__AT__UNSIGNED_INT_CONST,_ENUMERATION_TYPE_PERSONNE,_CLASS_TYPE_PERSONNE) unsigned int i;\
for (i=0; i<this->type.size(); i++)\
if(this->type[i] == (_ENUMERATION_TYPE_PERSONNE)){\
if ((__AT__UNSIGNED_INT_CONST)-- == 0)\
break;}\
return static_cast<_CLASS_TYPE_PERSONNE>(this->Equipe::operator[](i));

Personne $::getPers(unsigned int __at)const{
    if (__at >= this->type.size())
        throw __out_of_range;
    getType(__at,is::Pers,Personne)
}

#undef getType

EtudVaca $::getEtudVacat(unsigned int __at)const{
    
    if(__at >= this->type.size())
        throw __out_of_range;
    
    unsigned int i=0;
    for (i=0; i<this->type.size(); i++)
        if(this->type[i] == (is::EtudVacat)){
            if ((__at)-- == 0)
                break;}
    
    return *dynamic_cast<EtudVaca*>(&this->Equipe::operator[](i));
}

size_t $::getSize(void)const{
    return this->Equipe::getSize();
}

void $::clear(){
    this->type.clear();
    this->Equipe::clear();
}

void $::addProf(Professeur const& __p){
    this->Equipe::addJoueur(__p);
    this->type.push_back(is::Prof);
}
void $::addEtudiant(Etudiant const& __e){
    this->Equipe::addJoueur(__e);
    this->type.push_back(is::Etud);
}

void $::addEtudVacat(EtudVaca const& etudVacat){
    this->Equipe::addJoueur(etudVacat.Professeur::getPersonne());
    this->type.push_back(is::EtudVacat);
}


void $::remove(unsigned int const __at){
    if (__at >= this->type.size())
        throw __bad_argument;
    this->Equipe::suppJoueur(__at);
    this->type.erase(this->type.begin() + __at);
}

$::compl Ecole(){
    this->clear();
}

Ecole& $::operator+=(Personne const& _p){
    this->Equipe::addJoueur(_p);
    this->type.push_back(is::Pers);
    return *this;
}
Ecole& $::operator+=(Professeur const& _prof){
    this->Equipe::addJoueur(_prof);
    this->type.push_back(is::Prof);
    return *this;
}
Ecole& $::operator+=(Etudiant const& _etud){
    this->Equipe::addJoueur(_etud);
    this->type.push_back(is::Etud);
    return *this;
}
Ecole& $::operator+=(EtudVaca const& etudVacat){
    this->Equipe::addJoueur(etudVacat.Professeur::getPersonne());
    this->type.push_back(is::EtudVacat);
    return *this;
}

Personne $::operator[](int const _iter)const{
    if(_iter>this->getSize() || _iter < 0)
        throw __out_of_range;
    return this->Equipe::operator[](_iter);
}
Ecole& $::operator=(Ecole const& ecole){
    this->Equipe::operator=(ecole);
    this->type.clear();
    this->type = ecole.type;
    return *this;
}

bool $::operator>=(Ecole const& _e)const{
    return this->Equipe::getSize() >= _e.getSize();
}
bool $::operator>(Ecole const& _e)const{
    return this->Equipe::getSize() > _e.getSize();
}
bool $::operator==(Ecole const& _e)const{
    return this->Equipe::getSize() == _e.getSize();
}
bool $::operator!=(Ecole const& _e)const{
    return this->Equipe::getSize() != _e.getSize();
}
bool $::operator<=(Ecole const& _e)const{
    return this->Equipe::getSize() <= _e.getSize();
}
bool $::operator<(Ecole const& _e)const{
    return this->Equipe::getSize() < _e.getSize();
}

string $::toString()const{
    return this->Equipe::toString();
}

bool $::contains(Personne const& _p)const{
    return this->Equipe::contains(_p);
}

std::ostream& operator<<(ostream& stream,Ecole const& ecole){
    
    stream << "Nom de l'école : " << ecole.getNom();
    
    for (unsigned int i=0 ; i<ecole.getSize() ; stream << endl << ecole[i++]);
    
    stream << endl;
    
    return stream;
}
#undef $

