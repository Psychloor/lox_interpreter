//
// Created by blomq on 2025-08-16.
//

#ifndef LOX_INTERPRETER_TOKEN_HPP // NOLINT(*-redundant-preprocessor)
#define LOX_INTERPRETER_TOKEN_HPP

#include <optional>
#include <string>
#include <utility>
#include <variant>

#include "token_type.hpp"

namespace lox::token_type
{
    enum class TokenType : uint8_t;
}

using namespace lox::token_type;

using TokenLiteral = std::variant<double, std::string, bool, std::nullptr_t>;

struct Token
{
    TokenType type;
    std::string lexeme;
    TokenLiteral literal;
    size_t line;

    Token(const TokenType type, const std::string_view lexeme, TokenLiteral literal, const size_t line) :
        type(type), lexeme(lexeme), literal(std::move(literal)), line(line)
    {}

    std::string toString();
    std::string literalToString();

    template <typename T>
    std::optional<T> value();
};

#include "token.ipp"

#endif //LOX_INTERPRETER_TOKEN_HPP
