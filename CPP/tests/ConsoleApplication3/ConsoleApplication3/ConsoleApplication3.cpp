// Ilia Shemiakin, 2021
// Указатели

#include <iostream>
#include <iomanip>
#include <ctime>

// Объявления функций (определения в конце файла)

// функция возвращает сумму элементов массива
int getSum(const int* array, int size);

// функция возвращает среднее значение элементов двумерного массива постоянной размерности
double getAverage(const int* array, int nRow, int nColumn);

// функция меняет местами две строки матрицы без непосредственного перемещения элементов в памяти
// !!! защиты от выхода из допустимого диапазона номеров нет
void swapRows(int** array, int iLine1, int iLine2);

int main()
{
    std::srand(std::time(0));

    int ivar1 = 10;
    int* iptr1 = &ivar1;	// объявление и инициализация указателя значением адреса переменной var1
    int* iptr2(&ivar1);		// другой вариант (равнозначный) объявления и инициализации указателя
    int* iptr3 = iptr1;		// объявление и инициализация указателя значением другого указателя
    // Важно отметить, что:
    // переменная ivar1 имеет тип int,
    // выражение &ivar1 возвращает адрес переменной ivar1 (т.е. значение типа int*),
    // переменная iptr1 имеет тип int* (указатель на int),
    // выражение *iptr1 возвращает значение типа int (значение по адресу из iptr1)

    // выведем все переменные и адреса
    std::cout << "&var1=" << &ivar1 << ", var1=" << ivar1 << '\n'
        << "ptr1=" << iptr1 << ", *ptr1=" << *iptr1 << '\n'
        << "ptr2=" << iptr2 << ", *ptr2=" << *iptr2 << '\n'
        << "ptr3=" << iptr3 << ", *ptr3=" << *iptr3 << '\n';
    std::cout << std::endl;

    *iptr3 = 20;	// изменение значения по адресу (как вы думете, что выведется теперь?)
    std::cout << "&var1=" << &ivar1 << ", var1=" << ivar1 << '\n'
        << "ptr1=" << iptr1 << ", *ptr1=" << *iptr1 << '\n'
        << "ptr2=" << iptr2 << ", *ptr2=" << *iptr2 << '\n'
        << "ptr3=" << iptr3 << ", *ptr3=" << *iptr3 << '\n';
    std::cout << std::endl;

    double dvar1 = 2.5;
    // указателю на void (типу void*) можно присвоить значение уазателя на любой другой тип;
    // к сожалению, производить с типом void* какие-либо операции (разыменование, изменение значения,...) нельзя;
    // это логично, ведь компилятор не может знать, как интерпретировать значение по данному адресу
    void* vptr = &dvar1;
    // использовать тип void* можно совместно с явным приведением типов
    double* dptr1 = static_cast<double*>(vptr);
    std::cout << "vptr=" << vptr << ", *((double*)vptr)=" << *(static_cast<double*>(vptr)) << '\n'
        << "&dvar1=" << &dvar1 << ", dvar1=" << dvar1 << '\n'
        << "dptr1=" << dptr1 << ", *dptr1=" << *dptr1 << '\n';
    std::cout << std::endl;

    // Создание двумерного массива в статической области памяти и передача его в функцию при помощи указателя

    const int N_ARRAY = 5;
    int iArray[N_ARRAY][N_ARRAY];

    // инициалиация элементов массива случайными значениями от 0 до 9 и их вывод 
    for (int i = 0; i < N_ARRAY; ++i)
    {
        for (int j = 0; j < N_ARRAY; ++j)
        {
            iArray[i][j] = std::rand() % 10;
            std::cout << std::setw(2) << iArray[i][j];
        }
        std::cout << '\n';
    }

    // вывод среднего значения элементов массива
    std::cout << "average value: " << getAverage(*iArray, N_ARRAY, N_ARRAY) << '\n';
    // обратите внимание на то, что в функцию передаётся *iArray, а не iArray;
    // *iArray имеет тип int* (чего и требует наша функция),
    // тогда как iArray имеет тип int(*)[N_ARRAY], т.е. "указатель на массив int размером N_ARRAY"

    std::cout << std::endl;

    // Создание одномерного массива в динамической области памяти

    int nDynArray = 5;	// размер массива (переменная!)

    // выделение памяти под массив из nDynArray элементов типа int
    // и помещение указателя на эту память в переменную-указатель dynArray;
    // обратите внимание, что nDynArray - переменная, а не константа
    int* dynArray = new int[nDynArray];
    for (int i = 0; i < nDynArray; ++i)
    {
        // к элементам массива можно обращаться *(dynArray + i),
        // а можно dynArray[i],что одно и то же
        *(dynArray + i) = std::rand() % 10;
    }

    for (int i = 0; i < nDynArray; ++i)
    {
        std::cout << std::setw(2) << dynArray[i];
    }
    std::cout << std::endl;

    std::cout << "Sum of the elements of the array is " << getSum(dynArray, nDynArray) << '\n';

    // оператор delete освобождает память, привязанную к указателю; 
    // для массивов требуются скобки delete[]
    delete[] dynArray;

    std::cout << std::endl;

    // Создание динамического двумерного массива и передача его в функцию

    int nRow = 7;		// размеры массива; это переменные => их можно вводить с клавиатуры либо вычислять,
    int nColumn = 5;    // но сейчас для простоты зададим их     	

    // объявление указателя на указатель на int (адрес двумерного массива)
    // и выделение памяти на массив из nRow указателей на int; new вернёт int**
    int** dynTwoArray = new int* [nRow];

    // выделение памяти для каждой строки массива
    for (int i = 0; i < nRow; ++i)
    {
        *(dynTwoArray + i) = new int[nColumn];	// можно (и даже лучше) dynTwoArray[i] = new int[nColumn]; 
                                                // но сейчас для наглядности так;
                                                // а вообще выражения *(array + i) и array[i] эквивалентны
    }

    // инициалиация и вывод элементов массива
    for (int i = 0; i < nRow; ++i)
    {
        for (int j = 0; j < nColumn; ++j)
        {
            *(*(dynTwoArray + i) + j) = std::rand() % 10;   // соответственно *(*(array + i) + j) эквивалентно array[i][j]
            std::cout << std::setw(2) << dynTwoArray[i][j];	// теперь воспользуюсь способом со скобками
        }
        std::cout << '\n';
    }

    std::cout << std::endl;

    // поменяю местами вторую и шестую строки матрицы (помним, что индексы начинаются с 0)
    swapRows(dynTwoArray, 1, 5);

    for (int i = 0; i < nRow; ++i)
    {
        for (int j = 0; j < nColumn; ++j)
        {
            std::cout << std::setw(2) << dynTwoArray[i][j];
        }
        std::cout << '\n';
    }
    std::cout << std::endl;

    for (int i = 0; i < nRow; ++i)	// освобождение памяти производится в порядке обратном выделению
    {
        delete[] * (dynTwoArray + i);
    }
    delete[] dynTwoArray;

    return 0;
}

