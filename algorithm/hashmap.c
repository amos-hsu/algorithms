#include "uthash.h"

typedef struct TagHashEntry {
    int key;
    int val;
    UT_hash_handle hh;
} HashEntry;

typedef int bool;
#define true (bool)1
#define false (bool)0

HashEntry* FindHash(HashEntry** hashMap, int k)
{
    HashEntry* entry = NULL;
    HASH_FIND_INT(*hashMap, &k, entry);
    return entry;
}

bool AddHash(HashEntry** hashMap, int k, int v)
{
    HashEntry* entry = NULL;
    HASH_FIND_INT(*hashMap, &k, entry);
    if (entry == NULL) {
        HashEntry* p = (HashEntry*)malloc(sizeof(HashEntry));
        p->key = k;
        p->val = v;
        HASH_ADD_INT(*hashMap, key, p);
        return true;
    } else {
        entry->val = v;
        return false;
    }     
}

void DeleteHash(HashEntry** hashMap) {  
    HashEntry *current_HashEntry, *tmp;  
    HASH_ITER(hh, *hashMap, current_HashEntry, tmp) {  
        HASH_DEL(*hashMap,current_HashEntry);    
        free(current_HashEntry);              
    }  
}
