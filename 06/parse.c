#include <stdio.h>
#include <stdlib.h>
#include "map.h"

#include <string.h>
#include <math.h>

#define L_COMMAND 1
#define A_COMMAND 2
#define C_COMMAND 3


//map symbolMap=NULL;
extern map symbolMap;

int parseSymbols(char* in, int lineNumber){
    //symbolMap=createMap(1000);
    if (commandType(in)=="L_COMMAND")   //if (commandType(in)==1)
        return lineNumber+1;
    else{  //command is a label
        insertKey(symbolMap, in, lineNumber);

    }
        return 0;
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
    // Isolate everythin after @ symbol
    // const char str[] = "chandra@21";
   const char ch = '@';
   char *ret;
   int binary;
    int bin_A;
   int i = 0;

   ret = strchr(in, ch);
   char **ret2 = (ret + 1);
   int val = atoi(ret +1);
   // printf("String after |%c| is - |%s|\n", ch, (ret2));
   
   // convert val to binary and return val.
   while (val > 0){
        binary = val % 2;
        bin_A += binary * pow(10, i);
        val = val / 2;
        i++;
   }
    return bin_A;
}

int parseCCommand(char* in){ // turn C_command into binary representation
    char* temp_in = in;

    // opcode + 00
    // break in into 2-3 parts
    // call code.c corresponding binary
    // return binary
char *str = in;
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
}

int parseLCommand(char*in){ // turn into binary representation
   return 0;
}
