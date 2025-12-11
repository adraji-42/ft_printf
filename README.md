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
* **Unsigned Integers:** `%u`
* **Hexadecimals (Lower/Upper):** `%x`, `%X`
* **Percentage sign:** `%%`

[![GitHub stars](https://img.shields.io/github/stars/user/repo)](https://github.com/user/repo/stargazers)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)