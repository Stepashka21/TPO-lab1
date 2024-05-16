#ifndef TPO_LAB1_FILEWRITER_H
#define TPO_LAB1_FILEWRITER_H

#include <iostream>
#include <fstream>
#include "string"
#include "iostream"
using namespace std;

class FileWriter {
private:
    ofstream file;
public:
    explicit FileWriter(const string& filename) : file(filename, ios::out) {
        if (!file.is_open()) cerr << "Ошибка открытия файла!" << std::endl;
    }

    ~FileWriter() {
        if (file.is_open()) file.close();
    }

    void writeData(const string& data) {
        if (file.is_open()) file << data << ",";
        else cerr << "Файл не открыт!" << std::endl;
    }
};

#endif
