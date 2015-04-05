#!/bin/bash
bison -d semantico.y
flex semantico.l
cc lex.yy.c semantico.tab.c -o semantico -lfl -lm