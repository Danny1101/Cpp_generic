//
//  d.hpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 13/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include "PersExcep.h"

using namespace std;

class Date final{
    
    public :
    
    // Constructeurs
    Date(); // Par défaut
    explicit Date(unsigned int const,unsigned int const,unsigned int const);
    Date(Date const&); // Copy constructor
    
    // Getters
    unsigned int getJour(void)const;
    unsigned int getMois(void)const;
    unsigned int getAnnee(void)const;
    
    // Setters
    void setJour(volatile const unsigned int);
    void setMois(volatile const unsigned int);
    void setAnnee(volatile const unsigned int);
    
    // Opérateurs Arithmétiques
    Date& operator=(Date const&);
    /*Date& operator+(Date const&);
     Date& operator+=(Date const&);
     Date& operator-(Date const&);
     Date& operator-=(Date const&);*/
    
    // Opérateurs Logiques
    bool operator >(Date const&)const;
    bool operator >=(Date const&)const;
    bool operator ==(Date const&)const;
    bool operator !=(Date const&)const;
    bool operator <=(Date const&)const;
    bool operator <(Date const&)const;
    
    // Control de flux
    
    friend std::istream& operator>>(std::istream& flux, Date& date);
    
    // Void destructor
    
    string toString()const;
    
    private :
    unsigned int jour,mois,annee;
    
};

std::ostream& operator<<(std::ostream& flux, Date const& date);
std::istream& operator>>(std::istream& flux, Date const& date);


#endif /* Date_h */

