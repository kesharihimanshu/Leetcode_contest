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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* h=head;
        int a=0;
        while(h)
        {
            a++;
            h=h->next;
        }
        int u=a-k+1;
        if(u==k)
            return head;
        h=head;
        int i=0;
        if(k>u)
            swap(k,u);
        while(h)
        {
           i++;
            if(i==k)
            {
               break; 
            }
            h=h->next;
        }
        ListNode* y=h;
       i--;
         while(y)
        {
           i++;
            if(i==u)
            {
               break; 
            }
           y=y->next;  
        }
        swap(h->val,y->val);
        return head;
        
    }
};