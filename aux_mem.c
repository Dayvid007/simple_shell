#include "header.h"
#include "secondheader.h"

/**
 * _memorycpy - This program copies
 * information between void pointers.
 * @newpointer: The destination pointer.
 * @pointer: The source pointer.
 * @size: size of the new pointer.
 * Return: no return.
 */

void _memorycpy(void *newpointer, const void *pointer, unsigned int size)
{
	char *char_pointer = (char *)pointer;
	char *char_newpointer = (char *)newpointer;
	unsigned int a = 0;

	while (a < size)
	{
		char_newpointer[a] = char_pointer[a];
		a++;
	}
}

/**
 * _reallocate - This program reallocates a memory block.
 * @point: This is pointer to the memory previously allocated.
 * @prevs_size:  This size, in bytes, of the allocated space of ptr.
 * @nw_size: This new size, in bytes, of the new memory block.
 *
 * Return: point.
 * if nw_size == prevs_size, returns point without changes.
 * if malloc fails, returns NULL.
 */

void *_reallocate(void *point, unsigned int prevs_size, unsigned int nw_size)
{
	void *newpointer;

	if (point == NULL)
		return (malloc(nw_size));

	if (nw_size == 0)
	{
		free(point);
		return (NULL);
	}

	if (nw_size == prevs_size)
		return (point);

	newpointer = malloc(nw_size);
	if (newpointer == NULL)
		return (NULL);

	if (nw_size < prevs_size)
		_memorycpy(newpointer, point, nw_size);
	else
		_memorycpy(newpointer, point, prevs_size);

	free(point);
	return (newpointer);
}

/**
 * _realocdp - This program reallocates a memory block of a double pointer.
 * @point: This double pointer to the memory
 * previously allocated.
 * @prevs_size: This size, in bytes, of the allocated space of ptr.
 * @nw_size: nw size, in bytes, of the new memory block.
 * Return: point.
 * if nw_size == prevs_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */

char **_realocdp(char **point, unsigned int prevs_size, unsigned int nw_size)
{
	char **newpointer;
	unsigned int a = 0;

	if (point == NULL)
		return (malloc(sizeof(char *) * nw_size));

	if (nw_size == prevs_size)
		return (point);

	newpointer = malloc(sizeof(char *) * nw_size);
	if (newpointer == NULL)
		return (NULL);

	while (a < prevs_size)
	{
		newpointer[a] = point[a];
		a++;
	}
	free(point);

	return (newpointer);
}
