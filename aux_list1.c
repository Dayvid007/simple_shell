#include "secondheader.h"

/**
 * add_sep_node - adds a separator found at the end
 * of a sep_list.
 * @head: head of the linked list.
 * @divide: separator found (; | &).
 * Return: address of the head.
 */
sep_list *add_sep_node(sep_list **head, char divide)
{
	sep_list *str_new, *lis_temp;

	str_new = malloc(sizeof(sep_list));
	if (str_new == NULL)
		return (NULL);

	str_new->divider = divide;
	str_new->next = NULL;
	lis_temp = *head;

	if (lis_temp == NULL)
	{
		*head = str_new;
	}
	else
	{
		while (lis_temp->next != NULL)
			lis_temp = lis_temp->next;
		lis_temp->next = str_new;
	}

	return (*head);
}

/**
 * free_sep_list - frees a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep(sep_list **head)
{
	sep_list *lis_temp;
	sep_list *steph_curr;

	if (head != NULL)
	{
		steph_curr = *head;
		while ((lis_temp = steph_curr) != NULL)
		{
			steph_curr = steph_curr->next;
			free(lis_temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node - adds a command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @straight_line: command line.
 * Return: address of the head.
 */
line_list *add_line_node(line_list **head, char *straight_line)
{
	line_list *str_new, *lis_temp;

	str_new = malloc(sizeof(line_list));
	if (str_new == NULL)
		return (NULL);

	str_new->straight_line = straight_line;
	str_new->next = NULL;
	lis_temp = *head;

	if (lis_temp == NULL)
	{
		*head = str_new;
	}
	else
	{
		while (lis_temp->next != NULL)
			lis_temp = lis_temp->next;
		lis_temp->next = str_new;
	}

	return (*head);
}

/**
 * free_line_list - frees a line_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line_list(line_list **head)
{
	line_list *lis_temp;
	line_list *steph_curr;

	if (head != NULL)
	{
		steph_curr = *head;
		while ((lis_temp = steph_curr) != NULL)
		{
			steph_curr = steph_curr->next;
			free(lis_temp);
		}
		*head = NULL;
	}
}
