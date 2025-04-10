#include "directoryTools.hpp"
#include "fileTools.hpp"
#include "log.cpp"

Log logs;



directoryTools::directoryTools() {
    root = fs::current_path() / "root";
    if (!fs::exists(root)) {
        fs::create_directory(root);
    }
    currentDirectory = root;
    logs.logger("entered application");

    

}

directoryTools::directoryTools(const fs::path& startPath) {
    root = startPath;
    if (!fs::exists(root)) {
        fs::create_directory(root);
    }
    currentDirectory = root;
    logs.logger("entered application");
}

void directoryTools::createDirectory(const std::string& directoryName) {
    if (containsWhitespace(directoryName)) {
        std::cout << "Invalid directory name: contains whitespace.\n";
        return;
    }

    fs::path newDir = currentDirectory / directoryName;
    if (!fs::exists(newDir)) {
        fs::create_directory(newDir);
        std::cout << "Directory created: " << newDir << "\n";
        logs.logger("created a directory");

    } else {
        std::cout << "Directory already exists: " << newDir << "\n";
    }
}

void directoryTools::deleteDirectory(const std::string& directoryName) {
    fs::path targetDir = currentDirectory / directoryName;
    if (fs::exists(targetDir) && fs::is_directory(targetDir)) {
        fs::remove_all(targetDir);
        std::cout << "Directory deleted: " << targetDir << "\n";
        logs.logger("deleted a directory");

    } else {
        std::cout << "Directory does not exist: " << targetDir << "\n";
    }
}

void directoryTools::renameDirectory(const std::string& oldName, const std::string& newName) {
    fs::path oldPath = currentDirectory / oldName;
    fs::path newPath = currentDirectory / newName;
    if (fs::exists(oldPath)) {
        fs::rename(oldPath, newPath);
        std::cout << "Directory renamed.\n";
        logs.logger("renamed a directory");

    } else {
        std::cout << "Directory does not exist.\n";
    }
}

void directoryTools::changeDirectory(const std::string& path) {
    fs::path target = currentDirectory / path;
    if (fs::exists(target) && fs::is_directory(target)) {
        currentDirectory = target;
        logs.logger("moved into a directory: " + target.string());

    } else {
        std::cout << "Invalid directory.\n";
    }
}

void directoryTools::listDirectoryContents() const {
    std::cout << "Contents of " << currentDirectory << ":\n";
    for (const auto& entry : fs::directory_iterator(currentDirectory)) {
        std::cout << (fs::is_directory(entry.path()) ? "[DIR] " : "[FILE] ") << entry.path().filename() << "\n";
        logs.logger("listed directory contents");

    }
}

void directoryTools::goBack() {
    if (currentDirectory != root) {
        currentDirectory = currentDirectory.parent_path();
        logs.logger("moved up a directory level");

    } else {
        std::cout << "Already at root directory.\n";
    }
}

void directoryTools::resetToRoot() {
    logs.logger("moved to root");
    currentDirectory = root;
}

fs::path directoryTools::getCurrentDirectory() const {
    return currentDirectory;
}

bool directoryTools::containsWhitespace(const std::string& str) const {
    return str.find(' ') != std::string::npos;
}

void directoryTools::directoryMenu() {
    int option;
    std::string dirName, newName;

    while (true) {
        std::cout << "\n========== Directory Menu ==========\n";
        std::cout << "Current Directory: " << getCurrentDirectory() << "\n";
        std::cout << "1. Create Directory\n";
        std::cout << "2. Delete Directory\n";
        std::cout << "3. Rename Directory\n";
        std::cout << "4. Change Directory\n";
        std::cout << "5. Go Back\n";
        std::cout << "6. Reset to Root\n";
        std::cout << "7. File Operations\n";
        std::cout << "8. List Contents\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter option: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
            case 1:
                std::cout << "Enter directory name: ";
                std::getline(std::cin, dirName);
                createDirectory(dirName);
                break;
            case 2:
                std::cout << "Enter directory name to delete: ";
                std::getline(std::cin, dirName);
                deleteDirectory(dirName);
                break;
            case 3:
                std::cout << "Enter current directory name: ";
                std::getline(std::cin, dirName);
                std::cout << "Enter new directory name: ";
                std::getline(std::cin, newName);
                renameDirectory(dirName, newName);
                break;
            case 4:
                std::cout << "Enter directory name to enter: ";
                std::getline(std::cin, dirName);
                changeDirectory(dirName);
                break;
            case 5:
                goBack();
                break;
            case 6:
                resetToRoot();
                break;
            case 7: {
                fileTools ft(getCurrentDirectory());
                ft.fileMenu();
                break;
            }
            case 8:
                listDirectoryContents();
                break;
            case 9:{
                logs.displayLogs();
                break;
            }
            case 0:
                return;
            default:
                std::cout << "Invalid option.\n";
        }
    }
}
