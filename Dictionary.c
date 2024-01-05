#include <stddef.h>
#include <string.h>
#include <stdio.h>
#define HASHMAP_SIZE 64
#define HASHMAP_SIZE_LIST 1

/*esercizi
    ricerca
    rimozione
    chiave univoca
    refactor utilizzando le linked list (facoltativo)
    
  esercizi dizionari
    implementare chiave e valore
    tenere conto delle collisioni e espandere quando sono troppe (facoltativo)
*/




struct aiv_set_item
{
    const char *key;
    size_t key_len;
};

struct aiv_set
{
    struct aiv_set_item hashmap[HASHMAP_SIZE][HASHMAP_SIZE_LIST];
};

size_t djb33x_hash(const char *key, const size_t keylen)
{
    size_t hash = 5381;

    for (size_t i = 0; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }

    return hash;
}

void aiv_set_insert(struct aiv_set *set, const char *key)
{
    const size_t key_len = strlen(key);

    const size_t hash = djb33x_hash(key, key_len);

    const size_t index = hash % HASHMAP_SIZE;

    printf("hash of %s = %llu (index: %llu)\n", key, hash, index);

    if(key_len <= 0)
    {
        printf("Key must have at least 1 char");
        return;
    }

    for (size_t i = 0; i < HASHMAP_SIZE_LIST; i++)
    {
        if(set->hashmap[index][i].key == key)
        {
            printf("Key %s already in Set", key);
            return;
        }

        if (set->hashmap[index][i].key_len == 0)
        {
            
            set->hashmap[index][i].key = key;
            set->hashmap[index][i].key_len = key_len;
            printf("added %s at index %llu slot %llu\n", key, index, i);
            return;
        }
    }

    printf("COLLISION! for %s (index %llu)\n", key, index);
}

_Bool aiv_set_find(struct aiv_set *set, const char *key)
{
    const size_t key_len = strlen(key);

    const size_t hash = djb33x_hash(key, key_len);

    const size_t index = hash % HASHMAP_SIZE;

    printf("hash of %s = %llu (index: %llu)\n", key, hash, index);

    if(key_len <= 0)
    {
        printf("Key must have at least 1 char");
        return 0;
    }

    for (size_t i = 0; i < HASHMAP_SIZE_LIST; i++)
    {
        if (set->hashmap[index][i].key_len == key_len && !memcmp(set->hashmap[index][i].key, key, key_len))
        {
            printf("FOUND %s at index %llu slot %llu\n", key, index, i);
            return 1;
        }
    }
    printf("!FOUND %s \n", key);
    return 0;
}

void aiv_set_remove(struct aiv_set *set, const char *key)
{
    const size_t key_len = strlen(key);
    const size_t hash = djb33x_hash(key, key_len);
    const size_t index = hash % HASHMAP_SIZE;
    printf("hash of %s = %llu (index: %llu)\n", key, hash, index);

    if(key_len <= 0)
    {
        printf("Key must have at least 1 char");
        return;
    }
    size_t i;
    for(i = 0; i < HASHMAP_SIZE_LIST; i++)
    {
        if(set->hashmap[index][i].key_len == key_len && !memcmp(set->hashmap[index][i].key, key, key_len))
        {
            set->hashmap[index][i] = set->hashmap[index][i + 1];
        }
    }
    for(; i < HASHMAP_SIZE_LIST - 1; i++)
    {
        if(set->hashmap[index][i].key_len == key_len && !memcmp(set->hashmap[index][i].key, key, key_len))
        {
            set->hashmap[index][i] = set->hashmap[index][i + 1];
        }
    }
}


int main(int argc, char **argv)
{
    struct aiv_set myset;
    memset(&myset, 0, sizeof(struct aiv_set));
    /*
    myset.hashmap[0].key = NULL;
    myset.hashmap[0].key_len = 0;
    myset.hashmap[1].key = NULL;
    myset.hashmap[1].key_len = 0;
    myset.hashmap[2].key = NULL;
    myset.hashmap[2].key_len = 0;*/

    aiv_set_insert(&myset, "Hello");
    aiv_set_insert(&myset, "Hello2");
    aiv_set_insert(&myset, "Test");
    aiv_set_insert(&myset, "Foobar");
    aiv_set_insert(&myset, "XYZ");
    aiv_set_insert(&myset, "AAAAAA");
    aiv_set_insert(&myset, "AAAAAa");
    aiv_set_insert(&myset, "AAAAAa");

    aiv_set_find(&myset, "XYZ");
    aiv_set_find(&myset, "x");

    return 0;
}