#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> sumOfSub;
    int len = elements.size();
    
    // elements 배열을 두 배로 확장하여 원형 배열을 처리
    vector<int> extendedElements = elements;
    extendedElements.insert(extendedElements.end(), elements.begin(), elements.end());
    
    // 부분합의 길이를 1부터 len까지 처리
    for (int subLen = 1; subLen <= len; subLen++) {
        for (int start = 0; start < len; start++) {
            // 슬라이딩 윈도우를 이용하여 부분합 계산
            int sum = 0;
            for (int i = start; i < start + subLen; i++) {
                sum += extendedElements[i];
            }
            sumOfSub.insert(sum);
        }
    }
    
    return sumOfSub.size();
}