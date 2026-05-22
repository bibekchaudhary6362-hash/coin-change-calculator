#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "types.h"

// Open the input data file
FILE* open_data_file(const char* filename);

// Read how many records the file contains
int get_record_count(FILE* file);

// Parse one line from the input file
int parse_data_line(FILE* file, char *name, int *amount, char *currency, int line_num);

// Check if currency amount follows the rules
int check_currency_rules(char *currency, int amount, int line_num);

// Make sure amount is in valid range
int check_amount_range(int amount, int line_num);

// Get the index for a currency type
int get_currency_index(char *currency, int line_num);

// Read all data from the file into our records
int load_data_from_file(FILE* file, PersonRecord *records);

// Save the results to CSV file
void save_results_to_csv(PersonRecord *records, int count, const char* filename);

// Write one person's data to the CSV file
void write_person_to_csv(FILE* file, PersonRecord *person, int currency_idx);

#endif