class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length and tail
        int len = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Reduce unnecessary rotations
        k %= len;

        if (k == 0)
            return head;

        // Make the list circular
        tail->next = head;

        // Find the new tail (len - k - 1 steps from head)
        ListNode* newTail = head;
        for (int i = 1; i < len - k; i++) {
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }
};