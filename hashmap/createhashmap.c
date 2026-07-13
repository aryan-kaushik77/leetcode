#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 101

// Node structure
struct Node
{
    int key;
    int value;
    struct Node *next;
};

// Hash table
struct Node *table[TABLE_SIZE];

// Initialize hash table
void initialize()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

// Hash function
int hash(int key)
{
    if (key < 0)
        key = -key;

    return key % TABLE_SIZE;
}

// Insert or Update
void insert(int key, int value)
{
    int index = hash(key);

    struct Node *temp = table[index];

    // Update if key already exists
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }

    // Create new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];

    table[index] = newNode;
}

// Search
struct Node *search(int key)
{
    int index = hash(key);

    struct Node *temp = table[index];

    while (temp != NULL)
    {
        if (temp->key == key)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

// Delete
void deleteKey(int key)
{
    int index = hash(key);

    struct Node *curr = table[index];
    struct Node *prev = NULL;

    while (curr != NULL)
    {
        if (curr->key == key)
        {
            if (prev == NULL)
                table[index] = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

// Print hash table
void printTable()
{
    printf("\nHash Table\n");
    printf("------------------------------\n");

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != NULL)
        {
            printf("[%d] -> ", i);

            struct Node *temp = table[i];

            while (temp != NULL)
            {
                printf("(%d,%d)", temp->key, temp->value);

                if (temp->next != NULL)
                    printf(" -> ");

                temp = temp->next;
            }

            printf("\n");
        }
    }

    printf("------------------------------\n");
}

// Free memory
void freeTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct Node *temp = table[i];

        while (temp != NULL)
        {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }

        table[i] = NULL;
    }
}

int main()
{
    initialize();

    // Insert elements
    insert(5, 100);
    insert(15, 200);
    insert(25, 300);
    insert(106, 400);   // Collision with key 5
    insert(207, 500);   // Collision with key 5

    printTable();

    // Search
    int key = 106;

    struct Node *result = search(key);

    if (result != NULL)
        printf("\nKey %d found with value %d\n", result->key, result->value);
    else
        printf("\nKey not found\n");

    // Update
    insert(25, 999);

    printf("\nAfter Updating Key 25\n");

    printTable();

    // Delete
    deleteKey(15);

    printf("\nAfter Deleting Key 15\n");

    printTable();

    freeTable();

    return 0;
}'''