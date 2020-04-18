
// map.c
//
// This is a basic map data structure for key, value pairs of strings.
// Simplicity is favored over efficiency. Map lookups use linear search.
//
//
// Code for Clark University CSCI 140 assignments.
//
// Author: John Magee
// Date: 10/5/2017
// Version 1.0
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"



// Allocates a map data structure and an array of key,value pairs
// up to the max size provided.
//
// The memory allocated by this method can be freed by calling the freeMap() method
map createMap(int maxSize) {
    int i;
   
    // Allocate memory for the main struct and initialize values
    map newmap =  (map) malloc(sizeof(mapstruct));
    newmap->maxSize = maxSize;
    newmap->mapSize = 0;

    // allocate memory for the key, value pairs
    newmap->pairs = (stringpair *) malloc(maxSize * sizeof(stringpair));
    
    // Ensure that each key and value is currently NULL
    for(i = 0; i < maxSize; i++) {
        newmap->pairs[i].key = NULL;
        newmap->pairs[i].value = NULL;
    }

    // return a pointer to the newly allocated map
    return newmap;
}


// freeMap
// Frees the memory allocated by createMap
// Also frees any strings allocated within insertKey
void freeMap(map currentMap) {
     
    if(currentMap == NULL) {
       return;
    }

    int i;


    // delete any strings stored within the map
    // CAUTION: Any strings copied by pointer will be destroyed!
    for(i = 0; i < currentMap->maxSize; i++) {
         if(currentMap->pairs[i].key != NULL)
            free(currentMap->pairs[i].key);

         if(currentMap->pairs[i].value != NULL)
            free(currentMap->pairs[i].value);
    }

    // delete the array of pairs
    free(currentMap->pairs);

    // delete the map itself
    free(currentMap);

}


// containsKey method
// If the key is found, returns its index
// otherwise returns -1 if the key is not found
//
int containsKey(map aMap, char *searchKey) {
    // printf("inside contains key, search key is: %s\n", searchKey);
    int i;
    // linear search for the key
    for(i=0; i < aMap->mapSize; i++) {
        // printf("inside containsKey for-loop\n");
        if(strcmp(aMap->pairs[i].key, searchKey) == 0) {
            // key is found at location i
            // printf("inside containsKey, key found!\n");
            return i;
        }
    }
    // printf("inside containsKey, key NOT found!\n");
    // not found, return -1
    return -1;
}


// lookupIndex method
// lookupIndex is intended to be used with the containsKey method.
// If an index is already known, the value can be returned directly without
// searching through the whole array.
char* lookupIndex(map aMap, int i) {
    return aMap->pairs[i].value;
}


// lookupKey
// If the key is found, returns the associated value string
// otherwise returns NULL if the key is not found
//
char* lookupKey(map aMap, char *searchKey) {
    // printf("inside lookupKey \n");
    int index = containsKey(aMap, searchKey);
    // printf("inside lookupKey--after index, index is %d \n", index);
    if(index >= 0 ) {
        // printf("inside lookupKey: in if-statement \n");
        return lookupIndex(aMap, index);
    } else {
        // printf("inside lookupKey: in else-statement \n");
        return NULL;
    }
    // printf("inside lookupKey: end of method \n");
}




// insertKey
// Inserts a key into a map
int insertKey(map aMap, char* key, char *value) {
    if(aMap->mapSize < aMap->maxSize) {

        aMap->pairs[aMap->mapSize].key = (char *) malloc(STR_LENGTH * sizeof(char));
        aMap->pairs[aMap->mapSize].value = (char *) malloc(STR_LENGTH * sizeof(char));
    strcpy(aMap->pairs[aMap->mapSize].key, key);
    strcpy(aMap->pairs[aMap->mapSize].value, value);
        aMap->mapSize++;

        return 1;
    }

    fprintf(stderr, "Warning: map full, last insert failed!\n");
    return 0;





}
