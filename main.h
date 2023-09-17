#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/* Function prototypes */
int char_printf(int count, char buffer[], int *buffer_index, char c);
int string_printf(int count, char buffer[], int *buffer_index, const char *str);
int int_printf(int count, char buffer[], int *buffer_index, int num);
int _printf(const char *format, ...);

#endif /* MAIN_H */
