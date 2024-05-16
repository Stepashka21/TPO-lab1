//Дан массив целых чисел а0,...,аn-1. Все элементы массива, состоящие из нечетных цифр заменить суммой всех элементов массива.
//На входе функции:	массив целых чисел, длина массива может быть любой
//На выходе функции:	сумма всех элементов массива
//                      массив целых чисел
//                      массив ошибок при выполнении функции

// int -2.147.483.648 до 2.147.483.647

#pragma once

#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <map>
#include <sstream>
#include <variant>
#include <fstream>
#include "../tests/FileWriter.h"

using namespace std;

struct Data {
public:
    vector<int> input;
    int sum = 0;
    vector<int> result;
    map<string, vector<string>> errors;

    template<typename T>
    void foreach(const vector<T> &array, void (*func)(Data&, T&)){
        for (T element : array) {
            func(*this, element);
        }
    }
};

Data Solution(const vector<string>& testData);
bool checkOddDigitsIn(int number);