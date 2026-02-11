#include <iostream>
#include <cmath>
#include "Polynome.hpp"


     Polynome::Polynome (unsigned int  _degre, const double*  _coef)
     : degre(_degre), coef(nullptr)
     {
        coef = new double [degre + 1]; 
        for(size_t i = 0; i <= degre; i++ )
            coef[i] = _coef[i];        
     }


    Polynome::Polynome(const Polynome & src)
    : degre(src.degre), coef(nullptr)
    {
        coef = new double [degre + 1]; 
        for(size_t i = 0; i <= degre ; i++)
            coef[i] = src.coef[i];
    } 


    Polynome:: ~Polynome (){

        delete[] coef; 

    }

    Polynome Polynome::deriver() const{
        double  val [1] = {0.0};
        if(degre == 0)
                return Polynome(0,val);

        double* temp = new double [degre];

        for(size_t i = 1 ; i <= degre; i++ )
            temp[i-1] = coef[i]*i ;
        
        Polynome p_temp(degre -1 , temp);
        delete [] temp ; 
        return p_temp ; 
    }

    
    Polynome Polynome::operator=(const Polynome &p){
        delete [] coef ;  //Pour etre sur qu'on a asssez d'espace pour tout copier 
        coef = new double [p.degre + 1]; 
        degre = p.degre ; 
        for(size_t i = 0; i <= degre ; i++)
            coef[i] = p.coef[i];

        return *this; 
    }


    bool operator== (const Polynome & p1, const Polynome & p2 ){
        if(p1.degre != p2.degre ) return false; 

        for(size_t i = 0; i <= p1.degre; i++ )
            if(p1.coef[i] != p2.coef[i]) return false ;

        return true; 
    } 

    
    Polynome operator+ (const Polynome a, const Polynome b){
        const Polynome &big = (a.degre >= b.degre ? a:b); 
        const Polynome &small = (a.degre < b.degre ? a:b ); 
        Polynome res(big); 
        // res += small;
        for(size_t i = 0 ; i <= small.degre ; i++)
            res.coef[i] += small.coef[i];
        
        return res;    
    }


    Polynome operator-(const Polynome&m, const Polynome &n){
        unsigned int max_degre = (m.degre >= n.degre ? m.degre:n.degre);
        double *tmp = new double [max_degre + 1];
        for(size_t i = 0; i <= max_degre; i++){
            double m_coef = (i <= m.degre ? m.coef[i]: 0.0);
            double n_coef = (i <= n.degre ? n.coef[i]: 0.0);
            tmp[i] =  m_coef - n_coef;
        }
        Polynome res(max_degre, tmp);
        delete [] tmp; 
        return res;  
    }



    std::ostream &operator<<(std::ostream &os, const Polynome &p){
        if(p.degre ==0){
            os << p.coef[p.degre];
            return os;
        }
        size_t nb_affiches = 0 ; 
        for(size_t i = p.degre ; i > 0; i--){
            if(p.coef[i] == 0)
                continue ; //ignorer les coefs null
            if(nb_affiches > 0 && p.coef[i] > 0)
                os << '+';
            
            if(p.coef[i] == 1)
                { }
            else if(p.coef[i] == -1)
                os << '-';
            else 
                os << p.coef[i];
            os << "X" ; 
            if(i > 1 )
                os << "^" << i ; 
            nb_affiches++;
        }

        if(p.coef[0] != 0){

            if(nb_affiches > 0 && p.coef[0] > 0 )
                os << '+' ;
            os << p.coef[0];
            nb_affiches ++ ; 
        }
        if(nb_affiches == 0)
            os << '0';
        return os; 
    }



    

        double Polynome::operator()(const double &x){
            double resultat = 0; 
             for(size_t i = 0 ; i<= degre; i++)
                resultat += coef[i]*pow(x,i);
            return resultat;
        }
