#include <iostream>
using namespace std;

void task3() {
    int sizeA, sizeB;

    //спрашиваем у пользователя размеры массивов
    cout << "Введите размер массива A: ";
    cin >> sizeA;
    cout << "Введите размер массива B: ";
    cin >> sizeB;

    //создаем массивы для чисел
    int* arrA = new int[sizeA];  //массив A на sizeA чисел
    int* arrB = new int[sizeB];  //массив B на sizeB чисел

    //заполняем массив A числами от пользователя
    cout << "Введите элементы массива A:\n";
    for (int i = 0; i < sizeA; i++) {
        cout << "A[" << i << "] = ";
        cin >> *(arrA + i);  //кладем число в i-ю ячейку массив A
    }

    // Заполняем массив B числами от пользователя
    cout << "Введите элементы массива B:\n";
    for (int i = 0; i < sizeB; i++) {
        cout << "B[" << i << "] = ";
        cin >> *(arrB + i);  //кладем число в i-ю ячейку ящика B
    }

    //создаем третий массив C, куда поместится все из A и все из B
    int* arrC = new int[sizeA + sizeB];

    //перекладываем все из массива A в начало массива C
    for (int i = 0; i < sizeA; i++) {
        *(arrC + i) = *(arrA + i);  //берем из A -> кладем в C
    }

    //перекладываем все из массива B в продолжение массивва C
    for (int i = 0; i < sizeB; i++) {
        *(arrC + sizeA + i) = *(arrB + i);  //берем из B -> кладем в C 
    }

    //показываем, что получилость
    cout << "Массив C (A + B вместе): ";
    for (int i = 0; i < sizeA + sizeB; i++) {
        cout << *(arrC + i) << " ";
    }
    cout << endl;

    //освобождаем память
    delete[] arrA;
    delete[] arrB;
    delete[] arrC;
}

void task4() {
    int size, choice;

    //сколько чисел будет в массиве
    cout << "Введите размер массива: ";
    cin >> size;

    //создаем массив для чисел
    int* arr = new int[size];

    //заполняем массив числами от пользователя
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        cout << "A[" << i << "] = ";
        cin >> *(arr + i);  //кладем число в ячейку
    }

    //что было в массиве изначально
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    //какие числа выбросить
    cout << "\nМеню:\n";
    cout << "1. Выбросить четные числа (2, 4, 6...)\n";
    cout << "2. Выбросить нечетные числа (1, 3, 5...)\n";
    cout << "Выберите: ";
    cin >> choice;

    //проверяем, что пользователь ввел 1 или 2
    while (choice != 1 && choice != 2) {
        cout << "Так нельзя! Введи только 1 или 2: ";
        cin >> choice;
    }

    //считаем, сколько чисел останется после выбрасывания
    int remainingCount = 0;
    for (int i = 0; i < size; i++) {
        if (choice == 1) {
            //если выбрасываем четные, то считаем нечетные
            if (*(arr + i) % 2 != 0) remainingCount++;
        }
        else {
            //если выбрасываем нечетные, то считаем четные
            if (*(arr + i) % 2 == 0) remainingCount++;
        }
    }

    //создаем новый массив только для оставшихся чисел
    int* newArr = new int[remainingCount];
    int newIndex = 0;  //индекс для нового массива

    //перекладываем в новый массив только те числа, которые нужно оставить
    for (int i = 0; i < size; i++) {
        if (choice == 1) {
            if (*(arr + i) % 2 != 0) {
                //оставляем нечетное число
                *(newArr + newIndex) = *(arr + i);
                newIndex++;
            }
        }
        else {
            if (*(arr + i) % 2 == 0) {
                //оставляем четное число
                *(newArr + newIndex) = *(arr + i);
                newIndex++;
            }
        }
    }

    //
    cout << "После выбрасывания: ";
    if (remainingCount == 0) {
        cout << "массив пустой";
    }
    else {
        for (int i = 0; i < remainingCount; i++) {
            cout << *(newArr + i) << " ";
        }
    }
    cout << endl;

    //очистка памяти
    delete[] arr;
    delete[] newArr;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "ПРОГРАММА ДЛЯ РАБОТЫ С МАССИВАМИ\n\n";

    //складываем два массива в один
    cout << "1. складываем два массива в один большой\n";
    task3();

    //рисуем линию
    cout << "\n" << string(40, '-') << "\n\n";

    //выбрасываем числа из ящика
    cout << "2.четные или нечетные числа\n";
    task4();

    cout << "\nПрограмма завершена.\n";
    return 0;
}


