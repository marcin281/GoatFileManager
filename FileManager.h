#ifndef FILEMANAGER_FILEMANAGER_H
#define FILEMANAGER_FILEMANAGER_H

#include <filesystem>

class FileManager {
private:
    std::filesystem::path directorypath;

public:
    FileManager();

    bool show_files() const;
    bool open_directory(const std::string & name);
    bool make_directory(const std::string & name) const;
    bool delete_file(const std::string & name) const;
    bool copy(const std::string & name, const std::string & name2) const;
    bool copy_folder(const std::string & name, const std::string & name2) const;
    bool rename(const std::string & name, const std::string & name2) const;
    bool move(const std::string & name, const std::string & name2) const;
    bool back();
};

#endif