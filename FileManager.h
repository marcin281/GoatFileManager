#ifndef FILEMANAGER_FILEMANAGER_H
#define FILEMANAGER_FILEMANAGER_H

#include <filesystem>

class FileManager {
private:
    std::filesystem::path directorypath;

public:
    FileManager();

    void show_files() const;
    void open_directory();
    void make_directory() const;
    void delete_file() const;
    void copy() const;
    void copy_folder() const;
    void rename() const;
    void move() const;
    void back();
};

#endif