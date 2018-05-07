
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
			// Memory�� �������� �ڱ� �ڽ��� ����Ų��
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
	// Get Key: ���� �ʿ���
	int GetKey = 0;

	NODE* GetMemory = (NODE*)func_malloc();
	
	// Data ����
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
		// List ���� by HashKey


		// Release�� �޸𸮸� MemoryPool �������� ����
		NODE *ReleaseMemory = NULL;
		MemoryPool[MemoryPoolLastIndex].NextNum = ReleaseMemory->NextNum;
		MemoryPoolLastIndex = ReleaseMemory->NextNum;

		// �������� �ڽ� �����θ� ����Ų��.
		MemoryPool[MemoryPoolLastIndex].NextNum = MemoryPoolLastIndex;
	}
	else
	{
		// Error
		while (1);
	}
}

