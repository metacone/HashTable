#include<stdio.h>
#include "HashTable.h"


int main()
{
	InitMemoryPool();
	InitHashTable();
	func_Enroll("AAAA");
	func_Enroll("BAAA");
	func_Enroll("CAAA");
	func_Enroll("ADAA");
	func_Enroll("AAEA");
	func_Enroll("AAAF");

	return 0;
}