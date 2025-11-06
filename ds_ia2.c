#include <stdio.h>
#include <string.h>

#define DAYS 5
#define SLOTS 5

char days[DAYS][4] = {"Mon", "Tue", "Wed", "Thu", "Fri"};
char timetable[SLOTS][DAYS][20] = {
    {"Coa",   "Cspac", "Dsm",  "Foe",  "Cspac"},
    {"Ddl",   "Oopl",  "Dsa",  "Dsa",  "Dsa"},
    {"Dsm",   "Dsm",   "Coa",  "Oopl", "Ddl"},
    {"Foe",   "Dsa",   "Dsa",  "Coa",  "Foe"},
    {"Cspac", "",      "Foe",  "",     "Coa"}
};

void displayTimetable() {
    int i, j;
    printf("\n\t\tTIMETABLE\n\n");
    printf("\t");
    for (j = 0; j < DAYS; j++) {
        printf("%-8s", days[j]);
    }
    printf("\n");

    for (i = 0; i < SLOTS; i++) {
        printf("Slot %d\t", i + 1);
        for (j = 0; j < DAYS; j++) {
            if (strlen(timetable[i][j]) == 0)
                printf("%-8s", "-");
            else
                printf("%-8s", timetable[i][j]);
        }
        printf("\n");
    }
}

void addLecture() {
    int day, slot;
    char subject[20];

    displayTimetable();
    printf("\nEnter Day (1-Mon ... 5-Fri): ");
    scanf("%d", &day);
    printf("Enter Slot (1-5): ");
    scanf("%d", &slot);

    if (day < 1 || day > 5 || slot < 1 || slot > 5) {
        printf("\nInvalid Input!\n");
        return;
    }

    printf("Enter Subject to Add: ");
    scanf("%s", subject);

    strcpy(timetable[slot - 1][day - 1], subject);
    printf("\nLecture Added Successfully!\n");
}

void updateLecture() {
    int day, slot;
    char subject[20];

    displayTimetable();
    printf("\nEnter Day to Update (1-5): ");
    scanf("%d", &day);
    printf("Enter Slot to Update (1-5): ");
    scanf("%d", &slot);

    if (day < 1 || day > 5 || slot < 1 || slot > 5) {
        printf("\nInvalid Input!\n");
        return;
    }

    printf("Enter New Subject: ");
    scanf("%s", subject);

    strcpy(timetable[slot - 1][day - 1], subject);
    printf("\nLecture Updated Successfully!\n");
}

void deleteLecture() {
    int day, slot;

    displayTimetable();
    printf("\nEnter Day to Delete (1-5): ");
    scanf("%d", &day);
    printf("Enter Slot to Delete (1-5): ");
    scanf("%d", &slot);

    if (day < 1 || day > 5 || slot < 1 || slot > 5) {
        printf("\nInvalid Input!\n");
        return;
    }

    strcpy(timetable[slot - 1][day - 1], "");
    printf("\nLecture Deleted Successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\n========= TIMETABLE MENU =========\n");
        printf("1. Display Timetable\n");
        printf("2. Add Lecture\n");
        printf("3. Update Lecture\n");
        printf("4. Delete Lecture\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayTimetable(); break;
            case 2: addLecture(); break;
            case 3: updateLecture(); break;
            case 4: deleteLecture(); break;
            case 5: printf("\nExiting...\n"); break;
            default: printf("\nInvalid Choice!\n");
        }
    } while (choice != 5);

    return 0;
}
