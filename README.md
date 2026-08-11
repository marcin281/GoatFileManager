# Goat File Manager

**Goat File Manager** is a simple terminal-based file manager written in **C++** using the standard `<filesystem>` library.

The program allows you to browse directories, create and delete files/folders, copy and move files, rename items, and open files directly in **nano**.

## Features

* **Show files and directories**
* **Open directories**
* **Open files using nano**
* **Create directories**
* **Delete files and directories**
* **Copy files**
* **Copy folders recursively**
* **Rename files and directories**
* **Move files and directories**
* **Go back to the parent directory**
* **Log actions to a file**

## Requirements

Before running Goat File Manager, make sure you have:

* **C++17 or newer**
* A C++ compiler such as **g++**
* **nano** — required for opening files from the file manager
* A **Linux/Unix-like operating system**

The program uses the `$HOME` environment variable to determine the starting directory and the location of the log file.

### Fedora

```bash
sudo dnf install gcc-c++ nano
```
### Debian like

```bash
sudo apt install gcc-c++ nano
```
### Arch

```bash
sudo pacman install gcc-c++ nano
```

## Building

Clone the repository:

```bash
git clone https://github.com/marcin281/GoatFileManager.git
cd goat
```

Compile the project with:

```bash
g++ main.cpp FileManager.cpp log.cpp -o goat
```

Run the program:

```bash
./goat
```

## Usage

After starting the program, you will see the main menu:

```text
1 - Show files
2 - Open folder
3 - Create directory
4 - Delete file
5 - Copy file
6 - Copy folder
7 - Rename file
8 - Move
9 - Back
0 - Exit
```

### 1. Show files

Displays all files and directories in the current directory.

Example:

```text
Directory Documents
Directory Downloads
File test.txt
```

### 2. Open folder / file

Enter the name of a directory to enter it.

If the selected item is a file, it will be opened using **nano**.

Example:

```text
2
Documents
```

or:

```text
2
test.txt
```

### 3. Create directory

Creates a new directory in the current directory.

```text
3
NewFolder
```

### 4. Delete

Deletes a file or directory.

The program asks for confirmation before deleting:

```text
You want to delete this file/directory? y/N
```

Enter `y` to confirm.

### 5. Copy file

Copies a file to another location or name.

```text
5
file.txt
backup.txt
```

### 6. Copy folder

Copies a directory recursively.

```text
6
Documents
Backup
```

### 7. Rename

Renames a file or directory.

```text
7
old.txt
new.txt
```

### 8. Move

Moves a file or directory into another directory.

```text
8
file.txt
Documents
```

### 9. Back

Moves to the parent directory.

```text
9
```

### 0. Exit

Closes the application.

```text
0
```

## Logging

Goat automatically logs successful and failed operations.

The log file is stored at:

```text
~/.config/goat/log.txt
```

Example:

```text
Showed folder
Opened folder Documents
Created folder Test
Copied file.txt to backup.txt
Renamed old.txt to new.txt
Moved back
Closing app
```

The log directory is created automatically when the program starts.

## Technologies

* **C++**
* **C++17 `std::filesystem`**
* **fstream**
* **Linux filesystem**
* **nano**

## Project Structure

```text
.
├── main.cpp
├── FileManager.cpp
├── FileManager.h
├── log.cpp
├── log.h
└── README.md
```

## Notes

Goat File Manager is a simple project designed to practice working with:

* **C++ classes**
* **`std::filesystem`**
* **File and directory operations**
* **Exception handling**
* **Logging**
* **Command-line interfaces**
* **Linux filesystem paths**

The program currently starts in the user's home directory:

```text
$HOME
```

Most file operations use paths relative to the current directory.

## License

This project is for educational purposes.
Compile the project with:
