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
    static void defineType(std::ofstream& file, std::string_view baseName, std::string_view className, std::string_view fieldList);
};


#endif //LOX_INTERPRETER_GENERATE_AST_HPP