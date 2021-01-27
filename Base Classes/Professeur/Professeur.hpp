//
//  Professeur.hpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 30/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#ifndef Professeur_hpp
#define Professeur_hpp
#include "PersExcep.h"
#include "Personne.hpp"
#include "Etudiant.hpp"

class Professeur : public virtual Personne{
    
    public :
    
    // Constructors
    Professeur(); // Par défaut
    Professeur(Professeur const&); // Copy constructor
    explicit Professeur(Professeur const&,Filiere const&, string const);
    explicit Professeur(Personne const&);
    
    compl Professeur();
    
    // Getters
    Personne getPersonne(void)const;
    Filiere getFiliere(void)const;
    string getEtablissement(void)const;
    
    // Setters
    void setPersonne(Personne const&);
    void setFiliere(Filiere const&);
    void setEtablissement(string const);
    
    // Opérateurs arithmétiques
    Professeur& operator=(Professeur const&);
    
    // Contrôle du flux (stream)
    virtual string toString()const;
    friend std::istream& operator>>(istream&,Professeur&);
    
    private :
    Filiere filiere;
    string etablissement;
    
};

std::ostream& operator<< (std::ostream&, Professeur const&);
std::istream& operator>>(istream&,Professeur&);
#endif /* Professeur_hpp */
