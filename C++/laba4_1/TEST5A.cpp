// Программа TEST5A.cpp 
#include <iostream> 
using namespace std;

int I, J; 
char C, A[] = "Пример 1";

int main () 
{
  setlocale(0, "");
  I = 0;
  while (I!=8)
  {
    cout << "\n";
    for (J=0; J<9; J++)
      cout << A[J];
    cout << "\n";
    cout << " Номер=";  
    cin.get(C); I=C-'0'; // I - целое;
    cin.get();  
    cout << " I=" << I << endl;
    cout << " Знач.=";
    cin.get(C); // С - символ
    cin.get();
    cout << " C=" << C << endl;
    A[I]=C;
  }
  cin.get();
  return 0;
}

