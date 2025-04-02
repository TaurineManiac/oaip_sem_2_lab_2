#include <iostream>
#include <string>
#include <clocale>  // Заменил <locale.h> на <clocale>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include <random> // Для случайных чисел
#include "header.h"

using namespace std;

void bubbleSort(int* arr, int size) {
    int* arrtemp = new int[size];
    for (int i = 0; i < size; i++) {
        arrtemp[i] = arr[i];
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arrtemp[j] > arrtemp[j + 1]) { // Сравниваем элементы arrtemp
                int temp = arrtemp[j];
                arrtemp[j] = arrtemp[j + 1];
                arrtemp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("[%d]",arrtemp[i]);
    }
    cout << "\n";
    writeToFile(arrtemp, size, "Bubble Sort");
    delete[] arrtemp; // Освобождаем память
}

void selectSort(int* arr,int size){
    int* arrtemp = new int[size];
    for (int i = 0; i < size; i++) {
        arrtemp[i] = arr[i];
    }
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arrtemp[j] < arrtemp[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arrtemp[i];
        arrtemp[i] = arrtemp[min_idx];
        arrtemp[min_idx] = temp;

    }
    for (int i = 0; i < size; i++) {
        printf("[%d]",arrtemp[i]);
    }
    cout << "" << endl;
    writeToFile(arrtemp, size, "Select Sort");
    delete[] arrtemp;
}

void insertionSort(int* arr,int size){
    int* arrtemp = new int[size];
    for (int i = 0; i < size; i++) {
        arrtemp[i] = arr[i];
    }
    for (int i = 1; i < size; i++) {
        int key = arrtemp[i]; // Берем текущий элемент как ключ
        int j = i - 1;    // Индекс последнего элемента отсортированной части
        while (j >= 0 && arrtemp[j] > key) {
            arrtemp[j + 1] = arrtemp[j]; // Сдвигаем элемент вправо
            j--;                 // Переходим к предыдущему элементу
        }
        arrtemp[j + 1] = key; // Вставляем ключ на освободившееся место
    }
    for (int i = 0; i < size; i++) {
        printf("[%d]",arrtemp[i]);
    }
    cout << "" << endl;
    writeToFile(arrtemp, size, "Insertion Sort");
    delete[] arrtemp;

}

void shellSort(int* arr,int size){
    int* arrtemp = new int[size];
    for (int i = 0; i < size; i++) {
        arrtemp[i] = arr[i];
    }
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arrtemp[i];
            int j;
            for (j = i; j >= gap && arrtemp[j - gap] > temp; j -= gap) {
                arrtemp[j] = arrtemp[j - gap];
            }
            arrtemp[j] = temp;
        }
    }
    for (int i = 0; i < size; i++) {
        printf("[%d]",arrtemp[i]);
    }
    cout << "" << endl;
    writeToFile(arrtemp, size, "Shell Sort");
    delete[] arrtemp;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        // Выбираем средний элемент как pivot
        int mid = low + (high - low) / 2;
        int pivot = arr[mid];

        // Создаем временный массив для хранения элементов
        int* arrTemp = new int[high - low + 1];
        int left = 0;  // Индекс для элементов <= pivot в arrTemp
        int right = high - low; // Индекс для элементов > pivot в arrTemp

        // Копируем элементы в arrTemp и разделяем их
        for (int i = low; i <= high; i++) {
            if (i != mid) { // Пропускаем pivot на его месте
                if (arr[i] <= pivot) {
                    arrTemp[left] = arr[i];
                    left++;
                } else {
                    arrTemp[right] = arr[i];
                    right--;
                }
            }
        }

        // Вставляем pivot на правильное место
        arrTemp[left] = pivot;

        // Копируем отсортированный arrTemp обратно в arr
        for (int i = low; i <= high; i++) {
            arr[i] = arrTemp[i - low];
        }

        // Освобождаем память
        delete[] arrTemp;

        int pi = low + left; // Индекс, где оказался pivot

        // Рекурсивные вызовы для левой и правой частей
        quickSort(arr, low, pi - 1);  // Сортируем левую часть
        quickSort(arr, pi + 1, high); // Сортируем правую часть
    }
}

