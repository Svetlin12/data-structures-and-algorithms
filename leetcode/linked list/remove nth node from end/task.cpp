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
    int sizeList(ListNode* head)
    {
        int sz = 0;
        ListNode* tmp = head;
        while (tmp != nullptr)
        {
            sz++;
            tmp = tmp->next;
        }
        return sz;
    }
    
    void removeFromHead(ListNode*& head)
    {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = sizeList(head);
        if (size == 1)
        {
            delete head;
            head = nullptr;
            return head;
        }
        
        int index = size - n;
        
        if (index == 0)
        {
            removeFromHead(head);
            return head;
        }
        
        int counter = 0;
        ListNode* tmp = head;
        while (counter++ != index - 1)
            tmp = tmp->next;
        
        ListNode* toDelete = tmp->next;
        tmp->next = toDelete->next;
        delete toDelete;
        
        return head;
    }
};
