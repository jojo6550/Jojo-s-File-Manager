#include <iostream>
#include <fstream>
#include <filesystem>
#include "directoryTools.cpp"

int main(){
    directoryTools dt("root");
    dt.createSubdirectory("dir1");
    //dt.renameSubdirectory("dir1", "renamed_dir");
}