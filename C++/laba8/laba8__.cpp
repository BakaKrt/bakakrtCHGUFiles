#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

ofstream fout;
ifstream fin;

string fname1, fname2;    //��� ���� ������

int stCount = 10,         //���-�� ������� � �����, ���� ������� ���� � ���������
pgCount = 1;


const int KEY_ESC = 27;            //���������� ascii ���� ������� ESC

char ch, want, trigger;            //������� ����������
string str;

bool CheckContinue()         //������� �������� ������� ������������ ����������. ����� �� ������� ��������� �� � ������ ������ � ���������, �� �� ������ ������� ��� ����. � ���. �������� ������� �� ������ ����������
{
    cout << "Do you want continue?"; cin.get(want);
    if (want == KEY_ESC) return false;
}

void EnterName1()  //������� ��� ������� ����� ������� ����� � ��������� ������ ��� ��� ��������������
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

void EnterName2()     //����������� ���������� ������� ��� ������� �����
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

void CreateInput()    //������� �������� ����� ��� �������� ������ (������� �����). ����� ����� ����� ��, ���� ������������ ������� ��� ������� ����� ��� �������� ��������������
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

void OpenInput()      //������� ����������� ���� ��� ������ � ��������� �� ���������� ��������
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

void CreateOutput()           //�������� ��������� �����. � ���� ������� � ����� ��������������� �������������� �������. ������� � ������� �������� ��� ������ ����� ����
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
//����� ���� ������� ������ ������� �������� ������ ��������� �� �����. ������ ���� ������ ����� ����������, ��������������, ��������� ��� ����



int main(int argc, char*argv[])   //...� ���� ������� main
{
    cout << "Enter file name: ";
    cin >> fname1;

    cout << "Create a new file OR use an existing one? (n/e)";    //����� ��� ��� � ��������������� ������� ������������ ������������ ������� ���� ��� �� ������� ���� 
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

    system("type *FirstFileName*");    //������� ����������� ������� ����� � �������. ��� ������ ����� �� �����, �� ���� ��� ���� ������, �� �������� ���� ��� ������� ������ ������ *FirstFileName*

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
    system("type *SecondFileName*");       //������� ����������� ������� ����� � �������. ������ � ���� �� ��, ��� � ������� ���� ����
    system("pause");
}
/*������ ����������� ����������� ������ ������ � ������� � ������� ��������� ���� C++. 
* ����� �� �������� ��������� ����� � ��� ��������� ��� ��������� ���� ������,
* �� ��� ����� �������� ����� ����������. ������ 2 ������� �������� ���� ��� ����, ����� �� ������ ���� ����� �������������� ���.
*/
