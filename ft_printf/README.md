*This project has been created as part of the 42 curriculum by odschreu.*
 
# ft_printf
 
## Description
 
A reimplementation of the standard C `printf()` function as a static library. The project focuses on handling variadic arguments in C. The library is compiled into `libftprintf.a` and can be linked into any C project.
 
The function signature mirrors the original:
 
```c
int ft_printf(const char *, ...);
```
 
Supported conversions:
 
- `%c` Prints a single character.
- `%s` Prints a string (as defined by the common C convention).
- `%p` The void * pointer argument has to be printed in hexadecimal format.
- `%d` Prints a decimal (base 10) number.
- `%i` Prints an integer in base 10.
- `%u` Prints an unsigned decimal (base 10) number.
- `%x` Prints a number in hexadecimal (base 16) lowercase format.
- `%X` Prints a number in hexadecimal (base 16) uppercase format.
- `%%` Prints a percent sign.

---

## Instructions

To compile the library, simply type `make` in the terminal.

Other commands available:
- `make clean` : removes all the object files (if present)
- `make fclean` : removes all the object files and the static library (if present)
- `make all` : makes the library (and compiles the c files if these have been altered or not compiled yet)
- `make re` : first performes a full clean (`fclean`), then makes the library again (and compiles the c files if these have been altered or not compiled yet)

To use this library in your code:
- add `#include "ft_printf.h"` at the top of your c file
- compile with the following command (having the header file in the same directory as the file(s) you are compiling)
``` bash
cc -Wall -Werror -Wextra your_file.c -L. -lftprintf -o your_program
```

---

## Algorithm

This version of printf has been approached by the use of variadic functions. `ft_printf` takes at least one known parameter, namely a const char *, and will go through this string in its code. As it scans and successfully finds a % followed by an conversion specifier, it will then extract the next following parameter that is passed. This is done by the use of the following functions of the variadic library:
- `va_start`: this initializes the start of the list of arguments (of the type of va_list)
- `va_arg`: this function is called to extract and read each parameter when applicable, only able to be done once it is known what the type of this passing parameter must be (thus after finding the conversion specifier)
- `va_end`: once `ft_printf` reaches the end of the string (const char *), and thus the function is done 'consuming' the arguments passed while ft_printf was called, the list must be closed by va_end, before printf returns the number of character it has printed/written to the terminal.

For each conversion, the amount of characters written to the terminal/stdout are counted and returned to the main function, that then keeps track of the total characters written, which it will return after reaching the end of the const char *. 

---

## Resources

### Websites that have aided a lot during this project
- [Stack Overflow](https://stackoverflow.com)
- [Geeks for Geeks](https://geeksforgeeks.org)
- [Spark session from Codam about printf](https://github.com/codam-coding-college/spark-sessions/blob/main/spark-sessions/ft_printf/SparkSession%20-%20ft_printf.md)

Furthermore, some youtube videos have been used to understand variadic functions and see them in practice (mainly by showing how it would work with mathematical functions, sum/squared/etc).


### AI Usage

AI (Claude) has mainly been used to help draft this README. Next to that, AI has been used to ask questions regarding the theory and workings of variadic functions. The approach itself, and all code, has been written by odschreu. 

Claude has been instructed to give no answers whatsoever and mainly aid the studying process by asking more questions (and thus sending the learner out to find out more about what specifically is not clicking yet),

---

#### Test main
This is a sample tester that can be used by an evaluator to see if the ft_printf function works in correspondence to the real printf.

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ft_ret;
    int ret;
    void *ptr = (void *)0x4242;

    // %c
    ft_ret = ft_printf("ft: %c\n", 'A');
    ret =       printf("og: %c\n", 'A');
    printf("ft returned: %d | og returned: %d\n\n", ft_ret, ret);

    // %s
    ft_ret = ft_printf("ft: %s\n", "hello 42");
    ret =       printf("og: %s\n", "hello 42");
    printf("ft returned: %d | og returned: %d\n\n", ft_ret, ret);

    // %p
    ft_ret = ft_printf("ft: %p\n", ptr);
    ret =       printf("og: %p\n", ptr);
    printf("ft returned: %d | og returned: %d\n\n", ft_ret, ret);

    // %d and %i
    ft_ret = ft_printf("ft: %d | %i\n", -42, 42);
    ret =       printf("og: %d | %i\n", -42, 42);
    printf("ft returned: %d | og returned: %d\n\n", ft_ret, ret);

    // %u
    ft_ret = ft_printf("ft: %u\n", 4294967295u);
    ret =       printf("og: %u\n", 4294967295u);
    printf("ft returned: %d | og returned: %d\n\n", ft_ret, ret);

    // %x and %X
    ft_ret = ft_printf("ft: %x | %X\n", 255, 255);
    ret =       printf("og: %x | %X\n", 255, 255);
    printf("ft returned: %d | og returned: %d\n\n", ft_ret, ret);

    // %%
    ft_ret = ft_printf("ft: 100%%\n");
    ret =       printf("og: 100%%\n");
    printf("ft returned: %d | og returned: %d\n\n", ft_ret, ret);

    return (0);
}
```