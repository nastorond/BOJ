#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getPar(int set[], int x) {
    if(set[x] == x) return x;
    return set[x] = getPar(set, set[x]);
}

void unionPar(int set[], int a, int b) {
    a = getPar(set, a);
    b = getPar(set, b);
    
    if (a < b) set[b] = a;
    else set[a] = b;
}

int find(int set[], int a, int b) {
    a = getPar(set, a);
    b = getPar(set, b);
    if (a == b) return 1;
    else return 0;
}

class Edge {
public:
    int node[2];
    int dis;
    Edge(int a, int b, int dis) {
        this->node[0] = a;
        this->node[1] = b;
        this->dis = dis;
    }
    bool operator <(Edge &edge) {
        return this->dis < edge.dis;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<Edge> li;
    for (int i=0; i<costs.size(); i++) {
        li.push_back(Edge(costs[i][0], costs[i][1], costs[i][2]));
    }
    
    sort(li.begin(), li.end());
    
    int set[n];
    for (int i=0; i<n; i++) {
        set[i] = i;
    }
    
    for (int i=0; i<li.size(); i++) {
        if (!find(set, li[i].node[0], li[i].node[1])) {
            answer += li[i].dis;
            unionPar(set, li[i].node[0], li[i].node[1]);
        }
    }
    
    return answer;
}