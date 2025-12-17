*This project has been created as part of the 42 curriculum by `adraji`*

# FT_PRINTF

## Description

### Mandatory Part:

This project is centered around the printf() function, specifically the following formatting parameters:

* `%d` --> print signed decimal integer. **Range: [-(2^31) to (2^31) - 1]** (Standard 'int').

* `%i` --> print signed integer. (Same as `%d`).

* `%u` --> print unsigned decimal integer. **Range: [0 to (2^32) - 1]** (Standard 'unsigned int').

* `%x` --> print hexadecimal with lower case characters **[0123456789abcdef]**.

* `%X` --> print hexadecimal with upper case characters **[0123456789ABCDEF]**.

* `%c` --> print a single character. The argument is promoted to an **int** containing the character's value.

* `%s` --> print a string (character array terminated by '\0').
	* #### Pointer Check:
		* If the string pointer is **NULL (or 0)**, **printf must print (null)**.
* `%p` --> print memory address (pointer value). Printed in **lowercase hexadecimal (e.g., 0x...)**.
	* #### NULL Address:
		* If the address is **NULL (or 0)**, **printf must print (nil)**.
* `%%` --> print the literal percent sign '%'.
---
### Bonus Part:

The Bonus Part focuses on implementing advanced formatting capabilities of the standard `printf()` function, which include 
**Flags**, **Minimum Field Width**, and **Precision**. These features are crucial for customizing the output of the mandatory specifiers (`%c, s, p, d, i, u, x, X, %`).

---

#### Implemented Flags and Modifiers

The general format structure is: $\% \text{[flags][width][.precision][type]}$

| Flag / Modifier | Symbol | Description | Applied to Specifiers |
| :---: | :---: | :--- | :--- |
| **Left Justification** | **`-`** | Forces **left alignment** of the output within the minimum field width. If used with '0', the '-' takes precedence. | All types |
| **Zero Padding** | **`0`** | Pads the output with **leading zeros** instead of spaces when a width is specified. Ignored if precision is specified for integers (`d, i, u, x, X`). | `d, i, u, x, X` |
| **Precision** | **`.`** | Used to specify the **precision**. It has different effects based on the specifier: | All types |
| | | * **Strings (`%s`):** Maximum number of characters to be printed. | |
| | | * **Integers (`%d, %i, %u, %x, %X`):** Minimum number of digits to be printed (zero-padding). | |
| **Hash / Alternate Form** | **`#`** | Precedes non-zero hexadecimal outputs (`%x, %X`) with **`0x` or `0X`** respectively. | `x, X` |
| **Sign Display** | **`+`** | Forces a **sign (`+` or `-`)** to be placed before the result, even if the number is positive. | `d, i` |
| **Space Flag** | **` `** | Inserts a **space** before the result if the number is positive and no sign (`+`) is present. Ignored if the `+` flag is also used. | `d, i` |

---

#### Example Structure and Precedence

The flags and modifiers are read in the order shown:

$$\% \text{[flags][width][.precision][type]}$$

**Precedence Rules:**
* **Zero Padding (`0`)** is ignored when **Precision (`.`)** is applied to integer types (`d, i, u, x, X`).
* **Left Justification (`-`)** overrides **Zero Padding (`0`)**.
* **Sign Display (`+`)** overrides the **Space Flag (` `)**.
---
### External Functions Used

The project relies on a specific set of external functions to achieve the functionality of `printf()`, particularly its ability to handle a variable number of arguments (`...`).

| Function Name | Description |
| :--- | :--- |
| **`write`** | Writes data to a file descriptor.|
| **`va_start`** | Initializes the argument list pointer.|
| **`va_arg`** | Retrieves the next argument in the list.|
| **`va_copy`** | Copies the current state of a variable argument list.|
| **`va_end`** | Cleans up the argument list pointer.|

These functions collectively allow `ft_printf` to parse the format string, extract the correct type and value for each variable argument using the **`va_list`** mechanism, and then output the result using **`write`**.

## Instructions

**To Make Libftprintf Library:** 
*   `make`

**To Clean Repo:**
*   `make clean`

**To Delete Library:**
*   `make fclean`

**To Remake Library:**
*   `make re`

**To Compaile With Library:**
*   `cc -Wall -Wextra -Werror `**`file_name`**`libftprintf.a`

## Resources

