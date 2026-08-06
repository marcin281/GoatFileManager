#include "FileManager.h"
#include <iostream>
#include <cstdlib>

namespace fs = std::filesystem;
using namespace std;

FileManager::FileManager()
{
    directorypath = getenv("HOME");
}

bool FileManager::show_files() const {
    if (!fs::exists(directorypath)) {
        cout << "Directory does not exist\n";
        return false;
    }
    cout<<directorypath<<endl;
    for (const auto& entry :
         fs::directory_iterator(directorypath)) {
        if (entry.is_directory()) {cout<<"Directory ";}
        else {cout<<"File ";}
        cout << entry.path().filename() << endl;
         }
    return true;
}

bool FileManager::open_directory(const std::string & name) {
    string command;
    if (const fs::path checkpath = directorypath / name; fs::exists(checkpath)) {
        if (fs::is_directory(checkpath)) {directorypath = directorypath / name;}
        else {
            command = "nano \"" + checkpath.string() + "\"";
            system(command.c_str());
            return true;
        }

    }
    else{cout<<"Directory not found"<<endl;}
    return false;
}

bool FileManager::make_directory(const string& name) const {
    try {
        fs::create_directory(directorypath / name);
        return true;
    }
    catch(const fs::filesystem_error& e)
    {
        cout << e.what() << endl;
        return false;
    }
}
bool FileManager::delete_file(const string& name) const
{
    try {
        fs::remove_all(directorypath / name);
        return true;
    }
    catch(const fs::filesystem_error& e)
    {
        cout << e.what() << endl;
        return false;
    }
}
bool FileManager::copy(const string& name, const string& name2) const
{
    try {
        fs::copy_file(
            directorypath / name,
            directorypath / name2
        );
        return true;
    }
    catch(const fs::filesystem_error& e)
    {
        cout << e.what() << endl;
        return false;
    }
}
bool FileManager::copy_folder(const string& name, const string& name2) const
{
    try {
        fs::copy(
            directorypath / name,
            directorypath / name2 / name,
            fs::copy_options::recursive
        );
        return true;
    }
    catch(const fs::filesystem_error& e)
    {
        cout << e.what() << endl;
        return false;
    }
}
bool FileManager::rename(const std::string & name, const std::string & name2) const {
    try {
        fs::rename(directorypath/name, directorypath/name2);
        return true;
    }
    catch(const fs::filesystem_error& e)
    {
        cout << e.what() << endl;
        return false;
    }
}
bool FileManager::move(const std::string & name, const std::string & name2) const {
    try {
        fs::rename(directorypath/name, directorypath/name2/name);
        return true;
    }
    catch(const fs::filesystem_error& e)
    {
        cout << e.what() << endl;
        return false;
    }
}
bool FileManager::back() {
    directorypath = directorypath.parent_path();
    return true;
}