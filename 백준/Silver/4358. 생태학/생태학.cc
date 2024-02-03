#include <iostream>
#include <map>
#include <string>
#define endl "\n"

using namespace std;

map<string, int> trees;

int main () {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    float treeCnt = 0;
    while (getline(cin, s)) {
        trees[s]++;
        treeCnt++;
    }

    // output
    cout << fixed;
    cout.precision(4);
    for (auto iter:trees) {
        float averTree = (iter.second / treeCnt) * 100;
        cout << iter.first << " " << averTree << endl;
    }

    return 0;
}
