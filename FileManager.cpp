#include "FileManager.h"
#include <iostream>
#include <cstdlib>

namespace fs = std::filesystem;
using namespace std;

FileManager::FileManager()
{
    directorypath = getenv("HOME");
}

void FileManager::show_files() const {
    cout<<directorypath<<endl;
    for (const auto& entry :
         fs::directory_iterator(directorypath)) {
        if (entry.is_directory()) {cout<<"Directory ";}
        else {cout<<"File ";}
        cout << entry.path().filename() << endl;
         }
}

void FileManager::open_directory() {
    string dir;
    string command;
    cin>>dir;
    if (const fs::path checkpath = directorypath / dir; fs::exists(checkpath)) {
        if (fs::is_directory(checkpath)) {directorypath = directorypath / dir;}
        else {
            command="nano " + checkpath.string();
            system(command.c_str());
        }

    }
    else{cout<<"Directory not found"<<endl;}
}

void FileManager::make_directory() const {
    string dir;
    cin>>dir;
    fs::create_directory(directorypath / dir);
    cout<<"made "<<dir<<" directory"<<endl;
}
void FileManager::delete_file() const {
    string dir;
    char choice;
    cin>>dir;
    cout<<"Delete "<<dir<<"? y/N"<<endl;
    cin>>choice;
    if (choice == 'y') {fs::remove_all(directorypath / dir);}
}
void FileManager::copy() const {
    string dir1, dir2;
    cin>>dir1;
    cin>>dir2;
    fs::copy(directorypath/dir1, directorypath/dir2, fs::copy_options::recursive);
}
void FileManager::copy_folder() const {
    string dir1, dir2;
    cin>>dir1;
    cin>>dir2;
    fs::copy(directorypath/dir1, directorypath/dir2/dir1, fs::copy_options::recursive);
}
void FileManager::rename() const {
    string dir,dir2;
    cin>>dir;
    cin>>dir2;
    fs::rename(directorypath/dir, directorypath/dir2);
}
void FileManager::move() const {
    string dir,dir2;
    cin>>dir;
    cin>>dir2;
    fs::rename(directorypath/dir, directorypath/dir2/dir);
}
void FileManager::back() {
    directorypath = directorypath.parent_path();
}