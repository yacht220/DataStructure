/*
 * Hash table implementation for separate chaining.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 11 // Prime number

struct ListNode
{
    int key;
    ListNode* next;
};

struct HashTable
{
    int tableSize;
    ListNode** table;
};

int hashFunc(int key)
{
    return key % HASH_TABLE_SIZE; 
}

void initializeHashTable(HashTable& hashTbl)
{
    hashTbl.tableSize = HASH_TABLE_SIZE; 
    hashTbl.table = (ListNode**)malloc(sizeof(ListNode*) * hashTbl.tableSize);
    for(int i = 0; i < hashTbl.tableSize; i++)
    {
        hashTbl.table[i] = NULL;
    }
}

ListNode* findPosInHashTable(const HashTable* hashTbl, int key)
{
    int posInTable = hashFunc(key);
    ListNode* targetNode = hashTbl->table[posInTable];
    if(NULL == targetNode)
    {
        printf("Key %d. Position %d in hash table is empty.\n", key, posInTable);
        return targetNode;
    }

    while(NULL != targetNode && key != targetNode->key)
    {
        targetNode = targetNode->next;
    }

    if(NULL != targetNode)
    {
        printf("Target FOUND with key %d.\n", key);
    }
    else
    {
        printf("Nothing found with key %d.\n", key);
    }

    return targetNode;
}

void insertElemInHashTable(HashTable* hashTbl, int key)
{
    ListNode* targetNode = findPosInHashTable(hashTbl, key);
    if(NULL == targetNode)
    {
        int posInTable = hashFunc(key);
        targetNode = (ListNode*)malloc(sizeof(ListNode));
        targetNode->key = key;
        if(NULL == hashTbl->table[posInTable])
        {
            printf("Insert an element with key %d in hash table position %d, WITHOUT collision.\n", 
                    key, posInTable);
            hashTbl->table[posInTable] = targetNode;
            targetNode->next = NULL;
        }
        else
        {
            printf("Insert an element with key %d in hash table position %d, WITH collision.\n",
                    key, posInTable);
            targetNode->next = hashTbl->table[posInTable];
            hashTbl->table[posInTable] = targetNode;
        }
    }
}

void deleteElemInHashTable(HashTable* hashTbl, int key)
{
    ListNode* targetNode = findPosInHashTable(hashTbl, key);
    if(NULL != targetNode)
    {
        int posInTable = hashFunc(key);
        ListNode* prevNode = hashTbl->table[posInTable];
        if(prevNode == targetNode)
        {
            printf("Position %d in hash table contains only one element with key %d in list. Delete this element.\n", posInTable, key);
            free(targetNode);
            hashTbl->table[posInTable] = NULL;
            return;
        }

        while(key != prevNode->next->key)
        {
            prevNode = prevNode->next;
        }
        printf("Delete an element with key %d.\n", key);
        prevNode->next = targetNode->next;
        free(targetNode);
    }
}

int main(int argc, char** argv)
{
    int keySet[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};
    int sizeOfKeySet = sizeof(keySet) / sizeof(keySet[0]);
    HashTable hashTbl;
    initializeHashTable(hashTbl);
    for(int i = 0; i < sizeOfKeySet; i++)
    {
        insertElemInHashTable(&hashTbl, keySet[i]);    
    }

    for(int i = 0; i < sizeOfKeySet; i++)
    {
        findPosInHashTable(&hashTbl, keySet[i]);
    }

    findPosInHashTable(&hashTbl, 11);

    for(int i = 0; i < sizeOfKeySet; i++)
    {
        deleteElemInHashTable(&hashTbl, keySet[i]);
    }

    for(int i = 0; i < sizeOfKeySet; i++)
    {
        findPosInHashTable(&hashTbl, keySet[i]);
    }

    return 1;
}
