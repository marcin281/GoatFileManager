#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>

#include "FileManager.h"
#include "log.h"
#include "ncurses.h"

using namespace std;
namespace fs=std::filesystem;

fs::path directorypath = getenv("HOME");;


int main() {
    FileManager fm;

    ncurses_start(directorypath);

    return 0;
}