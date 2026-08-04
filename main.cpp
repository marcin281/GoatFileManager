#include "main.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>

using namespace std;
namespace fs=std::filesystem;

fs::path directorypath = getenv("HOME");;


void show_files() {
    cout<<directorypath<<endl;
    for (const auto& entry :
         fs::directory_iterator(directorypath)) {
        if (entry.is_directory()) {cout<<"Directory ";}
        else {cout<<"File ";}
        cout << entry.path().filename() << endl;
         }
}

void open_directory() {
    string dir;
    string command;
    cin>>dir;
    fs::path checkpath = directorypath / dir;
    if (fs::exists(checkpath)) {
        if (fs::is_directory(checkpath)) {directorypath = directorypath / dir;}
        else {
            command="nano " + checkpath.string();
            system(command.c_str());
        }

    }
    else{cout<<"Directory not found"<<endl;}
}

void make_directory() {
    string dir;
    cin>>dir;
    fs::create_directory(directorypath / dir);
    cout<<"made "<<dir<<" directory"<<endl;
}
void copy() {
    string dir1, dir2;
    cin>>dir1;
    cin>>dir2;
    fs::copy(directorypath/dir1, directorypath/dir2, fs::copy_options::recursive);
    //trzeba zrobic copy file i copy directory bo w directory musi byc źródło:
    //directorypath / dir1
    //
    //cel:
    //directorypath / dir2 / dir1
}
void rename() {
    string dir,dir2;
    cin>>dir;
    cin>>dir2;
    fs::rename(directorypath/dir, directorypath/dir2);
}
int main() {
    int a;
    while (true) {
        cout<<"1-show files, 2-open folder, 3-create Directory, 4- delete file, 5-copy files, 6-rename file, 7-exit"<<endl;
        cin>>a;
        switch (a) {
            case 1:
                cout<<"show"<<endl;
                show_files();
                break;
            case 2:
                cout<<"open"<<endl;
                open_directory();
                break;
            case 3:
                cout<<"create"<<endl;
                make_directory();
                break;
            case 4:
                cout<<"delete"<<endl;
                break;
            case 5:
                cout<<"copy"<<endl;
                copy();
                break;
            case 6:
                cout<<"rename"<<endl;
                rename();
                break;
            case 7:
                return 0;
            default:
                cout<<"Invalid option"<<endl;
                break;
        }
    }
    return 0;
}