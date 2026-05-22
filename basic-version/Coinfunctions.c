
#include <stdio.h>
#include "coin_functions.h"

void CurrencyOptions(void) {
     printf("Select a currency:\n");
     printf("1 for USD\n");
     printf("2 for AUD\n");
     printf("3 for Euro\n");
}

int ValidateCurrency(int currency) {
     if(currency < 1 || currency > 3) {
         printf("Invalid choice! Please enter 1, 2 or 3\n");
         return 0; // invalid
     }
     return 1; // valid
}

int ValidateAmount(int currency, int amount) {
     if(amount < 1 || amount > 95) {
         printf("Invalid amount! Amount must be between 1 to 95\n");
         return 0; // invalid
     }else if (currency == 2 && amount % 5 != 0) {
         printf("Invalid amount! For AUD, amount must be divisible by 5\n");
         return 0; // invalid
     }
     return 1; // valid
}



void SetCoins(int currency, int coins[4]) {
     if(currency == 1) { // USD
        coins[0] = 50; coins[1] = 25; coins[2] = 10; coins[3] = 1;
     }else if (currency == 2) { // AUD
        coins[0] = 50; coins[1] = 20; coins[2] = 10; coins[3] = 5;
     }else { // Euro
        coins[0] = 20; coins[1] = 10; coins[2] = 5; coins[3] = 1;
     }
}

void CalculateCoinCounts(int amount, int coins[4], int counts[4]) {
     for(int i = 0; i < 4; i++) {
         counts[i] = amount / coins[i];
         amount %= coins[i];
     }
} 

void DisplayCoinResults(int coins[4], int counts[4]) {
    for(int i = 0; i < 4; i++) {
         if (counts[i] > 0) {
             printf("You need %d coin(s) of %d cents.\n", counts[i], coins[i]);
        }
    }
}

int ChoiceContinue(char continueChoice) {
     if(continueChoice == 'y' || continueChoice == 'Y') {
         return 1; // valid
     }else {
         return 0; // invalid
    }
}