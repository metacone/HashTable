

#define MEMSIZE		(20000)
#define HASHSIZE	(100)
#define STRINGSIZE	(20)

struct NODE
{
	char *Data;
	NODE *Prev;
	int NextNum;
};




void InitMemoryPool();
void InitHashTable();
void* func_malloc();
bool func_Enroll(const char *EnrollData);
NODE* func_search(int HashKey, char *FindData);
void func_free(int HashKey);