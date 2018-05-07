
#include "HashTable.h"


#include <stdlib.h>
#include <string.h>

int MemoryPoolIndex		= 0;
int MemoryPoolLastIndex = 0;

struct NODE MemoryPool[MEMSIZE];
NODE* apHashTable[HASHSIZE];

void InitMemoryPool()
{
	for (int nPoolCnt = 0; nPoolCnt < MEMSIZE; nPoolCnt++)
	{
		if (MEMSIZE == (nPoolCnt + 1))
		{
			// Memory의 마지막은 자기 자신을 가리킨다
			MemoryPool[nPoolCnt].NextNum = nPoolCnt;
			MemoryPoolLastIndex = nPoolCnt;
			break;
		}
		MemoryPool[nPoolCnt].NextNum = nPoolCnt + 1;
	}
}

// Search Init Hash Table
void InitHashTable()
{
	for (int nPoolCnt = 0; nPoolCnt < HASHSIZE; nPoolCnt++)
	{
		apHashTable[nPoolCnt] = NULL;
	}
}


// Search Malloc
void* func_malloc()
{
	int NextMemoryPoolIndex = MemoryPool[MemoryPoolIndex].NextNum;
	int AllocMemoryPoolIndex = MemoryPoolIndex;

	MemoryPoolIndex = NextMemoryPoolIndex;
	return &(MemoryPool[AllocMemoryPoolIndex]);
}


// Enroll Hash Table
bool func_Enroll(const char *EnrollData)
{
	// Get Key: 구현 필요함
	int GetKey = 0;

	NODE* GetMemory = (NODE*)func_malloc();
	
	// Data 복사
	int nStringSize = strnlen(EnrollData, STRINGSIZE);
	GetMemory->Data = (char*)malloc(sizeof(char) * nStringSize + 1);
	strncpy_s(GetMemory->Data, sizeof(char) * nStringSize + 1, EnrollData, STRINGSIZE);

	// Hash Table List Up
	GetMemory->Prev = apHashTable[GetKey];
	apHashTable[GetKey] = GetMemory;

	return true;
}


// Search Function
NODE* func_search(int HashKey, char *FindData)
{
	NODE* SearchHash = apHashTable[HashKey];

	int nFindDataIndex = 0;
	
	while (SearchHash != NULL)
	{
		do
		{
			if (*((SearchHash->Data) + nFindDataIndex) != *(FindData + nFindDataIndex))
			{
				break;
			}
			nFindDataIndex++;
		} while (*(FindData + nFindDataIndex) != '\0');

		SearchHash = SearchHash->Prev;
	}
	return NULL;
}

void func_free(int HashKey)
{
	if (MemoryPool[MemoryPoolLastIndex].NextNum == MemoryPoolLastIndex)
	{
		// List 정리 by HashKey


		// Release된 메모리를 MemoryPool 마지막에 연결
		NODE *ReleaseMemory = NULL;
		MemoryPool[MemoryPoolLastIndex].NextNum = ReleaseMemory->NextNum;
		MemoryPoolLastIndex = ReleaseMemory->NextNum;

		// 마지막은 자신 스스로를 가리킨다.
		MemoryPool[MemoryPoolLastIndex].NextNum = MemoryPoolLastIndex;
	}
	else
	{
		// Error
		while (1);
	}
}

