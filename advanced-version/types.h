#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_RECORDS 100
#define CURRENCY_COUNT 3

// Currency names
#define CURRENCY_US "US$"
#define CURRENCY_AU "AU$" 
#define CURRENCY_EUR "EUR"

// Coin values for each currency
#define US_COIN_50 50
#define US_COIN_25 25
#define US_COIN_10 10
#define US_COIN_1 1

#define AU_COIN_50 50
#define AU_COIN_20 20
#define AU_COIN_10 10
#define AU_COIN_5 5

#define EUR_COIN_20 20
#define EUR_COIN_10 10
#define EUR_COIN_5 5
#define EUR_COIN_1 1

typedef struct {
    char person_name[MAX_NAME_LENGTH];
    int currency_amounts[CURRENCY_COUNT];
    int coin_breakdown[CURRENCY_COUNT][4];
} PersonRecord;

// Helper functions to get currency data
const char* get_currency_name(int index);
int get_coin_value(int currency_index, int coin_index);

// Global currency and coin data
extern const char* supported_currencies[CURRENCY_COUNT];
extern const int coin_denominations[CURRENCY_COUNT][4];

#endif