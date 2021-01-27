//
//  FilePatient.hpp
//  C++ cours
//
//  Created by Adam Boukhssimi on 20/11/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#ifndef FilePatient_hpp
#define FilePatient_hpp
#include "Personne.hpp"
#include <vector>
#include <fstream>
//#include <math.h>

using std::string;

class FilePatient{ // FIRST IN = FIRST OUT
    
    public :
    //Constructors
    FilePatient();
    FilePatient(FilePatient const&);
    FilePatient(Personne const&);
    FilePatient(unsigned int);
    
    // Setters
    void setPatient(volatile const unsigned int __at,Personne const& newPatient);
    void clear(); // viderFile
    bool testerVide()const;
    //bool testerPleine()const;
    size_t nbPatient()const;
    
    compl FilePatient();
    
    FilePatient& operator+=(Personne const&);
    Personne operator--();
    Personne operator[](volatile const unsigned int __at)const;
    
    FilePatient& operator=(FilePatient const&);
    bool operator==(FilePatient const&);
    bool operator!=(FilePatient const&);
    
    bool load(ifstream&);
    friend istream& operator>>(istream&,FilePatient const&);
    
    private :
    vector<Personne> patient;
    
};

ostream& operator<<(ostream&,FilePatient const&);
istream& operator>>(istream& ,FilePatient&);

#endif /* FilePatient_hpp */
