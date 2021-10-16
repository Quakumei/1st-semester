#include <iostream>
#include <string>

int main()
{
    std::string str = "abcdefg";
    std::string* var = &str;

    std::cout << "name:" << var << "\t*name:" << *var << "\t&name:" << &var << '\n';
    std::cout << "name_orig:" << str << "\t*name_orig:" << "NaN (errorv)" << "\t&name_orig:" << &str << '\n';

    //Из этого следует
    // &var - адрес переменной var в памяти
    // var - значение переменной var (в случае указателей - адрес переменной, на которую указывает)
    // *var - операция разыменовывания !*указателя*!, для других типов данных не работает, возвращает значение переменной

    *var = 'k';

    std::cout << "\nname:" << var << "\t*name:" << *var << "\t&name:" << &var << '\n';
    std::cout << "name_orig:" << str << "\t*name_orig:" << "NaN (errorv)" << "\t&name_orig:" << &str << '\n';

    //Все операции над *var применяются и к оригиналу, т.е.
    // *var = a; равносильно str = a;


    *var = 0x4E;

    std::cout << "\nname:" << var << "\t*name:" << *var << "\t&name:" << &var << '\n';
    std::cout << "name_orig:" << str << "\t*name_orig:" << "NaN (errorv)" << "\t&name_orig:" << &str << '\n';

    //при присваивании указателю при этом не работает проверка типов?, при этом присваиваются чистые данные. 
    // (в данном случае при присваивании числа мы видим что байты передались в строку и интерпретируются как
    // буквы)

    *var = 0x4E4E4E4E4E;

    std::cout << "\nname:" << var << "\t*name:" << *var << "\t&name:" << &var << '\n';
    std::cout << "name_orig:" << str << "\t*name_orig:" << "NaN (errorv)" << "\t&name_orig:" << &str << '\n';

    //но за память вылезти просто так не даст.

   // var += sizeof(char);
    *var = "aboba";

    std::cout << "\nname:" << var << "\t*name:" << *var << "\t&name:" << &var << '\n';
    std::cout << "name_orig:" << str << "\t*name_orig:" << "NaN (errorv)" << "\t&name_orig:" << &str << '\n';

    //поэтому меняем немного адрес... и сосём. так как есть защита памяти спасибо господи
    //а строку можно....... хм. а почему тогда число записывалось не полностью...

    //std::cout << static_cast<std::string>(0x4E4E4E);

    //ПОПРОБУЕМ НЕ ИСПОЛЬЗОВАТЬ std::string, тогда
    
    //char a[9] = "apchihba";
    //char* first = &a[0];
    //std::cout << '\n' << '\n' << *(&a);

    //указатель хранит ссылку
    //а передача по ссылке в функциях - сахар
    char a[9] = "apchihba";
    char* first = a;
    std::cout << '\n' << '\n' << *first << *(first+sizeof(char)) << *(first+sizeof(char)*2);
    first += sizeof(char);
    std::cout << '\n' << *first << *(first + sizeof(char)) << *(first + sizeof(char) * 2);
    char* first_elem = &a[0]+sizeof(char)*10; //out of range
    std::cout << '\n' << *first_elem;
}

void swap(int &a, int &b) { //сюда подставляется переменная, от неё берётся указатель и получается что int &a действует как разыменованный укзазатель...
    int temp = a;
    a = b;
    b = temp;
}

void swap(int* a, int* b) { //а здесь мы просто работаем с указателями...
    int temp = *a;
    *a = *b;
    *b = temp;
}