- [Manual CS50](https://manual.cs50.io/3/stdarg)
- [Geeksforgeeks](https://www.geeksforgeeks.org/c/variadic-functions-in-c)

### Use of AI

* AI been used on that project to: 
	* Explain some concepts, for exampel how to work vardiac function, explain to me how external functions work, except for the write function.
	* give me cases for flag and handle white me this cases.
	* Help to traduction my **`README.md`** file to english.

!!! AI was not used to write the source code.

## Algorithm and Data Structure

### Algorithm Flow

The execution of `ft_printf` follows a structured three-phase algorithm: **Parsing**, **Calculation**, and **Printing**.



### 1. Parsing Phase (`ft_parse_flags`)

This is the core intelligence of the bonus part, responsible for reading the format string and correctly interpreting the modifier sequence: $\% \text{[flags][width][.precision][type]}$.

* **Flag Precedence:** Enforces standard rules (e.g., `-` cancels `0`, `+` cancels ` `).
* **Dynamic Values (`*`):** Handles retrieving width and precision values dynamically from the argument list (`va_arg(args, int)`).
* **Negative Width:** A negative width value automatically sets the **minus** flag (`-`) and uses the absolute value as the width.
* **Precision Precedence:** If precision is set for integer types (`d, i, u, x, X`), the `zero` flag is automatically cleared.

### 2. Calculation Phase (`ft_calc_..._lens` functions)

For each specific type (e.g., `ft_print_int_fms`), a dedicated calculation function determines the exact space needed for each output component:

$$\text{Width} = \text{Space Padding} + \text{Sign/Prefix} + \text{Zero Padding} + \text{Data}$$

This phase calculates the number of required:
* **Data characters** (`len_data`).
* **Precision zeros** (`len_zeros`).
* **Width padding spaces** (`len_padding`).

### 3. Printing Phase (`ft_print_..._fms` functions)

The final output sequence is determined by the `minus` flag:

* **Default (Right Justified):** Space Padding → Sign/Prefix → Zeros → Data Content.
* **Left Justified (`-` flag):** Sign/Prefix → Zeros → Data Content → Space Padding.

### Data Structures Used:

To effectively manage the complexity introduced by flags, width, and precision in the bonus part, the project utilizes several custom data structures defined in `ft_printf_data_utils.h`. These structs organize related variables, making the code cleaner and easier to manage, especially during the printing process.

---

#### 1. `t_flags` (Format Specifier Details)

This structure is the core of the parser. It holds all the information extracted from the format string for a single conversion specifier (`%...`).

* **Members:**
    * `minus`, `zero`, `dot`, `hash`, `plus`, `space`: Boolean flags (`t_bool` / `char`) to track the presence of each formatting flag.
    * `width`: The minimum field width specified by the user.
    * `precision`: The precision value specified (after the `.`).
    * `specifier`: The final conversion character (`d, i, u, x, X, c, s, p, %`).
* **Purpose:** It encapsulates all the rules required to determine **how** the final value should be formatted and printed (e.g., alignment, padding type, minimum length).

#### 2. `t_lens` (Content Length Calculator)

This structure is crucial for calculating the exact dimensions of the output **before** printing begins, ensuring correct padding and alignment.

* **Members:**
    * `len_data`: The actual length of the data being printed (e.g., digits in a number, characters in a string).
    * `len_zeros`: The number of leading zeros required due to precision rules.
    * `len_padding`: The number of padding characters (spaces) required due to width rules.
    * `total_content_len`: The total length of the content **including** data, sign, prefix (`0x`), and zeros, but **excluding** the final space padding.
* **Purpose:** It centralizes the dimensional calculations (width vs. precision vs. data length) required for the `ft_print_...` functions.

#### 3. `t_vars` (Loop and Printing Status)

This structure is used primarily as a state machine to track progress within the main printing loop or helper functions.

* **Members:**
    * `index`: Typically used to track the current position within the format string (`fmt`).
    * `current_print`: A counter often used to track the number of characters printed by the current utility function call.
    * `total_printed`: The accumulated count of all characters successfully printed throughout the execution of `ft_printf`.
* **Purpose:** It manages the state and ensures that the overall return value (total printed characters) is correctly accumulated.

#### 4. `t_levas` (Norminette Utility)

This is a utility structure designed to help adhere to specific coding standards (like the 42 **Norminette**) by wrapping the `t_lens` and `t_vars` structures into a single argument.

* **Members:**
    * `len`: An instance of the `t_lens` structure.
    * `var`: An instance of the `t_vars` structure.
* **Purpose:** It allows helper functions to receive, modify, and return all necessary calculation and status data through a single pointer, reducing the number of local variables in the main functions.

---

This modular approach, using structures like `t_flags` and `t_lens`, greatly simplifies the complex logic of padding and alignment necessary for implementing a full-featured `printf`.
