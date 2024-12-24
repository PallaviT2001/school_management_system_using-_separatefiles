#ifndef FILEOPERATION_H
#define FILEOPERATION_H

void saveStudentsToFile(const char *filename);
void saveFacultyToFile(const char *filename);
void saveFeesToFile(const char *filename);
void saveSectionsToFile(const char *filename);

void loadStudentsFromFile(const char *filename);
void loadFacultyFromFile(const char *filename);
void loadFeesFromFile(const char *filename);
void loadSectionsFromFile(const char *filename);

#endif
