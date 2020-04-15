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





//global variable,
map compMap=NULL;
map jumMap=NULL;
// symbolMap=NULL;
map despMap=NULL;

int parseSymbols(char*, char*);
int parseLine(char*, char*);

int main(int argc, const char **argv) {    //./assembler add.asm add.hack
    printf("start of file");
    const char* inF=argv[1];
    const char* outF=argv[2];
    
    FILE * inFile= fopen(inF, "r"); //creating a input file in a read mode
    FILE * outFile= fopen(outF, "w"); //creating a output file and write there

    
    despMap=createMap(10);
    compMap=createMap(30); //new maps and no value inside it
    jumMap=createMap(10);
    // symbolMap=createMap(1000);
    
    //first step is to go into a file, and create a symbol table of that file
    
    char lineRaw[200]; //assumptions that the line we read is less than 200 characters
    //has a new line
    
    char lineOut[200];
    char lineBinary[17];
    
    fgets(lineRaw, 200, inFile);//reads one strings from a file ;  output destination with the maximum value, and inputfile
    
    
    int LineNumber=0 ;   //line number associates to that label
    
    while(!feof(inFile)) { //feof gives the end of end file
        
        //make the first pass and find all labels.
        printf("we're in the first pass");
        parseSymbols(lineRaw, LineNumber); // put the label in the symbolsdMap wih line number
        //if C or A instruction, increment LineNumber
        fgets(lineRaw, 200, inFile);    
    } 
    printf("finished w/ first pass");
    //done with the first pass;
    //at the end of inFile
    
    fseek(inFile,0, SEEK_SET);
    //now we can do the second pass
    
    fgets(lineRaw, 200, inFile);
    printf("about to enter second pass");

    while(!feof(inFile)){
        printf("we're in the second pass");

        if(parseLine(lineRaw, lineBinary)){ //lineRaw= " M+1
        //--->101001010000// binary equivalent    }
        fputs(lineBinary, outFile); //maybe I need to add '\0' at the end of the line??
        fputs("\0",outFile);
        }
        else continue;
        //second pass
    }
    fclose(inFile);
    fclose(outFile);
    
    freeMap(despMap);
    freeMap(compMap);
    freeMap(jumMap);
    // freeMap(symbolMap);
    return 0;
}
