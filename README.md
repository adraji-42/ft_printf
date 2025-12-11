*This project has been created as part of the 42 curriculum by [adraji].*

# ft_printf

## 🎯 Description

The main goal of this project is to **reimplement the standard C library function `printf()`**, named `ft_printf()`.

This project focuses on two core technical aspects:
1.  **Handling Variadic Functions:**
	Gaining a deep understanding of how to manage and access a variable number of arguments passed to a function, typically by utilizing the `stdarg.h` library macros (`va_list`, `va_start`, `va_arg`, `va_end`).

2.  **Text Processing and Parsing:**
	Developing robust logic to parse the format string (`const char *format`), identify conversion specifications (`%d`, `%s`, `%c`, ect), extract flags, width, precision, and apply the correct formatting rules before printing the final output to the standard output.

**Supported Conversions:**
* **Characters:** `%c`
* **Strings:** `%s`
* **Pointers:** `%p`
* **Integers (Decimal/Signed):**
	`%d` or `%i`: The difference between %d and %i is not at the output level but at the input level.
	**For example, metal**
_________________________________________________________________________________
|		```code:```																|
|																				|
|			int	d = 1;															|
|			int	i = 1;															|
|			printf("%i | %d\n", d, d);											|
|																				|
|			scanf("%i", &i);													|
|			scanf("%d", &d);													|
|																				|
|																				|
|			printf("variabl i whit %%i: %i | variabl i whit %%d: %d\n", i, i);	|
|			printf("variabl d whit %%i: %i | variabl d whit %%d: %d\n", d, d);	|
|_______________________________________________________________________________|

________________________________________________________________________________________________________________________
|	```output:```	|	```input:```			|	```output:```														|
|		1:	1 | 1	|		1:	10	for `i`		|		1:	variabl `i` whit `%i`: `10` | variabl i whit `%d`: `10`		|
|					|			10	for `d`		|			variabl `d` whit `%i`: `10` | variabl d whit `%d`: `10`		|
|___________________|___________________________|_______________________________________________________________________|
|					|							|																		|
|		2:			|		2:	010	for `i`		|		2:	variabl `i` whit `%i`: `8`  | variabl i whit `%d`: `8`		|
|			1 | 1	|			010	for `d`		|			variabl `d` whit `%i`: `10` | variabl d whit `%d`: `10`		|
|___________________|___________________________|_______________________________________________________________________|
|					|							|																		|
|		3:	1 | 1	|		3:	0x10 for `i`	|		3:	variabl `i` whit `%i`: `16` | variabl i whit `%d`: `16`		|
|					|			0x10 for `d`	|			variabl `d` whit `%i`: `0`  | variabl d whit `%d`: `0`		|
|___________________|___________________________|_______________________________________________________________________|
#										**`%d` can't work whit hexadicimal in scanf**

* **Unsigned Integers:** `%u`
* **Hexadecimals (Lower/Upper):** `%x`, `%X`
* **Percentage sign:** `%%`


## 📚 Resources

### References

This project relied on the following resources for understanding the C standard library and variable argument handling:

* **CS50 Manual**: General C documentation and function reference.

[![CS50 Manual](https://img.shields.io/badge/CS50%20Manual-Reference-red?style=for-the-badge&logo=appveyor)](https://manual.cs50.io)

* **GeeksforGeeks**: Documentation and examples for working with variable-length arguments in C.

[![GeeksforGeeks](https://img.shields.io/badge/GeeksforGeeks-Variable%20Args-darkgreen?style=for-the-badge&logo=geeksforgeeks&logoColor=white)](https://www.geeksforgeeks.org/c/variable-length-argument-c/)

* **Stack Overflow**: Understanding the internal structure and mechanics of the `va_list` implementation on x86-64 architecture.

[![Stack Overflow](https://img.shields.io/badge/Stack%20Overflow-va_list%20x86--64-orange?style=for-the-badge&logo=stackoverflow&logoColor=white)](https://stackoverflow.com/questions/4958384/what-is-the-format-of-the-x86-64-va-list-structure)


### AI Usage Policy

AI tools (specifically **Gemini**) were used strictly for research and instructional purposes to accelerate the understanding of complex concepts.

* **Understanding `stdarg.h`**: Used Gemini to query detailed explanations and flowcharts on the sequence of operations involving `va_list`, `va_start`, `va_arg`, and `va_end`.
* **Data Storage and Memory**: Used Gemini to inquire about the common methods and internal mechanisms used by C compilers to store and manage function arguments on the stack when dealing with variadic functions.
* **Documentation and Readme**: Used Gemini to refine the phrasing and structure of this README file.

**Crucial Note:** AI was **not** used to generate the core implementation code of `ft_printf` or the main parsing logic. All code was written and fully understood by adraji.
