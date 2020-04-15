////
////  assemble.c
////  06
////
////  Created by Chandra Adhikari on 4/13/20.
////  Copyright © 2020 Chandra Adhikari. All rights reserved.
////
//#include <stdio.h>
//#include <stdlib.h>
//#include "map.h"
//#include <string.h>
///*
////read a string and produce another string
//
//
////parse.c does this
////"M=M+1" ;JMP--> "1000101010101010"
////dest="M"
//// comp="M+1"
//// jump="JMP"
//
////code.c does this:
////M ----> "101"  just an example    char* dest(char*)--> void dest(char* dest, char* src)
////M+1"--> "1010101'
////JMP---> "111'
////"111"+"101"+"1010101"
//
//*/
//
//
////    their declaraation is in assembler.c
//extern map destMap;
//extern map compMap;
//
//extern map jumpMap;
//
//
//void dest (char* in, char* out){
//   out= lookupKey(destMap, in); //out=get(in)
//
//
//}
//
//void comp (char* in, char* out){
//    out= lookupKey(compMap, in);
//}
//
//void jump (char* in, char* out){
//    out= lookupKey(jumpMap, in);
//}
//
//void initJumpMap(){
//    insertKey(jumpMap, "null", "000");
//     insertKey(jumpMap, "null", "111");
//
//}
//
//
//
//void initcompMap(){
//
//
//
//}
//
//
//void initDestMap(){
//
//
//
//}
//
//
//void initJSymbolMap(){
//
//
//
//}
//
