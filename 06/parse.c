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
extern map destMap;
extern map jumpMap;
extern map compMap;

int parseSymbols(char* in, int lineNumber){
    //symbolMap=createMap(1000);
    if (commandType(in)=="L_COMMAND")   //if (commandType(in)==1)
        return lineNumber+1;
    else{  //command is a label
        insertKey(symbolMap, in, lineNumber);

    }
        return 0;
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
   int bin_A=0;
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

char parseCCommand(char* in){ // turn C_command into binary representation
    printf("inside parseCCommand! \n");
    //C-Instruction
    char DEST[255];
    char COMP[255];
    char JUMP[255];

    char temp1[255];
    for (int i = 2; i < strlen(in); i++) {
        temp1[i-2] = in[i];
    }
    printf("STILL inside parseCCommand! \n");
    if (in[1] == "=") {        //algorithim for reading after =
        strcpy(DEST, lookupKey(destMap, in[0]));
        strcpy(COMP, lookupKey(compMap, temp1));
        strcpy(JUMP, lookupKey(jumpMap, "null"));
        printf("inside if statement in parseCCommand! \n");
        char str[100];
        strcat(str,"111");
        strcat(str,DEST);
        strcat(str,COMP);
        strcat(str,JUMP);
        return str;

        //DEST = lookupKey(destmap, temp[0]);
        //COMP = lookupKey(compmap, temp1);
        //JUMP = lookupKey(jumpmap, "null");
        //return itoa("111" + COMP + DEST + JUMP);
        //sprintf()
    } else {  //algorithim for reading after ;
        printf("inside else statement in parseCCommand! \n");
        //DEST = lookupKey(destmap, "null");
        //COMP = lookupKey(compmap, temp[0]);
        //JUMP = lookupKey(jumpmap, temp1);
        char src[40];
        char dest[100];
  
        // memset(dest, '\0', sizeof(dest));
        strcpy(src, "This is tutorialspoint.com");
        strcpy(dest, src);

        printf("Final copied string : %s\n", temp1);
        // strcpy(DEST, lookupKey(destMap, "null"));
        // strcpy(COMP, lookupKey(compMap, in[0]));
        strcpy(COMP, lookupKey(compMap, "D"));
        printf("inside else statement, after strcopy in parseCCommand! \n");
        char str[100];
        strcat(str,"111");
        strcat(str,DEST);
        strcat(str,COMP);
        strcat(str,JUMP);
        printf("this is our string: %s\n", str);
        return str;
    }
    
    //char** temp_in = in;
    //char* jmp;
    //const char semi = ";";
    //jmp = strchr(in, semi);
    //int count = 0
    //while(!isspace(jmp)){
    //    count++;
    //}
    //char* JMP;
    //JMP = lookupKey(jumpMap, jmp+count);
    // opcode + 00
    // break in into 2-3 parts
    // break into dest


    // break into comp
    // break into jump

    // call code.c corresponding binary
    // return binary
   //  char *str = in;
   // int init_size = strlen(str);
    //char delim[] = {"=",";"};

   // char *ptr = strtok(str, delim);

   // while(ptr != NULL)
   // {
   //     ptr = strtok(NULL, delim);
   // }

   // dest();
   // printf("\n");

   // return 0;
}

int parseLCommand(char*in){ // turn into binary representation
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