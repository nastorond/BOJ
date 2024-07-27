#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<0>(a) < get<0>(b)) 
        return true;
    else if (get<0>(a) == get<0>(b)) {
        if (get<1>(a) > get<1>(b))
            return true;
        else
            return false;
    }
    return false;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    // 새롭게 정렬된 벡터
    vector<vector<int>> sorted_data;
    // 정렬 기준으로 삼을 데이터
    vector<tuple<int, int, int>> standard_for_sort;
    // S_i 값들을 저장할 데이터
    vector<int> S_i;
    
    for (int i=0; i<data.size(); i++) {
        standard_for_sort.push_back(make_tuple(data[i][col-1], data[i][0], i));
    }
    
    // 정렬 col 기준으로 오름차순, 기본키를 기준으로 내림차순 정렬
    sort(standard_for_sort.begin(), standard_for_sort.end(), compare);
    
    // 정렬한 데이터를 기준으로 3번 로직 수행
    for (int i=row_begin-1; i!=row_end; i++) {
        int idx = get<2>(standard_for_sort[i]), tmp = 0;
        
        for (int j=0; j<data[idx].size(); j++) {
            tmp += data[idx][j] % (i+1);
        }
        S_i.push_back(tmp);
    }
    
    // 4번 로직
    if (S_i.size() == 1) return S_i[0];
    else {
        int tmp = S_i[0];
        for (auto it=S_i.begin()+1; it!=S_i.end(); it++) {
            tmp = tmp ^ *it;
        }
        answer = tmp;
    }
    
    return answer;
}