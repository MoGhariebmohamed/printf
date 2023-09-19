#include "main.h"

/**
 * format_handlers - Array of format specifier handlers indexed by format characters.
 */
formatH format_handlers[] = {
    {'c', char_printf},
    {'s', string_printf},
    {'d', int_printf},
    {'i', int_printf},
    {'u', uint_printf},
    {'o', oct_printf},
    {'x', hex_printf},
    {'X', hex_upper_printf},
    {'\0', NULL}
};
