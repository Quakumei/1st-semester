//вар5 тампио 3530904/10002
#include <iostream>
#include <fstream>

#define IFNAME "input.txt"
#define OFNAME "output.txt"


bool aInB(const char a, const char* b) {
    for (int i = 0; b[i] != '\0'; i++) {
        if (b[i] == a) {
            return true;
        }
    }
    return false;
}

char* getDiff(char* destination, const char* source_a, const char* source_b) {
    // O(n^n) worst (case: search a, b, c in deffffff... ...fffabc)
    // optimization: sort and leave only unique - but it uses more memory.
    int j = 0;
    for (int i = 0; source_a[i] != '\0'; i++) {
        if (!aInB(source_a[i], destination) && !aInB(source_a[i], source_b)) {
            if (destination[j] == '\0') {
                throw "Недостаточно места в конечной строке";
            }
            destination[j] = source_a[i];
            j++;
        }
    }
    for (int i = 0; source_a[i] != '\0'; i++) {
        if (!aInB(source_b[i], destination) && !aInB(source_b[i], source_a)) {
            if (destination[j] == '\0') {
                throw "Недостаточно места в конечной строке";
            }
            destination[j] = source_b[i];
            j++;
        }
    }
    destination[j] = '\0';
    return destination;
}

int main()
{

    setlocale(LC_ALL, "RUSSIAN");

    std::cout << "\nИз файла...\n";
    std::ifstream fin(IFNAME);
    std::ofstream fout(OFNAME);
    if (!fin.good() || !fout.good()) {
        std::cerr << "Ошибка открытия файла. Завершение программы...\n";
        return 1;
    }
    while (!fin.eof()) {
        int arraySizeA = -1;
        fin >> arraySizeA;
        if (arraySizeA <= 0 || !fin.good()) {
            std::cerr << "Размер массива1 задан неверно. Завершение программы...\n";
            return 1;
        }
        int arraySizeB = -1;
        fin >> arraySizeB;
        if (arraySizeB <= 0 || !fin.good()) {
            std::cerr << "Размер массива2 задан неверно. Завершение программы...\n";
            return 1;
        }

        char* charArrayA = new char[arraySizeA + 1];
        char* charArrayB = new char[arraySizeB + 1];
        if (fin.eof()) {
            std::cerr << "Неожиданный конец файла при чтении массива1. Завершение программы...\n";
            return 1;
        }
        try {
            fin.getline(charArrayA, 2, ' ');
        }
        catch (const char * _){
            std::cerr << "Ошибка ввода. Завершение программы.";
            return 1;
        }
        
        if (fin.eof()) {
            std::cerr << "Неожиданный конец файла при чтении массива2. Завершение программы...\n";
            return 1;
        }
        try {
            fin >> charArrayB;
        }
        catch (const char* _) {
            std::cerr << "Ошибка ввода. Завершение программы.";
            return 1;
        }
             
        int arraySizeSum = arraySizeA + arraySizeB + 1;
        const int ASCII_SIZE = 256;
        int smallestSize = (arraySizeSum < ASCII_SIZE) ? arraySizeSum : ASCII_SIZE;
        char* destinationCharArray = new char[smallestSize + 1];
        destinationCharArray[smallestSize] = '\0';

        try {
            getDiff(destinationCharArray, charArrayA, charArrayB);
        }
        catch (const char * error){
            std::cerr << error;
            return 1;
        }
        
        fout << destinationCharArray << '\n';

        // LOG
        std::clog << "=============================\n";
        std::clog << charArrayA << '\n';
        std::clog << charArrayB << '\n';
        std::clog << destinationCharArray << '\n';


        delete[] charArrayA;
        delete[] charArrayB;
        delete[] destinationCharArray;
    }

    return 0;
}