#ifndef DISPLAY_H
#define DISPLAY_H
#include "types.h"

// Show the customer info header
void show_customer_info(PersonRecord *person, int currency_idx);

// Display individual coin count if greater than zero
void show_coin_count(int coin_value, int count);

// Show the change breakdown for a currency
void show_change_breakdown(PersonRecord *person, int currency_idx);

// Display all info for a person
void show_person_details(PersonRecord *records, int person_idx);

// Show message when person not found
void show_not_found_message(void);

// Get name input from user
void get_name_from_user(char *name_buffer);

// Check if user input is a valid integer
int get_valid_integer(int *result);

#endif