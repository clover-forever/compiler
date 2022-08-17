#ifndef COMPILER_HW_COMMON_H
#define COMPILER_HW_COMMON_H
#define M 200
#define N 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Add what you need */
struct symbol_table{
    int index[N];
    char *name[N];
    char *type[N];
    int addr[N];
    int lineno[N];
    char *func_sig[N];
    int scope_level[N];
};

/* parameters and return type can be changed */
static void create_symbol();
static void insert_symbol(char *, char *);
static void lookup_symbol(char *);
static void dump_symbol();

int get_address(char *);
char* getType(char *);
void initial();
void initial2();

#endif /* COMPILER_HW_COMMON_H */