#include<stdio.h>
#include<malloc.h>
typedef int key_t;
typedef unsigned int value_t;

typedef struct
{
	key_t key;
	value_t value;
} pair_t ;

typedef struct
{
	pair_t *data;
	unsigned int size;
	unsigned int data_size;
} binheap_t;

binheap_t *binheap_new (unsigned int initial_data_size);
void binheap_delete (binheap_t *target);
void binheap_checkup (binheap_t *target, unsigned int c);
void binheap_checkdown (binheap_t *target, unsigned int p);
void binheap_add (binheap_t *target, pair_t v);
int binheap_extract_min (binheap_t *target, pair_t *v);
