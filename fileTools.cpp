#include "fileTools.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

void fileTools::createFile(std::string fileName, std::string fileExtension) {
    std::string file = fileName + "." + fileExtension;
    bool accepted = false;

    if (containsWhitespace(fileName)) {
        return;
    }

    std::vector<std::string> fileTypes = {"txt", "dat"};
    for (const std::string& s : fileTypes) {
        if (s == fileExtension) {
            accepted = true;
        }
    }

    if (!accepted) {
        std::cout << "Invalid file extension: " << fileExtension << std::endl;
        return;
    }

    if (fs::exists(getCurrentDirectory() / file)) {
        std::cout << file << " already exists." << std::endl;
        return;
    }

    std::ofstream workingFile(getCurrentDirectory() / file);
    if (workingFile.is_open()) {
        workingFile << "Hello world" << std::endl;
        workingFile.close();
    }

    if (fileExtension == "txt") {
        std::string commandString = "notepad.exe \"" + (getCurrentDirectory() / file).string() + "\"";
        system(commandString.c_str());
    } else {
        std::cout << file << " has been created." << std::endl;
    }
}

void fileTools::readFile(std::string fileName ){
    if (containsWhitespace(fileName)) {
        return;
    }


    if(!fs::exists(getCurrentDirectory() / fileName)){
        std::cout << fileName << "does not exist." << std::endl;
    }

    std::ifstream workingFile(getCurrentDirectory() / fileName);

    std::string contents;

    while(getline(workingFile, contents)){
        std::cout << contents << std::endl;
    }

    workingFile.close();
}

void fileTools::editFile(std::string fileName){
    if (containsWhitespace(fileName)) {
        return;
    }

    if(!fs::exists(getCurrentDirectory() / fileName)){
        std::cout << fileName << "does not exist." << std::endl;
        return;
    }
    

    std::string commandString = "notepad.exe \"" + (getCurrentDirectory() / fileName).string() + "\"";
    system(commandString.c_str());
}


void fileTools::deleteFile(std::string fileName){
    std::string file = fileName + ".txt";
    fs::path filePath = getCurrentDirectory() / file;
    char confirm;
    if (containsWhitespace(fileName)) {
        return;
    }

    if(!fs::exists(filePath)){
        
        std::cout << fileName << " does not exist." << std::endl;
        return;
    } else {
        std::cout << fileName << " found." << std::endl;
    }
    std::cout << "Please confirm deletion order Y/N: " << std::endl;
    std::cin >> confirm;
        
    if(confirm == 'N' || confirm == 'n'){
        std::cout << "Deletion cancelled." << std::endl;
        return;
    } else if (confirm == 'Y' || confirm == 'y'){
        std::cout << "Deletion confirmed." << std::endl;
        fs::remove(filePath);
        return;
    } else {
        std::cout << "Invalid input!" << std::endl;
        return;
    }
    
    
}


void fileTools::fileMenu() {
    int option;
    std::string name, ext;

    while (true) {
        std::cout << "\n=========== File Menu ===========\n";
        std::cout << "Current Directory: " << getCurrentDirectory() << "\n";
        std::cout << "1. Create File\n";
        std::cout << "2. Read file\n";
        std::cout << "3. Edit file\n";
        std::cout << "4. Delete file\n";
        std::cout << "0. Return to Directory Menu\n";
        std::cout << "Enter option: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
            case 1:
                std::cout << "Enter file name (no extension): ";
                std::getline(std::cin, name);
                std::cout << "Enter file extension (txt, dat): ";
                std::getline(std::cin, ext);
                createFile(name, ext);
                break;
            case 2:
                std::cout << "Enter file name (with extension, txt only): ";
                std::getline(std::cin, name);
                readFile(name);
            break;
            case 3:
                std::cout << "Enter file name (with extension, txt only): ";
                std::getline(std::cin, name);
                editFile(name);
            break;
            case 4:
                std::cout << "Enter file name (with extension, txt only): ";
                std::getline(std::cin, name);
                deleteFile(name);
            break;
            case 0:
                return;
            default:
                std::cout << "Invalid option.\n";
        }
    }
}
