#ifndef RPN_CPP
#define RPN_CPP

#include <iostream>
#include <vector>
#include <string>

namespace rpn{

using Token = std::string;
using Expression = std::vector<Token>;

Expression stringToExpression(const Token &input); 
bool isValidOperator(Token &v ); 
Expression infixToPostfix(const Expression &v); 
double eval(const Expression &v);
std::string toString(const Expression &v);
bool isWellParenthesized(Expression &v);
bool isNumeric(const std::string& s); 



}


#endif 