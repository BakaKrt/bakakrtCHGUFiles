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
// Первая часть -------------------------------------------------------
// строку преобразуем в число
	cout << "Введите 10-ичное целое со знаком: ";
// Первый символ может быть знак
	cin.get(ch);
	minus = ch=='-';
	i=0;
	if (ch=='-' || ch=='+') {
// формируем строку для контрольного вывода
		InputString[i++] = ch;
		cin.get(ch); // читаем цифру
	}
	cout << "\nПреобразование числа10 в строку";
	short int zifra; // десятичный эквивалент введённого символа
// Пока поступают символы цифр
	is10Digit=((ch>='0'&&ch<='9'));
	while (is10Digit) {
// Обработать один символ цифры 10-ичной системы
		InputString[i++] = ch; //формируем строку
// символ преобразуем в число
		if (ch>='0' && ch<='9') zifra=ch-48;
// Число умножить на основание системы счисления
// и прибавить значение цифры (схема Горнера)
		chislo = chislo*10+zifra;
// контрольный вывод
		cout << "\n\tсимвол - " << ch << ", цифра - " << zifra
		<< ", " << " - число " << chislo;
		cin.get(ch);
		is10Digit=((ch>='0'&&ch<='9'));
	}
// Добавим знак
	if (minus) chislo = -chislo;
// Вывод результата первой части
	cout << "\nРезультат"
	"\n\tНа входе строка10: " << InputString
	<< "\n\tНа выходе число10: " << chislo;
// Вторая часть -------------------------------------------------------
// целое число преобразуем в строку
	char OutputString[Len] {};
	cout << "\n\nОбратное преобразование: Число10 в строку10";
	cout << "\n\tНа входе число: " << chislo;
	minus = chislo<0;
	chislo = abs(chislo);
// Цифры числа получаем, начиная с младшего разряда
	i=0;
		do {
// Остаток от деления есть очередная цифра
	ostatok = chislo%10;
// Частное есть следующее число
	chislo = chislo/10;
// Формируем выходную строку:
// полученную цифру преобразуем к соответствующему
// ASCII-коду символа 16й системы счисления
	if (ostatok<=9) OutputString[i++] = ostatok+48;
	else OutputString[i++] = ostatok+55;
// контрольный вывод
	cout << "\n\tочередная цифра - " << ostatok
	<< ", число - " << OutputString;
	}
	while (chislo!=0);
// Добавим знак
	if (minus) OutputString[i]='-';
// Записываем символы в обратном порядке
	for (i=0; i<strlen(OutputString)/2; i++) {
		ch=OutputString[i];
		OutputString[i]=OutputString[strlen(OutputString)-1-i];
		OutputString[strlen(OutputString)-1-i]=ch;
	}
// Вывод результата второй части
	cout << "\nНа выходе строка: " << OutputString;
	return 0;
}