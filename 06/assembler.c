//
//  assemble.c
//  06
//
//  Created by Chandra Adhikari on 4/13/20.
//  Copyright © 2020 Chandra Adhikari. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include <string.h>

//#include "parse.c"


//maybe global in here?
//

//global variable,
map compMap=NULL;
map jumpMap=NULL;
map symbolMap=NULL;
map destMap=NULL;

int parseSymbols(char*, char*);
int parseLine(char*, char*);
int parseACommand(char* in);
char parseCCommand(char* in);
void initJumpMap();
void initCompMap();
void initDestMap();
int containsKey(map aMap, char *searchKey);
void trim(char*);
int ParseC(char* in);

int main(int argc, const char **argv) {    //./assembler add.asm add.hack
    
    
    const char* inF=argv[1];
    const char* outF=argv[2];
    
    FILE * inFile= fopen(inF, "r"); //creating a input file in a read mode
    FILE * outFile= fopen(outF, "w"); //creating a output file and write there

    
    destMap=createMap(10);
    compMap=createMap(30); //new maps and no value inside it
    jumpMap=createMap(10);
    symbolMap=createMap(1000);

    initJumpMap();
    initCompMap();
    initDestMap();

    const char str[] = "0;JMP";
    char outC[255];
    
    //outC=ParseC(str);
    //parseLine(str,outC);

    //printf("outC is: %s", outC);

    parseLine(str,outC);
    //first step is to go into a file, and create a symbol table of that file
    //fputs(out3, outFile); //maybe I need to add '\0' at the end of the line??
    //fputs("\0",outFile);
    
    char lineRaw[200]; //assumptions that the line we read is less than 200 characters
    //has a new line
    
    char lineOut[200];
    char lineBinary[17];
    
    fgets(lineRaw, 200, inFile);//reads one strings from a file ;  output destination with the maximum value, and inputfile
    printf("lineRaw: [%s]", lineRaw);
    trim(lineRaw);
    printf("lineRaw: [%s]", lineRaw);
    
    int LineNumber=0 ;   //line number associates to that label
    
    while(!feof(inFile)){ //feof gives the end of end file 
         //make the first pass and find all labels.
         parseSymbols(lineRaw, LineNumber); // put the label in the symbolsdMap wih line number
         //if C or A instruction, increment LineNumber
         fgets(lineRaw, 200, inFile);
    } //done with the first pass;
    //at the end of inFile
    
    fseek(inFile,0, SEEK_SET);
    //now we can do the second pass
    
    fgets(lineRaw, 200, inFile);
    
    while(!feof(inFile)){
         if(parseLine(lineRaw, lineBinary)){ //lineRaw= " M+1
         //--->101001010000// binary equivalent    }
         fputs(lineBinary, outFile); //maybe I need to add '\0' at the end of the line??
         fputs('\0',outFile);
         }
         else continue;
         //second pass
        
    }
    fclose(inFile);
    fclose(outFile);
    
    
    freeMap(compMap);
    freeMap(jumpMap);
    // freeMap(symbolMap);
    return 0;
}
