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
    ListNode *detectCycle(ListNode *head) {
        ListNode *low=head;
        ListNode *high =head;
        bool flag=false;
        while(high!=NULL&& high->next !=NULL){
            low=low->next;
            high=high->next->next;
            if(low==high){
                flag =true;
                break;
            }
        }
if(!flag) return NULL;

 low=head;
while(low!=high){
    low=low->next;
    high=high->next;
}
return low;


    }
};