#include "validation.h"

int check_arguments(int argc) {
    if (argc > 2) {
        show_too_many_args_error();
        return -1;
    } else if (argc == 1) {
        show_argument_error();
        return 0;
    }
    return 1;
}

void show_program_info(char *program_name) {
    printf("Program name %s\n", program_name);
}

void show_file_info(char *filename) {
    printf("The argument supplied is %s\n", filename);
}

void show_argument_error(void) {
    printf("please supply argument.\n");
    getchar();
}

void show_too_many_args_error(void) {
    printf("Too many arguments supplied.\n");
}