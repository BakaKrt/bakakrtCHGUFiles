#include <iostream>
using namespace std;

int main(){
    char ch = 'a';
    for (int i = ch; i <= 'z'; i++)
        cout << char (i) << char (32) << i << "\n";
    cin.get();
}