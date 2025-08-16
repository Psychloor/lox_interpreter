//
// Created by blomq on 2025-08-16.
//

#ifndef LOX_INTERPRETER_LOX_HPP
#define LOX_INTERPRETER_LOX_HPP

#include <string>


class Lox
{
public:
    void runFile(const std::string& path);
    void runPrompt();
    static void error(size_t line, const std::string& message);
    [[nodiscard]] bool hadError() const;

private:
    void run(const std::string& source);
    static void report(size_t line, const std::string& where, const std::string& message);

    bool hadError_ = false;
};


#endif //LOX_INTERPRETER_LOX_HPP
