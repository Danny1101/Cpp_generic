//
//  Equipe.cpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 17/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#include "Equipe.hpp"
#define defaultNom "UNNAMED"
#define $ Equipe
#define newField(P) new Personne(P)

$::Equipe(){
    this->nom = defaultNom;
}
$::Equipe(Equipe const& __alias){
    this->nom = __alias.nom;
    this->tab = __alias.tab;
    this->dynamicFields = __alias.dynamicFields;
}
$::Equipe(string const nom){
    this->nom = nom;
}
$::Equipe(Personne const& pers){
    this->nom = defaultNom;
    this->tab.push_back(newField(pers));
    this->dynamicFields.push_back(true);
}
$::Equipe(Personne* const __restrict pers){
    
    if (pers == NULL)
        throw __null_ptr__;
    
    this->nom = nom;
    this->tab.push_back(pers);
    this->dynamicFields.push_back(false);
}
$::Equipe(string const nom,Personne const& pers){
    this->nom = nom;
    this->tab.push_back(newField(pers));
    this->dynamicFields.push_back(true);
}
$::Equipe(string const nom,Personne* const pers){
    if (pers == NULL)
        throw __null_ptr__;
    this->nom = nom;
    this->tab.push_back(pers);
    this->dynamicFields.push_back(false);
}

// Getters
string $::getNom(void)const{
    return this->nom;
}
size_t $::getSize(void)const{
    return this->tab.size();
}
Personne** $::getTabPointer(void){
    return &this->tab[0];
}

// Setters
void $::setNom(string const nom){
    this->nom = nom;
}
void $::addJoueur(Personne const& __added){
    this->tab.push_back(newField(__added));
    this->dynamicFields.push_back(true);
}
void $::addJoueur(Personne* __added){
    if (__added == NULL)
        throw __null_ptr__;
    this->tab.push_back(__added);
    this->dynamicFields.push_back(false);
}
bool $::suppJoueur(Personne const& __s){
    
    for(unsigned int i=0 ; i<tab.size() ; i++)
        if(*(this->tab[i]) == __s)
            if (this->tab[i]->getName() == __s.getName()){ // destroy the field
                if(this->dynamicFields[i])
                    delete this->tab[i];
                this->tab.erase(this->tab.begin()+i);
                this->dynamicFields.erase(this->dynamicFields.begin()+i);
                return true;
            }
    
    
    return false;
}
bool $::suppJoueur(int const __at){
    if(this->tab.size() <= __at)
        throw __out_of_range;
    
    if(this->dynamicFields[__at])
        delete this->tab[__at];
    this->tab.erase(this->tab.begin()+__at);
    this->dynamicFields.erase(this->dynamicFields.begin()+__at);
    
    
    return false;
}

// Destructor
$::compl Equipe(){
    for(unsigned int i=0 ; i<tab.size() ; i++)
        if (this->dynamicFields[i])
            delete this->tab[i];
    this->tab.clear();
    this->dynamicFields.clear();
    
}

void $::clear(){
    this->tab.clear();
    this->dynamicFields.clear();
}

// Opérateurs
Equipe& $::operator+=(Personne const& _p){
    this->addJoueur(_p);
    return *this;
}
Equipe& $::operator+=(Personne* _p){
    if (_p == NULL)
        throw __null_ptr__;
    this->addJoueur(_p);
    return *this;
}
Equipe& $::operator-=(Personne const& _s){
    this->suppJoueur(_s);
    return *this;
}

Personne& $::operator[](volatile int const iter)const{
    if (iter >= this->tab.size())
        throw __out_of_range;
    return *this->tab[iter];
}
Equipe $::operator=(Equipe const& eq){
    this->nom = eq.nom;
    tab = eq.tab;
    dynamicFields = eq.dynamicFields;
    return *this;
}

bool $::operator>(Equipe const& cmp)const{
    return this->tab.size() > cmp.getSize();
}
bool $::operator>=(Equipe const& cmp)const{
    return this->tab.size() >= cmp.getSize();
}
bool $::operator==(Equipe const& cmp)const{
    return this->tab.size() == cmp.getSize();
}
bool $::operator!=(Equipe const& cmp)const{
    return this->tab.size() != cmp.getSize();
}
bool $::operator<=(Equipe const& cmp)const{
    return this->tab.size() <= cmp.getSize();
}
bool $::operator<(Equipe const& cmp)const{
    return this->tab.size() < cmp.getSize();
}

// Méthodes custom
string $::toString()const{
    string output("Équipe : " + this->nom + '\n');
    for(unsigned int i=0 ; i<this->tab.size() ; output+= "\n\n" + this->tab[i++]->toString());
    return output;
}

bool $::contains(Personne const& __pers)const{
    for(unsigned int i=0 ; i<tab.size() ; i++){
        if(*(this->tab[i]) == __pers)
            if (this->tab[i]->getName() == __pers.getName()) // returns true
                return true;
    }
    
    return false;
    
}

std::ostream& operator<<(ostream& stream,Equipe& equipe){
    stream << "Nom de l'équipe : " << equipe.getNom();
    for (unsigned int i=0; i<equipe.getSize(); stream << endl << equipe[i++]);
    stream << endl;
    return stream;
}

#undef $
#undef newField
#undef defaultNom
