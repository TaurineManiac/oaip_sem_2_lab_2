#include <iostream>
#include <string>
#include <clocale>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include <random>
#include "header.h"

using namespace std;

int main() {
    int size = 0;
    int* a = nullptr;
    int* b = nullptr;
    int* c = nullptr;
    int* d = nullptr;
    int* e = nullptr;

    system("chcp 65001");
    cout << "Разработать программу для создания пяти динамических массивов: a[], b[], c[], d[] и e[].  \n"
            "Эти массивы необходимо отсортировать соответственно методом обмена,  \n"
            "методом выбора, методом вставки, методом Шелла и методом Хоора.  \n"
            "Организовать последовательный поиск определенного элемента в каждом исходном массиве и  \n"
            "подсчитать количество совпадений этого элемента в каждом массиве.  \n"
            "Организовать бинарный поиск определенного элемента в каждом отсортированном массиве.  \n"
            "Разработать в программе меню, структура которого следующая:  \n" << endl;

    while (true) {
        cout << "Menu:  \n"
                "1. Initilization arrays (инициализация массивов)  \n"
                "2. Result of bubble sort  \n"
                "3. Result of min sort  \n"
                "4. Result of insert sort  \n"
                "5. Result of Shell sort  \n"
                "6. Result of Hoor sort  \n"
                "7. Poisk \n"
                "8. Exit" << endl;
        string input;
        int choose;
        cout << "Выберите номер действия:" << endl;
        while (true) {
            getline(cin, input);
            bool znacki = false;
            for (int i = 0; i < input.size(); i++) {
                if (ispunct(input[i]) || isspace(input[i])) {
                    znacki = true;
                }
            }
            if (znacki) {
                cout << "Число должно быть не дробное:)" << endl;
                continue;
            }
            try {
                choose = stoi(input);
                if (choose <= 0) throw invalid_argument("Номер должен быть целым, положительным");
                if (choose >= 9) {
                    cout << "Введите число, входящее в промежуток(1-8)." << endl;
                    continue;
                }
                break;
            } catch (const exception& e) {
                cout << "Некорректный ввод. Введите целое, положительное число(1-8): " << endl;
            }
        }

        if (choose == 1) {
            cout << "Введите количество ячеек массивов(1-25(Для удобной визуальной проверки)):" << endl;
            while (true) {
                getline(cin, input);
                bool znacki = false;
                for (int i = 0; i < input.size(); i++) {
                    if (ispunct(input[i]) || isspace(input[i])) {
                        znacki = true;
                    }
                }
                if (znacki) {
                    cout << "Число должно быть не дробное:)" << endl;
                    continue;
                }
                try {
                    size = stoi(input);
                    if (size <= 0) throw invalid_argument("Количество элементов должно быть целым, положительным");
                    if (size > 25) {
                        cout << "Введите количество ячеек меньше 25." << endl;
                        continue;
                    }
                    break;
                } catch (const exception& e) {
                    cout << "Некорректный ввод. Введите целое, положительное число, меньше 25: " << endl;
                }
            }
            if (a != nullptr) {
                delete[] a; delete[] b; delete[] c; delete[] d; delete[] e;
                a = b = c = d = e = nullptr;
            }
            a = new int[size]();
            b = new int[size]();
            c = new int[size]();
            d = new int[size]();
            e = new int[size]();

            initilizationArrays(a, size);
            initilizationArrays(b, size);
            initilizationArrays(c, size);
            initilizationArrays(d, size);
            initilizationArrays(e, size);

            cout << "Массивы готовы:\n";
            cout << "a: "; printArrays(a, size); cout << endl;
            cout << "b: "; printArrays(b, size); cout << endl;
            cout << "c: "; printArrays(c, size); cout << endl;
            cout << "d: "; printArrays(d, size); cout << endl;
            cout << "e: "; printArrays(e, size); cout << endl;
        }
        else if (choose == 2) {
            if (a == nullptr) {
                cout << "Сначала инициализируйте массивы (пункт 1).\n";
            } else {
                // Логика для пузырьковой сортировки
                cout << "Отсортированный массив a:\n";
                bubbleSort(a,size);
                cout << "Отсортированный массив b:\n";
                bubbleSort(b,size);
                cout << "Отсортированный массив c:\n";
                bubbleSort(c,size);
                cout << "Отсортированный массив d:\n";
                bubbleSort(d,size);
                cout << "Отсортированный массив e:\n";
                bubbleSort(e,size);
            }
        }
        else if (choose == 3) {
            if (a == nullptr) {
                cout << "Сначала инициализируйте массивы (пункт 1).\n";
            } else {
                // Логика для сортировки выбором
                cout << "Отсортированный массив a:\n";
                selectSort(a,size);
                cout << "Отсортированный массив b:\n";
                selectSort(b,size);
                cout << "Отсортированный массив c:\n";
                selectSort(c,size);
                cout << "Отсортированный массив d:\n";
                selectSort(d,size);
                cout << "Отсортированный массив e:\n";
                selectSort(e,size);
            }
        }
        else if (choose == 4) {
            if (a == nullptr) {
                cout << "Сначала инициализируйте массивы (пункт 1).\n";
            } else {
                // Логика для сортировки вставками
                cout << "Отсортированный массив a:\n";
                insertionSort(a,size);
                cout << "Отсортированный массив b:\n";
                insertionSort(b,size);
                cout << "Отсортированный массив c:\n";
                insertionSort(c,size);
                cout << "Отсортированный массив d:\n";
                insertionSort(d,size);
                cout << "Отсортированный массив e:\n";
                insertionSort(e,size);
            }
        }
        else if (choose == 5) {
            if (a == nullptr) {
                cout << "Сначала инициализируйте массивы (пункт 1).\n";
            } else {
                // Логика для сортировки Шелла
                cout << "Отсортированный массив a:\n";
                shellSort(a,size);
                cout << "Отсортированный массив b:\n";
                shellSort(b,size);
                cout << "Отсортированный массив c:\n";
                shellSort(c,size);
                cout << "Отсортированный массив d:\n";
                shellSort(d,size);
                cout << "Отсортированный массив e:\n";
                shellSort(e,size);
            }
        }
        else if (choose == 6) {
            if (a == nullptr) {
                cout << "Сначала инициализируйте массивы (пункт 1).\n";
            } else {
                // Логика для быстрой сортировки Хоара
                cout << "Отсортированный массив a:\n";
                quickSort(a,size);
                cout << "Отсортированный массив b:\n";
                quickSort(b,size);
                cout << "Отсортированный массив c:\n";
                quickSort(c,size);
                cout << "Отсортированный массив d:\n";
                quickSort(d,size);
                cout << "Отсортированный массив e:\n";
                quickSort(e,size);
            }
        }
        else if (choose == 7) {
            if (a == nullptr) {
                cout << "Сначала инициализируйте массивы (пункт 1).\n";
            } else {
                // Логика для поиска
                int target;
                cout << "Введите число для поиска(-100...100): ";
                while (true) {
                    getline(cin, input);
                    bool znacki = false;
                    for (int i = 0; i < input.size(); i++) {
                        if (ispunct(input[i]) && input[i] != '-') {
                            znacki = true;
                        }
                    }
                    if (znacki) {
                        cout << "Число должно быть целым (дробные не допускаются):" << endl;
                        continue;
                    }
                    try {
                        target = stoi(input);
                        if(target<-100 || target>100){
                            cout << "(-100...100).... ";
                            continue;
                        }
                        break;
                    } catch (const exception& e) {
                        cout << "Некорректный ввод. Введите целое число: " << endl;
                    }
                }
                cout << "Обычный поиск в массиве а" << endl;
                searchDefault(a,size,target);
                cout << "Обычный поиск в массиве b" << endl;
                searchDefault(b,size,target);
                cout << "Обычный поиск в массиве c" << endl;
                searchDefault(c,size,target);
                cout << "Обычный поиск в массиве d" << endl;
                searchDefault(d,size,target);
                cout << "Обычный поиск в массиве e" << endl;
                searchDefault(e,size,target);
                cout << "" << endl;
                cout << "Бинарный поиск в массиве а" << endl;
                searchBinary(a,size,target);
                cout << "Бинарный поиск в массиве b" << endl;
                searchBinary(b,size,target);
                cout << "Бинарный поиск в массиве c" << endl;
                searchBinary(c,size,target);
                cout << "Бинарный поиск в массиве d" << endl;
                searchBinary(d,size,target);
                cout << "Бинарный поиск в массиве e" << endl;
                searchBinary(e,size,target);
            }
        }
        else if (choose == 8) {
            cout << "Произошёл выход." << endl;
            delete[] a;
            delete[] b;
            delete[] c;
            delete[] d;
            delete[] e;
            break;
        }
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
    }

    return 0;
}