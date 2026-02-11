#ifndef RPN_HPP
#define RPN_HPP 
#include <vector> 

namespace rpn{
    using Token = std::string ; 
    using Expression = std::vector<Token> ; 

    Expression stringToExpression(Token &v);
    bool isValidOperator(Token &expression); 
    double eval(Expression &expression); 
    Token toString(Expression &expression); 
    Expression infixToPostfix(Expression &expression);
    bool isWellParenthesized(Expression &expression);
}

#endif 