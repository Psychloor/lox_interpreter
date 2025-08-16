//
// Created by blomq on 2025-08-16.
//

#ifndef LOX_INTERPRETER_TOKEN_HPP
#define LOX_INTERPRETER_TOKEN_HPP

#include <format>
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

class TokenLiteral
{
private:
    std::variant<double, std::string, bool, std::nullptr_t> value_;

public:
    TokenLiteral() :
        value_(nullptr)
    {}

    explicit TokenLiteral(const double value) :
        value_(value)
    {}

    explicit TokenLiteral(const std::string& value) :
        value_(value)
    {}

    explicit TokenLiteral(const bool value) :
        value_(value)
    {}

    explicit TokenLiteral(const std::nullptr_t value) :
        value_(value)
    {}


    template <typename T>
    std::optional<T> value() const
    {
        if (std::holds_alternative<T>(value_))
        {
            return std::make_optional(std::get<T>(value_));
        }

        return std::nullopt;
    }

    [[nodiscard]] std::string toString() const
    {
        if (std::holds_alternative<double>(value_))
        {
            return std::to_string(std::get<double>(value_));
        }
        if (std::holds_alternative<std::string>(value_))
        {
            return std::get<std::string>(value_);
        }
        if (std::holds_alternative<bool>(value_))
        {
            return std::get<bool>(value_) ? "true" : "false";
        }
        if (std::holds_alternative<std::nullptr_t>(value_))
        {
            return "nil";
        }

        return "";
    }
};

struct Token
{
    TokenType type;
    std::string lexeme;
    TokenLiteral literal;
    size_t line;

    Token(const TokenType type, const std::string_view lexeme, TokenLiteral literal, const size_t line) :
        type(type), lexeme(lexeme), literal(std::move(literal)), line(line)
    {}

    std::string toString()
    {
        return std::format("{} {} {}", ToString(type), lexeme, literal.toString());
    }
};

#endif //LOX_INTERPRETER_TOKEN_HPP
