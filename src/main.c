#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "compress.h"
#include "decompress.h"
#include "utils.h"
#include "constants.h"

void print_usage() {
    printf("Usage:\n");
    printf("  ./fileCompressor -c <input_file>   for compression\n");
    printf("  ./fileCompressor -d <input_file>   for decompression\n");
    printf("  ./fileCompressor -h                to see this menu\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No arguments given\n");
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0) {
        print_usage();
        return 0;
    }

    if (argc != 3) {
        fprintf(stderr, "Error: Invalid number of arguments\n");
        print_usage();
        return 1;
    }

    const char *flag = argv[1];
    const char *input_file = argv[2];

    if (strcmp(flag, "-c") == 0) {
        printf("Initiated compressing \"%s\"...\n", input_file);
        if (compress_file(input_file) != 0) {
            fprintf(stderr, "Compression of \"%s\" failed\n", input_file);
            return 1;
        }
        printf("Successfully compressed \"%s\"\n", input_file);
    } else if (strcmp(flag, "-d") == 0) {
        printf("Initiated decompressing \"%s\"...\n", input_file);
        if (decompress_file(input_file) != 0) {
            fprintf(stderr, "Decompression of \"%s\" failed\n", input_file);
            return 1;
        }
        printf("Successfully decompressed \"%s\"\n", input_file);
    } else {
        fprintf(stderr, "Error: Invalid argument(s)\n");
        print_usage();
        return 1;
    }

    return 0;
}
