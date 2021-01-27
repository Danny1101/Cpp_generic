//
//  Equipe.hpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 17/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#ifndef Equipe_hpp
#define Equipe_hpp

#include "Personne.hpp"
#include "PersExcep.h"
#include <vector>

using std::string;

// ecole

class Equipe{
    public :
    
    Equipe();
    Equipe(Equipe const&);
    explicit Equipe(string const);
    explicit Equipe(Personne const&);
    explicit Equipe(Personne* const __restrict__ );
    explicit Equipe(string const,Personne const&);
    explicit Equipe(string const,Personne* const);
    
    // Getters
    virtual string getNom(void)const;
    virtual size_t getSize(void)const;
    Personne** getTabPointer(void);
    
    virtual void clear();
    
    // Setters
    virtual void setNom(string const);
    void addJoueur(Personne const&);
    void addJoueur(Personne*);
    bool suppJoueur(Personne const&);
    bool suppJoueur(int const __at);
    
    // Destructor
    compl Equipe();
    
    // Opérateurs
    Equipe& operator+=(Personne const&);
    Equipe& operator+=(Personne*);
    Equipe& operator-=(Personne const&);
    
    Personne& operator[](volatile int const)const;
    Equipe operator=(Equipe const&);
    
    bool operator>=(Equipe const&)const;
    bool operator>(Equipe const&)const;
    bool operator==(Equipe const&)const;
    bool operator!=(Equipe const&)const;
    bool operator<=(Equipe const&)const;
    bool operator<(Equipe const&)const;
    
    // Méthodes custom
    virtual string toString()const;
    
    bool contains(Personne const&)const;
    
    private :
    vector<Personne*> tab;
    vector<bool> dynamicFields;
    string nom;
    
};

std::ostream& operator<<(ostream&,Equipe&);

#endif /* Equipe_hpp */

