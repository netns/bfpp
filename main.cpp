#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "brainfuck.hpp"

using std::string;
using std::vector;

namespace fs = std::filesystem;

string getSourceCode(const string &filePath)
{

    if (!fs::exists(filePath))
        throw std::runtime_error("File does not exist: " + filePath);

    if (!fs::is_regular_file(filePath))
        throw std::runtime_error("Not a regular file: " + filePath);

    auto fileSize = fs::file_size(filePath);

    std::ifstream file{filePath, std::ios::binary};

    if (!file)
        throw std::runtime_error("Failed to open file: " + filePath);

    string content(fileSize, '\0');

    file.read(content.data(), fileSize);

    if (!file)
        throw std::runtime_error("Error reading file: " + filePath);

    return content;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filepath>\n";
        return 1;
    }

    string filePath = argv[1];

    BrainfuckInterpreter interpreter;
    try
    {
        string code = getSourceCode(filePath);
        interpreter.setInput("");
        interpreter.run(code);
        std::cout << interpreter.getOutput() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
