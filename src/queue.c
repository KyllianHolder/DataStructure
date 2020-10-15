/* 
 * File:   array_list.c
 * Author: Kyllian
 *
 */
#include "queue.h"

/**
 * Initialise la file
 * @author Kyllian Holder
 * @param s Queue
 */
void init_queue(Queue *s)
{
    s->index = -1;
}

/**
 * ajout de données
 * @author Kyllian Holder
 * @param q Queue
 * @param value Valeur a ajouter
 */
void enqueue(Queue *q, float value)
{
    q->index++;
    q->data[q->index] = value;
}

/**
 * récupération des données
 * @author Kyllian Holder
 * @param q Queue
 * @param value Valeur a ajouter
 * @return renvoie la valeur a l'avant de la file
 */
float dequeue(Queue *q)
{
    float donnee = q->data[0];
    float temp;
    float temp2;
    while (q->index > 0)
    {
        temp = q->data[q->index-1];
        q->data[q->index-1] = q->data[q->index];
        q->index--; //probleme
        
    }
    return donnee;
}

/**
 * Verifie si la file est vide
 * @author Kyllian Holder
 * @param q Queue
 * @return True si la queue est vide
 */
bool is_queue_empty(Queue *q)
{
    if (q->index==-1)
    {
        return true;
    }
    else return false; 
    
}

/**
 * renvoie la valeur a l'avant de la file
 * @author Kyllian Holder
 * @param q Queue
 * @return valeur a l'avant de la file
 */
float front(Queue *q) //aka peek
{
    return q->data[0];
}

void clearQ(Queue *q)
{
    init_queue(q);
}