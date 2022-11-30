#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  // максимальное число студентов в группе
  const int countMax = 25;
  enum Points { Udov = 1, Hor = 2, Otl = 3 }; // оценка
  struct TStud {         // запись о студенте
    char name[16];       // имя
    Points points;       // оценка
    double middle_point; // баллы
  };
  // группа студентов
  TStud group[countMax];
  const char RateStr[3][5] = {"Udov", "Hor", "Otl"};
  int countStud, Num,
      i; // число и номер студента       // номер времени года: 0..3
  cout << " Число студентов (до " << countMax + 1 << "): ";
  cin >> countStud;
  // Защита от 'дурака'
  if (countStud > countMax)
    countStud = countMax;
  if (countStud < 1) countStud = 1;
  // ввод данных
  for (Num = 0; Num < countStud; Num++) {
    cout << "\tСтудент №\n" << Num + 1 << ". " << setw(28) << left << "Имя?";
    cin >> group[Num].name;
    cout << "Oценки по шести предметам аттестата (алгебра, геометрия, русский язык, литература, информатика, география) "
         << "(Удов = 1 Хор = 2 Отл = 3)";
    for (int j = 0; j < 4; j++) {
      cin >> i;
      group[Num].points[j] = Points(i);
    }
    cout << "Средний балл аттестата: ";
    cin >> group[Num].middle_point;
  }

  // Защита от 'дурака' и преобразование типа
  // Вывод заголовка таблицы
  cout << "\nСписок группы:\n"
       << setw(13) << "Номер" << setw(12) << "Имя" << setw(25) << "Средний балл"
       << setw(11) << "Алгебра" << setw(11) << "Геометрия" << setw(10)
       << "Русский язык" << setw(12) << "Литература" << setw(13)
       << "Информатика" << setw(11) << "География" << endl;
  // Вывод полей таблицы
  for (Num = 0; Num < countStud; Num = 1 + Num) {
    cout << right << setw(5) << Num + 1 << setw(10) << group[Num].name
         << setw(5) << group[Num].middle_point << setw(11)
         << PointsStr[group[Num].points[0] - 3] << setw(11)
         << PointsStr[group[Num].points[1] - 3] << setw(10)
         << PointsStr[group[Num].points[2] - 3] << setw(11) 
         << PointsStr[group[Num].points[3] - 3] << endl;
  }

  // вывод результата
  cout << "\n Студент с максимальным средним баллом аттестата: "
       << "\n"
       << setw(6) << "Номер" << setw(10) << "Имя" << setw(25)
       << "Оценки по предметам аттестата" << setw(10)
       << "Средний балл аттестата по всем предметам" << endl;
  for (Num = 0; Num < countStud; Num++)
if (group[Num].middle_point == 5)
cout << setw(6) << Num+1 << setw(10) << group[Num].name
 << setw(5) << PointsStr[group[Num].points] << setw(19) << group[Num].points << endl;
cin.get();
return 0;
}