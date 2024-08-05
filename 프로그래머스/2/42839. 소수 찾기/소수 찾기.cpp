#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
#define MAXN 10000003

using namespace std;

bool primes[MAXN], already_checked[MAXN] = {false, }, visited[7];
int res=0;

void init_primes() {
    fill(primes, primes+MAXN, true);
    primes[0] = false;
    primes[1] = false;
    for (int i=2; i<pow(MAXN, 0.5); i++) {
        for (int j=i*i; j<MAXN; j+=i) primes[j] = false;
    }
}

void init () {
    for (int i=0; i<7; i++) visited[i] = false;
}

void dfs (string numbers, string tmp, int depth, int mlen) {
    if (depth == mlen) {
        if (primes[stoi(tmp)] && !already_checked[stoi(tmp)]) {
            already_checked[stoi(tmp)] = true;
            res++;
        }
        cout << mlen << " " << tmp << "\n";
    }
    for (int i=0; i<numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(numbers, tmp+numbers[i], depth+1, mlen);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    
    init_primes();
    
    for (int i=1; i<numbers.size()+1; i++) {
        init();
        dfs(numbers, "", 0, i);
    }
    
    return res;
}