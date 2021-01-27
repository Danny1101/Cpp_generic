//
//  fperson.h
//  C++ cours
//
//  Created by Adam Boukhssimi on 11/12/2017.
//  Copyright © 2017 Adam Boukhssimi. All rights reserved.
//

#ifndef fperson_h
#define fperson_h
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Base Classes/Personne/Personne.hpp"

namespace fperson {
    
    void save(vector<Personne>const& p,std::string const path="Tempo.txt"){
        
        ofstream stream(path);
        
        if(!stream)
            throw __bad_file;
        
        for (unsigned int i=0; i<p.size(); i++)
            stream << p[i] << endl;
        
        stream.close();
    }
    
    vector<Personne> load(std::string const path="Tempo.txt"){
        vector<Personne> p;
        ifstream stream(path);
        string temp;
        uint _temp;
        unsigned int iterator(0);
        
        if (!stream)
            throw __bad_file;
        
        while(!stream.eof()){
            
            for(unsigned short int i=0 ; i<50 ; i++)
                stream.ignore();
        
            p.push_back(Personne());
            getline(stream, temp);
            p[iterator].setName(temp);
            stream.ignore(); // for the \n
        
            for(unsigned short int i=0 ; i<50 ; i++)
                stream.ignore();
        
            // DAY
            stream >> _temp;
        
            if (_temp < 1 || _temp > 31)
                throw __bad_file;
        
            p[iterator].setJour(_temp);
            stream.ignore(); // for the /
        
            // MONTH
            stream >> _temp;
        
            if (_temp < 1 || _temp > 12)
                throw __bad_file;
        
            p[iterator].setMois(_temp);
            stream.ignore();
        
            // YEAR
            stream >> _temp;
        
            p[iterator++].setAnnee(_temp);
            stream.ignore();
        }
        
        return p;
        
    }
    
}


#endif /* fperson_h */
