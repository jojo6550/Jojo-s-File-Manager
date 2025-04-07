#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class directoryTools{
private:
    //define root directory
    fs::path root = "root";
    fs::path currentDirectory = root;

public:
    directoryTools(fs::path root){
        this->root = root;
        //creates root if it doesn't exists
        if(!fs::exists(root)){
            fs::create_directory(root);
        }
    }
    //returns current directory inside root
    fs::path getCurrentDirectory(){
        return currentDirectory;
    }

    void returnToRoot(){
        currentDirectory = root;
    }

    void changeDirectory(fs::path subDirectoryPath){
        fs::path newDirectory = currentDirectory / subDirectoryPath;

        if(fs::exists(newDirectory)){
            currentDirectory = newDirectory;
        } else {
            std::cout << "Directory does not exist." << std::endl;
        }
    }

    //creates directory
    void createSubdirectory(fs::path subDirectoryPath){
        if(fs::exists(getCurrentDirectory() / subDirectoryPath) || fs::is_directory(getCurrentDirectory() / subDirectoryPath)){
            std::cout << subDirectoryPath << " already exists!" << std::endl;
        } else {
            fs::create_directory(getCurrentDirectory() / subDirectoryPath);
        }
    }
    //renames directory
    void renameSubdirectory(fs::path oldDirectoryName, fs::path newDirectoryName){
        if(!fs::exists(getCurrentDirectory()/ oldDirectoryName) || !fs::is_directory(getCurrentDirectory() / oldDirectoryName)){
            std::cout << "Directory does not exist..." << std::endl;
        } else {
            fs::rename(getCurrentDirectory() / oldDirectoryName, getCurrentDirectory() / newDirectoryName);
        }
    }
    //deletes directory
    void deleteSubdirectory(fs::path subDirectoryPath){
        if(!fs::exists(getCurrentDirectory() / subDirectoryPath) || !fs::is_directory(getCurrentDirectory() / subDirectoryPath)){
            std::cout << "Directory does not exist..." << std::endl;
        } 

        std::cout << "Please enter directory name to confirm deletion order: " << std::endl;
        
        std::string dirName;

        std::cin >> dirName;

        if(dirName == subDirectoryPath.string()){
            fs::remove( getCurrentDirectory() / subDirectoryPath);
        } else {
            std::cout << "Deletion order cancelled..." << std::endl;
        }
    }
    

    void listSubdirectories(){
        fs::path workingDir = getCurrentDirectory();
        std::cout << "Current directory: " << workingDir << std::endl;
        for(const auto var : fs::directory_iterator(workingDir)){
            std::cout << var << std::endl;
        }

    }

    

};


