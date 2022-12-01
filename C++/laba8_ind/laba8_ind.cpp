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

char symbol_A, symbol_B;     //Символы для замены - А(первый) и В(второй)

const int KEY_ESC = 27;            //постоянаая ascii кода клавиши ESC

char ch, want, trigger;            //рабочие переменные
string str;

bool CheckContinue()      //функция проверки желания пользователя продолжить. Особо не парился вставлять ее в нужных местах в программе, но вы можете сделать это сами. С обл. видимоти проблем не должно возникнуть
{
    cout << "Продолжать?"; cin.get(want);
    if (want == KEY_ESC) return false;
    else return true;
}

string IS_TXT(string NAME) //проверка на .txt
{
    string fn = "";
    if (NAME.length() > 4) {
        for (int i = 0; i < NAME.length(); i++) {
            fn = NAME[i] + NAME[i + 1] + NAME[i + 2] + NAME[i + 3];
            if (fn != ".txt") {
                NAME = NAME + ".txt";
            }
        }
    }
    else {
        NAME = NAME + ".txt";
        }
    printf("NAME = %s\n",NAME.c_str());
    return NAME;
}

void EnterName1()  //Функция для задания имени первого файла с повторным вводом при его некорректности
{
    cout << "Введите имя файла (автодополнится в .txt при его отсутствии): ";
    cin >> fname1;
    fname1 = IS_TXT(fname1);
    fout.open(fname1, ios::out);
    printf("Это длина %s %u",fname1.c_str(), fname1.length());
    while (!fout.is_open())
    {
        cout << "Error! File is not open!" << endl;
        cout << "Try again." << endl;
        cin >> fname1;
        fout.open(fname1, ios::out);
    }
    cout << endl << "Enter succes!" << endl << endl;
}

void EnterSymbol_AB()  //Функция для задания 1 & 2 символа
{
    cout << "Введите символы А и В, которые будут друг друга заменять (через пробел):\n";
    cin.clear();
    cin >> symbol_A;
    cin >> symbol_B;
    printf("Ваши символы для замены: %c и %c\n", symbol_A, symbol_B);
    cin.clear();
}

void EnterName2()     //Аналогичная предыдущей функция для второго файла
{
    cout << "Введите имя выходного файла (так же дополнится до .txt): ";
    //cin >> fname2;
    cin.clear();
    getline(cin, fname2);
    cin.clear();
    fname2 = IS_TXT(fname2);
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
    int kolvo_strok, k=-1;
    cout << "Количество строк ввода: ";
    cin >> kolvo_strok;
    while (k!=kolvo_strok)
    {
        cout << k << kolvo_strok;
        getline(cin, str);
        fout << str<<'\n' << ios::app;
        k++;
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
    cout << endl << "Succes!" << fname1 <<endl << endl;
}

void CreateOutput()           //Создание выходного файла. В этой функции и будет реализовываться индивидуальное задание. Поэтому у каждого варианта код здесть будет свой
{
    char ch;
    while (!fin.eof()) {
        fin.get(ch);
        cout << ch << endl;
        if (ch == symbol_A) {
            fout.put(ch);
            fin.get(ch);
            cout << ch << endl;
            fout.put(symbol_B);
            symbol_A, symbol_B = symbol_B, symbol_A;
        }
        else
            fout.put(ch);
    }
}
//Кроме этой функции ничего другого изменять другим вариантам не нужно. Только если хотите чтото подправить, оптимизировать, подогнать под себя



int main(int argc, char* argv[])   //...и сама функция main
{
    setlocale(0, "");
    EnterName1();


    cout << "Create a new file OR use an existing one? (N/E)";    //здесь как раз и реализовывается желание пользователя использовать готовый файл или же создать свой 
    cin >> want;

    EnterSymbol_AB();

    if (want == 'N') {
        cin.get();
        CheckContinue();
        if (CheckContinue == 0) {
            cout << "Programm is over." << endl;
            system("pause");
            return 0;
        }

        CreateInput();
        fout.close();
    }
    //CreateInput();
    //fout.close();

//    system("type fname1");    //выводим содержимове первого файла в консоль. Эту строку можно не юзать, но если все таки будете, то вставьте свое имя первого фалйла вместо *FirstFileName*

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
    CreateOutput();
    cout << "File is succesfully create!" << endl << endl;
    fin.close();
    fout.close();
//    system("type fname2");       //выводим содержимове второго файла в консоль. Делаем с этим то же, что я написал чуть выше
    system("pause");
}
/*Можете попробовать реализовать выводы файлов в консоль с помощью написания кода C++.
* Тогда не придется постоянно лезть в код программы для изменения имен файлов,
* тк это будет делаться самой программой. Данные 2 строчки написаны лишь для того, чтобы не писать этот самый дополнительный код.
*/