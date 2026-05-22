#include "calculator.h"

void calculate_coins_for_currency(PersonRecord *person, int currency_idx) {
    if (person->currency_amounts[currency_idx] > 0) {
        int remaining = person->currency_amounts[currency_idx];
        int coin_type;
        for (coin_type = 0; coin_type < 4; coin_type++) {
            person->coin_breakdown[currency_idx][coin_type] = remaining / coin_denominations[currency_idx][coin_type];
            remaining = remaining % coin_denominations[currency_idx][coin_type];
        }
    }
}

void calculate_person_coins(PersonRecord *person) {
    int currency_idx;
    for (currency_idx = 0; currency_idx < CURRENCY_COUNT; currency_idx++) {
        calculate_coins_for_currency(person, currency_idx);
    }
}

void calculate_all_coins(PersonRecord *records, int total_people) {
    int person_idx;
    for (person_idx = 0; person_idx < total_people; person_idx++) {
        calculate_person_coins(&records[person_idx]);
    }
}