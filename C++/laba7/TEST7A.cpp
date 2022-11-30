#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	enum Months {January=1, February, March, April, May, June,
		July, August, September, October, November, December};
	struct TDate {
		unsigned short day;
		Months month;
		unsigned short year;
	};
	typedef char TStroka [16];
	struct TPerson {
		TStroka name;
		TDate birthDay;
	};
	TPerson table[10];
	TPerson R;
	int i, j, k, N;	
	cout << "„исло персон? "; cin >> N;
	if (N>10) N=10;
	if (N<1) N=1;
	for (i=0; i<N; i=1+i) {
		cout << "»м€? ";
		cin >> table[i].name;
		cout << "ƒень (1..31), мес€ц (1..12), год (YYYY)? ";
		cin >> table[i].birthDay.day;
		unsigned short data;
		cin >> data; table[i].birthDay.month = Months(data);
		cin >> table[i].birthDay.year;
	}
	for (k=N-1; k>=0; k=k-1)
		for (i=0; i<k; i=i+1)
			if (strcmp(table[i].name, table[i+1].name)>0) {
				R=table[i];
				table[i]=table[i+1];
				table[i+1]=R;
			}
	for (i=0; i<N; i++)
	cout << i+1 << ". " << table[i].name << " - "
	<< table[i].birthDay.day << "."
	<< table[i].birthDay.month << "."
	<< table[i].birthDay.year << "\n";
return 0;
}