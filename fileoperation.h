#ifndef FILEOPERATION_H
#define FILEOPERATION_H
#include "student.h"
#include "faculty.h"
#include "section.h"
#include "fees.h"
#include <stdio.h>

// Function prototypes
//FILE *openFile(const char *filename, const char *modeIfExists, const char *modeIfNotExists);
FILE *openFile(const char *filename);
struct Student *findStudentById(int student_id);

void loadFromFile(const char *filename);
void writeToFile(const char *filename);
void saveStudentData();
void loadFacultyFromFile(const char *filename);
void writeFacultyToFile(const char *filename);
void saveFacultyData();
void loadSectionFromFile(const char *filename);
void writeSectionToFile(const char *filename);
void saveSectionData();
void loadFeesFromFile(const char *filename);
void writeFeesToFile(const char *filename);
void saveFeesData();

#endif // FILEOPERATION_H
