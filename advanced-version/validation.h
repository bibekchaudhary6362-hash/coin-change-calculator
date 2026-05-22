#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdio.h>

// Check if we have the right number of command line arguments
int check_arguments(int argc);

// Show program information
void show_program_info(char *program_name);

// Display what file we're processing
void show_file_info(char *filename);

// Handle case when no arguments provided
void show_argument_error(void);

// Handle case when too many arguments provided
void show_too_many_args_error(void);

#endif