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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* start=head->next;
        ListNode* curr=head;
        ListNode* ans=curr;
        int sum=0;
        while(start!=NULL)
        {
            if(start->val==0)
            {
                ListNode *d=new ListNode();
                d->val=sum;
                sum=0;
                curr->next=d;
                curr=curr->next;
                
            }
            else
            {
                sum+=start->val;
            }
            start=start->next;
        }
        return head->next;
    }
};