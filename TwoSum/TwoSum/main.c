//
//  main.c
//  TwoSum
//
//  Created by Yestay Muratov on 07.04.2023.
//

#include <stdio.h>
#include "stdlib.h"



#define SIZE 1000

struct DataItem {
    int index;
    int key;
};

int hashCode(int key) {
   return key % SIZE;
}

struct DataItem* hashArray[SIZE];
struct DataItem* hashArrayNegative[SIZE];

struct DataItem *search(int key) {
    int hashIndex = hashCode(key);
    
    while(hashArray[hashIndex] != NULL) {
        
        if (hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }
        
        hashIndex++;
        
        hashIndex %= SIZE;
    }
    
    return NULL;
}

struct DataItem *searchNegative(int key) {
    int hashIndex = hashCode(key * -1);
    
    while(hashArrayNegative[hashIndex] != NULL) {
        
        if (hashArrayNegative[hashIndex]->key == key) {
            return hashArrayNegative[hashIndex];
        }
        
        hashIndex++;
        
        hashIndex %= SIZE;
    }
    
    return NULL;
}

void insert(int key,int index) {
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->key = key;
    item->index = index;
    
    int hashIndex = hashCode(key);
   
    while (hashArray[hashIndex] != NULL) {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

void insertNegative(int key,int index) {
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->key = key;
    item->index = index;
    
    int hashIndex = hashCode(key * -1);
   
    while (hashArrayNegative[hashIndex] != NULL) {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArrayNegative[hashIndex] = item;
}

void freeHashTable() {
    for (int h = 0; h < SIZE; h++) {
        free(&hashArray[h]);
        free(hashArrayNegative[h]);
    }
}

int* twoSum(int* nums, int numsSize, int target){
    int *answer = (int *)malloc(sizeof(int) * 2);
    
    for (int i = 0; i<numsSize; i++) {
        int s1 = nums[i];
        int s2 = target - s1;
        struct DataItem *savedS2DataItem = s2 < 0 ? searchNegative(s2) : search(s2);
        
        if (savedS2DataItem) {
            answer[0] = savedS2DataItem->index;
            answer[1] = i;
            freeHashTable();
            break;
        } else {
            s1 < 0 ? insertNegative(s1, i) : insert(s1, i);
        }
    }
   
    return answer;
}

int main(int argc, const char * argv[]) {
   
    int nums[] = {0, -4, 10, 0 };
    
    int *result = twoSum(nums, 4, 6);
    
    for (int j =0 ; j< 2; j++)
        printf("%d ", result[j]);
    
    int nums2[] = { 3,2,4 };
    int *result2 = twoSum(nums2, 3, 6);

    for (int j =0 ; j< 2; j++)
        printf("%d ", result2[j]);
    
    return 0;
}
