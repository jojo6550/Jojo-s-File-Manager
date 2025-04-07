#include <iostream>
#include <fstream>
#include <filesystem>
#include "directoryTools.cpp"

int main(){
    directoryTools dt("root");
    fileTools ft(dt);
    ft.createFile("test2", "txt");
    //dt.directoryMenu();
    
}