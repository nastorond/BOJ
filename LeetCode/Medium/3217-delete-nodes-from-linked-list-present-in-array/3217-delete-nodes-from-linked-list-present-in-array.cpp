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
    
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> deleteNums;
        for (int num : nums) {
            deleteNums.insert(num);
        }
        
        ListNode* ans;
        ListNode* prev=head;
        bool flg = true;
        
        while (head != nullptr) {
            if (deleteNums.count(head->val) == 0) {
                if (flg) {
                    ans = head;
                    prev = head;
                    flg = false;
                }
                else {
                    prev->next = head;
                    prev = head;
                }
            }
            head = head->next;
            prev->next = nullptr;
        }
        return ans;
    }
};