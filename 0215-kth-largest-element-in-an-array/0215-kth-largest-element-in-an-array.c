#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct MinHeap
{
    int *arr;
    int size;
    int capacity;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap *h, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->arr[left] < h->arr[smallest])
        smallest = left;

    if (right < h->size && h->arr[right] < h->arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

void insert(struct MinHeap *h, int key)
{
    if (h->size == h->capacity)
        return;

    int i = h->size;
    h->arr[i] = key;
    h->size++;

    while (i != 0 && h->arr[(i - 1) / 2] > h->arr[i])
    {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int getMin(struct MinHeap *h)
{
    if (h->size == 0)
        return -1;

    return h->arr[0];
}

int extractMin(struct MinHeap *h)
{
    if (h->size == 0)
        return -1;

    if (h->size == 1)
    {
        h->size--;
        return h->arr[0];
    }

    int root = h->arr[0];

    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    heapify(h, 0);

    return root;
}

void decreaseKey(struct MinHeap *h, int i, int newValue)
{
    h->arr[i] = newValue;

    while (i != 0 && h->arr[(i - 1) / 2] > h->arr[i])
    {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteKey(struct MinHeap *h, int i)
{
    decreaseKey(h, i, INT_MIN);
    extractMin(h);
}

int findKthLargest(int *nums, int numsSize, int k)
{
    struct MinHeap *heap = (struct MinHeap *)malloc(sizeof(struct MinHeap));

    heap->arr = (int *)malloc(sizeof(int) * k);
    heap->size = 0;
    heap->capacity = k;

    // Insert first k elements
    for (int i = 0; i < k; i++)
    {
        insert(heap, nums[i]);
    }

    // Process remaining elements
    for (int i = k; i < numsSize; i++)
    {
        if (nums[i] > getMin(heap))
        {
            extractMin(heap);
            insert(heap, nums[i]);
        }
    }

    int ans = getMin(heap);

    free(heap->arr);
    free(heap);

    return ans;
}