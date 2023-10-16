#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

int _printf(const char *format, ...);
void format_string(va_list arg, const char *format, char spec[], char res[]);
void concat(char result[], char ch, char specifier[]);
void chtoStrcat(char *str, char ch);
void check_specifier(char specifier[], char format);
void print_binary(char *result, int num, char specifier[]);
void print_string(char *result, char *str, char specifier[]);

#endif
