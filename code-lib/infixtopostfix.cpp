#include <iostream>
#include <stack>
#include <cstring>

bool isOperator( char c );

bool isOperand( char c );
int getOperatorWeight(char c);


bool isRightAssociative(char c);

bool hasHigherPrecedence(char op1, char op2);

std::string infixToPostfix( std::string expression );

using namespace std;

bool isOperator( char c )
{
  if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    return true;
  }
  return false;
}

bool isOperand( char c )
{
  if ( c >= 'a' && c <= 'z' ) return true;
  if ( c >= 'A' && c <= 'Z' ) return true;
  return false;
}

int getOperatorWeight( char c )
{
  int weight;
  switch(c) {
    case '+':
    case '-':
      weight = 1;
      break;
    case '*':
    case '/':
      weight = 2;
      break;
    case '^':
      weight = 3;
      break;
    default:
      weight = -1;
  }
  return weight;
}


bool isRightAssociative( char op )
{
  if ( op == '^') return true;
  return false;
}

bool hasHigherPrecedence( char op1, char op2 )
{
 
  int w1 = getOperatorWeight(op1);
  int w2 = getOperatorWeight(op2);

  if ( w1 == w2 ) {
    if ( isRightAssociative(op1) ) {
      return false;
    }
    return true;
  }
  return w1 > w2 ? true : false;
}


std::string infixToPostFix(std::string expr)
{
  bool errorDetected = false;
  stack<char> operatorStack;
  std::string postFixExpr = "";

  for ( char c : expr ) {


    if ( c == ',' || c == ' ') {
      continue;
    }

    else if ( isOperand(c) ) {
      postFixExpr += c;
    }

    else if ( isOperator(c) ) {

      while ( !operatorStack.empty() &&  operatorStack.top() != '(' &&
              hasHigherPrecedence(operatorStack.top(), c) ) {
          postFixExpr += operatorStack.top();
          operatorStack.pop();
      }
      operatorStack.push(c);
    }

    else if( c == '(' ) {
      operatorStack.push(c);
    }

    else if( c == ')' ) {
      while( !operatorStack.empty() && operatorStack.top() != '(' ) {
        postFixExpr += operatorStack.top();
        operatorStack.pop();
      }
      operatorStack.pop();
    }

    else {
      std::cout << " ERROR An invalid operator/operand detected\n";
      errorDetected = true;
      break;
    }
  }
  if (errorDetected) {
    return "INVALID EXPR!";
  }

  while( !operatorStack.empty() ) {
    postFixExpr += operatorStack.top();
    operatorStack.pop();
  }
  return postFixExpr;
}


int main()
{
  std::string expr;
  std::cout << "Provide an expression such that :"
            << "1. Expression shoule be parenthesis valid.\n"
            << "2. Operators should contain +, -, /, *, ^\n"
            << "3. Operands should contain A-Z or a-z \n"
            << "Your expression is :";
  std::getline(std::cin, expr);
  std::cout << "Corresponding postfix expression of the express - "
            << expr
            << " is :" << infixToPostFix(expr) << std::endl;
  return 0;
}