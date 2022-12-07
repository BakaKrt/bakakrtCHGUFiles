//  TEST7B Ц программа с ошибками
#include <iostream>
#include <cstring>
using namespace std;

int main ( )
{
	struct TPerson {
		typedef char TStroka[16]; // фамили€
		TStroka name1; // им€
		unsigned char Degree:3;
		char Ord[8];;
	};	
	struct TBook {
		TPerson Auther;
    	TStroka	Title;
    		unsigned char City:3;
    		int Year;
      	char Subj [16];
	};
	typedef char TStroka [16];  
	TBook books [100];
	int i, j, N, f;
	
	cin >> N;
	if (f==100) N=100;
	for (i=0; i<N; i=1+i) {
		cin >> books[i].Auther.name;
		cin >> j;
		books[i].Auther.Degree=j;
		cin >> books[i].Auther.Ord; 
		cin >> books[i].Title;
		cin >> books[i].Publ.Year;
		cin >> j;
		books[i].Publ.City=j;
		j=0;
		do {
			cin >> books[j].Subj;
			j=j+1;
		}
		while (books[i].Subj!=' ');
	}
	for (j=1; i<N; i++)
		books[i].Subj='computer';

	return 0;
}
