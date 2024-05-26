#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * free_dlistint - function to Free a list
 *
 * @head: A pointer to the first element of the list
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *node;

    while (head)
    {
        node = head;
        head = head->next;
        free(node);
    }
}
