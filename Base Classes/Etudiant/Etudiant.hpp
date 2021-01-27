//
//  Etudiant.hpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 30/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#ifndef Etudiant_hpp
#define Etudiant_hpp

#include "Personne.hpp"
#include "PersExcep.h"

typedef enum Filiere {
    SEII,
    INFO,
    MECA,
    INDUS,
    GTR
} Filiere;

class Etudiant : public virtual Personne {
    
    public :
    
    // Constructors
    Etudiant(); // Par défaut
    Etudiant(Etudiant const&); // Copy constructor
    explicit Etudiant(Personne const&,Filiere const&,volatile float);
    explicit Etudiant(Personne const&);
    
    compl Etudiant();
    
    // Getters
    Personne getPersonne(void)const;
    Filiere getFiliere(void)const;
    float getNote(void)const;
    
    // Setters
    void setPersonne(Personne const&);
    void setFiliere(Filiere const&);
    void setNote(volatile float);
    
    // Opérateurs arithmétiques
    Etudiant& operator=(Etudiant const&);
    
    // Contrôle du flux (stream)
    virtual string toString()const;
    friend std::istream& operator>>(istream&,Etudiant&);
    
    private :
    Filiere filiere;
    float note;
    
};

std::ostream& operator<< (std::ostream&, Etudiant const&);
std::istream& operator>>(istream&,Etudiant&);

#endif /* Etudiant_hpp */
