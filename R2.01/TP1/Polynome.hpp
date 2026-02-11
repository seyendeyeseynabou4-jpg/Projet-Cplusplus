#ifndef POLYNOME_HPP
#define POLYNOME_HPP

#include <iostream> 

class Polynome {
    private:
        
        unsigned int degre ; 
        double * coef; 

    public:

        Polynome (unsigned int degre, const double* coef);  

        Polynome()= delete; //interdirction de la construction d'une instance vide

        Polynome(const Polynome &src); //Constructeur de copie 

        ~Polynome () ;//Le destructeur 

        inline unsigned int getDegre(){ return degre ; }

        Polynome deriver() const ; 

        Polynome operator=(const Polynome &p) ;

        friend bool operator== (const Polynome & p1, const Polynome & p2); 

        friend Polynome operator+ (const Polynome a, const Polynome b);

        friend Polynome operator- (const Polynome &m, const Polynome &n);

        friend std::ostream &operator<<(std::ostream & os, const Polynome &p);

        inline double  operator[](size_t i){ if(i <= degre ) return coef[i]; else throw std::runtime_error("Le degré de votre polynome est superieur au nombre de case"); }

        double operator()(const double &x);

};



#endif 