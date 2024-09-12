#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> hashing;
    
    for (int i=0; i<arr1.size(); i++) {
        hashing.push_back(arr1[i] | arr2[i]);
    }
    
    for (int num : hashing) {
        string tmp = "";
        
        while (num>0) {
            if (num%2==0) {
                tmp = " " + tmp;
            } else{
                tmp = "#" + tmp;
            }
            num/=2;
        }
        if (tmp.size() < n) {
            tmp.insert(0, n-tmp.size(), ' ');
        }
        answer.push_back(tmp);
    }
    
    
    return answer;
}