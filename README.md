# Simple printf() Implementation in C

'printf' is a standard C library function used to output formatted text to the console. It takes a format string and any additional arguments specified in the format string, and prints out the formatted text.

## How to Compile

To use this implementation of printf(), follow these steps:

1. Download the folowing files and save them in a single directory.
- [myprintf.c](https://github.com/lataba/holbertonschool-printf/blob/b843c678f1b585b8175e0a66b366fbc3fc8eecaf/myprintf.c) Containing the source code of the printf function.
- [main.h](https://github.com/lataba/holbertonschool-printf/blob/b843c678f1b585b8175e0a66b366fbc3fc8eecaf/main.h) Header file containing prototypes of the functions used by the source code. This is included in the rest of the files through the expression: #include "main.h"
- [get_and_out.c](https://github.com/lataba/holbertonschool-printf/blob/efa2b975d3e35951a31b5e6cd985f78eecb2ac37/get_and_out.c) Containing auxiliar functions.
- [function.c](https://github.com/lataba/holbertonschool-printf/blob/efa2b975d3e35951a31b5e6cd985f78eecb2ac37/functions.c) Containing auxiliar functions.

2. Compile the code, using:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o myprintf
```

## Usage
Call the myprintf() function using the same format specifiers as the standard printf() function. This implementation of printf() supports the following format specifiers:

%d: integer

%i: integer

%s: string

%c: character

%%: litteral percent symbol

### For example:

```
myprintf("Hello, I'm %s! I'm %d years old.\n", "Laura", 30);
```
### The expected output is:

```
Hello, I'm Laura! I'm 30 years old.
```

## Limitations

This implementation of printf() has some limitations compared to the standard printf() function. Here are a few things to keep in mind:

It does not support all the format specifiers and options that are available in the standard printf() function.

It may not be as efficient as the standard printf() function, especially for large or complex output.

It does not perform any input validation, so it is possible to cause buffer overflows or other security issues if you pass in invalid input.

It is not type-safe, so it is possible to pass in arguments of the wrong type and cause undefined behavior.


## Test

If you want to test this function you can download any of the files included in the [Tests](https://github.com/lataba/holbertonschool-printf/tree/master/Tests) folder. To do this you must include the file in the same folder as the rest, and you must compile everything again. 

Then you can run it using this command: 
```
./myprintf
```

## Flowchart

[](https://github.com/lataba/holbertonschool-printf/blob/d632d5ffeca6ec94a28cca507db6820455400e89/Prinf%20flowchart.jpeg)
