#include <iostream>
using namespace std;

int main(){
    int n = 25;
    for ( ; n>=0; n--){
        cout << char(n+'A') << ' ' << n+'A' << "\n";
    }
    cin.get();
}