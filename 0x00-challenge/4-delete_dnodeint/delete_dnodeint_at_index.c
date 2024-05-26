#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;
    for (i = 0; current != NULL && i < index; i++)
    {
        current = current->next;
    }

    if (current == NULL) /* Index out of range */
        return (-1);

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next; /* Update head if needed */

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return (1);
}
