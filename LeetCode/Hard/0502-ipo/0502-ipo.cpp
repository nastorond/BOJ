class Solution {
public:  
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> li;
        
        for (int i=0; i<n; i++) {
            li.push_back(make_pair(capital[i], profits[i]));
        }
        
        sort(li.begin(), li.end());
        
        priority_queue<int> pq;
        
        int idx = 0;
        for(int j=0; j<k; j++) {
            while (idx < n && li[idx].first <= w) {
                pq.push(li[idx].second);
                idx++;
            }
            
            if (pq.empty()) break;
            
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};