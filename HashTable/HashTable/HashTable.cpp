#ifndef _HASHTABLE_H_
#include "HashTable.h"
#endif

int MemoryPoolIndex		= 0;
int MemoryPoolLastIndex = 0;

void InitMemoryPool()
{
	for (int nPoolCnt = 0; nPoolCnt < MEMSIZE; nPoolCnt++)
	{
		if (MEMSIZE == (nPoolCnt + 1))
		{
			// Memory의 마지막은 자기 자신을 가리킨다
			MemoryPoolList[nPoolCnt] = nPoolCnt;
			MemoryPoolLastIndex = nPoolCnt;
			break;
		}
		MemoryPoolList[nPoolCnt] = nPoolCnt + 1;
	}
}


void* func_malloc()
{
	int NextMemoryPoolIndex = MemoryPoolList[MemoryPoolIndex];
	int AllocMemoryPoolIndex = MemoryPoolIndex;

	MemoryPoolIndex = NextMemoryPoolIndex;
	return &(MemoryPool[AllocMemoryPoolIndex]);
}

void func_free()
{


	if (MemoryPoolList[MemoryPoolLastIndex] == MemoryPoolLastIndex)
	{
	}
	else
	{
		// Error
		while (1);
	}
}

