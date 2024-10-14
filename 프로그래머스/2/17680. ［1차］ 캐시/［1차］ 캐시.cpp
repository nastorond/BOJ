#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

struct Node {
    string name;
    Node* next;
    Node* prev;
    
    Node () : name(""), next(nullptr), prev(nullptr) {}
};

Node* root = new Node;
Node* tmp = nullptr;
int listSize = 1;

bool isRecentlyUsed(string name) {
    Node* node = root;
    
    while (node != nullptr) {
        if (node->name == name) {
            tmp = node;
            return true;
        }
        node = node->next;
    }
    return false;
}

void updateList(int limitLen, string name) {
    Node* node = root;
    
    Node* newNode = new Node;
    newNode->name = name;
    
    while (node->next != nullptr) {
        node = node->next;
    }
    node->next = newNode;
    newNode->prev = node;
    listSize++;
    
    if (listSize > limitLen) {
        Node* first = root;
        root = root->next;
        root->prev = nullptr;
        listSize--;
        delete first;
    }
}

void moveNode() {
    // tmp가 마지막 노드일 경우 이동할 필요 없음
    if (tmp->next == nullptr) return;
    
    // tmp가 루트일 경우 처리
    if (tmp == root) {
        root = root->next;  // 두 번째 노드를 새로운 루트로 설정
        if (root != nullptr) {
            root->prev = nullptr;
        }
    } else {
        // tmp가 중간에 있을 경우 처리
        if (tmp->prev != nullptr) tmp->prev->next = tmp->next;
        if (tmp->next != nullptr) tmp->next->prev = tmp->prev;
    }
    
    Node* node = root;
    while (node->next != nullptr) {
        node = node->next;
    }

    node->next = tmp;
    tmp->prev = node;
    tmp->next = nullptr;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int len = cities.size();
    
    if (cacheSize == 0) return cities.size() * 5;
    
    for (int i = 0; i < len; i++) {
        for (char &c : cities[i]) {
            c = tolower(c);
        }
    }
    root->name = cities[0];
    answer += 5;
    
    for (int i = 1; i < len; i++) {
        if (isRecentlyUsed(cities[i])) {
            answer += 1;
            moveNode();
        } else {
            answer += 5;
            updateList(cacheSize, cities[i]); 
        }
    }
    
    return answer;
}
