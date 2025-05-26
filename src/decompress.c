#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "decompress.h"
#include "utils.h"

int decompress_file(const char *input_file_path) {
    FILE *input = fopen(input_file_path, "r");
    if (input == NULL) {
        fprintf(stderr, "Error opening file: %s\n", input_file_path);
        return 1;
    }

    char *output_file_path = generate_unique_filename(input_file_path, ".txt");
    if (output_file_path == NULL) {
        fclose(input);
        fprintf(stderr, "Error generating output file name.\n");
        return 1;
    }

    FILE *output = fopen(output_file_path, "w");
    if (output == NULL) {
        fprintf(stderr, "Error creating output file: %s\n", output_file_path);
        free(output_file_path);
        fclose(input);
        return 1;
    }

    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (ch == '\n') {
            fputc('\n', output);
            continue;
        }

        char character = ch;
        int count = 0;

        // Parse integer following character
        while ((ch = fgetc(input)) != EOF && isdigit(ch)) {
            count = count * 10 + (ch - '0');
        }

        for (int i = 0; i < count; i++) {
            fputc(character, output);
        }

        if (ch == '\n') {
            fputc('\n', output);
        } else if (ch != EOF) {
            ungetc(ch, input); // put back if not newline (next letter)
        }
    }

    fclose(input);
    fclose(output);
    free(output_file_path);
    return 0;
}
