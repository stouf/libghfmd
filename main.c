#include "headers/ghfmd.h"


int main(int argc, char** argv) {
    printf("This program transform markdown formated text into the ");
        printf("corresponding HTML using the GitHub API v3.\n");
    printf("Please, paste your code bellow:(8192 maximum for this test)\n\n");
    
    char markdown[8192];
    scanf("%s", markdown);
    
    char* html = get_html_from_markdown(markdown);
    
    if (html == NULL) {
        printf("Something bad happened during the communication with the ");
        printf("GitHub API server.\n");
        free(markdown);
        return EXIT_FAILURE;
    }
    
    printf("%s\n", html);
    
    free(markdown);
    free(html);

    return EXIT_SUCCESS;
}
