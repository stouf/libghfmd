#ifndef GHFMD_H
#define GHFMD_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>



#define API_REQUEST_URL "https://api.github.com/markdown/raw"
#define API_REQUEST_PORT 443
#define JSON_SQUELETON_SIZE 32







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
 * @return  The corresponding HTML content. It can also return NULL if any
 *          problem connected to the libcurl occured
 */
char* get_html_from_markdown(char* markdown);



#endif // GHFMD_H
