/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reverseList(ListNode*& head)
    {
        ListNode* next = nullptr, *previous = nullptr, *current = head;
        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tmp1 = l1, *tmp2 = l2;
        while (tmp1 != nullptr && tmp2 != nullptr)
        {
            ListNode* tmp;
            if (tmp1->val > tmp2->val)
            {
                tmp = new ListNode(tmp2->val);
                tmp2 = tmp2->next;
            }
            else
            {
                tmp = new ListNode(tmp1->val);
                tmp1 = tmp1->next;
            }
            tmp->next = head;
            head = tmp;
        }
        
        while (tmp1 != nullptr)
        {
            ListNode* tmp = new ListNode(tmp1->val);
            tmp->next = head;
            head = tmp;
            tmp1 = tmp1->next;
        }
        
        while (tmp2 != nullptr)
        {
            ListNode* tmp = new ListNode(tmp2->val);
            tmp->next = head;
            head = tmp;
            tmp2 = tmp2->next;
        }
        
        reverseList(head);
        return head;
    }
};
