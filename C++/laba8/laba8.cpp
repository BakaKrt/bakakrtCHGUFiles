#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

ofstream fout;
ifstream fin;

string fname1, fname2;    //для имен файлов

int stCount = 10,         //кол-во страниц и строк, если создаем файл в программе
pgCount = 1;


const int KEY_ESC = 27;            //постоянаая ascii кода клавиши ESC

char ch, want, trigger;            //рабочие переменные
string str;

bool CheckContinue()         //функция проверки желания пользователя продолжить. Особо не парился вставлять ее в нужных местах в программе, но вы можете сделать это сами. С обл. видимоти проблем не должно возникнуть
{
    cout << "Do you want continue?"; cin.get(want);
    if (want == KEY_ESC) return false;
}

void EnterName1()  //Функция для задания имени первого файла с повторным вводом при его некорректности
{
    fout.open(fname1);
    while (!fout.is_open())
    {
        cout << "Error! File is not open!" << endl;
        cout << "Try again." << endl;
        cin >> fname1;
        fout.open(fname1);
    }
    cout << endl << "Enter succes!" << endl << endl;
}

void EnterName2()     //Аналогичная предыдущей функция для второго файла
{
    cout << "Enter file name: ";
    cin >> fname2;
    fout.open(fname2);
    while (!fout.is_open())
    {
        cout << "Error! File is not open!" << endl;
        cout << "Try again." << endl;
        cin >> fname2;
        fout.open(fname2);
    }
    cout << endl << "Enter succes!" << endl << endl;
}

void CreateInput()    //Функция создания файла для будущего чтения (первого файла). Далее будем юзать ее, если пользователь захочет сам набрать текст для будущего форматирования
{
    cout << "Enter page count in your file (1 - 10). : ";
    cin >> pgCount;
    while (pgCount < 1 || pgCount > 10)
    {
        cout << "Error! Uncorrect input!" << endl
            << "Try again." << endl;
        cin >> pgCount;
    }
    cout << "and string count on one page (5 - 15): ";
    cin >> stCount;
    while (stCount < 5 || stCount > 15)
    {
        cout << "Error! Uncorrect input!" << endl
            << "Try again." << endl;
        cin >> stCount;
    }
    cout << "Enter your text, please!" << endl;
    for (int i = 0; i < pgCount; i++)
    {
        for (int j = -1; j < stCount; j++)
        {
            getline(cin, str);
            if (str.length() > 50) {
                cout << "String length is very big!";
                ch = '!';
                return; 
            }
            fout << str << '\n';
        }
        fout << '\n' << "#############################" << i + 1 << "#############################" << "\n\n";
        if (i == 0) stCount--;
    }
}

void OpenInput()      //Функция открывающая файл для чтения с проверкой на успешность операции
{
    fin.open(fname1, ios_base::in);
    while (!fin.is_open())
    {
        cout << "Error! File is not found!" << endl;
        cout << "Try again. Enter correct file name." << endl;
        cin >> fname1;
        fin.open(fname1);
    }
    cout << endl << "Succes!" << endl << endl;
}

void CreateOutput()           //Создание выходного файла. В этой функции и будет реализовываться индивидуальное задание. Поэтому у каждого варианта код здесть будет свой
{
    while (!fin.eof()) {
        fin.get(ch);
        while (true) {
            fin.get(ch);
            if (fin.eof()) break;
            if (ch == trigger) break;
        }
        if (fin.eof()) break;
        while (ch != '\n')
        {
            fin.get(ch);
            if (fin.eof()) break;
            fout.put(ch);
        }
        cout << "File is succesfully create!" << endl << endl;
    }
}
//Кроме этой функции ничего другого изменять другим вариантам не нужно. Только если хотите чтото подправить, оптимизировать, подогнать под себя



int main_(int argc, char*argv[])   //...и сама функция main
{
    cout << "Enter file name: ";
    cin >> fname1;

    cout << "Create a new file OR use an existing one? (n/e)";    //здесь как раз и реализовывается желание пользователя использовать готовый файл или же создать свой 
    cin >> want;
    
    if (want == 'n') {     
        cin.get();
        CheckContinue();
        if (CheckContinue == 0) {
            cout << "Programm is over." << endl;
            system("pause");
            return 0;
        }

        EnterName1();
        CreateInput();
        fout.close();
    }

//    system("type *FirstFileName*");    //выводим содержимове первого файла в консоль. Эту строку можно не юзать, но если все таки будете, то вставьте свое имя первого фалйла вместо *FirstFileName*

    cin.get();

    CheckContinue();
    if (CheckContinue == 0) {
        cout << "Programm is over." << endl;
        system("pause");
        return 0;
    }
    
    cout << "Create Second file for input" << endl;
    EnterName2();
    OpenInput();
    cin.get();
    cout << "Enter trigger char:"; 
    cin.get(trigger);
    cout << "File is succesfully create!" << endl << endl;
    fin.close();
    fout.close();
//    system("type *SecondFileName*");       //выводим содержимове второго файла в консоль. Делаем с этим то же, что я написал чуть выше
    system("pause");
}
/*Можете попробовать реализовать выводы файлов в консоль с помощью написания кода C++. 
* Тогда не придется постоянно лезть в код программы для изменения имен файлов,
* тк это будет делаться самой программой. Данные 2 строчки написаны лишь для того, чтобы не писать этот самый дополнительный код.
*/