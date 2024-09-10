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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head;
        ListNode* ans = head;
        
        while (head->next != nullptr) {
            head = head->next;
            ListNode* gcdNode = new ListNode();
            gcdNode->val = gcd(prev->val, head->val);
            prev->next = gcdNode;
            gcdNode->next = head;
            prev = head;
        }
        
        return ans;
    }
};