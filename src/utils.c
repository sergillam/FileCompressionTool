#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <sys/stat.h>
#include "utils.h"

#define MAX_FILENAME_LENGTH 4096

// Helper: Check if file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Helper: Copy path safely
static char* safe_strdup(const char* src) {
    size_t len = strlen(src) + 1;
    char* dest = malloc(len);
    if (dest) {
        strncpy(dest, src, len);
    }
    return dest;
}

char* generate_unique_filename(const char *input_path, const char *new_ext) {
    char *input_path_copy = safe_strdup(input_path);
    if (!input_path_copy) return NULL;

    // Extract directory + base filename
    char *dir = dirname(input_path_copy);
    char *base = basename(input_path);

    // Remove extension from base name
    char *dot = strrchr(base, '.');
    size_t base_len = dot ? (size_t)(dot - base) : strlen(base);

    // Prepare formatted output path
    char *output_path = malloc(MAX_FILENAME_LENGTH);
    if (!output_path) {
        free(input_path_copy);
        return NULL;
    }

    int version = 0;
    do {
        if (version == 0) {
            snprintf(output_path, MAX_FILENAME_LENGTH, "%s/%.*s%s", dir, (int)base_len, base, new_ext);
        } else {
            snprintf(output_path, MAX_FILENAME_LENGTH, "%s/%.*s_%d%s", dir, (int)base_len, base, version, new_ext);
        }
        version++;
    } while (file_exists(output_path));

    free(input_path_copy);
    return output_path;
}
