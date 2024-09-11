#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int stand;

bool compare(string a, string b) {
    if (a[stand] == b[stand]) return a < b;
    return a[stand] < b[stand];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    stand = n;
    
    sort(strings.begin(), strings.end(), compare);
    
    return strings;
}