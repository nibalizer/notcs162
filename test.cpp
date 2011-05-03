#include <iostream>

using namespace std;

int main(){
    char temp[80];
    cout << "\n";
    cout << ">";
    cin.get(temp,80);
    cout << temp << endl;
    int i;
    for (i=0; temp[i] != '\0'; i++){
        if ('a' <= temp[i] ){
        cout << temp[i] << endl;
        }
    }
}

