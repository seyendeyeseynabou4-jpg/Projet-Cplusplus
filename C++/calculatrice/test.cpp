



// Autrement 


// Expression stringToExpression(const Token &input){
//     Expression exp; 
//     Token chaine ; 

//     for( char c:input){
//         if(c != ' ')
//             chaine+=c; 
//         else 
//             if(!chaine.empty())
//                 exp.push_back(chaine);
//                 chaine.clear(); 
//     }
//     if(!chaine.empty())
//         exp.push_back(chaine); 
//     return exp; 

// }

#include <iostream>
#include <string>
#include <sstream>  
#include <stack>
#include <vector>
using namespace std; 

namespace rpn {
    using Token = string; 
    using Expression = std::vector<Token> ;


    bool isNumeric(const std::string& s) {
        size_t sz=0; 
        try {
            std::stod(s, &sz);
        } catch (const std::invalid_argument& ia){}
        return (( sz>0) && (s.size() == sz));
    }

    Expression stringToExpression(const Token &input){
        char espace = ' '; 
        Token token; 
        stringstream ss(input); 
        Expression tokens; 
        while(getline(ss, token, espace)){
            if(!token.empty()) // Ignorer les tokens vides
                tokens.push_back(token);
        }
        return tokens; 
    }

        int priorityOperator(Token &op){
        if(op == "+" || op == "-")
            return 1 ; 
        if(op == "*" || op == "/")
            return 2; 
        return 0;
    }


        bool isValidOperator(Token v ){
        char c = v[0];
        if(v.length() != 1)   
            return false; 
        return( c == '+' || c == '-' || c == '*' || c =='/');
    }


     Expression infixToPostfix(Expression v){
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


}

int main(){
    // Avec des espaces entre chaque token (˽ = espace)
    std::string chaine = "20×(10-3)"; 
    // string nana = ""
    
    std::cout << "Chaine: " << chaine << std::endl; 
    
    rpn::Expression resultat = rpn::stringToExpression(chaine);
    
    std::cout << "Tokens: ";
    for(const auto& token : resultat){
        std::cout << " " << token << " ";
    }
    std::cout << std::endl;
   rpn::infixToPostfix(resultat); 
        for(const auto& token : resultat){
        std::cout << "Apres conversion " << token << " ";
    }
    
    
    return 0; 
}

