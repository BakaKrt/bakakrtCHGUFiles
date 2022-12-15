#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

ofstream fout;
ifstream fin;
string in_bool;
string fname1, fname2,FOUT1, FOUT2;    //для имен файлов
string symbol_A, symbol_B; 
char IN_OUT;
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


void CREATE_FILE_(bool X)
{

    setlocale(0, "");
    if (X == 0) {
        cout << "Создать новый файл или использовать уже существующий?(New/Exist): ";
        cin >> in_bool;
    }
    if (in_bool == "N")
    {
        if (X == 0){
            printf("Введите название входного файла: ");
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
        cout << "Введите количество строк [по 2 на страницу]: ";
        cin >> kolvo_str;
        cin.clear();
        cout << "Введите сами строки [не длиннее 30 символов]:" << endl;
        for (int i = -1; i != kolvo_str;) {
            getline(cin, str, '\n');
            if (str.length() < 30) {
                fout << str << '\n';
                if ((i + 1) % 2==0) {
                    cout << "\nНовая страница:\n";
                    fout << "\n##########" << int((i+1)/2)+1 << "##########\n";
                }
                if ((kolvo_str-(i+1))>0)
                    cout << i+2 << " ";
                i++;
            }
            else cout << "\t\tСлишком длинная строка! Введите заново:\n";
        }
    }
    else {
        if (X == 0) {
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




void EnterSymbol_AB(bool X)  //Функция для задания 1 & 2 символа
{
    if (X == 0) {
        cout << "Введите символы А и В, которые будут друг друга заменять:\n";
        cin >> symbol_A;
        if (symbol_A.length() > 1) {
            symbol_B = symbol_A[1];
            symbol_A = symbol_A[0];
        }
        else cin >> symbol_B;
        cin.clear();
        printf("Ваши символы для замены: %s и %s\n", symbol_A.c_str(), symbol_B.c_str());
    }
}

void EnterName2(bool X)     //Аналогичная предыдущей функция для второго файла
{
    if (X == 0)
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
        cout << "Ошибка!" << endl;
        cout << "Попробуйте снова ввести имя: " << endl;
        cin >> fname2;
        fout.open(fname2);
    }
}


void OpenInput()      //Функция открывающая файл для чтения с проверкой на успешность операции
{
    fin.open(fname1, ios_base::in);
    while (!fin.is_open())
    {
        cout << "Ошибка! Файл не найден" << endl;
        cout << "Введите заново: " << endl;
        cin >> fname1;
        fin.open(fname1, ios_base::in);
    }
}

void CreateOutput()
{
    char ch;
    symbol_A = symbol_A.c_str();
    char *csymbol_A = &symbol_A[0];
    symbol_B = symbol_B.c_str();
    char *csymbol_B = &symbol_B[0];
    while (!fin.eof()) {
        fin.get(ch);
        if (ch == *csymbol_A) {
            fout.put(ch);
            fin.get(ch);
            fout.put(*csymbol_B);
            symbol_A, symbol_B = symbol_B, symbol_A;
        }
        else
            fout.put(ch);
    }
}

int main(int argc, char* argv[])
{
    bool CHOOSE;
    string inp;
    setlocale(0, "");
    cout << "\nЗадание:\n\tЗамена в тексте каждого символа,\n "
        << "\tстоящего после заданного символа, другим заданным символом,\n "
        << "\tпричем после каждой замены замененный символ\n\tстановится искомым, а искомый – заменяющим.\n";
    cout << "Получать ввод с клавиатуры[0] или использовать аргументы из консоли[1]? ";
    cin >> CHOOSE;
    for (int i = 1; i < argc; i++)
        printf("%d %s\n", i, argv[i]);
    system("cls"); //очистка cmd
    printf("\nВаш выбор - %d\n\n", CHOOSE);
    if (argc > 2 && CHOOSE == 1)
    {
        in_bool = argv[1];
        fname1 = argv[2];
    }
    CREATE_FILE_(CHOOSE);
    if (CHOOSE == 1 && argc > 4) {
        symbol_A = argv[3];
        symbol_B = argv[4];
        printf("Символы A и B: %s, %s", symbol_A.c_str(), symbol_B.c_str());
        cout << "\nСимвол А внутри цикла: " << symbol_A << endl;
    }
    EnterSymbol_AB(CHOOSE);
    if (argc > 5 && CHOOSE) fname2 = argv[5];
    EnterName2(CHOOSE);
    if (argc > 6 && CHOOSE ) inp = argv[6];
    
    OpenInput();
    CreateOutput();
    fin.close();
    fout.close();
    if (CHOOSE == 0) {
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
    system("cls");
    system("color 3");
    printf("Имя входного файла: %s", fname1.c_str());
    if (inp == "type ")
        cout << "\n************ВХОД*************";
    system(type1.c_str());
    if (inp == "type ") 
        cout << "*********КОНЕЦ ВХОДА*********\n";
    printf("\nИмя выходного файла: %s", fname2.c_str());
    if (inp == "type ")
        cout << "\n************ВЫВОД************";
    system(type2.c_str());
    if (inp == "type ")
        cout << "*********КОНЕЦ ВЫВОДА********\n";
    printf("\n\tЗаменяемые символы: %s и %s", symbol_A.c_str(), symbol_B.c_str());
    cout << "\nЗадание:\n\tЗамена в тексте каждого символа,\n "
        << "\tстоящего после заданного символа, другим заданным символом,\n "
        << "\tпричем после каждой замены замененный символ\n\tстановится искомым, а искомый – заменяющим.\n";
    return 0;
}