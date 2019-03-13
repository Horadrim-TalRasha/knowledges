#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <unistd.h>

#define List(Type) \
typedef struct ListNode_##Type    \
{                                 \
    Type * type_;                 \
    struct ListNode_##Type * next;   \
} ListNode_##Type;                \
\
typedef struct List_##NodeType  \
{                               \
    ListNode_##Type * _head;    \
    ListNode_##Type * _tail;    \
    unsigned int _size;         \
} List_##Type;                  \
\
void init_list(List_##Type * list)              \
{                                               \
    __sync_lock_test_and_set(&list->_size, 0);  \
    list->_head = NULL;                         \
    list->_tail = NULL;                         \
}                                               \
\
void insert_from_tail(List_##Type * list, ListNode_##Type * node)  \
{                                                                  \
    if(list->_head == NULL)                                        \
    {                                                              \
        list->_head = node;                                        \
        list->_tail = node;                                        \
        __sync_add_and_fetch(list->_size, 1);                      \
        return;                                                    \
    }                                                              \
}


#endif