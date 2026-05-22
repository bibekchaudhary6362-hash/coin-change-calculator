#ifndef MENU_H
#define MENU_H

#include "types.h"
#include "display.h"
#include "search.h"
#include "file_handler.h"

// Show the main menu options
void show_menu_options(void);

// Handle the name search functionality
void handle_name_lookup(PersonRecord *records, int total_people);

// Handle the exit and save functionality
void handle_program_exit(PersonRecord *records, int total_people);

// Show message for invalid menu choice
void show_invalid_choice_message(void);

// Process the user's menu selection
int handle_menu_selection(int choice, PersonRecord *records, int total_people);

// Run the main program loop
void start_menu_loop(PersonRecord *records, int total_people);

#endif