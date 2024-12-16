#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    if (a == b) {
        cout << 0 << "\n";
        return 0;
    }
    b--;

    cout << b-a << "\n";
    while (a < b){
        cout << ++a << " ";
    }

    return 0;
}