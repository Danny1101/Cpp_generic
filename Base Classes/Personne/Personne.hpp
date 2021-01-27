//
//  d.hpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 13/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#ifndef Personne_h
#define Personne_h

#include "PersExcep.h"
#include "Date.hpp"
#include <iomanip>

using std::string;

class Personne{
    public :
    
    // Constructors
    Personne();                 // Par défaut
    Personne(Personne const&);  // Copy constructor
    explicit Personne(string const,Date const&);
    explicit Personne(string const,uint const jour,uint const mois,uint const annee);
    
    // Getters
    Date getBirthday(void)const;
    string getName(void)const;
    unsigned int getNbPersonnesCrees(void)const;
    
    uint getJour(void)const;
    uint getMois(void)const;
    uint getAnnee(void)const;
    
    // Setters
    void setBirthday(Date const&);
    void setName(string const);
    
    void setJour(uint const);
    void setMois(uint const);
    void setAnnee(uint const);
    
    // Opérateurs arithmétiques
    virtual Personne& operator=(Personne const&);
    /*Personne& operator+(Personne const&);
     Personne& operator+=(Personne const&);
     Personne& operator-(Personne const&);
     Personne& operator-=(Personne const&);*/
    
    // Opérateurs Logiques
    bool operator >(Personne const&)const;
    bool operator >=(Personne const&)const;
    bool operator ==(Personne const&)const;
    bool operator !=(Personne const&)const;
    bool operator <=(Personne const&)const;
    bool operator <(Personne const&)const;
    
    compl Personne();
    
    // Contrôle du flux (stream)
    virtual string toString()const;
    friend std::istream& operator>>(istream&,Personne&);
    friend unsigned int nbPersonnesActuelles(void);
    
    protected :
    static unsigned int nbPersonneCree;
    
    private :
    Date birthday;
    string nom;
};

std::ostream& operator<< (std::ostream&, Personne const&);
std::istream& operator>>(istream&,Personne&);

#endif /* Personne_h */

