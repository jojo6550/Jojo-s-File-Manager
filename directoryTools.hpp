#ifndef DIRECTORYTOOLS_HPP
#define DIRECTORYTOOLS_HPP

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <ctime>

namespace fs = std::filesystem;

class directoryTools {
protected:
    fs::path root;
    fs::path currentDirectory;
    std::string logType;

public:
    directoryTools();
    directoryTools(const fs::path& startPath);

    void createDirectory(const std::string& directoryName);
    void deleteDirectory(const std::string& directoryName);
    void renameDirectory(const std::string& oldName, const std::string& newName);
    void changeDirectory(const std::string& path);
    void listDirectoryContents() const;
    void goBack();
    void resetToRoot();
    void directoryMenu();
    
    fs::path getCurrentDirectory() const;
    bool containsWhitespace(const std::string& str) const;
};

#endif // DIRECTORYTOOLS_HPP
