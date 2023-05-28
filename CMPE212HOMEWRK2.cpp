#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile() {
    string filename;
    cout << "Enter the new file name: ";
    cin >> filename;

    ofstream file(filename);

    if (file) {
        cout << "File created successfully!" << endl;
        file.close();
    }
    else {
        cout << "Failed to create file." << endl;
    }
}

void copyFile() {
    string source, destination;
    cout << "Enter the source file name: ";
    cin >> source;
    cout << "Enter the destination file name: ";
    cin >> destination;

    ifstream sourceFile(source);
    ofstream destFile(destination);

    if (sourceFile && destFile) {
        char ch;
        while (sourceFile.get(ch)) {
            destFile.put(ch);
        }

        cout << "File copied successfully!" << endl;
        sourceFile.close();
        destFile.close();
    }
    else {
        cout << "Failed to copy file." << endl;
    }
}

void copyFileWithoutSpaces() {
    string source, destination;
    cout << "Enter the source file name: ";
    cin >> source;
    cout << "Enter the destination file name: ";
    cin >> destination;

    ifstream sourceFile(source);
    ofstream destFile(destination);

    if (sourceFile && destFile) {
        char ch;
        while (sourceFile.get(ch)) {
            if (!isspace(ch)) {
                destFile.put(ch);
            }
        }

        cout << "File copied successfully without spaces!" << endl;
        sourceFile.close();
        destFile.close();
    }
    else {
        cout << "Failed to copy file without spaces." << endl;
    }
}

void mergeFiles() {
    string source1, source2, destination;
    cout << "Enter the first source file name: ";
    cin >> source1;
    cout << "Enter the second source file name: ";
    cin >> source2;
    cout << "Enter the destination file name: ";
    cin >> destination;

    ifstream file1(source1);
    ifstream file2(source2);
    ofstream destFile(destination);

    if (file1 && file2 && destFile) {
        char ch;
        while (file1.get(ch)) {
            destFile.put(ch);
        }

        while (file2.get(ch)) {
            destFile.put(ch);
        }

        cout << "Files merged successfully!" << endl;
        file1.close();
        file2.close();
        destFile.close();
    }
    else {
        cout << "Failed to merge files." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1- Create file" << endl;
        cout << "2- Copy file" << endl;
        cout << "3- Copy file without spaces" << endl;
        cout << "4- Merge files" << endl;
        cout << "5- Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createFile();
            break;
        case 2:
            copyFile();
            break;
        case 3:
            copyFileWithoutSpaces();
            break;
        case 4:
            mergeFiles();
            break;
        case 5:
            cout << "Quitting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
