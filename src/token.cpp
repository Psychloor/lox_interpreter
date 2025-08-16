//
// Created by blomq on 2025-08-16.
//

#include "token.hpp"

#include <format>

std::string Token::toString()
{
    return std::format("{} {} {}", ToString(type), lexeme, literalToString());
}

std::string Token::literalToString()
{
    return std::visit([]<typename TVariant>(TVariant& arg) -> std::string
    {
        using T = std::decay_t<TVariant>;
        if constexpr (std::is_same_v<T, double>)
        {
            return std::to_string(arg);
        }
        else if constexpr (std::is_same_v<T, std::string>)
        {
            return arg;
        }
        else if constexpr (std::is_same_v<T, bool>)
        {
            return arg ? "true" : "false";
        }
        else if constexpr (std::is_same_v<T, std::nullptr_t>)
        {
            return "nil";
        }
        else
        {
            static_assert(false, "non-exhaustive visitor!");
            return "";
        }
    }, this->literal);
}
