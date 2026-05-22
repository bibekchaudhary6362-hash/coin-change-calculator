#include "menu.h"

void show_menu_options(void) {
    printf("\n1. Enter name\n2. Exit\n");
    printf("Enter your choice: ");
}

void handle_name_lookup(PersonRecord *records, int total_people) {
    char search_name[MAX_NAME_LENGTH];
    get_name_from_user(search_name);
    int person_idx = find_person_by_name(records, total_people, search_name);
    if (person_idx == -1) {
        printf("\nName: %s\n", search_name);
        show_not_found_message();
    } else {
        show_person_details(records, person_idx);
    }
}

void handle_program_exit(PersonRecord *records, int total_people) {
    save_results_to_csv(records, total_people, "change.csv");
    printf("Data written to change.csv.\n");
}

void show_invalid_choice_message(void) {
    printf("Invalid choice. Enter choice again.\n");
}

int handle_menu_selection(int choice, PersonRecord *records, int total_people) {
    switch (choice) {
        case 1:
            handle_name_lookup(records, total_people);
            break;
        case 2:
            handle_program_exit(records, total_people);
            break;
        default:
            show_invalid_choice_message();
    }
    return choice;
}

void start_menu_loop(PersonRecord *records, int total_people) {
    int user_choice;
    do {
        show_menu_options();
        if (!get_valid_integer(&user_choice)) {
            continue;
        }
        user_choice = handle_menu_selection(user_choice, records, total_people);
    } while (user_choice != 2);
}