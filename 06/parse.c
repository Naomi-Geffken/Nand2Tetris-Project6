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


int parseSymbols(char*, in, int lineNumber){
 if (commandType(in)=="L_COMMAND")   //if (commandType(in)==1)
     return lineNumber+1;
 else{  //command is a label
     insertKey(symbolMap, in, lineNumber);
     
 }
    
}

int parseLine(char*, char*){
    if (commandType(in)!= L_COMMAND){
       out= parseLCommand(in);
        return 1;
    }
    else if(commandType(in)!= A_COMMAND){
        out=parseACommand(in);
        return 1;
    }
    else if (commandType(in)!=C_COMMAND){
        out=parseCCommand(in);
        return 1;
        
    }
    else{
        return 0;
    }//empty lines, comments, etc
    
}

int commandType(char* in){
    return 1;
    
    
    
    
}
