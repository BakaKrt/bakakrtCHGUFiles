#include <iostream>
#include <cstring>
using namespace std;
int main ( )
{
	bool minus = false, is10Digit;
	char ch;
	long long chislo = 0;
	const int Len = 11;
	char InputString[Len] {'\0'};
	short int ostatok, i;
// ������ ����� -------------------------------------------------------
// ������ ����������� � �����
	cout << "������� 10-����� ����� �� ������: ";
// ������ ������ ����� ���� ����
	cin.get(ch);
	minus = ch=='-';
	i=0;
	if (ch=='-' || ch=='+') {
// ��������� ������ ��� ������������ ������
		InputString[i++] = ch;
		cin.get(ch); // ������ �����
	}
	cout << "\n�������������� �����10 � ������";
	short int zifra; // ���������� ���������� ��������� �������
// ���� ��������� ������� ����
	is10Digit=((ch>='0'&&ch<='9'));
	while (is10Digit) {
// ���������� ���� ������ ����� 10-����� �������
		InputString[i++] = ch; //��������� ������
// ������ ����������� � �����
		if (ch>='0' && ch<='9') zifra=ch-48;
// ����� �������� �� ��������� ������� ���������
// � ��������� �������� ����� (����� �������)
		chislo = chislo*10+zifra;
// ����������� �����
		cout << "\n\t������ - " << ch << ", ����� - " << zifra
		<< ", " << " - ����� " << chislo;
		cin.get(ch);
		is10Digit=((ch>='0'&&ch<='9'));
	}
// ������� ����
	if (minus) chislo = -chislo;
// ����� ���������� ������ �����
	cout << "\n���������"
	"\n\t�� ����� ������10: " << InputString
	<< "\n\t�� ������ �����10: " << chislo;
// ������ ����� -------------------------------------------------------
// ����� ����� ����������� � ������
	char OutputString[Len] {};
	cout << "\n\n�������� ��������������: �����10 � ������10";
	cout << "\n\t�� ����� �����: " << chislo;
	minus = chislo<0;
	chislo = abs(chislo);
// ����� ����� ��������, ������� � �������� �������
	i=0;
		do {
// ������� �� ������� ���� ��������� �����
	ostatok = chislo%10;
// ������� ���� ��������� �����
	chislo = chislo/10;
// ��������� �������� ������:
// ���������� ����� ����������� � ����������������
// ASCII-���� ������� 16� ������� ���������
	if (ostatok<=9) OutputString[i++] = ostatok+48;
	else OutputString[i++] = ostatok+55;
// ����������� �����
	cout << "\n\t��������� ����� - " << ostatok
	<< ", ����� - " << OutputString;
	}
	while (chislo!=0);
// ������� ����
	if (minus) OutputString[i]='-';
// ���������� ������� � �������� �������
	for (i=0; i<strlen(OutputString)/2; i++) {
		ch=OutputString[i];
		OutputString[i]=OutputString[strlen(OutputString)-1-i];
		OutputString[strlen(OutputString)-1-i]=ch;
	}
// ����� ���������� ������ �����
	cout << "\n�� ������ ������: " << OutputString;
	return 0;
}