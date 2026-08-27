#ifndef FILEMANAGER_FILEMANAGER_H
#define FILEMANAGER_FILEMANAGER_H

#include <filesystem>
#include <vector>
namespace fs = std::filesystem;
class FileManager {
private:
    std::filesystem::path directorypath;

public:
    FileManager();

    bool show_files() const;
    [[nodiscard]] std::vector<fs::directory_entry> get_files() const;
    void open_directory(const std::string & name);
    bool make_directory(const std::string & name) const;
    bool delete_file(const std::string & name) const;
    bool copy(const std::string & name, const std::string & name2) const;
    bool copy_folder(const std::string & name, const std::string & name2) const;
    bool rename(const std::string & name, const std::string & name2) const;
    bool move(const std::string & name, const std::string & name2) const;
    bool back();
};

#endif