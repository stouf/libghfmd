/**
 * Test of the several functions contained in headers/ghfmd.h.
 * 
 * This tests process uses the library minunit for unit tests
 */


#include "../headers/ghfmd.h"
#include "minunit.h"


int tests_run = 0;






/**
 * Get the html version of the markdown-text "Hellow world", that should simply
 * be "<p>Hello world</p>"
 */
char* test_get_html_from_markdown() {
    // Retrieve the HTML version of the string "Hello world"
    // Supposed to be "<p>Hello world</p>"
    char* result = get_html_from_markdown("Hello world");
    
    mu_assert("The resulted HTML is not as expected",
        (strcmp("<p>Hello world</p>", result) == 0));
    
    free(result);
    
    return 0;
}





/**
 * Run all defined tests
 */
char* all_tests() {
    mu_run_test(test_get_html_from_markdown);
    
    return 0;
}





// #############################################################################
// #############################################################################
// #############################################################################


int main(int argc, char** argv) {
    printf("\t\t=> GHFMD.C / BEGIN<=\n\n\n");
    
    // Run all tests
    char* result = all_tests();
    
    // Print the tests result
    if (result != 0) {
        printf("Some tests have failed: %s\n", result);
    } else {
        printf("All tests have been successful dude !!! :)\n");
    }
    printf("\t=> %d tests run\n", tests_run);
    
    printf("\n\n\t\t=> GHFMD.C / END<=\n\n\n");
    
    return EXIT_SUCCESS;
}
