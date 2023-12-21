#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype>

void displayFileContent(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    int lineNumber = 1;

    while (std::getline(inputFile, line)) {
        std::cout << "Line " << lineNumber << ": " << line << std::endl;
        lineNumber++;
    }

    inputFile.close();
}

void logAction(const std::string& action) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Error: Unable to open log file." << std::endl;
        exit(EXIT_FAILURE);
    }

    time_t currentTime = time(0);
    tm* localTime = localtime(&currentTime);

    logFile << action << " at " << asctime(localTime);
    logFile.close();
}

int main() {
    // Task 1: Display file content and log the action
    std::cout << "Task 1: Displaying input.txt contents" << std::endl;
    displayFileContent("input.txt");
    logAction("File was read");

    // Task 2: Copy contents to output.txt and update log.txt
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    std::string line;

    while (std::getline(inputFile, line)) {
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
    logAction("File contents were copied to output.txt");

    // Task 3: Add line numbers to each line in output.txt and update log.txt
    std::ifstream inputOutputFile("output.txt");
    std::ofstream numberedOutputFile("output.txt", std::ios::app);
    int currentLineNumber = 1;

    while (std::getline(inputOutputFile, line)) {
        numberedOutputFile << currentLineNumber << ": " << line << std::endl;
        currentLineNumber++;
    }

    inputOutputFile.close();
    numberedOutputFile.close();
    logAction("Line numbers were added to output.txt");

    // Task 4: Append content in uppercase to output.txt and update log.txt
    std::ifstream uppercaseInputFile("input.txt");
    std::ofstream uppercaseOutputFile("output.txt", std::ios::app);

    while (std::getline(uppercaseInputFile, line)) {
        for (char& c : line) {
            c = std::toupper(c);
        }
        uppercaseOutputFile << line << std::endl;
    }

    uppercaseInputFile.close();
    uppercaseOutputFile.close();
    logAction("Uppercase content was appended to output.txt");

    return 0;
}
