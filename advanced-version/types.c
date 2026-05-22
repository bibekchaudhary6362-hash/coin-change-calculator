#include "types.h"

const char* supported_currencies[CURRENCY_COUNT] = {"US$", "AU$", "EUR"};
const int coin_denominations[CURRENCY_COUNT][4] = {
    {50, 25, 10, 1},   // US$ coins
    {50, 20, 10, 5},   // AU$ coins  
    {20, 10, 5, 1}     // EUR coins
};