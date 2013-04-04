/**
 * This program reads the file given as first parameter which is supposed to be
 * a markdown-formated text file. It reads this file and returns its html
 * equivalent to the stdout
 */


#include "headers/ghfmd.h"

#define MAX_SIZE 12288


int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("Please, give your markdown file as first argument.\n");
        return EXIT_FAILURE;
    }
    
    // Open the file given as argument
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open the file\n");
        return EXIT_FAILURE;
    }
    
    // Allocate the memory for the coming file
    char* file_content = (char*) malloc(MAX_SIZE * sizeof(char));
    if (file_content == NULL) {
        printf("Could not allocate enough memory for the purpose.\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    
    // Read the file
    char tmp = 0;
    int i = -1;
    while (i++ < MAX_SIZE) {
        tmp = (char) fgetc(file);
        if (tmp == EOF) {
            // We've reached the end of the file, let's exit now
            file_content[i] = '\0';
            break;
        } else {
            file_content[i] = tmp;
        }
    }
    fclose(file);
    
    // Now,  we just have to give our file's content to the library :)
    char* html = get_html_from_markdown(file_content);
    if (html == NULL) {
        printf("Something has happened during the parsing process.\n");
        free(file_content);
    }
    
    printf("%s", html);
    
    free(file_content);
    free(html);

    return EXIT_SUCCESS;
}
