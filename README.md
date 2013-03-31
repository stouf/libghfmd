libghfmd
========

This C library uses the GitHub API v3 in order to generates HTML content from
Markdown formated text contents.




GitHub API v3 reference
-----------------------

- [GitHub API v3](http://developer.github.com/v3/)
    - [Markdown section](http://developer.github.com/v3/markdown/)



Dependencies
------------

- The [libcurl](http://curl.haxx.se/libcurl/) is required for this project.
    - A great [tutorial](http://curl.haxx.se/libcurl/c/libcurl-tutorial.html)
      about how to use curl


Current issue
-------------

**Be careful!**   

This repo is currently in an **unstable** status.

When I call the **curl_easy_cleanup** function, I got a segmentation fault for
an unknown reason.

So, first, this is **not stable** at all, and then, I could not perform all the
necessary tests that allow me to claim that this project is stable.
