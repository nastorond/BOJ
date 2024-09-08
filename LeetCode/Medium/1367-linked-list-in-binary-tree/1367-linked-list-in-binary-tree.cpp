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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool ret = false;
    
    void isAnswer (TreeNode* root, ListNode* head) {       
        if (root->val != head->val || ret) return;
        if (head->next == nullptr) {
            if (root->val == head->val) ret = true;
            return ;
        }
        
        if (root->left != nullptr) isAnswer(root->left, head->next);
        if (root->right != nullptr) isAnswer(root->right, head->next);
    }
    
    void findStartPoint (TreeNode* root, ListNode* head) {
        if (ret) return ;
        if (root->val == head->val) {
            isAnswer(root, head);
        }
        if (root->left != nullptr) findStartPoint(root->left, head);
        if (root->right != nullptr) findStartPoint(root->right, head);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        findStartPoint(root, head);
        
        return ret;
    }
};