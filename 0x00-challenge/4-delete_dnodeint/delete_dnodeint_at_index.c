#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - function prototype that
 * Deletes a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 *
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *temp;
	unsigned int m;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	m = 0;
	while (m < index && *head != NULL)
	{
		*head = (*head)->next;
		m++;
	}
	if (m != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (0 == index)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
		if (temp != NULL)
		{
			temp->prev = NULL;
		}
	}
	else
	{
		(*head)->prev->next = (*head)->next;
		free(*head);
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev;
		*head = saved_head;
	}
	return (1);
}
