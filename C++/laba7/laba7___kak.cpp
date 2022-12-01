#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
	// максимальное число студентов в группе
	const int countMax=29;

	struct STUD
		{
		char NAME[16];
		int ATTESTATION [6]={1,1,1,1,1,1};;
		float STEPENDIA;
		};
		STUD GROUP[countMax];
	const char Attest_bal[6][7] = {"ploh", "harosh","neploh"};
	int countStud, Num, OZENKA; // число и номер студента
	cout << " Число студентов (до " << countMax+1 << "): ";
	cin >> countStud;
// Защита от 'дурака'
	if (countStud>countMax) countStud=countMax;
	if (countStud<1) countStud=1;
// ввод данных
	for (Num=0; Num<countStud; Num++) {
		cout << "\tСтудент No\n" << Num+1 << ". "
		<< setw(28) << left << "Имя?";
		cin >> GROUP[Num].NAME;	
		cout << " Аттестат (алгебра, геометрия, русский язык, литература, информатика, география) [в одну строчку]: ";
		for (int attest_len=0;attest_len!=6;attest_len++){
			cin >> OZENKA; GROUP[Num].ATTESTATION[attest_len]=OZENKA;
		}
		for (int attest_len=0;attest_len!=6;attest_len++){
			cout << attest_len+1<<"-ый предмет:\t"<<GROUP[Num].ATTESTATION[attest_len]<<endl;
		}
		cout << " Размер степухи (float): ";
		cin >> GROUP[Num].STEPENDIA;
		cout << GROUP[Num].STEPENDIA;
	}
	cin.get();
	return 0;
}
