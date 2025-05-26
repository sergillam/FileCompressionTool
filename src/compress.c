#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"
#include "utils.h"
#include "constants.h"

int compress_file(const char *input_file_path) {
    FILE *input = fopen(input_file_path, "r");
    if (input == NULL) {
        fprintf(stderr, "Error opening file: %s\n", input_file_path);
        return 1;
    }

    char *output_file_path = generate_unique_filename(input_file_path, ".rle");
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

    int current_char, previous_char = EOF, count = 0;
    while ((current_char = fgetc(input)) != EOF) {
        if (current_char == '\n') {
            if (previous_char != EOF) {
                fprintf(output, "%c%d", previous_char, count);
                previous_char = EOF;
                count = 0;
            }
            fputc('\n', output);
            continue;
        }

        if (current_char == previous_char) {
            count++;
        } else {
            if (previous_char != EOF) {
                fprintf(output, "%c%d", previous_char, count);
            }
            previous_char = current_char;
            count = 1;
        }
    }

    if (previous_char != EOF) {
        fprintf(output, "%c%d", previous_char, count);
    }

    fclose(input);
    fclose(output);
    free(output_file_path);
    return 0;
}
