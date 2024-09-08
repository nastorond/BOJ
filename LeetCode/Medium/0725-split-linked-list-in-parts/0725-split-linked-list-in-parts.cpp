/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ret(k, nullptr);
        
        ListNode* curNode = head;
        int len = 0;
        while (curNode != nullptr) {
            curNode = curNode->next;
            len++;
        }
        
        int cnt = len > k ? len%k : 0, arrLen=len/k;
        
        curNode = head;
        for (int i=0; i<k && i<len; i++) {
            int counting=1;
            
            ListNode* nextNode=curNode;
            while (counting < arrLen && nextNode != nullptr) {
                nextNode = nextNode->next;
                counting++;
            }
            if (cnt>0 && nextNode != nullptr) {
                nextNode = nextNode->next;
                cnt--;
            }
            
            ret[i]=curNode;
            curNode = nextNode != nullptr ? nextNode->next : nextNode;
            nextNode != nullptr ? nextNode->next=nullptr : 0;
        }
        
        return ret;
    }
};