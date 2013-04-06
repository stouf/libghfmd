libghfmd
========

This C library uses the GitHub API v3 in order to generates HTML content from
Markdown formated text contents.


Use
---

Simply use it as follow:

```c
#include "ghfmd.h"

/**
 * Returns a HTML version of a given markdown formated text content
 *
 * @param markdown_text     The markdown formated text content
 *
 * @return                  Either a char pointer on the string that contains
                            the exepcted html version, either NULL if a problem
                            has occured
 */
char* your_function(char* markdown_text) {
    return get_html_from_markdown(markdown_text);
}
```


The current main.c file reads a given file (supposed to be a markdown file) in
order to parse it and returns its HTML version to the stdout.
You can use it as follow:
```bash
$ make MD_FILE="/path/to/md/file"
```

It's also possible to compile the program with debug flags. Example:
```bash
$ make DBG_FLAG="-g" build_main
```

And finally, run the program with a debugger. Example:
```bash
make DBG_FLAG="-g" DBG_CMD="gcc" MD_FILE="test.md"
```



And then???
-----------


And then, you've got an HTML file, which is the body of your final HTML page.
So, you can add whatever you wanna add to this body.

But, there're something you should add to the received body in order to get the
expected syntax highlighting: **the CSS files!**

Those are available [here](css/) ;-)

- *documentation.css* is for the document itself
- *pygments.css* is for the syntax highlighting

Feel free to add the one you need, or even both, of course :) ;)




GitHub API v3 references
------------------------

- [GitHub API v3](http://developer.github.com/v3/)
    - [Markdown section](http://developer.github.com/v3/markdown/)
    
    
    
GitHub Flavored Markdown references
-----------------------------------

- [Main repository](https://github.com/github/github-flavored-markdown)
    - [CSS folder](https://github.com/github/github-flavored-markdown/tree/gh-pages/shared/css)



Dependencies
------------

- The [libcurl](http://curl.haxx.se/libcurl/) is required for this project.
    - A great [tutorial](http://curl.haxx.se/libcurl/c/libcurl-tutorial.html)
      about how to use curl
