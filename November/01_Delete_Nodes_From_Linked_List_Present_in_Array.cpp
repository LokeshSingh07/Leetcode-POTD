// 3217. Delete Nodes From Linked List Present in Array

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
        set<int> se(begin(nums), end(nums));
 
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        ListNode* temp = head;

        while(temp){
            if(!se.count(temp->val)){
                curr->next = temp;
                curr = curr->next;
            }
            temp = temp->next;
        }
        curr->next = nullptr;

        return dummy->next;
    }
};