/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int middleNode(struct ListNode* head) {
    int count=0;
    int index=0;
    struct ListNode *current=head;
    while (current!=NULL){
        count++;
        current=current->next;
}   
    if (count%2==0){
        index=count/2;
    }
    else{
        index=count/2;
    }
    struct ListNode *temp=head;
    printf("%d,%d",count,index);
    for(int i=0;i<index;i++){
        temp=temp->next;
        
    }
    
    return index;
}
struct ListNode* deleteMiddle(struct ListNode* head) {
    int index=middleNode(head);
    struct ListNode* prev=NULL;
    struct ListNode* current1=head;
    if (head->next==NULL){
        return NULL;
    }
    for(int i=0;i<index;i++){
        prev=current1;
        current1=current1->next;
    }
    prev->next=current1->next;
    free(current1);
    return head;
}