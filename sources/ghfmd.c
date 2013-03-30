#include "../headers/ghfmd.h"



/**
 * Return the JSON expected by the REST API as a string, ready to be sent over
 * the network
 * 
 * @param   text    The markdown formated text submited
 * 
 * @return  The JSON expected by the REST API. It returns NULL if no memory
 *          could be allocated for the result.
 */
char* get_json(char* text) {
    size_t text_len = strlen(text);
    
    // Allocate the memory for the result
    // The final result will look like:
    //  {"text": $text, "mode": "mardown"}
    char* json = (char*) malloc((text_len + 31) * sizeof(char));
    
    if (json == NULL) {
        return NULL;
    }

    int num_of_char_written = snprintf(json, (31 + text_len + 1),
        "{\"text\": \"%s\", \"mode\": \"mardown\"}", text);
    
    if (num_of_char_written != (text_len + 31)) {
        // Something bad has happened during the writting process to $json
        free(json);
        return NULL;
    }
    
    return json;
}
