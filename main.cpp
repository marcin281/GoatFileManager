#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>

#include "FileManager.h"
#include "log.h"

using namespace std;
namespace fs=std::filesystem;

fs::path directorypath = getenv("HOME");;


int main() {
    FileManager fm;
    int a;
    string name, name2, choice;
    while (true) {
        log log;
        cout<<"1-show files, 2-open folder, 3-create Directory, 4- delete file, 5-copy files, 6-copy folder, 7-rename file, 8- move, 9- back,0-exit"<<endl;
        cin>>a;
        switch (a) {
    case 1:
        cout << "show" << endl;
        if (fm.show_files())
            log.add("Showed folder");
        else
            log.add("Show folder failed");
        break;

    case 2:
        cout << "open" << endl;
        cin >> name;
        if (fm.open_directory(name))
            log.add("Opened folder " + name);
        else
            log.add("Open folder failed");
        break;

    case 3:
        cout << "create" << endl;
        cin >> name;
        if (fm.make_directory(name))
            log.add("Created folder " + name);
        else
            log.add("Create folder failed");
        break;

    case 4:
        cout << "delete" << endl;
        cin >> name;
        cout << "You want to delete this file/directory? y/N" << endl;
        cin >> choice;

        if (choice == "y") {
            if (fm.delete_file(name))
                log.add("Deleted " + name);
            else
                log.add("Delete failed");
        }
        break;

    case 5:
        cout << "copy" << endl;
        cin >> name;
        cin >> name2;
        if (fm.copy(name, name2))
            log.add("Copied " + name + " to " + name2);
        else
            log.add("Copy failed");
        break;

    case 6:
        cout << "copy folder" << endl;
        cin >> name;
        cin >> name2;
        if (fm.copy_folder(name, name2))
            log.add("Copied folder " + name + " to " + name2);
        else
            log.add("Copy folder failed");
        break;

    case 7:
        cout << "rename" << endl;
        cin >> name;
        cin >> name2;
        if (fm.rename(name, name2))
            log.add("Renamed " + name + " to " + name2);
        else
            log.add("Rename failed");
        break;

    case 8:
        cout << "move" << endl;
        cin >> name;
        cin >> name2;
        if (fm.move(name, name2))
            log.add("Moved " + name + " to " + name2);
        else
            log.add("Move failed");
        break;

    case 9:
        cout << "back" << endl;
        if (fm.back())
            log.add("Moved back");
        else
            log.add("Back failed");
        break;

    case 0:
        log.add("Closing app");
        return 0;

    default:
        cout << "Invalid option" << endl;
        break;
}
    }
}