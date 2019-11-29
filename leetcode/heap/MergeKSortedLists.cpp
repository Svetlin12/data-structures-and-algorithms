/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct compare
{
    bool operator()(ListNode* l1, ListNode* l2)
    {   
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = (int)lists.size();
        int i = 0;
        priority_queue<ListNode*, vector<ListNode*>, compare> sorted;
    
        while (i++ != size)
        {
            if (lists[i - 1])
                sorted.push(lists[i - 1]);
        }
        
        ListNode* start = nullptr, *tmp;
        while (!sorted.empty())
        {
            ListNode* newNode = sorted.top();
            sorted.pop();
            
            if (newNode->next)
                sorted.push(newNode->next);
            
            if (!start)
                start = newNode;
            else
                tmp->next = newNode;
            
            tmp = newNode;
        }
        return start;
    }
};
