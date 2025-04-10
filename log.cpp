#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <ctime>


class Log {
private:
    std::vector<std::string> logs;
    time_t timestamp;
public:


    void logger(std::string event){
        time(&timestamp);
        std::string time = ctime(&timestamp);
        logs.emplace_back("User has " + event + " @ " + time);
    }

    void displayLogs(){
        for(std::string log : logs){
            std::cout << log << std::endl;
        }
    }
};