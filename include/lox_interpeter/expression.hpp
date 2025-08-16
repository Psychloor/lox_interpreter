//
// Created by blomq on 2025-08-16.
//

#ifndef LOX_INTERPRETER_EXPRESSION_HPP
#define LOX_INTERPRETER_EXPRESSION_HPP

struct Token;

class Expression
{
public:

};

class BinaryExpression : public Expression
{
public:
    BinaryExpression(Expression* left, Expression* right, Token* operator_) :
        left(left), right(right), operator_(operator_) {};

private:
    Expression* left;
    Expression* right;
    Token* operator_;
};

#endif //LOX_INTERPRETER_EXPRESSION_HPP
