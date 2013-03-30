/**
 * Test of the several functions contained in headers/ghfmd.h.
 * 
 * This tests process uses the library minunit for unit tests
 */


#include "../headers/ghfmd.h"
#include "minunit.h"


int tests_run = 0;



/**
 * Compare a "hard-written" result with the one received from the get_json()
 * function
 */
char* test_get_json() {
    char* text = (char*) malloc(11 * sizeof(char));
    strcpy(text, "Hello world");
    char* expected_json = (char*) malloc(42 * sizeof(char));
    strcpy(expected_json, "{\"text\": \"Hello world\", \"mode\": \"mardown\"}");
    
    char* json = get_json(text);
    
    mu_assert("The JSON generator didn't returned a correct string",
        (strcmp(json, expected_json) == 0));
        
    return 0;
}





/**
 * Run all defined tests
 */
char* all_tests() {
    mu_run_test(test_get_json);
    
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
