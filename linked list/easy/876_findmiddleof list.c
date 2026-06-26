/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
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
    head=temp;
    return head;
}