// Функция возвращает сумму элементов массива
int getSum(const int* array, int size)
{
    int res = 0;
    for (int i = 0; i < size; ++i)
    {
        res += *(array + i);
    }
    return res;
}

// Функция возвращает среднее значение элементов двумерного массива.
// Обратите внимание, что размеры массива передаются функции как параметры, а не жёстко указываются в объявлении.
// Стоит вспомнить, что двумерный массив представляет собой массив одномерных массивов,
// а его элементы располагаются в памяти последовательно.
// Первый аргумент функции типа int* будем понимать, как указатель на первый элемент первого одномерного массива.
// Именно поэтому в функцию из main был передан *iArray, а не iArray,
// т.к. iArray представляет собой указатель на первый одномерный массив, а не на первый элемент
double getAverage(const int* array, int nRow, int nColumn)
{
    double sum = 0;
    for (int i = 0; i < nRow; ++i)
    {
        for (int j = 0; j < nColumn; ++j)
        {
            // вычисляем адрес элемента array[i][j] как адрес начала массива (array) плюс 
            // смещение на кол-во строк (nColumn * i) плюс смещение внутри строки (j)
            sum += *(array + nColumn * i + j);
        }
    }
    return sum / (nRow * nColumn);
}

// Функция меняет местами две строки матрицы без непосредственного перемещения элементов в памяти
// !!! Защиты от выхода из допустимого диапазона номеров не сделано
void swapRows(int** array, int iLine1, int iLine2)
{
    int* temp = *(array + iLine1);
    *(array + iLine1) = *(array + iLine2);
    array[iLine2] = temp;	// array[iLine2] то же, что и *(array + iLine2); 
                            // хотя в реальности, конечно, стоит пользоваться какой-либо одной нотацией
}
// эта функция прекрасно показывает, что указатели позволяют нам быстро логически перемещать
// большие объёмы данных без их физического переноса в памяти
