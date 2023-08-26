#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for (int i; i<str.length(); ++i)
        if(str[i]>='A' && str[i]<='Z'){
            str[i] = tolower(str[i]);
        }
        else if(str[i]>='a' && str[i]<='z'){
            str[i] = toupper(str[i]);
        }
    cout << str;
    return 0;
}