// Обёртка для вызова QuickSort
void quickSort(int* arr, int size) {
    if (size <= 0) return;
    quickSort(arr, 0, size - 1);
    cout << "Отсортированный массив Хоара :\n";
    printArrays(arr, size);
    cout << "\n";
    writeToFile(arr, size, "Quick Sort ");
}

void initilizationArrays(int* arr,int size){
    random_device rd;//Здесь создаётся объект gen типа mt19937.
    //rd() — это начальное значение (seed), которое мы берём из random_device.
    //gen теперь готов генерировать случайные числа, начиная с этого начального значения.
    mt19937 gen(rd());
//    Здесь создаётся объект gen типа mt19937.
//    rd() — это начальное значение (seed), которое мы берём из random_device.
//    gen теперь готов генерировать случайные числа, начиная с этого начального значения.
    uniform_int_distribution<> dis(-100,100);
//    uniform означает, что каждое число в диапазоне имеет одинаковую вероятность быть выбранным.
    for(int i=0;i<size;i++){
        arr[i]=dis(gen);
    }
}

void searchDefault(int* arr, int size, int target) {
    int counter = 0;
    bool proverka=true;
    int firstOccurrence;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            if(proverka){
                firstOccurrence=i;
                proverka= false;
            }
            counter++;
        }
    }

    if (counter > 0) {
        cout << "Элемент " << target << " найден. Количество вхождений: " << counter << " (начиная с индекса " << firstOccurrence << ")\n";;
    } else {
        cout << "Элемент " << target << " не найден в массиве.\n";
    }
    // Запись в файл new.txt с текущим состоянием массива
    ofstream file("new.txt", ios::app);
    if (file.is_open()) {
        file << "Default Search для " << target << ":\n";
        for (int i = 0; i < size; i++) {
            file << "[" << arr[i] << "] ";
        }
        file << "\n";
        if (counter > 0) {
            file << "Элемент " << target << " найден. Количество вхождений: " << counter << "\n";
        } else {
            file << "Элемент " << target << " не найден.\n";
        }
        file << "\n";
        file.close();
//        cout << "Результат поиска записан в файл new.txt\n";
    } else {
        cout << "Не удалось открыть файл для записи.\n";
    }
}

void searchBinary(int* arr, int size, int target) {
    int* arrtemp = new int[size];
    for (int i = 0; i < size; i++) {
        arrtemp[i] = arr[i];
    }
    quickSort(arrtemp, size);

    int left = 0;
    int right = size - 1;
    int firstOccurrence = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arrtemp[mid] == target) {
            firstOccurrence = mid;
            right = mid - 1;
        } else if (arrtemp[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    int counter = 0;
    if (firstOccurrence != -1) {
        counter = 1;
        int currentIndex = firstOccurrence + 1;
        while (currentIndex < size && arrtemp[currentIndex] == target) {
            counter++;
            currentIndex++;
        }
        currentIndex = firstOccurrence - 1;
        while (currentIndex >= 0 && arrtemp[currentIndex] == target) {
            counter++;
            currentIndex--;
        }
        cout << "Элемент " << target << " найден. Количество вхождений: " << counter << " (начиная с индекса " << firstOccurrence << ")\n";
    } else {
        cout << "Элемент " << target << " не найден в массиве.\n";
    }

    ofstream file("new.txt", ios::app);
    if (file.is_open()) {
        file << "Binary Search для " << target << ":\n";
        for (int i = 0; i < size; i++) {
            file << "[" << arrtemp[i] << "] ";
        }
        file << "\n";
        if (firstOccurrence != -1) {
            file << "Элемент " << target << " найден. Количество вхождений: " << counter << "\n";
        } else {
            file << "Элемент " << target << " не найден.\n";
        }
        file << "\n";
        file.close();
//        cout << "Результат поиска записан в файл new.txt\n";
    } else {
        cout << "Не удалось открыть файл для записи.\n";
    }
    delete[] arrtemp;
}

void printArrays(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d]",arr[i]);
    }
}

void writeToFile(int* arr,int size,const string& operation){
    ofstream file("new.txt", ios::app);
    if (file.is_open()) {
        file << operation << ":\n";
        for (int i = 0; i < size; i++) {
            file << "[" << arr[i] << "] ";
        }
        file << "\n\n";
        file.close();
//        cout << "Результат записан в файл new.txt\n";
    } else {
        cout << "Не удалось открыть файл для записи.\n";
    }
}
