#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sync_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "r");
    FILE *dest = fopen(destination, "w");

    if (!src || !dest) {
        printf("Error opening files\n");
        return;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File synchronized successfully\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    sync_file(argv[1], argv[2]);

    return 0;
}