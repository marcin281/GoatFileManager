#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>

#include "FileManager.h"

using namespace std;
namespace fs=std::filesystem;

fs::path directorypath = getenv("HOME");;


int main() {
    FileManager fm;
    int a;
    while (true) {
        cout<<"1-show files, 2-open folder, 3-create Directory, 4- delete file, 5-copy files, 6-copy folder, 7-rename file, 8- move, 9- back,0-exit"<<endl;
        cin>>a;
        switch (a) {
            case 1:
                cout<<"show"<<endl;
                fm.show_files();
                break;
            case 2:
                cout<<"open"<<endl;
                fm.open_directory();
                break;
            case 3:
                cout<<"create"<<endl;
                fm.make_directory();
                break;
            case 4:
                cout<<"delete"<<endl;
                fm.delete_file();
                break;
            case 5:
                cout<<"copy"<<endl;
                fm.copy();
                break;
            case 6:
                cout<<"copy folder"<<endl;
                fm.copy_folder();
                break;
            case 7:
                cout<<"rename"<<endl;
                fm.rename();
                break;
            case 8:
                cout<<"move"<<endl;
                fm.move();
                break;
            case 9:
                cout<<"back"<<endl;
                fm.back();
                break;
            case 0:
                return 0;
            default:
                cout<<"Invalid option"<<endl;
                break;
        }
    }
}