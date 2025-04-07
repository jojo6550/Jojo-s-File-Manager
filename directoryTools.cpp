#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class directoryTools
{
private:
    //define root directory
    fs::path root = "root";

public:
    directoryTools(fs::path root){
        this->root = root;
        //creates root if it doesn't exists
        if(!fs::exists(root)){
            fs::create_directory(root);
        }
    }

    void createSubdirectory(fs::path subDirectoryPath){
        if(fs::exists(root / subDirectoryPath) || fs::is_directory(root / subDirectoryPath)){
            std::cout << subDirectoryPath << " already exists!" << std::endl;
        } else {
            fs::create_directory(root / subDirectoryPath);
        }
    }

    void renameSubdirectory(fs::path oldDirectoryName, fs::path newDirectoryName){
        fs::rename(oldDirectoryName,newDirectoryName);
    }

};


