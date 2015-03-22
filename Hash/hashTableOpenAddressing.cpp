/*
 * Hash table implementation for open addressing.
 */

#include <stdio.h>
#include <stdlib.h>

const unsigned int gc_hashTableSize = 19; // Prime number

struct HashTableEntry
{
    int key;
    bool isOccupied;
};

struct HashTable
{
    int size;
    HashTableEntry* table;
};

unsigned int hashFunc(int key)
{
    return (unsigned int)(key % gc_hashTableSize);
}

void initializeHashTable(HashTable& hashTbl)
{
    hashTbl.size = gc_hashTableSize;
    hashTbl.table = (HashTableEntry*)malloc(sizeof(HashTableEntry) * gc_hashTableSize);
    for (int it = 0; it < hashTbl.size; it++)
    {
        hashTbl.table[it].isOccupied = false;
    }
}

/**
 * @brief Find the position in hash table for a given key.
 *
 * @param hashTbl - Hash table
 * @param key - A given key
 *
 * @return Position index in hash table
 */
unsigned int findPosInHashTable(const HashTable& hashTbl, int key)
{
    unsigned int pos = hashFunc(key);
    unsigned int collisionNum = 1;
    while (true == hashTbl.table[pos].isOccupied &&
           hashTbl.table[pos].key != key)
    {
        printf("Key %d collides in pos %d.\n", key, pos);
        pos += collisionNum * collisionNum;
        collisionNum++;
        if (pos >= hashTbl.size)
        {
            pos -= hashTbl.size;
        }
    }
    return pos;
}

void insertElemInHashTable(HashTable& hashTbl, int key)
{
    unsigned int pos = findPosInHashTable(hashTbl, key);
    if (false == hashTbl.table[pos].isOccupied)
    {
        hashTbl.table[pos].isOccupied = true;
        hashTbl.table[pos].key = key;
    }
    else if (key == hashTbl.table[pos].key)
    {
        printf("Key %d exists in pos %d of hash table.\n", key, pos);
    }
}

void deleteElemInHashTable(HashTable& hashTbl, int key)
{
    unsigned int pos = findPosInHashTable(hashTbl, key);
    if (true == hashTbl.table[pos].isOccupied)
    {
        hashTbl.table[pos].isOccupied = false;
    }
    else
    {
        printf("Key %d does NOT exist in pos %d of hash table.\n", key, pos);
    }
}

int main(int argc, char** argv)
{
    int keySet[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};
    unsigned int sizeOfKeySet = sizeof(keySet) / sizeof(keySet[0]);
    HashTable hashTbl;
    initializeHashTable(hashTbl);
    
    for (int i = 0; i < sizeOfKeySet; i++)
    {
        insertElemInHashTable(hashTbl, keySet[i]);
    }

    for (int i = 0; i < sizeOfKeySet; i++)
    {
        /* 
         * BUG!!
         * Can not delete some keys since the positions which are hit during finding at very begining could be empty
         * due to deletions beforehand.
         */
        deleteElemInHashTable(hashTbl, keySet[i]);
    }

    return 1;
}
