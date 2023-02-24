#include <ShlObj.h> 
#include <sysinfoapi.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void printArray(int input[], int count) { //функция для вывода массива через printf_s (потому что мы можем себе это позволить). получаем в функцию массив и его размер.
    printf_s("{"); //выводим скобочку
    for (int i = 0; i < count; i++)
    {
        printf_s("%d", input[i]); //выводим число
        printf_s(","); //выводим запятую, разделяющую элементы массива между собой
    }
    printf_s("\b}\n"); //удаляем последний знак (чтобы не было запятой)
}


struct Smartphone //структура телефона
{
    string model; //модель смартфона
    string osType; //тип операционной системы
    int ram; //емкость оперативной памяти
};

void print_house(Smartphone phone) 
{
    cout << "Наименование: " << phone.model << " " << "Тип ОС: " << phone.osType << " " << "Оперативная память: " << phone.ram << " " << endl; //вывод характеристик смартфона на экран
}


int main()
{
    setlocale(LC_ALL, "Russian"); //подключаем русский язык
    int number_group; //объявление переменной, в которой будем хранить номер бригады
    cout << "Введите номер бригады: ";
    cin >> number_group; //ввод номера бригады с клавиатуры
    char nameFirstStudent[] = "Саранцева"; //создание массивов символов, в которых мы будем хранить фамилии студентов
    char nameSecondStudent[] = "Рябова"; 
    
    cout << "Вывод с помощью cout:\n"; //выводим нужное на экран с помощью cout
    cout << "Бригада №" << number_group << endl;
    cout << nameFirstStudent << endl << nameSecondStudent << endl << endl;

    cout << "Вывод с помощью printf_s:\n"; //все тоже самое, но с помощью printf_s
    printf_s("Бригада № %d\n%s\n%s", number_group, nameFirstStudent, nameSecondStudent); //%d - целочисленный аргумент, %s - строковый формат

    cout << endl << endl;

    const int count = 3; //размер массива
    int mas[count] = { 1, 2, 3 }; //массивы из методички
    int mmm[count] = { 4, 5, 6 }; 

    printArray(mas, count); //используем объявленную раннее функцию для вывода массива на экран
    printArray(mmm, count);


    const int count_phones = 5; //количество элементов массива 5 (значение из методички)
    Smartphone phones[count_phones] = { {"Модель1", "ОС1",40}, {"Модель2", "ОС2",50},{"Модель3", "ОС3",40}, {"Модель4","ОС4",50} ,{"Модель5", "ОС5",20} };

    int stricts; //граница1
    int strictf; //граница2
    cout << "Введите начало интервала, которому должна удовлетворять емкость оперативной памяти: ";
    cin >> stricts; 
    cout << "Введите конец интервала, которому должна удовлетворять емкость оперативной памяти: ";
    cin >> strictf;

    ofstream out; //открываем файл для записи
    out.open("C:\\Users\\Анастасия\\Desktop\\system software\\smartphone.txt", ios::trunc); //уничтожение содержимого, если этот файл существует (позволяет перезапись)

    for (int i = 0; i < count_phones; i++) { 
        if ((phones[i].ram > stricts) && (phones[i].ram <= strictf)) { //если объем оперативной памяти удовлетворяет условию, то выводим на экран и записываем в файл
            print_house(phones[i]);
            if (out.is_open()) { //проверяем открыт ли файл
                out << "Наименование: " << phones[i].model << " " << "Тип ОС: " << phones[i].osType << " " << "Оперативная память: " << phones[i].ram << " " << endl;
            }

        }
    }
    out.close(); //закрываем файл для записи
    char system_folder[MAX_PATH]; //строка с завершающим нулевым символом, содержащая путь специальной папки (куда мы его запишем)
    SHGetSpecialFolderPathA(0, system_folder, CSIDL_WINDOWS, false); //дескриптор окна, было выше, id папки, если мы не нашли папку, то не будем ее создавать
    printf(system_folder); //выводим на экран то, что находится в system_folder
    cout << endl; //переход на новую строку
    SYSTEM_INFO sysInfo; //в сисинфо лежит информация о системе
    GetSystemInfo(&sysInfo); //получаем информацию (& - указатель)
    switch (sysInfo.wProcessorArchitecture) //смотрим архитектуру
    {
    case 6:
        printf("Intel Itanium");
        break;
    case 9:
        printf("x64(AMD or Intel)");
        break;
    case 0:
        printf("x086");
        break;
    case 5:
        printf("ARM");
        break;
    case 12:
        printf("ARM64");
        break;
    default:
        printf("Unknown");
        break;
    }

}
