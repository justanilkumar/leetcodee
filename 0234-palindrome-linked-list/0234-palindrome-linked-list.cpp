class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: find middle
        ListNode* low = head;
        ListNode* high = head;

        while (high != NULL && high->next != NULL) {
            low = low->next;
            high = high->next->next;
        }

        // Step 2: reverse second half
        ListNode* prev = NULL;
        ListNode* curr = low;

        while (curr != NULL) {
            ListNode* nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }

        // Step 3: compare
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
