// Ilia Shemiakin, 2021
// Массивы и строки

#include <iostream>
#include <iomanip>	// для манипулятора setw()
#include <vector>
#include <string>

#include <cmath>    // для функции sqrt(), которая возвращает квадратный корень аргумента
#include <ctime>    // для установки генератора случайных чисел: функции time(0),  rand()

// глобальные константы для массива постоянной размерности
const int N_ROW = 3; // используются в прототипах функций
const int N_COLUMN = 5;

// Объявления функций  (определения в конце файла)
// Для указания размера массива можно также использовать беззнаковые типы
// unsigned int или size_t, но в любом случае, если размер указан неверно,
// то проверить это внутри функции невозможно

// Функция, возвращающая евклидову норму вектора (она же длина n-мерного вектора) 
// norm_e=(v1^2+v2^2+v3^2+...+vn^2)^(1/2)
double euklidNorm(const double array[], int n);

// Функция, возвращающая максимум двумерного массива;
// обратите внимание, что в случае двумерного встроенного (не динамического) массива
// второй размер обязтельно(!) должен быть указан
// int array[][N_COLUMN] - передаваемый массив
// int nRow - количество строк массива
// int nColumn - количество столбцов массива
int getMaxValue(const int array[][N_COLUMN], int nRow, int nColumn);
// можно и так: int getMaxValue(int[][N_COLUMN], int, int);


