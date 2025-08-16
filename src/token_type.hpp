//
// Created by blomq on 2025-08-16.
//

#ifndef LOX_INTERPRETER_TOKEN_TYPE_HPP
#define LOX_INTERPRETER_TOKEN_TYPE_HPP

#include <cassert>
#include <cstdint>
#include <map>
#include <string>

namespace lox::token_type
{
    enum class TokenType : uint8_t
    {
        // Single-character tokens.
        LeftParen, RightParen, LeftBrace, RightBrace,
        Comma, Dot, Minus, Plus, Semicolon, Slash, Star, Question, Colon,

        // One or two character tokens.
        Bang, BangEqual,
        Equal, EqualEqual,
        Greater, GreaterEqual,
        Less, LessEqual,
        PlusPlus, MinusMinus,


        // Literals.
        Identifier, String, Number,

        // Keywords.
        And, Class, Else, False, Fun, For, If, Nil, Or,
        Print, Return, Super, This, True, Var, While, LoxTrue, LoxFalse, LoxEof,

        Eof,
    };

    static const std::map<TokenType, std::string> LOOKUP_TABLE{
        {TokenType::LeftParen, "LEFT_PAREN"},
        {TokenType::RightParen, "RIGHT_PAREN"},
        {TokenType::LeftBrace, "LEFT_BRACE"},
        {TokenType::RightBrace, "RIGHT_BRACE"},
        {TokenType::Comma, "COMMA"},
        {TokenType::Comma, "COLON"},
        {TokenType::Dot, "DOT"},
        {TokenType::Question, "QUESTION"},
        {TokenType::Semicolon, "SEMICOLON"},
        {TokenType::Slash, "SLASH"},
        {TokenType::Star, "STAR"},
        {TokenType::Bang, "BANG"},
        {TokenType::BangEqual, "BANG_EQUAL"},
        {TokenType::Equal, "EQUAL"},
        {TokenType::EqualEqual, "EQUAL_EQUAL"},
        {TokenType::Greater, "GREATER"},
        {TokenType::GreaterEqual, "GREATER_EQUAL"},
        {TokenType::Less, "LESS"},
        {TokenType::LessEqual, "LESS_EQUAL"},
        {TokenType::Minus, "MINUS"},
        {TokenType::MinusMinus, "MINUS_MINUS"},
        {TokenType::Plus, "PLUS"},
        {TokenType::PlusPlus, "PLUS_PLUS"},
        {TokenType::Identifier, "IDENTIFIER"},
        {TokenType::String, "STRING"},
        {TokenType::Number, "NUMBER"},
        {TokenType::And, "AND"},
        {TokenType::Class, "CLASS"},
        {TokenType::Else, "ELSE"},
        {TokenType::LoxFalse, "FALSE"},
        {TokenType::Fun, "FUN"},
        {TokenType::For, "FOR"},
        {TokenType::If, "IF"},
        {TokenType::Nil, "NIL"},
        {TokenType::Or, "OR"},
        {TokenType::Print, "PRINT"},
        {TokenType::Return, "RETURN"},
        {TokenType::Super, "SUPER"},
        {TokenType::This, "THIS"},
        {TokenType::LoxTrue, "TRUE"},
        {TokenType::Var, "VAR"},
        {TokenType::While, "WHILE"},
        {TokenType::LoxEof, "EOF"},
        {TokenType::Eof, "EOF"}};

    static std::string ToString(const TokenType type)
    {
        assert(LOOKUP_TABLE.contains(type) && "Lookup table does not contain token type");
        return LOOKUP_TABLE.at(type);
    }
}

#endif //LOX_INTERPRETER_TOKEN_TYPE_HPP
