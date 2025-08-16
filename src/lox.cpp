//
// Created by blomq on 2025-08-16.
//

#include "lox_interpeter/lox.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

#include "lox_interpeter/scanner.hpp"

void Lox::runFile(const std::string& path)
{
    const std::filesystem::path p(path);
    if (!exists(p))
    {
        std::cerr << "File does not exist: " << path << '\n';
        return;
    }

    const auto status = std::filesystem::status(p);
    if (status.type() != std::filesystem::file_type::regular)
    {
        std::cerr << "Not a regular file: " << path << '\n';
        return;
    }

    std::ifstream file(p);
    if (!file.is_open())
    {
        std::cerr << "Could not open file: " << path << '\n';
        return;
    }

    const std::string source{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
    run(source);
}

void Lox::runPrompt()
{
    bool running = true;
    while (running)
    {
        std::cout << "> ";
        std::string line;
        std::getline(std::cin, line);
        if (line.empty())
        {
            running = false;
            continue;
        }

        run(line);
    }
}

void Lox::error(const size_t line, const std::string& message)
{
    report(line, "at line", message);
}

// ReSharper disable once CppDFAConstantFunctionResult
bool Lox::hadError() const
{
    return hadError_;
}

void Lox::report(const size_t line, const std::string& where, const std::string& message)
{
    std::cerr << "[line " << line << "] Error " << where << ": " << message << '\n';
}

void Lox::run([[maybe_unused]] const std::string& source)
{
    Scanner scanner(source);
    const auto tokens = scanner.scanTokens();

    for (auto&& token : tokens)
    {}
}
