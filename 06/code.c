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

/*
//read a string and produce another string


//parse.c does this
//"M=M+1" ;JMP--> "1000101010101010"
//dest="M"
// comp="M+1"
// jump="JMP"

//code.c does this:
//M ----> "101"  just an example    char* dest(char*)--> void dest(char* dest, char* src)
//M+1"--> "1010101'
//JMP---> "111'
//"111"+"101"+"1010101"

*/


//    their declaraation is in assembler.c
extern map destMap;
extern map compMap;

extern map jumpMap;
extern map symbolMap;

void dest (char* in, char* out){
   out= lookupKey(destMap, in); //out=get(in)


}

void comp (char* in, char* out){
    out= lookupKey(compMap, in);
}

void jump (char* in, char* out){
    out= lookupKey(jumpMap, in);
    //where the jump part is actually in
    //look for ;
    //create a string of size 3
}

void initJumpMap(){
    insertKey(jumpMap, "null", "000");
    insertKey(jumpMap, "JGT", "001");
    insertKey(jumpMap, "JEQ", "010");
    insertKey(jumpMap, "JGE", "011");
    insertKey(jumpMap, "JLT", "100");
    insertKey(jumpMap, "JNE", "101");
    insertKey(jumpMap, "JLE", "110");
    insertKey(jumpMap, "JMP", "111");

}



void initCompMap(){
    insertKey(compMap, "0", "0101010");
    insertKey(compMap, "1", "0111111");
    insertKey(compMap, "-1", "0111010");
    insertKey(compMap, "D", "0001100");
    insertKey(compMap, "A", "0110000");
    insertKey(compMap, "!D", "0001101");
    insertKey(compMap, "!A", "0110001");
    insertKey(compMap, "-D", "0001111");
    insertKey(compMap, "-A", "0110011");
    insertKey(compMap, "D+1", "0011111");
    insertKey(compMap, "A+1", "0110111");
    insertKey(compMap, "D-1", "0001110");
    insertKey(compMap, "A-1", "0110010");
    insertKey(compMap, "D+A", "0000010");
    insertKey(compMap, "D-A", "0010011");
    insertKey(compMap, "A-D", "0000111");
    insertKey(compMap, "D&A", "0000000");
    insertKey(compMap, "D|A", "0010101");
    // a = 1
    insertKey(compMap, "M", "1110000");
    insertKey(compMap, "!M", "1110001");
    insertKey(compMap, "-M", "1110011");
    insertKey(compMap, "M+1", "1110111");
    insertKey(compMap, "M-1", "1110010");
    insertKey(compMap, "D+M", "1000010");
    insertKey(compMap, "D-M", "1010011");
    insertKey(compMap, "M-D", "1000111");
    insertKey(compMap, "D&M", "1000000");
    insertKey(compMap, "D|M", "1010101");
}


void initDestMap(){
    insertKey(destMap, "null", "000");
    insertKey(destMap, "M", "001");
    insertKey(destMap, "D", "010");
    insertKey(destMap, "MD", "011");
    insertKey(destMap, "A", "100");
    insertKey(destMap, "AM", "101");
    insertKey(destMap, "AD", "110");
    insertKey(destMap, "AMD", "111");


}


void initSymbolMap(){

  
    insertKey(symbolMap, "SP", "0");
    insertKey(symbolMap, "LCL", "1");
    insertKey(symbolMap, "ARG", "2");
    insertKey(symbolMap, "THIS", "3");
    insertKey(symbolMap, "THAT", "4");
    insertKey(symbolMap, "R0", "0");
    insertKey(symbolMap, "R1", "1");
    insertKey(symbolMap, "R2", "2");
    insertKey(symbolMap, "R3", "3");
    insertKey(symbolMap, "R4", "4");
    insertKey(symbolMap, "R5", "5");
    insertKey(symbolMap, "R6", "6");
    insertKey(symbolMap, "R7", "7");
    insertKey(symbolMap, "R8", "8");
    insertKey(symbolMap, "R9", "9");
    insertKey(symbolMap, "R10", "10");
    insertKey(symbolMap, "R11", "11");
    insertKey(symbolMap, "R12", "12");
    insertKey(symbolMap, "R13", "13");
    insertKey(symbolMap, "R14", "14");
    insertKey(symbolMap, "R15", "15");
    insertKey(symbolMap, "SCREEN", "16384");
    insertKey(symbolMap, "KBD", "24576");
    
    
    

}

