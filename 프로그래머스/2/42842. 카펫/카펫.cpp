#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    if (brown == 8) return {3, 3};
    
    brown -= 4;
    int x=brown/2, y=brown/2;
    if (x%2) {
        x++;
        y--;
    }
    x/=2;
    y/=2;
    while (y>0) {
        if (x*y == yellow) return {x+2, y+2};
        else {
            x++;
            y--;
        }
    }
    
    return {x+2, y+2};
}