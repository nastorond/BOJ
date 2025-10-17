#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for std::pair

// 무한대를 나타내는 값 (문제의 최대 비용보다 큰 값)
const int INF = 1e9;

int n, m;
int start, goal;

// 그래프를 인접 리스트로 표현
// gp[i]는 i번 노드에서 출발하는 간선들의 정보를 담고 있음
// 각 간선 정보는 {도착 노드, 비용} 형태의 pair로 저장
std::vector<std::pair<int, int>> gp[1001]; // 노드 최대 개수에 따라 조절

// 최단 거리 테이블
int distance[1001];

void find_cost(int start_node) {
    // 우선순위 큐(최소 힙) 선언. {비용, 현재 노드} 형태로 저장
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여 큐에 삽입
    pq.push({0, start_node});
    distance[start_node] = 0;

    while (!pq.empty()) {
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        // (더 짧은 경로를 이미 발견한 경우)
        if (distance[now] < cost) {
            continue;
        }

        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (const auto& edge : gp[now]) {
            int neighbor = edge.first;
            int edge_weight = edge.second;
            int add_cost = cost + edge_weight;

            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (add_cost < distance[neighbor]) {
                distance[neighbor] = add_cost;
                pq.push({add_cost, neighbor});
            }
        }
    }
}

int main() {
    // C++ 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;

    // 최단 거리 테이블을 모두 무한으로 초기화
    for (int i = 1; i <= n; ++i) {
        distance[i] = INF;
    }

    // 모든 간선 정보를 입력받기
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        gp[u].push_back({v, w});
    }

    std::cin >> start >> goal;

    // 다익스트라 알고리즘 수행
    find_cost(start);

    // 도착점까지의 최단 거리 출력
    std::cout << distance[goal] << "\n";

    return 0;
}