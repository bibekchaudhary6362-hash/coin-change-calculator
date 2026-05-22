#include "file_handler.h"
#include "calculator.h"
#include "display.h"
#include "types.h"
#include "validation.h"
#include "menu.h"

// Set up empty records for our data
void setup_empty_records(PersonRecord *records) {
    int i, j, k;
    for (i = 0; i < MAX_RECORDS; i++) {
        records[i].person_name[0] = '\0';
        for (j = 0; j < CURRENCY_COUNT; j++) {
            records[i].currency_amounts[j] = 0;
            for (k = 0; k < 4; k++) {
                records[i].coin_breakdown[j][k] = 0;
            }
        }
    }
}

// Load and process the data file
int process_data_file(char *filename, PersonRecord *records) {
    FILE *data_file = open_data_file(filename);
    if (data_file == NULL) {
        return -1;
    }
    return load_data_from_file(data_file, records);
}

// Main program entry point
int main(int argc, char *argv[]) {
    char input_filename[MAX_NAME_LENGTH] = "coins.txt";
    
    // Use provided filename if given
    if (argc > 1) {
        strcpy(input_filename, argv[1]);
    }
    
    PersonRecord all_records[MAX_RECORDS];
    setup_empty_records(all_records);
    
    int total_people = process_data_file(input_filename, all_records);
    if (total_people <= 0) {
        return -1;
    }
    
    calculate_all_coins(all_records, total_people);
    start_menu_loop(all_records, total_people);
    
    return 0;
}