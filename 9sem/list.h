#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
    int value;
    struct node* next;
    struct node* prev;
};
typedef struct node Node;

struct list
{
    Node* head;
    Node* tail;
    size_t size;
};
typedef struct list List;

List init(size_t n) {
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    for (size_t i = 0; i < n; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = 0;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (list.head == NULL)
        {
            list.head = new_node;
            list.tail = new_node;
        }
        else
        {
            list.tail->next = new_node;
            new_node->prev = list.tail;
            list.tail = new_node;
        }
        list.size++;
    }
    return list;
}

void print(const List* pl) {
    Node* current = pl->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void push_back(List* pl, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = pl->tail;

    if (pl->tail != NULL) {
        pl->tail->next = new_node;
    }
    pl->tail = new_node;

    if (pl->head == NULL) {
        pl->head = new_node;
    }
    pl->size++;
}

int pop_back(List* pl) {
    if (pl->size <= 0)
    {
        fprintf(stderr, "Brain damage, no nodes.\n");
        exit(1);
    }
    int value = pl->tail->value;
    Node* old_tail = pl->tail;

    if (pl->size == 1)
    {
        pl->head = NULL;
        pl->tail = NULL;
    }
    else
    {
        pl->tail = pl->tail->prev;
        pl->tail->next = NULL;
    }
    pl->size--;
    free(old_tail);
    return value;
}

void push_front(List* pl, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = pl->head;
    new_node->prev = NULL;

    if (pl->head != NULL)
        pl->head->prev = new_node;
    pl->head = new_node;

    if (pl->tail == NULL)
        pl->tail = new_node;
    pl->size++;
}

int pop_front(List* pl) {
    assert(pl->size > 0);
    int value = pl->head->value;
    Node* old = pl->head;

    if (pl->size == 1)
    {
        pl->head = NULL;
        pl->tail = NULL;
    }
    else
    {
        pl->head = pl->head->next;
        pl->head->prev = NULL;
    }
    pl->size--;
    free(old);
    return value;
}

Node* erase(List* pl, Node* p) {
    if (p == pl->head && p == pl->tail)
    {
        pl->head = NULL;
        pl->tail = NULL;
        pl->size = 0;
        free(p);
        return NULL;
    }
    else if (p == pl->head)
    {
        pl->head = pl->head->next;
        pl->head->prev = NULL;
        pl->size--;
        free(p);
        return pl->head;
    }
    else if (p == pl->tail)
    {
        pl->tail = pl->tail->prev;
        pl->tail->next = NULL;
        pl->size--;
        free(p);
        return NULL;
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        pl->size--;
        free(p);
        return p->next;
    }
}

void splice(List* plist, Node* p, List* pother) {
    if (pother->size <= 0) {
        return;
    }
    if (p == NULL) {
        p = plist->head;
    }
    Node* other_tail = pother->tail;
    Node* other_head = pother->head;

    if (plist->head == NULL) {
        plist->head = other_head;
        plist->tail = other_tail;
    } else {
        other_tail->next = p;
        p->prev->next = other_head;
        other_head->prev = p->prev;
        p->prev = other_tail;
    }
    plist->size += pother->size;
    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void advance(Node** pp, size_t n) {
    Node* current = *pp;
    while (n > 0 && current != NULL) {
        current = current->next;
        n--;
    }
    *pp = current;
}

void destroy(List* pl) {
    Node* current = pl->head;
    size_t n = pl->size;
    for (size_t i = 0; i < n; i++)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}
