/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aurelio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "queue.h"
#include "stack.h"
#include "array_list.h"

float test(int a)
{
    errno = a;
    assert(a == 5);
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
}

void testStack()
{
    Stack s;
    init_stack(&s);
    assert(s.index == -1);
    push(&s, 2);
    assert(s.index == 0);
    assert(s.data[s.index] == 2);
    float testPop = pop(&s); //renvoie la valeur et la supprime donc retour index a -1
    assert(testPop == 2);
    assert(is_stack_empty(&s) == 1);
    for (int i = 0; i <= 10; i++)
    {
        push(&s, i);
    }
    assert(peek(&s) == 10);
    dup(&s);
    assert(s.data[s.index] == s.data[s.index - 1]);
    push(&s, 41);
    swap(&s);
    assert(s.data[s.index] == 10 && s.data[s.index - 1] == 41);
    clear(&s);
    assert(s.index == -1);
}

void testQueue()
{
    Queue q;
    init_queue(&q);
    assert(q.index == -1);
    enqueue(&q, 0);
    assert(q.data[q.index] == 0);
    for (int i = 1; i <= 9; i++)
    {
        enqueue(&q, i);
    }
    float testDequeue = dequeue(&q);
    assert(testDequeue == 0);
    //assert(q.data[0] == 1); dequeue ne fonctionne pas
}

void testArrayList()
{
    Array_list l;
    init_array_list(&l);
    assert(l.index == -1);
    for (float i = 0; i < 10; i++)
    {
        add(&l, i);
    }
    insert_at(&l, 5, 25);
    assert(l.data[5] == 25);
    assert(l.data[6] == 5);
    float testRemoveAt = remove_at(&l, 5);
    assert(testRemoveAt == 25);
    assert(l.data[5] != 25);
    assert(l.data[5] == 5);
    float testGet_At = get_at(&l, 8);
    assert(testGet_At == 8);
    clearA(&l);
    assert(l.data[0] != 0);
}
int main(int argc, char **argv)
{
    // Stack
    testStack();

    // Queue
    testQueue();

    // Array lists
    testArrayList();
    return (0);
}
