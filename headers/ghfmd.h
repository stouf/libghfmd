#ifndef GHFMD_H
#define GHFMD_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>



#define API_REQUEST_URL "https://api.github.com"
#define MARKDOWN_URI "/markdown"






/**
 * Return the JSON expected by the REST API as a string, ready to be sent over
 * the network
 * 
 * @param   text    The markdown formated text submited
 * 
 * @return  The JSON expected by the REST API. It returns NULL if no memory
 *          could be allocated for the result.
 */
char* get_json(char* text);



/**
 * Convert a mardown formated content into its corresponding HTML content.
 * 
 * This process is done by the Github API, available through a RESTful interface
 * than you can find into the documentation of this project.
 * 
 * We use the lib curl for this purpose
 *
 * @param   markdown    The markdown content to process
 * 
 * @return  The corresponding HTML content. As this function uses a REST API, it
 *          can then return a NULL value if case of a problem of communication
 *          with the API
 */
char* get_html_from_markdown(char* markdown);



#endif // GHFMD_H
