#include "lr1.h"

//Дан массив целых чисел а0,...,аn-1. Все элементы массива, состоящие из нечетных цифр заменить суммой всех элементов массива.
//На входе функции:	массив целых чисел, длина массива может быть любой
//На выходе функции:	сумма всех элементов массива
//                      массив целых чисел
//                      массив ошибок при выполнении функции

// int -2.147.483.648 до 2.147.483.647

using namespace std;

inline bool checkOddDigitsIn(int number){
    do {
        int digit = number % 10;
        if (!(digit % 2)) return false;
        number = (number - digit) / 10;
    } while(number);

    return true;
}

inline void funcForResult(Data &data, int &element){
    if (checkOddDigitsIn(element))
        data.result.push_back(data.sum);
    else data.result.push_back(element);
}

inline void parseInt(Data &data, string &element){
    try {
        int number = stoi(to_string(stod(element)));
        data.input.push_back(number);

        int temp = data.sum + number;
        if(number > 0 && temp < data.sum || number < 0 && temp > data.sum)
            data.errors["overflow of sum"].emplace_back(element);
        else data.sum = temp;
    }
    catch (const invalid_argument& invalidArgument) {
        data.errors["invalid argument"].emplace_back(element);
    }
    catch (const out_of_range& outOfRange) {
        data.errors["out of range integer"].emplace_back(element);
    }
}

Data Solution(const vector<string>& array){
    Data data;
    if (array.empty()) { data.errors["array empty"]; return data;}
    if (array.size() > 1024) { data.errors["array is overflowed"]; return data;}

    data.foreach(array,  parseInt);
    data.foreach(data.input,  funcForResult);

    return data;
}
