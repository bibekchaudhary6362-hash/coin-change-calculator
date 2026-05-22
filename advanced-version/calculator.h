#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "types.h"

// Calculate coins needed for one currency for one person
void calculate_coins_for_currency(PersonRecord *person, int currency_idx);

// Calculate all coins for one person across all currencies
void calculate_person_coins(PersonRecord *person);

// Calculate coins for all people in our records
void calculate_all_coins(PersonRecord *records, int total_people);

#endif