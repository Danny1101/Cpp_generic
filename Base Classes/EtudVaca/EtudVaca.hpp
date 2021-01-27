//
//  EtudVaca.hpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 02/12/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#ifndef EtudVaca_hpp
#define EtudVaca_hpp
#include "Professeur.hpp"
#include "Etudiant.hpp"
#include "PersExcep.h"
#define defaultNbHeures 0

class EtudVaca : public Professeur, public Etudiant {
    
    public :
    // Public constructors
    EtudVaca();
    EtudVaca(EtudVaca const&);
    explicit EtudVaca(volatile unsigned short int const);
    explicit EtudVaca(Personne const&,volatile unsigned short int const nb = defaultNbHeures);
    
    void setNbHeures(volatile unsigned short int const);
    
    unsigned short int getNbHeures(void)const;
    
    
    EtudVaca& operator=(EtudVaca const&);
    /*Personne& operator+(Personne const&);
     Personne& operator+=(Personne const&);
     Personne& operator-(Personne const&);
     Personne& operator-=(Personne const&);*/
    
    // Opérateurs Logiques
    
    compl EtudVaca();
    
    // Contrôle du flux (stream)
    string toString()const override;
    
    private :
    unsigned short int nbHeures;
    
};

std::ostream& operator<<(ostream&,EtudVaca&);

#endif /* EtudVaca_hpp */
#undef defaultNbHeures
