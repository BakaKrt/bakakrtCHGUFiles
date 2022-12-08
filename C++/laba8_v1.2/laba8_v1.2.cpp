#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

ofstream fout;
ifstream fin;
string in_bool;
string fname1, fname2,FOUT1, FOUT2;    //для имен файлов

char symbol_A, symbol_B, IN_OUT;     //Символы для замены - А(первый) и В(второй)

const int KEY_ESC = 27;            //постоянаая ascii кода клавиши ESC

char ch, want, trigger;            //рабочие переменные
string str;


string IS_TXT(string NAME) //проверка на .txt
{
    if (NAME.length() > 4) {
        for (int i = 0; i != NAME.length()-4;i++) {
            if (NAME[i] == '.' && NAME[i + 1] == 't' && NAME[i + 2] == 'x' && NAME[i + 3] == 't')
                break;
        }
        NAME = NAME + ".txt";
    }
    else if (NAME == "")
    { return "default.txt";}
    else { 
        NAME = NAME + ".txt";
    }
    printf("\nNAME = %s\n", NAME.c_str());
    return NAME;
}

bool CheckContinue()
{
    cout << "Продолжать?"; cin.get(want);
    if (want == KEY_ESC) return false;
    else return true;
}

/*void CREATE_FILE_(char X)
{

    setlocale(0, "");
    cout << "Создать новый файл или использовать уже существующий?(New/Exist): ";
    cin >> in_bool;
    cout << in_bool;
    if (in_bool == "N")
    {
        printf("Введите название выходного файла: ");
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
        printf("Введите название выходного файла: ");
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
*/

void CREATE_FILE_(char X)
{

    setlocale(0, "");
    if (X == '0') {
        cout << "Создать новый файл или использовать уже существующий?(New/Exist): ";
        cin >> in_bool;
    }
    if (in_bool == "N")
    {
        if (X == '0'){
            printf("Введите название выходного файла: ");
            cin >> fname1;
        }
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
        if (X == '0') {
            printf("Введите название входного файла: ");
            cin >> fname1;
        }
        fname1 = IS_TXT(fname1);
        fout.open(fname1, ios_base::in);
        while (!fout.is_open())
        {
            cout << "\nЧто-то пошло не так! Введи название файла заново:  ";
            cin >> fname1;
            fname1 = IS_TXT(fname1);
            fout.open(fname1, ios_base::in);
        }
        printf("Открыл существущий входной файл %s\n", fname1.c_str());
    }
    fout.close();
    cout << "Завершил этап 1\n";
}




void EnterSymbol_AB(char X)  //Функция для задания 1 & 2 символа
{
    if (X == '0') {
        cout << "Введите символы А и В, которые будут друг друга заменять:\n";
        cin >> symbol_A;
        cin >> symbol_B;
        cin.clear();
        printf("Ваши символы для замены: %c и %c\n", symbol_A, symbol_B);
    }
}

void EnterName2(char X)     //Аналогичная предыдущей функция для второго файла
{
    if (X == '0')
    {
        cout << "Введите имя выходного файла (так же дополнится до .txt): ";
        cin.clear();
        cin >> fname2;
    }
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

void CreateOutput()
{
    char ch;
    while (!fin.eof()) {
        fin.get(ch);
        if (ch == symbol_A) {
            fout.put(ch);
            fin.get(ch);
            fout.put(symbol_B);
            symbol_A, symbol_B = symbol_B, symbol_A;
        }
        else
            fout.put(ch);
    }
}



int main(int argc, char* argv[])   //...и сама функция main
{
    char CHOOSE;
    string inp;
    setlocale(0, "");
    cout << "Получать ввод с клавиатуры[0] или использовать аргументы из консоли[1]? ";
    cin >> CHOOSE;
    if (argc != 1 && argc<8) {
        cout << argc << endl;
        for (int i = 1; i < argc; i++)
            printf("%d %s\n", i, argv[i]);
        //system("cls"); //очистка cmd
        printf("\nВаш выбор - %c\n\n", CHOOSE);

        in_bool = argv[1];
        fname1 = argv[2];

        CREATE_FILE_(CHOOSE);
        if (CHOOSE == '1') {
            char* symbol_A = argv[3];
            char* symbol_B = argv[4];
            printf("Символы A и B: %s, %s", symbol_A, symbol_B);
        }
        EnterSymbol_AB(CHOOSE);
        fname2 = argv[5];
        EnterName2(CHOOSE);
        inp = argv[6];
    }
    OpenInput();
    CreateOutput();
    fin.close();
    fout.close();

    if (CHOOSE == '0') {
        cout << "\nВывод содержимого файлов:\nИспользовать консоль (0) или Notepad(1)? ";
        cin >> inp;
    };
    if (inp == "0")
    {
        inp = "type ";
    }
    else inp = "notepad ";
    string type1 = inp + fname1;
    string type2 = inp + fname2;
    system("color 3");
    cout << "\n************ВХОД*************";
    system(type1.c_str());
    cout << "*********КОНЕЦ ВХОДА*********\n";
    cout << "\n************ВЫВОД************";
    system(type2.c_str());
    cout << "*********КОНЕЦ ВЫВОДА********\n";
    cout << "\nЗадание:\n\tЗамена в тексте каждого символа, "
        << "стоящего после заданного символа, другим заданным символом, "
        << "причем после каждой замены замененный символ становится искомым, а искомый – заменяющим.";
    return 0;
}