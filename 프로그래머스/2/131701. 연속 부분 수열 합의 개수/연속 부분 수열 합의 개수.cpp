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

    // 누적 합 배열 생성
    vector<int> prefixSum(2 * len + 1, 0);
    for (int i = 1; i <= 2 * len; i++) {
        prefixSum[i] = prefixSum[i - 1] + extendedElements[i - 1];
    }
    
    // 부분합 계산
    for (int subLen = 1; subLen <= len; subLen++) {
        for (int start = 0; start < len; start++) {
            int sum = prefixSum[start + subLen] - prefixSum[start];
            sumOfSub.insert(sum);
        }
    }
    
    return sumOfSub.size();
}