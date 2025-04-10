#include <iostream>
#include <fstream>
#include <filesystem>
#include "directoryTools.hpp"
#include "fileTools.hpp"




int main(){
    directoryTools dt("root");
    //fileTools ft();
    //ft.createFile("test2", "txt");
    dt.directoryMenu();
    return 0;


    
}

