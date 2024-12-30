#include "fileoperation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "faculty.h"
#include "section.h"
#include "fees.h"

struct Student *findStudentById(int student_id) {
    struct Student *temp = studentHead;
    while (temp != NULL) {
        if (temp->id == student_id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

FILE *openFile(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        file = fopen(filename, "w+");
        if (file == NULL) {
            printf("Error: Could not open or create the file: %s\n", filename);
            return NULL;
        }
    }
    return file;
}

void loadFromFile(const char *filename) {
    FILE *file = openFile(filename);
    if (file == NULL) {
        return;
    }

    int id, age;
    char name[50], contactNumber[20];
    while (fscanf(file, "%d %49s %d %19s", &id, name, &age, contactNumber) != EOF) {
        insertStudent(id, name, age, contactNumber);
    }

    fclose(file);
    printf("Data loaded successfully from file.\n");
}

void writeToFile(const char *filename) {
    FILE *file = openFile(filename);
    if (file == NULL) {
        return;  // If file couldn't be opened, return
    }

    struct Student *temp = studentHead;
    while (temp != NULL) {
        fprintf(file, "%d %s %d %s\n", temp->id, temp->name, temp->age, temp->contactNumber);
        temp = temp->next;
    }

    fclose(file);
    printf("Data written to file successfully.\n");
}

void saveStudentData() {
    writeToFile("students.dat");
}

void loadFacultyFromFile(const char *filename) {
    FILE *file = openFile(filename);
    if (file == NULL) {
        return;
    }

    int id, age;
    char name[50], department[50], qualification[50];
    while (fscanf(file, "%d %49s %49s %d %49s", &id, name, department, &age, qualification) != EOF) {
        insertFaculty(id, name, department, age, qualification);
    }

    fclose(file);
    printf("Faculty data loaded successfully from file.\n");
}

void writeFacultyToFile(const char *filename) {
    FILE *file = openFile(filename);
    if (file == NULL) {
        return;
    }

    struct Faculty *temp = facultyHead;
    while (temp != NULL) {
        fprintf(file, "%d %s %s %d %s\n", temp->id, temp->name, temp->department, temp->age, temp->qualification);
        temp = temp->next;
    }

    fclose(file);
    printf("Faculty data written to file successfully.\n");
}

void saveFacultyData() {
    writeFacultyToFile("faculty.dat");
}

void loadSectionFromFile(const char *filename) {
    FILE *file = openFile(filename);
    if (file == NULL) {
        return;  // If file couldn't be opened, return
    }

    int section_id, student_id;
    char section_name[50];
    while (fscanf(file, "%d %49s %d", &section_id, section_name, &student_id) != EOF) {
        struct Student *student = findStudentById(student_id);
        if (student != NULL) {
            struct Section *newSection = (struct Section *)malloc(sizeof(struct Section));
            if (!newSection) {
                printf("Memory allocation failed!\n");
                exit(EXIT_FAILURE);
            }

            newSection->studentDetails = student;
            newSection->section_id = section_id;
            strncpy(newSection->section_name, section_name, sizeof(newSection->section_name) - 1);
            newSection->section_name[sizeof(newSection->section_name) - 1] = '\0';
            newSection->next = NULL;

            addSectionToList(newSection);
        } else {
            printf("Warning: Student ID %d not found while loading section data.\n", student_id);
        }
    }

    fclose(file);
    printf("Section data loaded successfully from file.\n");
}

void writeSectionToFile(const char *filename) {
    FILE *file = openFile(filename);
    if (file == NULL) {
        return;
    }

    struct Section *temp = sectionHead;
    while (temp != NULL) {
        if (temp->studentDetails != NULL) {
            fprintf(file, "%d %s %d\n", temp->section_id, temp->section_name, temp->studentDetails->id);
        }
        temp = temp->next;
    }

    fclose(file);
    printf("Section data written to file successfully.\n");
}

void saveSectionData() {
    writeSectionToFile("sections.dat");
}

void loadFeesFromFile(const char *filename) {
    FILE *file = openFile(filename);
    if (file == NULL) {
        return;
    }

    int receipt_number, student_id;
    float paid_amount;
    while (fscanf(file, "%d %f %d", &receipt_number, &paid_amount, &student_id) != EOF) {
        struct Student *student = findStudentById(student_id);
        if (student != NULL) {
            struct Fees *newFees = (struct Fees *)malloc(sizeof(struct Fees));
            if (!newFees) {
                printf("Memory allocation failed!\n");
                exit(EXIT_FAILURE);
            }

            newFees->studentDetails = student;
            newFees->receipt_number = receipt_number;
            newFees->paid_amount = paid_amount;
            newFees->next = NULL;

            addFeesToList(newFees);
        } else {
            printf("Warning: Student ID %d not found while loading fee data.\n", student_id);
        }
    }

    fclose(file);
    printf("Fee data loaded successfully from file.\n");
}

void writeFeesToFile(const char *filename) {
    FILE *file = openFile(filename);
    if (file == NULL) {
        return;
    }

    struct Fees *temp = feesHead;
    while (temp != NULL) {
        if (temp->studentDetails != NULL) {
            fprintf(file, "%d %.2f %d\n", temp->receipt_number, temp->paid_amount, temp->studentDetails->id);
        }
        temp = temp->next;
    }

    fclose(file);
    printf("Fee data written to file successfully.\n");
}

void saveFeesData() {
    writeFeesToFile("fees.dat");
}
