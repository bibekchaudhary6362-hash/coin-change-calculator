#include "search.h"

int find_person_by_name(PersonRecord *records, int total_people, char* search_name) {
    int i;
    for (i = 0; i < total_people; i++) {
        if (strcasecmp(records[i].person_name, search_name) == 0) {
            return i;
        }
    }
    return -1;
}

int person_exists(PersonRecord *records, int total_people, char* search_name) {
    return find_person_by_name(records, total_people, search_name) != -1;
}