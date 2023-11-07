#include "secondheader.h"

/**
 * add_rvar - adds a variable at the end
 * of a r_var list.
 * @head: head of the linked list.
 * @Ivap: length of the variable.
 * @var: value of the variable.
 * @ival: length of the value.
 * Return: address of the head.
 */
r_var *add_rvar(r_var **head, int Ivap, char *var, int ival)
{
	r_var *str_new, *lis_temp;

	str_new = malloc(sizeof(r_var));
	if (str_new == NULL)
		return (NULL);

	str_new->variable_length = Ivap;
	str_new->value = var;
	str_new->value_length = ival;

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
 * free_rvar - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar(r_var **head)
{
	r_var *lis_temp;
	r_var *steph_curr;

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
