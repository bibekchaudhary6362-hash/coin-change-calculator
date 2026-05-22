

/*
 * Function: CurrencyOptions
 * Purpose: Displays the available currency options to the user
 * Parameters: None (void)
 * Returns: Nothing (void)
 */
void CurrencyOptions(void);

/*
 * Function: ValidateCurrency
 * Purpose: Validates if the currency choice is within the valid range (1-3)
 * Parameters:
 *   currency - integer representing the user's currency choice
 * Returns: 1 if valid (1-3), 0 if invalid
 */
int ValidateCurrency(int currency);

/*
 * Function: ValidateAmount
 * Purpose: Validates if the amount is within range and meets currency-specific rules
 * Parameters:
 *   currency - integer representing the selected currency type
 *   amount - integer representing the amount to validate
 * Returns: 1 if valid, 0 if invalid
 */
int ValidateAmount(int currency, int amount);

/*
 * Function: ValidateCurrencyInput
 * Purpose: Wrapper function to validate currency input
 * Parameters:
 *   currency - integer representing the user's currency choice
 * Returns: 1 if valid, 0 if invalid
 */

void CalculateCoinCounts(int amount, int coins[4], int counts[4]);

/*
 * Function: DisplayCoinResults
 * Purpose: Displays the calculated coin counts for each denomination
 * Parameters:
 *   coins - array of 4 integers containing coin denominations
 *   counts - array of 4 integers containing the count of each coin type
 * Returns: Nothing (void)
 */
void DisplayCoinResults(int coins[4], int counts[4]);

/*
 * Function: ChoiceContinue
 * Purpose: Determines if the user wants to continue the program
 * Parameters:
 *   continueChoice - character representing user's choice ('y'/'Y' or other)
 * Returns: 1 if user wants to continue, 0 if user wants to exit
 */
int ChoiceContinue(char continueChoice);

/*
 * Function: SetCoins
 * Purpose: Sets the coin denominations based on the selected currency
 * Parameters:
 *   currency - integer representing the currency type (1=USD, 2=AUD, 3=Euro)
 *   coins - array of 4 integers to store the coin denominations
 * Returns: Nothing (void) - results stored in coins array
 */
void SetCoins(int currency, int coins[4]);
