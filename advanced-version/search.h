#ifndef SEARCH_H
#define SEARCH_H

#include "types.h"

// Look for a person by name in our records
int find_person_by_name(PersonRecord *records, int total_people, char* search_name);

// Check if a person exists in our records
int person_exists(PersonRecord *records, int total_people, char* search_name);

#endif