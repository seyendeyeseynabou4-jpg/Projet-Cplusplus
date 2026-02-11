#include "rpn.hpp"
#include <iostream>
#include <string>
#include <sstream>  
#include <stack>
#include <vector>

using namespace std; 

namespace rpn {


    Expression stringToExpression(const Token &input){
        char espace = ' ' ; 
        Token token; 
        stringstream ss(input); 
        Expression tokens; 
        while(getline(ss,token ,espace)){
            tokens.push_back(token);
        }
     
        return tokens; 
    }
    
    bool isValidOperator(Token &v ){
        char c = v[0];
        if(v.length() != 1)   
            return false; 
        return( c == '+' || c == '-' || c == '*' || c =='/');
    }


    bool isNumeric(const std::string& s) {
        size_t sz=0; 
        try {
            std::stod(s, &sz);
        } catch (const std::invalid_argument& ia){}
        return (( sz>0) && (s.size() == sz));
    }


    int priorityOperator(Token &op){
        if(op == "+" || op == "-")
            return 1 ; 
        if(op == "*" || op == "/")
            return 2; 
        return 0;
    }

// TANT QUE op2 >= op1 on dépile o2 et on le met dans la sortie
// Ensuite (dans tous les cas) on empile o1
    
Expression infixToPostfix(const Expression &v){
        Token chaine; 
        std::stack <Token> pile; 
        Expression sortie; 
        for(size_t i  = 0 ; i < v.size(); i++){
            chaine = v[i]; 
            if(isNumeric(chaine)){
                sortie.push_back(chaine);
            }
            else if(chaine == "(")
                pile.push(chaine);

            else if(chaine == ")" ){
                while(!pile.empty() && pile.top() != "("){
                    sortie.push_back(pile.top());
                    pile.pop();
                }
                if(!pile.empty())
                    pile.pop();
            }
            else if(isValidOperator(chaine) ){
                while(!pile.empty() && pile.top() != "(" && priorityOperator(pile.top()) >= priorityOperator(chaine) ){

                    sortie.push_back(pile.top());
                    pile.pop();
                }
                pile.push(chaine);

            }
            
        }
        while(!pile.empty()){
            sortie.push_back(pile.top());
            pile.pop();

        }
        return sortie;
}


    double eval(const Expression &v){
        Token chaine = v.back(); 
        std::stack <Token> pile; 
        double resultat ;
        Expression exp ;
        if(!isValidOperator(chaine))
            exp = infixToPostfix(v);
        for(size_t i = 0 ; i < exp.size(); i++){
            chaine = exp[i];
            if(isNumeric(chaine)){
                pile.push(chaine);
            }
            else if(isValidOperator(chaine)){
                double val2 = stod(pile.top());
                pile.pop(); 
                double val1 = stod(pile.top());
                pile.pop(); 
                if(chaine == "+")
                    resultat = val1 + val2;
                else if(chaine == "-")
                    resultat = val1 - val2; 
                else if(chaine == "*") 
                    resultat = val1 * val2; 
                else {
                    if(val2 != 0 )
                        resultat = val1 / val2;
                    else {
                        cerr << "Impossible d'effectuer ce calcul" ;
                        return 0.0 ;

                    }

                }
                pile.push(to_string(resultat));        
            }
             
        }
        return stod(pile.top());


        }

    // A FAIRE
    std::string toString(const Expression &v){
        return " ";
    }

        // A FAIRE
    bool isWellParenthesized(Expression &v) {
        return false;
    }




}







