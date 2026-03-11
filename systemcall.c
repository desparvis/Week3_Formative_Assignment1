#include <stdio.h>
#include <stdlib.h>

// Question 2 in the assignment

int main() {

    FILE *log;
    FILE *backup;
    char buffer[256];

    // File creation and writing logs
    log = fopen("backup.log", "w");
    if (log == NULL) {
        perror("Error creating log file");
        return 1;
    }

    fprintf(log, "Backup process started\n");
    fclose(log);

    // Create backup file
    backup = fopen("backup.txt", "w");
    fprintf(backup, "This is a backup file\n");
    fclose(backup);

    // Read file
    backup = fopen("backup.txt", "r");
    fgets(buffer, sizeof(buffer), backup);
    printf("Read from backup file: %s", buffer);
    fclose(backup);

    return 0;
}