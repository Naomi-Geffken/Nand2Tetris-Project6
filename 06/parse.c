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

#define L_COMMAND 1
#define A_COMMAND 2
#define C_COMMAND 3


int parseSymbols(char* in, int lineNumber){
 if (commandType(in)=="L_COMMAND")   //if (commandType(in)==1)
     return lineNumber+1;
 else{  //command is a label
     insertKey(symbolMap, in, lineNumber);
     
 }
    
}

int parseLine(char* in, char* out){  // (lineRaw, lineBinary)
    if (commandType(in)== L_COMMAND){
       out= parseLCommand(in);
       return out;
    }
    else if(commandType(in)== A_COMMAND){
        out=parseACommand(in);
        return out;
    }
    else if (commandType(in)==C_COMMAND){
        out=parseCCommand(in);
        return out;  
    }
    else{
        return 0;
    }//empty lines, comments, etc
}

int commandType(char* in){
    char* L = "(";
    char* A = "@";
    char* C = '=';
 
    if (strstr(in, L)!=NULL){
        return L_COMMAND;
    }
    else if (strstr(in, A)!=NULL){
        return A_COMMAND;
    }
    else if (strstr(in, C)!=NULL){
        return C_COMMAND;
    } else {
        return 0;
	}
}

int parseACommand(char* in){ // turn A_Command into binary representation
    return 0;
}

<<<<<<< Updated upstream
int parseCCommand(int* in){ // turn C_command into binary representation
    
    return 0;
=======
int parseCCommand(char* in){ // turn C_command into binary representation
    char* temp_in = in;
    char* jmp;
    jmp = strchr(in, ";");
    // opcode + 00
    // break in into 2-3 parts
    // break into dest nn


    // break into comp
    // break into jump

    // call code.c corresponding binary
    // return binary

	int init_size = strlen(str);
	char delim[] = {"=",";"};

	char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		ptr = strtok(NULL, delim);
	}

	dest();
	printf("\n");

	return 0;
>>>>>>> Stashed changes
}

int parseLCommand(char*in){ // turn into binary representation
   return 0;
}


