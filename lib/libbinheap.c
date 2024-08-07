#include<stdio.h>
#include<malloc.h>
#include"libbinheap.h"


typedef int key_t;
typedef unsigned int value_t;

binheap_t *binheap_new (unsigned int initial_data_size)
{
	binheap_t *target = (binheap_t *) malloc (sizeof (binheap_t));
	target->data = (pair_t *) malloc (sizeof (pair_t) * (1 + initial_data_size));
	target->data_size = 1 + initial_data_size;
	target->size = 0;
	return target;
}

void binheap_delete (binheap_t *target)
{
	if (target)
	{
		if (target->data)
			free (target->data);

		free (target);
	}
}

void binheap_checkup (binheap_t *target, unsigned int c)
{
	unsigned int p;

	for (p = c / 2; p > 0 ; c = p, p = c / 2)
	{
		if (target->data[p].key > target->data[c].key)
		{
			pair_t tmp = target->data[p];
			target->data[p] = target->data[c];
			target->data[c] = tmp;
		}
		else
			break;
	}
}

void binheap_checkdown (binheap_t *target, unsigned int p)
{
	unsigned int c;

	for (c = 2 * p ; c <= target->size ; p = c, c = 2 *p)
	{
		if (c + 1 <= target->size && target->data[c + 1].key < target->data[c].key)
			c++;

		if (target->data[c].key < target->data[p].key)
		{
			pair_t tmp;
			tmp = target->data[c];
			target->data[c] = target->data[p];
			target->data[p] = tmp;
		}
		else
			break;
	}
}


void binheap_add (binheap_t *target, pair_t v)
{
	if (target->size + 1 >= target->data_size)
	{
		target->data_size *= 2;
		target->data = (pair_t *) realloc (target->data, target->data_size * sizeof (pair_t));
	}

	target->data[ ++ (target->size) ] = v ;
	binheap_checkup (target, target->size);
}

int binheap_extract_min (binheap_t *target, pair_t *v)
{
	if (target->size == 0)
		return 0;

	*v = target->data[1];
	target->data[1] = target->data[ (target->size)--];
	binheap_checkdown (target, 1);
	return 1;
}
