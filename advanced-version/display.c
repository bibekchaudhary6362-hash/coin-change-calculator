#include "display.h"

void show_customer_info(PersonRecord *person, int currency_idx) {
    printf("Customer:\n%s %d cents in %s\n", 
           person->person_name, person->currency_amounts[currency_idx], 
           supported_currencies[currency_idx]);
}

void show_coin_count(int coin_value, int count) {
    if (count > 0) {
        printf("%d cents: %d\n", coin_value, count);
    }
}

void show_change_breakdown(PersonRecord *person, int currency_idx) {
    printf("Change:\n");
    int coin_idx;
    for (coin_idx = 0; coin_idx < 4; coin_idx++) {
        show_coin_count(coin_denominations[currency_idx][coin_idx], 
                       person->coin_breakdown[currency_idx][coin_idx]);
    }
}

void show_person_details(PersonRecord *records, int person_idx) {
    if (person_idx != -1) {
        int currency_idx;
        for (currency_idx = 0; currency_idx < CURRENCY_COUNT; currency_idx++) {
            if (records[person_idx].currency_amounts[currency_idx] > 0) {
                show_customer_info(&records[person_idx], currency_idx);
                show_change_breakdown(&records[person_idx], currency_idx);
                printf("\n");
            }
        }
    } else {
        show_not_found_message();
    }
}

void show_not_found_message(void) {
    printf("\nNot found\n");
}

void get_name_from_user(char *name_buffer) {
    printf("Enter name: ");
    scanf("%s", name_buffer);
}

int get_valid_integer(int *result) {
    if (scanf("%d", result) != 1) {
        printf("Invalid input. Enter a number.\n");
        while (getchar() != '\n');
        return 0;
    }
    return 1;
}