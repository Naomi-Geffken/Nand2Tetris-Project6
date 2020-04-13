
// map.h
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


#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED


#define STR_LENGTH 26

typedef struct {
    char *key;
    char *value;
} stringpair;

typedef struct {
    int mapSize;
    int maxSize;
    stringpair* pairs;
}  mapstruct;

typedef mapstruct* map;



// function definitions

map createMap(int maxSize) ;
void freeMap(map currentMap);
int containsKey(map aMap, char *searchKey);
char* lookupIndex(map aMap, int i) ;
char* lookupKey(map aMap, char *searchKey);
int insertKey(map aMap, char* key, char *value);


#endif
