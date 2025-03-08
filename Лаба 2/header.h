#include <string>

using namespace std;

#ifndef _2_HEADER_H
#define _2_HEADER_H

void bubbleSort(int* arr, int size);
void selectSort(int* arr, int size);
void insertionSort(int* arr, int size);
void shellSort(int* arr, int size);
void quickSort(int* arr, int size);//Хаора
void quickSort(int* arr, int low, int high); // Для однофункциональной реализации
void initilizationArrays(int* arr, int size);
void searchDefault(int* arr, int size, int target);
void searchBinary(int* arr, int size, int target);
void printArrays(int* arr, int size);
void writeToFile(int* arr, int size, const string& operation);

#endif //_2_HEADER_H
