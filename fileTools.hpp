#ifndef FILETOOLS_HPP
#define FILETOOLS_HPP

#include "directoryTools.hpp"
#include <vector>
#include <string>

class fileTools : public directoryTools {
public:
    fileTools() = default;
    fileTools(fs::path rootPath) {
        this->root = rootPath;
        if (!fs::exists(root)) {
            fs::create_directory(root);
        }
        this->currentDirectory = root;
    }

    void createFile(std::string fileName, std::string fileExtension);
    void readFile(std::string fileName, std::string fileExtension);
    void fileMenu();
};

#endif
