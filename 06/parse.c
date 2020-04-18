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

void trim(char *s) {
    char *d = s;
    while (isspace(*s++))
        ;
    s--;
    while (*d++ = *s++)
        ;
    d--;
    while (isspace(*--d))
        *d = 0;
}

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
    printf("inside CommandType and in is: %s\n", in);

    if (strstr(in, L)!=NULL){
        printf("inside L_COMMAND\n");
        return L_COMMAND;
    }
    else if (strstr(in, A)!=NULL){
        printf("inside A_COMMAND\n");
        return A_COMMAND;
    }
    else{
        printf("inside C_COMMAND\n");
        return C_COMMAND;
    } 
    //else {
    //    return 0;
    //}
}

int parseACommand(char* in){ // turn A_Command into binary representation
    // Isolate everythin after @ symbol
    // const char str[] = "chandra@21";
    printf("inside A command\n");
    // get rid of '@'
    const char ch = '@';
    char *ret;
    ret = strchr(in, ch);

    // [to add: check if ret+1 is in symbol table]
    // if yes: return value, and call atoi on that value
    // otherwise: call atoi on ret+1
  
    int val;
    val= atoi(ret+1); 

    int c, d, count;
    char *pointer;
   
    count = 0;
    pointer = (char*)malloc(16+1);
    // add opcode
    *(pointer+count) = 0 + '0';
    count++;
    //compute binary
    for (c = 14 ; c >= 0 ; c--)
    {
      d = val >> c;
     
      if (d & 1){
         *(pointer+count) = 1 + '0';
         }
      else
         *(pointer+count) = 0 + '0';
     
      count++;
      printf("pointer is: %s\n", pointer);
    }
    *(pointer+count) = '\0';
   
    return  pointer;
}

char parseCCommand(char* in){ // turn C_command into binary representation
    printf("inside parseCCommand! \n");
    // copy *in
    return 0;
}

// Strtok requres "" NOT ''
char *ParseC(char* in){

	printf("it works %s\n", in);
	
	const char jmp[] = "0;JMP";
    const char case1[] = "0;JGT";
    const char case2[] = "0=JGT";
	const char equals = '=';
	const char semi =';';
	char *ret;
	char *ret1;
	char *ret2;
	char *comp;
	char *dest;
	
	char str_copy[225];
	strcpy(str_copy, in);
    char DEST[255];
    char COMP[255];
    char JUMP[255];
	
	if(strstr(str_copy, "=")!=NULL){ // there is an =
		//printf("this is strcopy: %s\n", str_copy);
		//printf("this is str: %s\n", in);
		dest = strcpy(str_copy, in);
		strtok(dest, "=");
		
		
        printf("dest is .%s.\n", dest);
		strcpy(DEST, lookupKey(destMap, dest));
        printf("DEST is %s\n", DEST);
		strcpy(str_copy, in);
        printf("DEST is %s\n", DEST);
		if(strstr(str_copy, ";")!=NULL){ // case 1: both equals and semi
			printf("case2\n");
			ret1 = strchr(str_copy, equals);
			comp = strtok(ret1,";");
			printf("comp is %s\n", comp+1);
            strcpy(COMP, lookupKey(compMap, comp+1));
            printf("COMP is %s\n", COMP);
			printf("this is strcopy: %s\n", str_copy);
			printf("this is str: %s\n", in);
			strcpy(str_copy, in);	
			ret = strchr(str_copy, semi);
			printf("jump is %s\n", ret+1);
			strcpy(JUMP, lookupKey(jumpMap, ret+1));
            printf("JMP is %s\n", JUMP);
            printf("this is strcopy: %s\n", str_copy);
			printf("this is str: %s\n", in);
           
		}
		else{ //case 2: just equals
			printf("hey, there, there isn't a semi colon\n");
			ret1 = strchr(str_copy, equals);
			printf("comp: %s\n", ret1+1);
            strcpy(COMP, lookupKey(compMap, ret1+1));
            printf("COMP is %s\n", COMP);
            strcpy(JUMP, lookupKey(jumpMap, "null"));
            printf("JMP is %s\n", JUMP);

		}
	}
	else if(strstr(in, ";")!=NULL){ // case 3: just semi
		printf("case 3\n");
        strcpy(DEST, lookupKey(destMap, "null"));
        printf("DEST is %s\n", DEST);
		comp = strcpy(str_copy, in);
		strtok(comp, ";");
		printf("comp is %s\n", comp);
        strcpy(COMP, lookupKey(compMap, comp));
        printf("COMP is %s\n", COMP);
		strcpy(str_copy, in);
		
		strcpy(str_copy, in);	
		ret = strchr(str_copy, semi);
		printf("jump is %s\n", ret+1);
        strcpy(JUMP, lookupKey(jumpMap, ret+1));
        printf("JMP is %s\n", JUMP);
		
		
	}
    // Append!
    char *C_Binary[255];
    C_Binary[0]='\0';
    strcat(C_Binary,"111"); // Append 111
    
    strcat(C_Binary,COMP); // Append comp
    strcat(C_Binary,DEST); // Append DEST
    strcat(C_Binary,JUMP); // Append JUMP
    printf("our binary is: %s\n", C_Binary);
    //int val;
    //val=atoi(C_Binary);
    //printf("our binary is: %d", C_Binary);
    //return C_Binary;
    //char* out1;
    //out1= C_Binary;
    //in=out1;
    char* final_answer[255];
    strcpy(final_answer, C_Binary);
    
    return final_answer;
    //printf("in is: %s\n",in);
    // return in;
	//return 0;	
}
  


int parseLCommand(char*in){ // turn into binary representation
   return 0;
}

char *parseLine(char* in, char* out){  // (lineRaw, lineBinary)
    //if (commandType(in)== L_COMMAND){
    //   out= parseLCommand(in);
    //   return out;
    //}
    printf("inside ParseLine\n");
    if(commandType(in) == A_COMMAND){
        printf("in is an A_COMMAND\n");
        return parseACommand(in);
        //return out;
    }
    else if (commandType(in)==C_COMMAND){
        printf("in is a C_COMMAND\n");
        //char* outforC = "this";
        //char* output[255] = out;
        //output = '\0';
        return ParseC(in);
        //printf("out is: %s\n", output);
        //return output;
    }
    else{
        printf("in is something else entirely\n");
        return 0;
    }//empty lines, comments, etc
}