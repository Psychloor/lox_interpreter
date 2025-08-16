//
// Created by blomq on 2025-08-16.
//

#include "scanner.hpp"

#include "lox.hpp"

std::vector<Token> Scanner::scanTokens()
{
    while (!isAtEnd())
    {
        start_ = current_;
        scanToken();
    }

    tokens_.emplace_back(TokenType::Eof, "", TokenLiteral(nullptr), line_);
    return tokens_;
}

void Scanner::scanToken()
{
    const char c = advance();
    switch (c)
    {
    case '(':
        addToken(TokenType::LeftParen);
        break;
    case ')':
        addToken(TokenType::RightParen);
        break;
    case '{':
        addToken(TokenType::LeftBrace);
        break;
    case '}':
        addToken(TokenType::RightBrace);
        break;
    case ',':
        addToken(TokenType::Comma);
        break;
    case '.':
        addToken(TokenType::Dot);
        break;
    case '-':
        addToken(TokenType::Minus);
        break;
    case '+':
        addToken(TokenType::Plus);
        break;
    case ';':
        addToken(TokenType::Semicolon);
        break;
    case '*':
        addToken(TokenType::Star);
        break;
    case '!':
        addToken(match('=') ? TokenType::BangEqual : TokenType::Bang);
        break;
    case '=':
        addToken(match('=') ? TokenType::EqualEqual : TokenType::Equal);
        break;
    case '<':
        addToken(match('=') ? TokenType::LessEqual : TokenType::Less);
        break;
    case '>':
        addToken(match('=') ? TokenType::GreaterEqual : TokenType::Greater);
        break;
    case '/':
        if (match('/'))
        {
            while (peek() != '\n' && !isAtEnd())
                advance();
        }
        else if (match('*'))
        {
            while (!isAtEnd())
            {
                if (peek() == '*' && peekNext() == '/')
                {
                    advance(); // Consume *
                    advance(); // Consume /
                    break;
                }
                if (peek() == '\n')
                    ++line_;
                advance();
            }
        }
        else
        {
            addToken(TokenType::Slash);
        }
        break;
    case ' ':
    case '\r':
    case '\t':
        // Ignore whitespace
        break;
    case '\n':
        ++line_;
        break;

    case '"':
        string();
        break;

    default:
        if (std::isdigit(c))
        {
            number();
        }
        else if (isAlpha(c))
        {
            identifier();
        }
        else
        {
            Lox::error(line_, "Unexpected character.");
        }
        break;
    }
}

bool Scanner::isAtEnd() const
{
    return current_ >= end_;
}

bool Scanner::isDigit(const char c)
{
    return c >= '0' && c <= '9';
}

bool Scanner::isAlpha(const char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool Scanner::isAlphaNumeric(const char c)
{
    return isAlpha(c) || isDigit(c);
}

char Scanner::advance()
{
    return source_[current_++];
}

bool Scanner::match(const char expected)
{
    if (isAtEnd())
        return false;
    if (source_[current_] != expected)
        return false;

    current_++;
    return true;
}

char Scanner::peek() const
{
    if (isAtEnd())
        return '\0';
    return source_[current_];
}

char Scanner::peekNext() const
{
    if (current_ + 1 >= end_)
        return '\0';
    return source_[current_ + 1];
}

void Scanner::string()
{
    while (peek() != '"' && !isAtEnd())
    {
        if (peek() == '\n')
            line_++;
        advance();
    }
    if (isAtEnd())
    {
        Lox::error(line_, "Unterminated string.");
        return;
    }
    // The closing " character
    advance();

    // Trim the surrounding quotes.
    const std::string value(source_.begin() + start_ + 1, source_.begin() + current_ - 1);
    addToken(TokenType::String, TokenLiteral(value));
}

void Scanner::number()
{
    while (std::isdigit(peek()))
        advance();

    if (peek() == '.' && isDigit(peekNext()))
    {
        advance();

        while (std::isdigit(peek()))
            advance();
    }

    addToken(TokenType::Number, TokenLiteral(std::stod(source_.substr(start_, current_ - start_))));
}

void Scanner::identifier()
{
    while (isAlphaNumeric(peek()))
        advance();

    const std::string text = source_.substr(start_, current_ - start_);
    if (keywords_.contains(text))
    {
        addToken(keywords_[text]);
        return;
    }

    addToken(TokenType::Identifier);
}

void Scanner::addToken(const TokenType type)
{
    addToken(type, TokenLiteral(nullptr));
}

void Scanner::addToken(TokenType type, TokenLiteral literal)
{
    std::string text = source_.substr(start_, current_ - start_);
    tokens_.emplace_back(type, text, literal, line_);
}

std::map<std::string, TokenType> Scanner::keywords_ = {
    {"and", TokenType::And},
    {"class", TokenType::Class},
    {"else", TokenType::Else},
    {"false", TokenType::False},
    {"for", TokenType::For},
    {"fun", TokenType::Fun},
    {"if", TokenType::If},
    {"nil", TokenType::Nil},
    {"or", TokenType::Or},
    {"print", TokenType::Print},
    {"return", TokenType::Return},
    {"super", TokenType::Super},
    {"this", TokenType::This},
    {"true", TokenType::True},
    {"var", TokenType::Var},
    {"while", TokenType::While}
};
