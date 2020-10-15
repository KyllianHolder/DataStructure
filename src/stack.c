/* 
 * File:   stack.c
 * Author: Kyllian
 *
 */


#include "stack.h"


/**
 * Fonction d'initialisation de la pile
 * @author Kyllian Holder
 * @param s Pointeur sur la sructure s
 */
void init_stack(Stack *s)
{
    s->index = -1;
    
}
/**
 * Empile les données sur la pile
 * @author Kyllian Holder
 * @param s Pile
 * @param value valeur a ajouter a la pile
*/
void push(Stack *s, float value) {
    s->index++;
    s->data[s->index] = value;
    
    
}
/**
 * Renvoie la derniere valeur de la pile et la supprime de la pile
 * @author Kyllian Holder
 * @param s Pile
 */
float pop(Stack *s)
{
    float value = s->data[s->index];
    s->index--;
    return value;
}

/**
 * Verifie si la pile est vide
 * @author Kyllian Holder
 * @param s Pile
 * @return true si la pile est vide
 */
bool is_stack_empty(Stack *s)
{
    if (s->index = -1)
    {
        return true;
    }
    else return false;
    
}

/**
 * Renvoie la derniere valeur de la pile sans la supprimer
 * @author Kyllian Holder
 * @param s Pile
 */
float peek(Stack *s) // aka top or front
{
    float value = s->data[s->index];
    return value;
}

/**
 * Dupplique le sommet de la pile
 * @author Kyllian Holder
 * @param s Pile
 */
void dup(Stack *s)
{
    float value = s->data[s->index];
    push(s , value);
}

/**
 * Echange les deux valeurs au sommet de la pile
 * @author Kyllian Holder
 * @param s Pile
 */
void swap(Stack *s)
{
    float value1 = s->data[s->index];
    pop(s);
    float value2 = s->data[s->index];
    pop(s);
    push(s, value1);
    push(s, value2);
}

void clear(Stack *s)
{
    init_stack(s);
    
}