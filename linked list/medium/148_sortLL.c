/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* left, struct ListNode* right) {

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    struct ListNode *head1;
    struct ListNode *tail;


    if (left->val <= right->val) {
        head1 = left;
        left = left->next;
    } else {
        head1 = right;
        right = right->next;
    }

    tail = head1;

    while (left != NULL && right != NULL) {

        if (left->val <= right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    // Attach the remaining list
    if (left != NULL)
        tail->next = left;
    else
        tail->next = right;

    return head1;
}
struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *mid=NULL;
    struct ListNode *slow=head;
    struct ListNode *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    mid=slow->next;
    slow->next=NULL;
    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(mid);

    return merge(left, right);
}