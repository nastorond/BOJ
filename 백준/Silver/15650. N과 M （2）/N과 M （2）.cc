#include <iostream>
using namespace std;

int n, m;
int nums[9];
bool visited[9];


void backTrack(int num, int cnt){
    if (cnt == m){
        for(int i=0;i<m;i++){
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    for(int i=num; i<=n; i++){
        if(!visited[i]){
            visited[i]=true;
            nums[cnt]=i;
            backTrack(i+1, cnt+1);
            visited[i]=false;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> n >> m;

    backTrack(1, 0);

    return 0;
}