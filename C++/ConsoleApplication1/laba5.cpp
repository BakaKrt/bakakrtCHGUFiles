#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	const int N = 5; // ????? ??p??, ????????
	int Row, Elem; // ???????: ??????, ???????
	float A[N][N], B[N][N]; // ???????
	char Ch; // ??? ????p? ?????
	setlocale(0, "");
	
	
	// *********???? ?????? ??????? ?**************
	cout << "\n??????? 5 ??p?? ?? 5 ?????:\n";
	// ???? ??????? ?: ???? ? ????????????
	Elem = 0; // ??? ??????? ?????????? ? ????!
	while (Elem < N){ // ???? ?? ??? ??????? ???????
		cout<<Elem+1<<": "; // ??????? ????? ??????
		Row = 0; // ????? ???????? ???? ?????????? ? 0
		while (Row < N) { // ?????? ???????? ???????
			cin>>A[Row][Elem]; // ?????????? ?????? ?????
			Row++; // ????? ?????????? ????????
		}
		// ?p????? ?????? ??p??? (??????? ????p? ?????)
		// ???? ????????? ???????? ??????, ??? ????
		do // ?p??????? ????? ??p??? ???????????
			cin.get(Ch);
		while ( Ch != '\n' ); // ?? ???????? ??????
		Elem=Elem+1; // ????? ?????????? ???????
	}
	cout<<endl;
	
	
	// ********??????????? ????? ?????? *************
	// ******? ?????????? ????? ? ????????***********
	// ????? ? ?????? ? ????????????
	cout<<" ????? ??????? ?:\n";
	for (Elem=1; Elem<=N; Elem++)
		cout << setw(9) << Elem; // ??????? ?????? ???????? 1-5
	cout<<endl;
	Row = 0; // ???????? ? ??????? ??????
	do { // ????? ?????? ?? ?????? ?????????? ? 1
		cout << Row+1 <<":"; // ??????? ????? ????
		Elem = 0; // ???????? ? ???????? ????????
		do {
			cout << setw(9) << A[Row][Elem]; // ??????? ??????? ?
			Elem++; // ????? ?????????? ????????
		// ???? ?? ?????? ??? ????????
		} while (Elem < N);
		cout << endl;
		Row++; // ????? ????????? ??????
	} while (Row < N); // ???? ?? ??? ??????
	
	cin.get(Ch); // ????????????? ??????????
	
	
	// ********** ????????? ??????? ? ***************
	// **** ??????????? ????????? ????????? *********
	cout << "\n?????????? ?: ????p?????? ?? A:";
	cout << "\n???: ????????"; // ?????????
	for (Row = 0; Row < N; Row++) {
		cout << "\n" << Row + 1 << ": ";
		for (Elem = 0; Elem < N; Elem++)
			if (Elem + Row == 4)
				B[Row][Elem] = A[Row][Elem];
		cout << Elem + 1;
	}

	// ***** ????????? ????????? ????????? **********
	cout << "\n\n??p?????? ?: ????????? ?????????:";
	cout << "\n???: ????????";
	
	
	for (Row=0; Row<N; Row++) {	
		cout << "\n" << Row+1 << ": ";		
		for (Elem=0; Elem<abs(Row-4); B[Row][Elem]=0, Elem++)
		cout<<Elem+1<<", "; 
	} 
	
	for (Row=0; Row<N; Row++) {	
		cout << "\n" << Row+1 << ": ";

	for (Elem=4; Elem+Row>4; B[Row][Elem]=0, Elem--)
		cout<<	Elem+1<<", "; 
	} 

	// ******** ????? ?????? ??????? ?*************
	// ????? ??????? B ??p?? cout ? ???? ? ????????????
	cout << setprecision(2);// ???p ?p???
	// ?????????? ?????? ??????: ?????p??????? ?????,
	// ???????? ?????, ????? ????????????
	cout << setiosflags(ios::fixed | ios::showpoint | ios::left);
	cout << "\n ????? ? ??p?? cout ? ???? ? ???????????? \n";
	cout << "\t";
	for (Elem=1; Elem<=N; Elem++)
		// ????????? ???????? ? 9-?? ????????
		cout << setw(9) << Elem;
	Row = 0; // ?????????? ?????? ?? 0-? ?? 4-?
	do {
		// ??????? ?????? ? ?????
		cout << '\n' << Row+1 << ": ";
		if (Row == 3) {
			// ?????????? ?p???? ??p?????????
			cout << resetiosflags(ios::left);
			cout << setiosflags(ios::right);
		}	
		Elem = 0; // ?? ???? ?????????, ??????? ? 0-??
		do {
			// ??????? ???????? ? 9-?? ????????
			cout << resetiosflags(ios::left);
			cout << setw(9) << B[Row][Elem];
		} while (++Elem < N); // ?? ???? ?????????
	} while (++Row < N); // ?? ???? ???????
	cin.get();
	return 0;
}