int main()
{
    // установка генератора псевдослучайных чисел; функция time(0) объявлена в <ctime>
    std::srand(std::time(0));

    const int N_FIRST_ARRAY = 10;
    int firstArray[N_FIRST_ARRAY];	// объявление массива элементов типа int размером N_FIRST_ARRAY
                                    // память выделена до выполнения программы

    // инициализация массива случайными числами от -50 до 49;
    // функция rand() используется для получения псевдослучайных чисел в диапазоне от 0 до RAND_MAX
    // константа RAND_MAX определена в stdlib, ее значение 2^15-1
    for (int i = 0; i < N_FIRST_ARRAY; ++i)
    {
        firstArray[i] = std::rand() % 100 - 50;
    }

    // вывод массива
    std::cout << "firstArray: ";
    for (int i = 0; i < N_FIRST_ARRAY; ++i)
    {
        std::cout << std::setw(4) << firstArray[i];
    }
    std::cout << '\n';

    // Вычисление евклидовой нормы вектора

    const int N_SECOND_ARRAY = 3;
    double secondArray[N_SECOND_ARRAY];

    for (int i = 0; i < N_SECOND_ARRAY; ++i)
    {
        secondArray[i] = std::rand() % 41 - 20;
    }

    std::cout << "secondArray:";
    for (int i = 0; i < N_SECOND_ARRAY; ++i)
    {
        std::cout << std::setw(4) << secondArray[i];
    }
    std::cout << "  Norm: " << euklidNorm(secondArray, N_SECOND_ARRAY);

    std::cout << "\n\n";

    // Поиск максимума двумерного массива (матрицы)

    // объявление двумерного массива с N_ROW строками и N_COLUMN столбцами
    int matrix[N_ROW][N_COLUMN];

    for (int i = 0; i < N_ROW; ++i)
    {
        for (int j = 0; j < N_COLUMN; ++j)
        {
            matrix[i][j] = std::rand() % 100 - 50;
        }
    }
    // вывод двумерного массива по строкам
    for (int i = 0; i < N_ROW; ++i)
    {
        for (int j = 0; j < N_COLUMN; ++j)
        {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    std::cout << "Max element of dArray is " << getMaxValue(matrix, N_ROW, N_COLUMN);
    std::cout << "\n\n";

    // Массивы символов

    // Строки в C++ реализуются как массивы элементов char (так называемые char*-строки)
    // Важно помнить, что все char*-строки завершаются символьной константой '\0', ASCII код которой равен 0
    // '\0' называется нулевым символом и обозначает конец строки

    const int MAX_N_STRING = 20;

    char strChar[MAX_N_STRING] = "";

    std::cout << "Enter string without spaces: ";
    std::cin >> std::setw(MAX_N_STRING) >> strChar;
    std::cout << "You entered string: " << strChar << '\n';

    // Обратите внимание:
    // 1. У строк также есть размер, который должен быть указан. 
    //    Если размер заранее неизвестен - нужно взять с запасом
    // 2. Чтобы избежать переполнения в программе использован манипулятор setw. 
    //    Если введённая строка окажется больше MAX_STRING_SIZE,
    //    то она будет обрезана и последним символом str[19] будет '\0'
    //    (попробуйте убрать  setw и ввести длинную строку)
    // 3. Операторы "<<" и ">>" знают, что ожидается ввод/вывод строки и ведут себя корректно (циклов не требуется)
    // 4. Строка не может содержать пробелов (всё, что после пробела просто отбрасывается), 
    //    т.к. оператор ">>" считает пробел символом-разделителем

    // Ввод строки с пробелами

    std::cout << "Enter string with spaces: ";

    std::cin.ignore(std::cin.rdbuf()->in_avail(), '\n');
    std::cin.get(strChar, MAX_N_STRING);

    std::cout << "You entered string: " << strChar << '\n';
    // get - метод класса istream, аргументы - массив и его размер (для предотвращения переполнения)
    // ignore - метод объекта istream для очистки потока ввода после операции ">>",  
    // аргументы - кол-во символов для очистки и символ-разделитель (тоже будет очищен)
    // выражение std::cin.rdbuf()->in_avail() позволяет получить количество символов, находящихся в потоке

    std::cout << '\n';


    // Копирование строк; скопируем strChar в strCharCopy (т.к. strChar меньше)
    char strCharCopy[MAX_N_STRING] = "";
    int i = 0;
    while (strChar[i] != '\0')
    {
        strCharCopy[i] = strChar[i];
        ++i;
    }
    strCharCopy[i] = '\0'; // необходимо завершить str2 нулевым символом

    std::cout << "str: " << strChar << '\n';
    std::cout << "strCopy: " << strCharCopy << '\n';

    std::cout << '\n';

    // Класс string из стандартной библиотеки шаблонов (STL; необходимо подключить <string>)

    // с объектами string можно обращаться как с обычными переменными
    std::string firstStr("string1");		// 1 способ инициализации
    std::string secondStr = "string2";	// 2 способ инициализации
    std::string thirdStr;				// без инициализации

    thirdStr = firstStr + " plus " + secondStr;
    std::cout << "thirdStr: " << thirdStr << '\n';

    // Класс string содержит множество встроенных методов
    // Один из них - метод find возвращает позицию вхождения подстроки в строку либо -1 (std::string::npos)

    std::cout << "Enter first string: ";
    std::cin >> firstStr;

    std::cout << "Enter second string: ";
    std::cin >> secondStr;

    int n = firstStr.find(secondStr);

    if (n != -1)
    {
        std::cout << "Second string is in the first string on position " << n << '\n';
    }
    else
    {
        std::cout << "Second string is not in the first string\n";
    }

    std::cout << "\n\n";

    // Динамические массивы vector из стандартной библиотеки шаблонов (STL; необходимо подключить <vector>) 

    std::vector<int> vectArray;	// синтаксис может сейчас показаться странным, но потом станет понятно почему так
                                // создаем массив целых чисел

    std::cout << "Vector(1) size: " << vectArray.size() << '\n';	// встроенный метод size возвращает размер массива

    for (int i = 0; i < 5; ++i)
    {
        vectArray.push_back(i);	// метод push_back помещает аргумент в конец массива
    }

    std::cout << "Vector(2): [";
    for (size_t i = 0; i < vectArray.size(); ++i)
    {
        std::cout << std::setw(4) << vectArray[i];
    }
    std::cout << "]; size: " << vectArray.size() << '\n';

    vectArray.push_back(5);
    vectArray.push_back(6);
    vectArray.insert(vectArray.begin() + 5, 15);	// vectArray.begin() - указатель на начало массива

    // обратите внимание на то, что размер vector может меняться
    // посмотрите, куда вставился элемент 15
    std::cout << "Vector(3): [";
    for (size_t i = 0; i < vectArray.size(); ++i)
    {
        std::cout << std::setw(4) << vectArray[i];
    }
    std::cout << "]; size: " << vectArray.size() << '\n';

    return 0;
}



// Функция, возвращающая евклидову норму вектора (она же длина n-мерного вектора) 
// norm_e=(v1^2+v2^2+v3^2+...+vn^2)^(1/2)
// int array[] - передаваемый массив
// int n - количество элементов массива
double euklidNorm(const double array[], int n)
{
    double res = 0;
    for (int i = 0; i < n; ++i)
    {
        res += array[i] * array[i];
    }
    return std::sqrt(res);  // функция sqrt() возвращает квадратный корень аргумента (описана в <cmath>)
}

// Функция, возвращающая максимум двумерного массива
// Обратите внимание, что в случае двумерного массива второй размер обязтельно(!) должен быть указан
// int array[][N_COLUMN] - передаваемый массив
// int nRow - количество строк массива
// int nColumn - количество столбцов массива
int getMaxValue(const int array[][N_COLUMN], int nRow, int nColumn)
{
    int maxValue = array[0][0];
    for (int i = 0; i < nRow; ++i)
    {
        for (int j = 0; j < nColumn; ++j)
        {
            if (array[i][j] > maxValue)
            {
                maxValue = array[i][j];
            }
        }
    }
    return maxValue;
}