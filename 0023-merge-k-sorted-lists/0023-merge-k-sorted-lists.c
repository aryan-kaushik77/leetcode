/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct MinHeap {
    struct ListNode **arr;
    int size;
    int capacity;
};

void swap(struct ListNode **a, struct ListNode **b) {
    struct ListNode *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap *h, int i) {

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->arr[left]->val < h->arr[smallest]->val)
        smallest = left;

    if (right < h->size && h->arr[right]->val < h->arr[smallest]->val)
        smallest = right;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

void insert(struct MinHeap *h, struct ListNode *node) {

    int i = h->size;

    h->arr[i] = node;
    h->size++;

    while (i != 0 && h->arr[(i - 1) / 2]->val > h->arr[i]->val) {

        swap(&h->arr[i], &h->arr[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

struct ListNode *extractMin(struct MinHeap *h) {

    if (h->size == 0)
        return NULL;

    if (h->size == 1) {
        h->size--;
        return h->arr[0];
    }

    struct ListNode *root = h->arr[0];

    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    heapify(h, 0);

    return root;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    if (listsSize == 0)
        return NULL;

    struct MinHeap *heap = (struct MinHeap *)malloc(sizeof(struct MinHeap));

    heap->arr = (struct ListNode **)malloc(sizeof(struct ListNode *) * listsSize);
    heap->size = 0;
    heap->capacity = listsSize;

    // Insert first node of every non-empty list
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL)
            insert(heap, lists[i]);
    }

    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode *tail = &dummy;

    while (heap->size != 0) {

        struct ListNode *minNode = extractMin(heap);

        tail->next = minNode;
        tail = tail->next;

        if (minNode->next != NULL)
            insert(heap, minNode->next);
    }

    tail->next = NULL;

    free(heap->arr);
    free(heap);

    return dummy.next;
}