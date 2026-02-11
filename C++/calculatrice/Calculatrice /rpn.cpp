#include <iostream>
#include <vector> 
#include <string>
#include "rpn.hpp"

namespace rpn{
    using Token = std::string ; 
    using Expression = std::vector<Token> ; 

    Expression stringToExpression(Token &v){
        return {};
    }


    bool isValidOperator(Token &expression){
        return true; 
    } 


    double eval(Expression &expression){
        return 0;
    } 


    Token toString(Expression &expression){
        return " ";
    } 


    Expression infixToPostfix(Expression &expression){
        return {};
    }


    bool isWellParenthesized(Expression &expression){
        return true ; 
    }
}
