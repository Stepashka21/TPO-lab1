#include <iostream>
#include "vector"
#include "../tests/FileWriter.h"
#include "../lib/lr1.h"
#include <cstdlib>

using namespace std;

int generateRandomNumber() {
    return - 999 + rand() % 2000;
}


int main() {
    srand(time(nullptr));
    FileWriter file("../../tests/log.txt");
    vector<int> array;
    for(int i = 0; i < 800;){
        int value = generateRandomNumber();
        if (checkOddDigitsIn(value)){
            array.push_back(value);
            file.writeData(to_string(value));
            i++;
//            if (i == 729/2){
//                array.push_back(21);
//                file.writeData(to_string(21));
//            }
        } else {
//            array.push_back(value);
//            file.writeData(to_string(value));
//            i++;
        }

//        array.push_back(value);
//        file.writeData(to_string(value));
//        i++;
    }
    file.writeData("\n");
    int sum = 0;
    for (int num : array) {
        sum += num;
    }
    file.writeData(to_string(sum) + "\n");
    for(auto item: array){
        if(checkOddDigitsIn(item))
            file.writeData(to_string(sum));
        else file.writeData(to_string(item));
    }
    return 0;
}