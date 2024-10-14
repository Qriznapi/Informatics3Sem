#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings() {
    char** string_array = (char**)malloc(4 * sizeof(char*));

    string_array[0] = (char*)malloc(6 * sizeof(char));
    strcpy(string_array[0], "Cat");

    string_array[1] = (char*)malloc(8 * sizeof(char));
    strcpy(string_array[1], "Mouse");

    string_array[2] = (char*)malloc(11 * sizeof(char));
    strcpy(string_array[2], "Elephant");

    string_array[3] = NULL;

    return string_array;
}

void print_strings(FILE* stream, char** string_array) {
    int i = 0;
    while (string_array[i] != NULL) {
        fprintf(stream, "%s\n", string_array[i]);
        i++;
    }
}
char** load_lines(const char* filename) {
    FILE* file = fopen(filename, "r");
    int num_lines = 1;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            num_lines++;
        }
    }
    fseek(file, 0, SEEK_SET);

    char** string_array = (char**)malloc((num_lines + 1) * sizeof(char*));

    int* line_lengths = (int*)malloc(num_lines * sizeof(int));
    int line_length = 0;
    int cnt = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            line_lengths[cnt++] = line_length;
            line_length = 0;
        } else {
            line_length++;
        }
    }
    line_lengths[cnt] = line_length;

    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < num_lines; i++) {
        string_array[i] = (char*)malloc((line_lengths[i] + 1) * sizeof(char));
    }
    string_array[num_lines] = NULL;

    for (int i = 0; i < num_lines; i++) {
        fgets(string_array[i], line_lengths[i] + 1, file);
        if (string_array[i][line_lengths[i]] == '\n') {
            string_array[i][line_lengths[i]] = '\0';
        }
    }
    free(line_lengths);
    fclose(file);

    return string_array;
}

void destroy_strings(char*** p_string_array) {
    if (*p_string_array != NULL) {
        for (int i = 0; (*p_string_array)[i] != NULL; i++) {
            free((*p_string_array)[i]);
        }
        free(*p_string_array);
        *p_string_array = NULL;
    }
}
void sort_strings(char** words) {
    if (words == NULL) {
        return;
    }
    char* temp;
    for (int i = 0; words[i] != NULL; i++) {
        for (int j = i + 1; words[j] != NULL; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}


int main(int argc, char* argv[]) {

    char* input_filename = argv[1];
    char* output_filename = argv[2];

    char** string_array = load_lines(input_filename);

    sort_strings(string_array);

    FILE* output_file = fopen(output_filename, "w");

    print_strings(output_file, string_array);

    fclose(output_file);

    destroy_strings(&string_array);

    return 0;
}
