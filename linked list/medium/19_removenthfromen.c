/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *current=head;
    int total=0;
    while(current!=NULL){
        total++;
        current=current->next;
    }
    int index=total-n;
    printf("%d,%d",index,total);
    current=head;
    if(index==0){
        if(current->next!=NULL){
            head=current->next;
            free(current);
            return head;
        }
        else{
            return NULL;
        }
    }
    struct ListNode *prev=NULL;
    for(int i=0;i<index;i++){
        prev=current;
        current=current->next;                      
    }
    prev->next=current->next;
    free(current);
    return head;

}