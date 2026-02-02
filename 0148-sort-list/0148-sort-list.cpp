class Solution {
public:
    // Find node BEFORE middle
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1) temp->next = list1;
        else temp->next = list2;

        return dummy.next;
    }

  
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* mid = findMiddle(head);

        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left, right);
    }
};
