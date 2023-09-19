#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/* Define a function pointer type for handling format specifiers */
typedef int (*FormatHandler)(int count, char buffer[], int *buffer_index, va_list args);

typedef struct {
    char specifier;
    FormatHandler handler;
} formatH;

/* Function prototypes for format specifier handlers */
int char_printf(int count, char buffer[], int *buffer_index, va_list args);
int string_printf(int count, char buffer[], int *buffer_index, va_list args);
int int_printf(int count, char buffer[], int *buffer_index, va_list args);
int uint_printf(int count, char buffer[], int *buffer_index, va_list args);
int oct_printf(int count, char buffer[], int *buffer_index, va_list args);
int hex_upper_printf(int count, char buffer[], int *buffer_index, va_list args);
int hex_printf(int count, char buffer[], int *buffer_index, va_list args);

/* Function prototype for the _printf function */
int _printf(const char *format, ...);

/**
 * Array of format specifier handlers indexed by format characters.
 */
extern formatH format_handlers[];

#endif /* MAIN_H */
