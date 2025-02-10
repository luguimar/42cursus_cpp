#include <iostream>
#include <fstream>
#include <string>

static std::string replaceAllOccurrences(const std::string& line,
                                         const std::string& s1,
                                         const std::string& s2)
{
    std::string result;
    size_t startPos = 0;
    size_t foundPos;

    // Loop as long as we find occurrences of s1 in the line
    while ((foundPos = line.find(s1, startPos)) != std::string::npos) {
        // Copy everything from startPos up to (but not including) foundPos
        result.append(line, startPos, foundPos - startPos);
        // Append s2 in place of s1
        result.append(s2);
        // Move startPos to end of the replaced occurrence
        startPos = foundPos + s1.length();
    }

    // Append any remaining characters after the last occurrence
    result.append(line, startPos, line.length() - startPos);
    return result;
}

int main(int argc, char* argv[])
{
    // ------------------------------------------------------------------
    // 1. Validate arguments
    // ------------------------------------------------------------------
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1       = argv[2];
    std::string s2       = argv[3];

    if (filename.empty()) {
        std::cerr << "Error: Filename cannot be empty." << std::endl;
        return 1;
    }
    if (s1.empty() || s2.empty()) {
        std::cerr << "Error: s1 and s2 cannot be empty." << std::endl;
        return 1;
    }

    // ------------------------------------------------------------------
    // 2. Open the input file
    // ------------------------------------------------------------------
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for reading." << std::endl;
        return 1;
    }

    // ------------------------------------------------------------------
    // 3. Open the output file: <filename>.replace
    // ------------------------------------------------------------------
    std::string outFilename = filename + ".replace";
    std::ofstream outputFile(outFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open file '" << outFilename << "' for writing." << std::endl;
        return 1;
    }

    // ------------------------------------------------------------------
    // 4. Read the file line by line, replace occurrences, and write
    // ------------------------------------------------------------------
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string replacedLine = replaceAllOccurrences(line, s1, s2);
        outputFile << replacedLine << std::endl;
    }

    // ------------------------------------------------------------------
    // 5. Close files and finish
    // ------------------------------------------------------------------
    inputFile.close();
    outputFile.close();

    std::cout << "Replaced all occurrences of '" << s1
              << "' with '" << s2
              << "' in file '" << filename
              << "' -> '" << outFilename << "'" << std::endl;

    return 0;
}
