//
//  main.cpp
//  Lab_1
//
//  Created by Елизавета Шимкович on 10.03.23.
//


#include <stdio.h>
#include <iostream>
#include <boost/process.hpp>
#include <boost/thread/thread.hpp>
#include <fstream>
#include <cstdio>

namespace bp = boost::process;
using namespace std;

bool ExecuteCreator(std::string& file) {
    std::cout << "Enter bin File name: ";
    std::string number;
    std::cin >> file;
    std::cout << "Enter amount of quires: ";
    std::cin >> number;
    std::vector<std::string> creator_args = {file, number};
    bp::child creator("./Creator", creator_args);
    creator.wait();
    if (creator.exit_code() != 0) {
        return EXIT_FAILURE;
    }

    return 0;
}

bool ExecuteReporter(std::string fileIN, std::string& fileOUT)
{
    std::string pay;
    std::cout << "Enter output File name: ";
    std::cin >> fileOUT;
    std::cout << "Enter pay for an hour: ";
    std::cin >> pay;
    std::vector<std::string> reporter_args = {fileIN, fileOUT, pay};
    bp::child reporter("./Reporter", reporter_args);
    reporter.wait();
    if (reporter.exit_code() != 0) {
        std::cerr << "Creator failed with exit code " << reporter.exit_code() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}

bool DeleteBinary(const std::string& filename)
{
    std::remove(filename.c_str());
    return 0;
}

void displayFile(const std::string& filename)
{
    std::ifstream inputFile(filename, std::ios::binary);

    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    inputFile.seekg(0, std::ios::end);
    std::streampos fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);
    char* buffer = new char[fileSize];
    inputFile.read(buffer, fileSize);
    std::cout << "Contents of file:\n";
    std::cout.write(buffer, fileSize);
    std::cout << "\n";
    delete[] buffer;
    inputFile.close();
}

int main() {
    std::string FileBin;
    if (ExecuteCreator(FileBin)) {
        DeleteBinary(FileBin);
        return EXIT_FAILURE;
    }
    std::string FileReport;
    if (ExecuteReporter(FileBin, FileReport))
    {
        DeleteBinary(FileBin);
        return EXIT_FAILURE;
    }

    displayFile(FileReport);
    DeleteBinary(FileBin);

    return 0;
}
