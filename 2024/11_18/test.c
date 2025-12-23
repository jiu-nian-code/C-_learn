#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<string.h>

#include<stdlib.h>


 struct Node {
     int val;
     struct Node *next;
    struct Node *random;
};
 


struct Node* buynewnode(int x)
{
    struct Node* newnode = calloc(1, sizeof(struct Node));
    newnode->val = x;
    return newnode;
}

struct Node* copyRandomList(struct Node* head) {
    if (!head)
    {
        return NULL;
    }
    struct Node* newlist = calloc(1, sizeof(struct Node));
    struct Node* curr1 = head;
    struct Node* curr2 = newlist;
    struct Node* prev = NULL;
    while (curr1)
    {
        prev = curr1;
        curr2->next = buynewnode(curr1->val);
        curr1 = curr1->next;
        prev->next = curr2->next;
        curr2->next->random = prev;
        curr2 = curr2->next;
    }
    curr2 = newlist->next;
    while (curr2)
    {
        if (curr2->random->random != NULL)
        {
            curr2->random = curr2->random->random->next;
        }
        else
        {
            curr2->random = NULL;
        }
        curr2 = curr2->next;
    }
    return newlist->next;
}

int main()
{
    struct Node* a = calloc(1, sizeof(struct Node));
    struct Node* b = calloc(1, sizeof(struct Node));
    struct Node* c = calloc(1, sizeof(struct Node));
    struct Node* d = calloc(1, sizeof(struct Node));
    struct Node* e = calloc(1, sizeof(struct Node));
    struct Node* f = calloc(1, sizeof(struct Node));

    a->val = 3;
    b->val = 3;
    c->val = 3;
    d->val = 1;
    e->val = 3;
    f->val = 4;

    a->next = b;
    b->next = c;
    //c->next = d;
    //d->next = e;
    //e->next = f;

    a->random = NULL;
    b->random = a;
    c->random = NULL;
    //d->random = NULL;
    //e->random = NULL;
    //f->random = NULL;
    //d->next = e;
    //e->next = f;

    copyRandomList(a);
    return 0;
}