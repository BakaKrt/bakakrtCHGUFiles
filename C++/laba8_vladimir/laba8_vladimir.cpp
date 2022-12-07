#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

ofstream fout;
ifstream fin;

string fname1, fname2, FOUT1, FOUT2;    //для имен файлов

char symbol_A, symbol_B, IN_OUT;     //Символы для замены - А(первый) и В(второй)

const int KEY_ESC = 27;            //постоянаая ascii кода клавиши ESC

char ch, want, trigger;            //рабочие переменные
string str;


string IS_TXT(string NAME) //проверка на .txt
{
    if (NAME.length() > 4) {
        for (int i = 0; i != NAME.length() - 4; i++) {
            if (NAME[i] == '.' && NAME[i + 1] == 't' && NAME[i + 2] == 'x' && NAME[i + 3] == 't')
                break;
        }
        NAME = NAME + ".txt";
    }
    else if (NAME == "")
    {
        return "default.txt";
    }
    else {
        NAME = NAME + ".txt";
    }
    printf("NAME = %s\n", NAME.c_str());
    return NAME;
}

bool CheckContinue()
{
    cout << "Продолжать?"; cin.get(want);
    if (want == KEY_ESC) return false;
    else return true;
}

void CREATE_FILE_(char X)
{
    string x_;
    if (X == 'I') x_ = "входного";
    else x_ = "выходного";

    setlocale(0, "");
    string in_bool;
    cout << "Создать новый файл или использовать уже существующий?(New/Exist): ";
    cin >> in_bool;
    if (in_bool == "N")
    {
        printf("Введите название %s файла: ", x_.c_str());
        cin >> fname1;
        fname1 = IS_TXT(fname1);
        fout.open(fname1);
        while (!fout.is_open())
        {
            cout << "\nЧто-то пошло не так! Введите название файла заново: ";
            cin >> fname1;
            fname1 = IS_TXT(fname1);
            fout.open(fname1);
        }

        cout << "\nФайл был успешно создан\n";
        int kolvo_str;
        cin.clear();
        cout << "Введите количество строк: ";
        cin >> kolvo_str;
        for (int i = -1; i != kolvo_str; i++) {
            getline(cin, str, '\n');
            fout << str << '\n';
        }
    }
    else {
        printf("Введите название %s файла: ", x_.c_str());
        cin >> fname1;
        fname1 = IS_TXT(fname1);
        fout.open(fname1, ios_base::in);
        while (!fout.is_open())
        {
            cout << "\nЧто-то пошло не так! Введи название файла заново:  ";
            cin >> fname1;
            fname1 = IS_TXT(fname1);
            fout.open(fname1);
        }
    }
    fout.close();
}




void EnterSymbol_AB()  //Функция для задания 1 & 2 символа
{
    cout << "Введите символ А:\n";
    cin >> trigger;
    printf("Ваш символ для замены: %c\n", trigger);
}

void EnterName2()     //Аналогичная предыдущей функция для второго файла
{
    cout << "Введите имя выходного файла (так же дополнится до .txt): ";
    cin.clear();
    getline(cin, fname2);
    fname2 = IS_TXT(fname2);
    fout.open(fname2);
    printf("Открыл %s", fname2.c_str());
    while (!fout.is_open())
    {
        cout << "Error! File is not open!" << endl;
        cout << "Try again." << endl;
        cin >> fname2;
        fout.open(fname2);
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
}

/*void CreateOutput()
{
    while (!fin.eof()) {
        getline(fin, str);
        cout << endl<<str;
        int i1 = str.find(trigger);
        int i2 = str.find(trigger, i1 + 1);
        //printf("\ni1 = %d, i2 = %d", i1, i2);
        while (i1 != -1 && i2 != -1){
            printf("\n1-ый: %d, 2-ой: %d",i1,i2 );
            cin.get();
            i1 = str.find(trigger, str.find(trigger)+1);
            i2 = str.find(trigger, i1 + 1);
            if (i2 - i1 != 1) {
                str.erase(i1 + 1, i2 - i1 - 1);
                fout << str << endl;
            }
            else
            {
                i1 = str.find(trigger, str.find(trigger) + 2);
                i2 = str.find(trigger, i1 + 1);
                printf("\nновый 1-ый: %d, 2-ой: %d", i1, i2);
                //str.erase(i2);
            }
        }
    }
    fout << str << endl;
    

    /*while (!fin.eof())
    {
        getline(fin, str);
        //cout << str << endl;
        //cout << str.find(trigger);
        while (str.find(trigger)!=1)
        {
            int i1 = str.find(trigger);
            int i2 = str.find(trigger, i1 + 1);
            //printf("i1 = %d, i2 = %d", i1, i2);
            //cout << i1 << i2 << endl;
            //cin.get();
            if ((i2 - i1) != 1)
            {
                str.erase(i1 + 1, i2 - i1 - 1);
                fout << str << endl;
                //printf("заменённая строка");
            }
            else str.erase(i1, i2);
        }
    }
    

}*/

/*
void CreateOutput()           //Создание выходного файла. В этой функции и будет реализовываться индивидуальное задание. Поэтому у каждого варианта код здесть будет свой
{
    getline(fin,str);
    cout << str;
    while (!fin.eof()) {
        int i1 = str.find(trigger);
        int i2 = str.find(trigger, i1 + 1);
        if (i2 - i1 != 1 && i1!=-1 && i2!=-1) {
            cout << i1 << i2 << endl;
            str.erase(i1, i2 - i1);
            //int i1 = str.find(trigger);
            //int i2 = str.find(trigger, i1 + 1);
            fout << str << endl;
        }
        else str.erase(i1, i2);
    }
    fout << str << endl;
}
*/

void CreateOutput() {
    while (!fin.eof()) {
        getline(fin, str);
        int i1 = str.find(trigger);
        int i2 = str.find(trigger, i1+1);
        //cout << i1 << i2 << endl;
        cout << "Исходная строка: " << str << endl;
        while ((i1!=-1) && (i2!=-1)) {
            cout << i1 << i2 << i2 - i1 << endl;
            cout << str.substr(i1,i2-1) << endl;
            str.erase(i1+1, i2-1);
            int i1 = str.find(trigger);
            int i2 = str.find(trigger, i1 + 1);
            cout << str << endl;
            cout << i1 << i2 << endl;
            cin.get();
        }
    }
}



int main(int argc, char* argv[])   //...и сама функция main
{
    setlocale(0, "");
    CREATE_FILE_('I');
    EnterSymbol_AB();

    cin.get();
    EnterName2();
    OpenInput();

    CreateOutput();
    fin.close();
    fout.close();
    system("color 3");

    cout << "\nВывод содержимого файлов:\nИспользовать консоль (0) или Notepad(1)? ";
    string inp;
    cin >> inp;
    if (inp == "0")
    {
        inp = "type ";
    }
    else inp = "notepad ";
    string type1 = inp + fname1;
    string type2 = inp + fname2;
    cout << "\n************ВХОД*************";
    system(type1.c_str());
    cout << "*********КОНЕЦ ВХОДА*********\n";
    cout << "\n************ВЫВОД************";
    system(type2.c_str());
    cout << "*********КОНЕЦ ВЫХОДА********\n";
    printf("Задание 9: Удаление из каждой строки последовательности символов, ограниченных с обеих сторон заданным символом.");
    return 0;
}