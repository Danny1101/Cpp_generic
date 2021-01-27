//
//  Ecole.hpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 19/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#ifndef Ecole_hpp
#define Ecole_hpp

#include "Equipe.hpp"
#include "Personne.hpp"
#include "Etudiant.hpp"
#include "EtudVaca.hpp"
#include "Professeur.hpp"
#include "PersExcep.h"
#include <vector>
#include <iostream>

using std::string;

typedef enum is {
    Pers,
    Prof,
    Etud,
    EtudVacat,
} type;

class Ecole : protected virtual Equipe{
    
    public :
    
    // Constructeurs
    Ecole();
    Ecole(Ecole const&);
    Ecole(Equipe const&);
    explicit Ecole(string const);
    explicit Ecole(string const,Etudiant const&);
    explicit Ecole(string const,Professeur const&);
    explicit Ecole(string const,EtudVaca const&);
    
    // Getters
    
    string getNom(void)const override;
    
    size_t getPersSize(is const)const;
    
    Personne getPers(unsigned int __at)const;
    Professeur getProf(unsigned int __at)const;
    Etudiant getEtud(unsigned int __at)const;
    EtudVaca getEtudVacat(unsigned int __at)const;
    
    size_t getSize(void)const override;
    
    void clear()override;
    
    // Setters
    
    void addProf(Professeur const&);
    void addEtudiant(Etudiant const&);
    void addEtudVacat(EtudVaca const&);
    
    void remove(unsigned int const __at);
    
    // Destructor
    compl Ecole();
    
    // Opérateurs
    Ecole& operator+=(Personne const&);
    Ecole& operator+=(Professeur const&);
    Ecole& operator+=(Etudiant const&);
    Ecole& operator+=(EtudVaca const&);
    
    Personne operator[](int const)const;
    Ecole& operator=(Ecole const&);
    
    bool operator>=(Ecole const&)const;
    bool operator>(Ecole const&)const;
    bool operator==(Ecole const&)const;
    bool operator!=(Ecole const&)const;
    bool operator<=(Ecole const&)const;
    bool operator<(Ecole const&)const;
    
    // Méthodes custom
    string toString()const override;
    
    bool contains(Personne const&)const;
    
    private :
    vector<is> type;
    
};

std::ostream& operator<<(ostream&,Ecole const&);

#endif /* Ecole_hpp */

