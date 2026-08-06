#ifndef FILEMANAGER_LOG_H
#define FILEMANAGER_LOG_H
#include <filesystem>
#include <string>

class log {
    std::filesystem::path logfile;
    public:
    log();

    void add(const std::string& message) const;
};


#endif //FILEMANAGER_LOG_H
