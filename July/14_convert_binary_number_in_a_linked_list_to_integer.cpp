// 1290. Convert Binary Number in a Linked List to Integer


// Approach-1 : (Two traversal)
class Solution {
public:
    ListNode* reverse(ListNode* &head){
        if(!head || !head->next) return head;

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    int getDecimalValue(ListNode* head) {
        long long result = 0;
        int power=0;

        ListNode* temp = reverse(head);
        while(temp){
            result += (temp->val * (1<<power));
            power++;
            temp = temp->next;
        }

        return (int)result;
    }
};



// Approach-2 : (one traversal)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int result = 0;

        while(temp){
            result = (result << 1) | (temp->val);
            temp = temp->next;
        }

        return result;
    }
};