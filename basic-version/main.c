/*
 * Coin Change Calculator - Basic Version
 * Console-based single-session calculator
 * Supports USD, AUD and EUR currencies
 */

#include <stdio.h>
#include "coin_functions.h"


int main() {
	 // Declaring variables
     int currency;        
     int amount;         
     char continueChoice; 
     int coins[4];        
     int counts[4];       
    
     // Initializing continue choice to 'Y'
     continueChoice = 'Y';
    
     // loop continues until user chooses to exit
     while (ChoiceContinue(continueChoice)) {
        
         
         // Taking input(currency) and validating until the user enters valid input
         do{
             CurrencyOptions(); // Displaying currency options to the user 
             printf("Enter your choice: ");
             scanf("%d", &currency);               
             } while (!ValidateCurrency(currency)); // Validating the input and repeat the loop if the input is invalid
        
             // Takin input ( amount) and validating until the user enters valid amount
		     do{
                 printf("Enter an amount between 1 to 95: ");
                 scanf("%d", &amount);               
                 } while (!ValidateAmount( currency,  amount)); // Validating the amount and repeating the loop if invalid
        
         // Setting the coin denominations based on the selected currency
         SetCoins(currency, coins);
        
         // Calculate the minimum number of coins needed for each denomination
         CalculateCoinCounts(amount, coins, counts);
        
         // Displays the calculated results 
         DisplayCoinResults(coins, counts);
        
         // Asking if the user want to continue or not and taking input
         printf("Do you want to continue? (Y/N): ");
         scanf(" %c", &continueChoice);           
    }
    
    // Displaying exit message.
    printf("Program exited successfully.\n");
    return 0; 
}