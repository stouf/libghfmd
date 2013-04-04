#include "../headers/ghfmd.h"








/**
 * This function is called by the libcurl when receiving data from the remote
 * host.
 * For more, information, please see:
 *  http://curl.haxx.se/libcurl/c/libcurl-tutorial.html
 * It copies the data received through the HTTP request to the userdata passed
 * argument in order to make those data available in the caller function.
 * 
 * @param   ptr         The data itself
 * @param   size        The final of the unit used for the data
 * @param   nmemb       The number of unit received
 * @param   userdata    A pointer on a structure that will be passed from the
 *                      function where this function has been assigned as the
 *                      callback for data reception.
 *                      In our case, it's a char**
 * 
 * @return  It should return the amount of data that this function has taken
 *          care about (which means not necessary all the data received !!!)
 */
size_t receive_http_data(char* ptr, size_t size, size_t nmemb, void* userdata) {
    if (size * nmemb > 0) {
        char** user_data = userdata;
        *user_data = (char*) malloc((size * nmemb) * sizeof(char));
        strcpy(*user_data, ptr);
        
        return strlen(*user_data);
    } else {
        return 0;
    }
}





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
char* get_html_from_markdown(char* markdown) {
    // Let's init curl's data
    
    // First, the global initialization
    if (curl_global_init(CURL_GLOBAL_ALL) != 0) {
        return NULL;
    }
    
    // Easy interface initialization
    CURL* curl = curl_easy_init();
    if (curl == NULL) {
        curl_global_cleanup();

        return NULL;
    }
    
    
    // Let's define the several options needed for this communication
    
    // First, the host and the destination PORT
    curl_easy_setopt(curl, CURLOPT_URL, API_REQUEST_URL);
    curl_easy_setopt(curl, CURLOPT_PORT, API_REQUEST_PORT);
    
    // Set the necessary HTTP headers
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: text/plain");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    
    // Bind the callback for the data reception and which data will be called
    // with this callback as the 4th argument (see the function descript above)
    char* html_resulted = NULL;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, receive_http_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html_resulted);
    
    // Specify the data to send using the POST method
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, markdown);
    
    
    // And finally send the request
    if (curl_easy_perform(curl) != 0) {
        // The request could not be sent...
        curl_easy_cleanup(curl);
        curl_global_cleanup();

        return NULL;
    }
    
    // Free the HTTP headers
    curl_slist_free_all(headers);
    
    // Cleanup the stuff done by curl
    curl_easy_cleanup(curl);
    
    return html_resulted;
}
