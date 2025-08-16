//
// Created by blomq on 2025-08-16.
//

#ifndef LOX_INTERPRETER_SCANNER_HPP
#define LOX_INTERPRETER_SCANNER_HPP

#include <map>
#include <string>
#include <vector>

#include "token.hpp"


class Scanner
{
public:
    explicit Scanner(const std::string& source) :
        source_(source), end_(source.size())
    {};

    std::vector<Token> scanTokens();

private:
    void scanToken();

    [[nodiscard]] bool isAtEnd() const;
    static bool isDigit(char c);
    static bool isAlpha(char c);
    static bool isAlphaNumeric(char c);

    char advance();
    bool match(char expected);
    [[nodiscard]] char peek() const;
    [[nodiscard]] char peekNext() const;

    void string();
    void number();
    void identifier();

    void addToken(TokenType type);
    void addToken(TokenType type, TokenLiteral literal);

    std::string source_;
    std::vector<Token> tokens_;

    size_t start_ = 0;
    size_t current_ = 0;
    size_t end_ = 0;
    size_t line_ = 1;

    static std::map<std::string, TokenType> keywords_;
};


#endif //LOX_INTERPRETER_SCANNER_HPP
