#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    int n;
    cin >> str >> n;
    for (int cnt = 0; cnt < n; ++cnt)
        cout << str;
    return 0;
}