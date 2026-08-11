//
// Created by marcin on 8/6/26.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include "log.h"

using namespace std;
namespace fs = std::filesystem;

log::log() {
    logfile = fs::path(getenv("HOME")) / ".config/goat/log.txt";
    fs::create_directories(logfile.parent_path());
}
void log::add(const string& message) const {
    if (ofstream file(logfile, ios::app); file.is_open()) {
        file << message << endl;
    }
}
