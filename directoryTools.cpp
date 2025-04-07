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


    //Returns current directory to parent folder
    void returnToRoot(){
        currentDirectory = root;
    }

    //Changes directory one level down
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
    
    //lists subdirectories
    void listSubdirectories(){
        fs::path workingDir = getCurrentDirectory();
        std::cout << "Current directory: " << workingDir << std::endl;
        for(const auto var : fs::directory_iterator(workingDir)){
            std::cout << var << std::endl;
        }

    }

    void countSubdirectories(){
        fs::path workingDir = getCurrentDirectory();
        int count = 0;
        for(const auto var : fs::directory_iterator(workingDir)){
            count++;
        }
        std::cout << "# of subdirectories found: " << count << std::endl;
    }


    void directoryMenu(){
        int option;
        std::string input1, input2;
    
        while (true) {
            std::cout << "\n==============================\n";
            std::cout << "  Directory Manager Menu\n";
            std::cout << "==============================\n";
            std::cout << "Current Directory: " << getCurrentDirectory() << "\n";
            countSubdirectories();
            std::cout << "1. Create Subdirectory\n";
            std::cout << "2. Rename Subdirectory\n";
            std::cout << "3. Delete Subdirectory\n";
            std::cout << "4. Change Directory\n";
            std::cout << "5. Return to Root\n";
            std::cout << "6. List Subdirectories\n";
            std::cout << "0. Exit\n";
            std::cout << "==============================\n";
            std::cout << "Enter option: ";
            std::cin >> option;
    
            std::cin.ignore(); // clear input buffer
    
            switch(option){
                case 1:
                    std::cout << "Enter name of subdirectory to create: ";
                    std::getline(std::cin, input1);
                    createSubdirectory(input1);
                    break;
                case 2:
                    std::cout << "Enter current name of subdirectory: ";
                    std::getline(std::cin, input1);
                    std::cout << "Enter new name: ";
                    std::getline(std::cin, input2);
                    renameSubdirectory(input1, input2);
                    break;
                case 3:
                    std::cout << "Enter name of subdirectory to delete: ";
                    std::getline(std::cin, input1);
                    deleteSubdirectory(input1);
                    break;
                case 4:
                    std::cout << "Enter subdirectory to navigate into: ";
                    std::getline(std::cin, input1);
                    changeDirectory(input1);
                    break;
                case 5:
                    returnToRoot();
                    std::cout << "Returned to root directory.\n";
                    break;
                case 6:
                    listSubdirectories();
                    break;
                case 0:
                    std::cout << "Exiting directory manager...\n";
                    return;
                default:
                    std::cout << "Invalid option. Please try again.\n";
            }
        }       
    }
    

};


