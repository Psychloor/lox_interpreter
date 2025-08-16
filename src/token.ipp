//
// Created by blomq on 2025-08-16.
//

#ifndef LOX_INTERPRETER_TOKEN_IPP
#define LOX_INTERPRETER_TOKEN_IPP

#include "token.hpp"

template <>
inline std::optional<double> Token::value()
{
    if  (std::holds_alternative<double>(literal))
    {
        return std::get<double>(literal);
    }

    return std::nullopt;
}

template <>
inline std::optional<std::string> Token::value()
{
    if  (std::holds_alternative<std::string>(literal))
    {
        return std::get<std::string>(literal);
    }

    return std::nullopt;
}

template <>
inline std::optional<bool> Token::value()
{
    if  (std::holds_alternative<bool>(literal))
    {
        return std::get<bool>(literal);
    }

    return std::nullopt;
}

template <>
inline std::optional<nullptr_t> Token::value()
{
    if  (std::holds_alternative<nullptr_t>(literal))
    {
        return std::get<nullptr_t>(literal);
    }

    return std::nullopt;
}

#endif //LOX_INTERPRETER_TOKEN_IPP