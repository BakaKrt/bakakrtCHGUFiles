// ����������� ���������� ��������� ������ � ���� ���� 
// � ��������� �� �������� �� LPG ����� �� ������.
// ��������� PRNT.cpp

#include <iostream>  // cout, cin
#include <fstream>   // ifstream, ofstream
using namespace std;

const int
  LPG=10,         // ������ ��������
  LSTR=80,        // ������������ ����� ������
  NLEN=20;        // ������������ ����� ����� �����
ifstream Prg;              // ������� �
ofstream List;             // �������� �����
char Name[NLEN],           // ��� �����
     Chr;                  // ������� ������
int  I, Len, NoExist=0;    // ������� ����������
int  NextChar;    // ��� ����������� ����� �����

int main ()
{
  // �������� ��������� �����
  List.open("PRN1.c��");  
  do                 // ������ ����� ������� ������
  {
    cout << "\n ������� ��� ����� ";
    cin >> Name;
    Prg.open(Name);  // �������� �������� �����
    if (Prg)     // ���������, ���� ���� ����������
    {
      while (Prg.get(Chr)) // ���� �������
      {
        for (I=1; I<=LPG; I++)
        {                                      // ������ ����� ��������
          NextChar = Prg.peek();
          if (NextChar == EOF)
          {
            cout << "\n��������� �������� - �������� \n";
            I = LPG;
          }
          else
            do               // ���� ������
            {
              Prg >> Chr;    // ������ �
              List << Chr;   // ������ �������
            }
            while (Chr != '\n' && !Prg.eof());  // ����� ������
        }                                       // ����� ��������
      }
      cout << "����� ������ ������ �����";
    }
    else NoExist = 1;
  }
  while ( !NoExist ); // ����� ����� ������� ������
  List.close();
  return 0;
}

