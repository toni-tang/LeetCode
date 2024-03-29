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
    void reorderList(ListNode* head) {
        if(!head) return;
        
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast->next) slow = slow->next;
        
        ListNode* prev = NULL;
        while(slow)
        {
            fast = slow->next;
            slow->next = prev;
            prev = slow;
            slow = fast;
        }
        slow = prev;
        
        ListNode* temp = head;
        while(temp && slow)
        {
            fast = temp->next;
            prev = slow->next;
            temp->next = slow;
            slow->next = fast;
            temp = fast;
            slow = prev;
        }
        
        if(temp && temp->next) temp->next->next = NULL;
    }
};