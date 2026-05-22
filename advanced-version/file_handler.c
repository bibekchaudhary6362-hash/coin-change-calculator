#include "file_handler.h"

FILE* open_data_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("File opening failed");
    }
    return file;
}

int get_record_count(FILE* file) {
    int num_records;
    if (file == NULL) {
        perror("Error: File pointer is NULL\n");
        return 0;
    }
    
    if (fscanf(file, "%d", &num_records) != 1) {
        printf("Error reading number of records\n");
        return 0;
    }
    
    printf("Number of records to be read: %d\n", num_records);
    return num_records;
}

int parse_data_line(FILE* file, char *name, int *amount, char *currency, int line_num) {
    if (fscanf(file, "%s %d cents in %s", name, amount, currency) != 3) {
        printf("The data file has incorrect values. Line number %d contains incorrect values.\n", line_num);
        return 0;
    }
    return 1;
}

int check_currency_rules(char *currency, int amount, int line_num) {
    if (strcasecmp(currency, "AU$") == 0 && amount % 5 != 0) {
        printf("The data file has incorrect values. Line number %d contains incorrect values.\n", line_num);
        return 0;
    }
    return 1;
}

int check_amount_range(int amount, int line_num) {
    if (amount < 1 || amount > 95) {
        printf("The data file has incorrect values. Line number %d contains incorrect values.\n", line_num);
        return 0;
    }
    return 1;
}

int get_currency_index(char *currency, int line_num) {
    int i;
    for (i = 0; i < CURRENCY_COUNT; i++) {
        if (strcasecmp(currency, supported_currencies[i]) == 0) {
            return i;
        }
    }
    printf("The data file has incorrect values. Line number %d contains incorrect values.\n", line_num);
    return -1;
}

int load_data_from_file(FILE* file, PersonRecord *records) {
    int total_records, amount, record_count = 0;
    char name[MAX_NAME_LENGTH], currency[4];
    
    total_records = get_record_count(file);
    if (total_records == 0) {
        return 0;
    }

    int i;
    for (i = 0; i < total_records; i++) {
        int current_line = i + 2;  // Line numbers start from 2 (after count)
        
        if (!parse_data_line(file, name, &amount, currency, current_line)) {
            continue;
        }

        if (!check_currency_rules(currency, amount, current_line)) {
            continue;
        }

        if (!check_amount_range(amount, current_line)) {
            continue;
        }
        
        int currency_idx = get_currency_index(currency, current_line);
        if (currency_idx == -1) {
            continue;
        }

        // Look for existing person
        int person_index = -1;
        int j;
        for (j = 0; j < record_count; j++) {
            if (strcasecmp(records[j].person_name, name) == 0) {
                person_index = j;
                break;
            }
        }

        // Add new person if not found
        if (person_index == -1) {
            if (record_count >= MAX_RECORDS) {
                printf("Maximum number of records reached\n");
                break;
            }
            person_index = record_count;
            strcpy(records[person_index].person_name, name);
            
            // Initialize new person's data
            int k, l;
            for (k = 0; k < CURRENCY_COUNT; k++) {
                records[person_index].currency_amounts[k] = 0;
                for (l = 0; l < 4; l++) {
                    records[person_index].coin_breakdown[k][l] = 0;
                }
            }
            record_count++;
        }

        // Add amount to person's currency total
        records[person_index].currency_amounts[currency_idx] += amount;
    }
    
    fclose(file);
    if (record_count == 0) {
        printf("No records were read from the file.\n");
        return -1;
    }
    return record_count;
}

void write_person_to_csv(FILE* file, PersonRecord *person, int currency_idx) {
    fprintf(file, "%s, the change for %d cents in %s is %d,%d,%d,%d\n",
            person->person_name, person->currency_amounts[currency_idx], 
            supported_currencies[currency_idx],
            person->coin_breakdown[currency_idx][0], person->coin_breakdown[currency_idx][1], 
            person->coin_breakdown[currency_idx][2], person->coin_breakdown[currency_idx][3]);
}

void save_results_to_csv(PersonRecord *records, int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s for writing\n", filename);
        return;
    }

    int i, j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < CURRENCY_COUNT; j++) {
            if (records[i].currency_amounts[j] > 0) {
                write_person_to_csv(file, &records[i], j);
            }
        }
    }

    fclose(file);
}