#include "array_list.h"

/**
 * Initialise l'array list
 * @author Kyllian Holder
 * @param l Liste
 */
void init_array_list(Array_list *l)
{
    l->index = -1;
}
/**
 * Insere la valeur value a la position spécifiée
 * @author Kyllian Holder
 * @param l Liste
 * @param position Position ou ajouter la valeur
 * @param value Valeur a ajouter a la liste
 */
void insert_at(Array_list *l, int position, float value)
{
    float tempVal;
    for (int i = l->index+1 ; i > position ; i--)
    {
        l->data[i] = l->data[i-1];
    }
    
    l->data[position] = value;
    l->index++;
}
/**
 * Ajoute une valeur a la fin de l'array list
 * @author Kyllian Holder
 * @param l Liste
 * @param value Valeur a ajouter a la liste
 */
void add(Array_list *l, float value)
{
    l->index++;
    l->data[l->index] = value;
}
/**
 * Supprime l'element à la position choisie et decale la liste en conscequence et renvoie la valeur supprimée
 * @author Kyllian Holder
 * @param l Liste
 * @param position Position de la valeur a supprimer
 * @return Renvoie la valeur supprimée 
 */
float remove_at(Array_list *l, int position)
{
    float tempVal = l->data[position];
    for (int i = position; i <= l->index; i++)
    {
        l->data[i] = l->data[i+1];
    }
    l->index--;
    return tempVal;
}
/**
 * recupère la valeur a la position sans la modifier ou la supprimer
 * @author Kyllian Holder
 * @param l Liste
 * @param position Position de la valeur a recuperer
 * @return Valeur à la position choisie
 */
float get_at(Array_list *l,int position)
{
    return l->data[position];
}
/**
 * Vide l'array list
 * @author Kyllian Holder
 * @param l Liste
 */
void clearA(Array_list *l)
{
    for (int i = l->index; i >= 0 ; i--)
    {
        remove_at(l, i);
    }
    init_array_list(l);
    
}
