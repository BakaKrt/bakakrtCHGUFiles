#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
	setlocale(0, "");
	const int countMax = 29;

	struct STUD
	{
		char NAME[16];
		int ATTESTATION[6] = { 1,1,1,1,1,1 };
		float STEPENDIA = { 0 };
	};
	STUD GROUP[countMax];

	int countStud, Num, OZENKA; // число и номер студента, оценка по аттестату
	printf("Число студентов (до %d): ", countMax + 1);
	cin >> countStud;

	if (countStud > countMax) countStud = countMax;
	if (countStud < 1) countStud = 1;

	for (Num = 0; Num < countStud; Num++) {
		cout << "\tСтудент номер:\n" << Num + 1 << ". "
			<< setw(28) << left << "Имя?";
		cin >> GROUP[Num].NAME;
		cout << " Аттестат (алгебра, геометрия, русский язык, литература, информатика, география) [1-удовл, 2-хорошо, 3-отлично]: ";
		for (int attest_len = 0; attest_len != 6; attest_len++) {
			cin >> OZENKA;
			if (OZENKA > 3) OZENKA = OZENKA % 3;
			GROUP[Num].ATTESTATION[attest_len] = OZENKA;
		}
		for (int attest_len = 0; attest_len != 6; attest_len++) {
			cout << attest_len + 1 << "-ый предмет:\t" << GROUP[Num].ATTESTATION[attest_len] << endl;
		}
		cout << "Размер степухи (float): ";
		cin >> GROUP[Num].STEPENDIA;
	}
	bool is_step = false;
	for (Num = 0; Num < countStud; Num++) {
		if (GROUP[Num].STEPENDIA != 0) {
			if (is_step == false) {
				cout << "У кого есть степуха:\n";
				is_step = true;
			}
			cout << "Имя:";
			cout << "\t" << GROUP[Num].NAME << endl;
			cout << "Оценки по аттестату: ";
			for (int i = 0; i < 6; i++) {
				cout << "\t" << GROUP[Num].ATTESTATION[i];
			}
			cout << "\nСтепендия:";
			cout << "\t" << GROUP[Num].STEPENDIA << endl;
		}
	}
	if (is_step == false)
		cout << "Видимо всех отчислили, ни у кого нет степухи :(";

	cin.get();
	return 0;
}