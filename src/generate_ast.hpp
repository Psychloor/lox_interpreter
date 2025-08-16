//
// Created by blomq on 2025-08-16.
//

#ifndef LOX_INTERPRETER_GENERATE_AST_HPP
#define LOX_INTERPRETER_GENERATE_AST_HPP

#include <filesystem>
#include <string>
#include <vector>

class GenerateAst
{
    public:


    private:
    static void defineAst(const std::filesystem::path& outputDir, const std::string& baseName, const std::vector<std::string>& types);
    static void defineType(std::ofstream& file, const std::string& baseName, const std::string& className, const std::string& fieldList);
};


#endif //LOX_INTERPRETER_GENERATE_AST_HPP