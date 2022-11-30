#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  // ������������ ����� ��������� � ������
  const int countMax = 25;
  enum Points { Udov = 1, Hor = 2, Otl = 3 }; // ������
  struct TStud {         // ������ � ��������
    char name[16];       // ���
    Points points;       // ������
    double middle_point; // �����
  };
  // ������ ���������
  TStud group[countMax];
  const char RateStr[3][5] = {"Udov", "Hor", "Otl"};
  int countStud, Num,
      i; // ����� � ����� ��������       // ����� ������� ����: 0..3
  cout << " ����� ��������� (�� " << countMax + 1 << "): ";
  cin >> countStud;
  // ������ �� '������'
  if (countStud > countMax)
    countStud = countMax;
  if (countStud < 1) countStud = 1;
  // ���� ������
  for (Num = 0; Num < countStud; Num++) {
    cout << "\t������� �\n" << Num + 1 << ". " << setw(28) << left << "���?";
    cin >> group[Num].name;
    cout << "O����� �� ����� ��������� ��������� (�������, ���������, ������� ����, ����������, �����������, ���������) "
         << "(���� = 1 ��� = 2 ��� = 3)";
    for (int j = 0; j < 4; j++) {
      cin >> i;
      group[Num].points[j] = Points(i);
    }
    cout << "������� ���� ���������: ";
    cin >> group[Num].middle_point;
  }

  // ������ �� '������' � �������������� ����
  // ����� ��������� �������
  cout << "\n������ ������:\n"
       << setw(13) << "�����" << setw(12) << "���" << setw(25) << "������� ����"
       << setw(11) << "�������" << setw(11) << "���������" << setw(10)
       << "������� ����" << setw(12) << "����������" << setw(13)
       << "�����������" << setw(11) << "���������" << endl;
  // ����� ����� �������
  for (Num = 0; Num < countStud; Num = 1 + Num) {
    cout << right << setw(5) << Num + 1 << setw(10) << group[Num].name
         << setw(5) << group[Num].middle_point << setw(11)
         << PointsStr[group[Num].points[0] - 3] << setw(11)
         << PointsStr[group[Num].points[1] - 3] << setw(10)
         << PointsStr[group[Num].points[2] - 3] << setw(11) 
         << PointsStr[group[Num].points[3] - 3] << endl;
  }

  // ����� ����������
  cout << "\n ������� � ������������ ������� ������ ���������: "
       << "\n"
       << setw(6) << "�����" << setw(10) << "���" << setw(25)
       << "������ �� ��������� ���������" << setw(10)
       << "������� ���� ��������� �� ���� ���������" << endl;
  for (Num = 0; Num < countStud; Num++)
if (group[Num].middle_point == 5)
cout << setw(6) << Num+1 << setw(10) << group[Num].name
 << setw(5) << PointsStr[group[Num].points] << setw(19) << group[Num].points << endl;
cin.get();
return 0;
}