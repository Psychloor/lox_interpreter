//
// Created by blomq on 2025-08-16.
//

#include "generate_ast.hpp"

#include <fstream>
#include <ranges>

void GenerateAst::defineAst(const std::filesystem::path& outputDir, const std::string& baseName,
                            const std::vector<std::string>& types)
{
    create_directories(outputDir);
    const std::filesystem::path path = outputDir / (baseName + ".hpp");

    std::ofstream file(path, std::ios::out | std::ios::trunc);

    file << "package com.craftinginterpreters.lox;" << '\n';
    file << "import java.util.List;" << '\n';
    file << '\n';
    file << "abstract class " << baseName << " {" << '\n';

    for (const std::string_view type : types)
    {
        const auto colon = type.find(':');
        const auto className = type.substr(0, colon);
        const auto fields = type.substr(colon + 1);
        defineType(file, baseName, className, fields);
    }

    file << "}" << 'n';
    file.close();
}

void GenerateAst::defineType(std::ofstream& file, const std::string& baseName, const std::string& className,
                             const std::string& fieldList)
{
    file << "static class " << className << " extends " << baseName << " {" << '\n';

    // Constructor
    file << "    " << className << "(" << fieldList << ") {" << '\n';

    // Store parameters in fields
    std::vector<std::string> fields;
    {
        std::stringstream ss((fieldList));
        std::string field;

        while (std::getline(ss, field, ','))
        {
            if (field.starts_with(' '))
                field = field.substr(1); // Remove the leading space
            fields.push_back(field);
        }
    }

    for (const auto& field : fields)
    {
        file << "        this." << field << " = " << field << ';' << '\n';
    }

    file << "    }" << '\n';
}
