// Копирование нескольких текстовых файлов в один файл 
// с разбивкой на страницы по LPG строк на каждой.
// Программа PRNT.cpp

#include <iostream>  // cout, cin
#include <fstream>   // ifstream, ofstream
using namespace std;

const int
  LPG=10,         // размер страницы
  LSTR=80,        // максимальная длина строки
  NLEN=20;        // максимальная длина имени файла
ifstream Prg;              // входной и
ofstream List;             // выходной файлы
char Name[NLEN],           // имя файла
     Chr;                  // рабочий символ
int  I, Len, NoExist=0;    // рабочие переменные
int  NextChar;    // для обнаружения конца файла

int main ()
{
  // открытие выходного файла
  List.open("PRN1.cрр");  
  do                 // начало цикла входных файлов
  {
    cout << "\n Введите имя файла ";
    cin >> Name;
    Prg.open(Name);  // открытие входного файла
    if (Prg)     // обработка, если файл существует
    {
      while (Prg.get(Chr)) // цикл страниц
      {
        for (I=1; I<=LPG; I++)
        {                                      // начало цикла страницы
          NextChar = Prg.peek();
          if (NextChar == EOF)
          {
            cout << "\nПоследняя страница - неполная \n";
            I = LPG;
          }
          else
            do               // цикл строки
            {
              Prg >> Chr;    // чтение и
              List << Chr;   // запись символа
            }
            while (Chr != '\n' && !Prg.eof());  // конец строки
        }                                       // конец страницы
      }
      cout << "КОНЕЦ ВЫДАЧИ ОДНОГО ФАЙЛА";
    }
    else NoExist = 1;
  }
  while ( !NoExist ); // конец цикла входных файлов
  List.close();
  return 0;
}

