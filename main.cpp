#include <iostream>
#include <fstream>
#include <filesystem>
#include "directoryTools.cpp"

int main(){
    directoryTools dt("root");
    dt.createSubdirectory("dir1");
    std::cout << dt.getCurrentDirectory() << std::endl;
    dt.changeDirectory("dir1");
    std::cout << dt.getCurrentDirectory() << std::endl;
    dt.returnToRoot();
    std::cout << dt.getCurrentDirectory() << std::endl;
    //dt.renameSubdirectory("dir1", "renamed_dir");
    dt.deleteSubdirectory("dir1");

    dt.listSubdirectories();
    
}