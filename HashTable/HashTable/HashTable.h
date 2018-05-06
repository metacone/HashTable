#include<stdio.h>

#define MEMSIZE		(20000)
#define HASHSIZE	(100)

struct NODE
{
	char *Data;
	NODE *Prev;
};


struct NODE MemoryPool[MEMSIZE];
int MemoryPoolList[MEMSIZE];

NODE(*apHashTable)[HASHSIZE];

void* func_malloc();