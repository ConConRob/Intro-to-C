#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    // loop till '\0'
    int len = strlen(y);
    for (int i = 0; i <= len; i++)
    {
        *(x + i) = *(y + i);
    }
    return NULL;
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c)
{
    // loop looking for match
    // on match return pointer
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (*(str + i) == c)
        {
            return str + i;
        }
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    int len_haystack = strlen(haystack);
    int len_needle = strlen(needle);
    for (int i = 0; i < len_haystack; i++)
    {
        int j = 0;
        while (free)
        {
            if (j == len_needle)
            {

                return haystack + i;
            }
            if (*(haystack + i + j) == *(needle + j))
            {
                ++j;
                continue;
            }
            break;
        }
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char buffer[1024];
    string_copy(buffer, "Hello!");
    printf("%s\n", buffer); // Prints "Hello!"
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
