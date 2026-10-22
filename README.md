*This project has been created as part of the 42 curriculum by ayague-a.*

<img width="1700" height="360" alt="ft_printf" src="https://github.com/user-attachments/assets/22c1c16a-34ab-46cd-a874-f70ff8d8b828" />

## Description

`ft_printf` is a C library that recreates the mandatory conversions of the standard `printf()` function. The project introduces variadic functions, argument handling with `<stdarg.h>`, number conversion, and the organization of reusable code into a static library.

The library exposes the following function through `libftprintf.h`:

```c
int ft_printf(char const *format, ...);
```

It writes to standard output, without reproducing the original function's buffering system. Its return value is intended to represent the number of characters printed. In this implementation, a `NULL` format string returns `-1`.

### Conversions

| Conversion | Purpose |
| --- | --- |
| `%c` | Print one character, including a null character. |
| `%s` | Print a null-terminated string. |
| `%p` | Print a pointer with a hexadecimal `0x` prefix. |
| `%d`, `%i` | Print a signed decimal integer. |
| `%u` | Print an unsigned decimal integer. |
| `%x` | Print an unsigned integer in lowercase hexadecimal. |
| `%X` | Print an unsigned integer in uppercase hexadecimal. |
| `%%` | Print a literal percent sign without consuming an argument. |

A null string argument produces `(null)`, and a null pointer argument produces `(nil)`. These are the conventions used by this implementation; null handling is not universally identical across C libraries.

The project implements the mandatory conversion set. Field width, precision, bonus flags, floating-point conversions, and length modifiers are not implemented.

## Instructions

### Compilation

Requirements: a C compiler available as `cc`, `make`, and `ar`, in a Unix-like environment.

Run the following commands from the project root:

| Command | Action |
| --- | --- |
| `make` or `make all` | Compile Libft and the project, then create `libftprintf.a`. |
| `make clean` | Remove object files from the project and Libft. |
| `make fclean` | Remove object files and both static libraries. |
| `make re` | Clean everything and rebuild. |

The Makefile uses `-Wall -Wextra -Werror`. It builds the bundled `libft/` first, then uses `ar rcs` to include the project and Libft object files in `libftprintf.a`. There is no `bonus` target.

### Usage

The project produces a library, not an executable. Include its header and link the archive into a program. Save this example as `main.c` in the project root:

```c
#include "libftprintf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello, %s! Number: %d | Hex: %x | %%\n",
            "42", 42, 255u);
    ft_printf("Printed characters: %d\n", count);
    return (0);
}
```

Build and execute it:

```sh
make
cc -Wall -Wextra -Werror main.c libftprintf.a -o example
./example
```

Expected output:

```text
Hello, 42! Number: 42 | Hex: ff | %
Printed characters: 36
```

Place `libftprintf.a` after the source or object files that call it in the compiler command. No separate `libft.a` argument is needed. When integrating the library elsewhere, keep `libftprintf.h` and `libft/libft.h` accessible, because the former includes the latter.

## Algorithm and data structures

### Sequential parsing and dispatch

`ft_printf()` scans the format string from left to right using a pointer named `ptr`. Ordinary characters are written immediately and increase the output counter. When the parser encounters `%`, it calls `flag_manager()`, which advances to the conversion character and selects a formatter through an `if` / `else if` chain.

Each formatter consumes its argument, prints the corresponding representation, updates the counter, and advances the format pointer. `%d` and `%i` share the same formatter because both produce signed decimal output. `%%` prints directly and does not access the argument list.

This single-pass approach fits a fixed set of conversion characters: it requires neither tokenization nor a temporary copy of the format string. Separate formatters keep parsing, argument interpretation, and output responsibilities easy to follow. An explicit dispatch chain is sufficient for this small conversion set, so a function-pointer table is unnecessary.

### Variadic arguments and parser state

The parser uses three main pieces of state:

- `va_list args` tracks the variable arguments, initialized with `va_start()` and finalized with `va_end()`.
- `char *ptr` tracks the current position in the format string.
- `int out` accumulates the output length.

Formatters receive `char **` and `int *` so they can update the caller's pointer and counter directly. No list, tree, or dynamically allocated parser structure is needed. Although Libft includes list utilities, the formatting algorithm does not use them.

Arguments must match their conversion types. For example, `%c` retrieves an `int` because character arguments undergo integer promotion, and `%p` retrieves a `void *`.

### Number conversion

Unsigned decimal and hexadecimal helpers use recursive division by the base. They first print the quotient, then convert the remainder into the current digit. This prints digits in the correct order without allocating or reversing a temporary string. Hexadecimal letters are selected in lowercase or uppercase according to the helper's `iscap` parameter. Signed decimal output delegates to Libft's `ft_putnbr_fd()`.

For a number with `k` digits, conversion takes `O(k)` time and `O(k)` recursive stack space. Overall, parsing and formatting take `O(n + m)` time, where `n` is the format length and `m` is the generated output length. Parser state uses constant space, excluding the recursive number-conversion stack. The formatting path does not allocate heap memory.

## Current limitations

The supplied version compiles, but still has these correctness limitations:

- Output helpers do not propagate `write()` failures, so the counter is not a reliable report of successful output when a write fails.

Use valid format strings containing the listed conversions. Unsupported conversions and an incomplete trailing `%` are outside the supported interface. Compilation and the usage example are not a complete equivalence test against libc `printf()`.

## Resources

- **42 ft_printf subject, version 12.0**: the supplied project specification, including mandatory conversions and README requirements.
- [GNU C Library: Formatted Output](https://sourceware.org/glibc/manual/latest/html_node/Formatted-Output.html): reference material for formatted output and conversion syntax.
- [GNU C Language Manual: Variable Number of Arguments](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Variable-Number-of-Arguments.html): variadic functions, argument access, and promotions.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/): build rules, targets, and dependencies.
- [GNU Binutils: ar](https://sourceware.org/binutils/docs/binutils/ar.html): static archive creation and management.

### Use of AI

AI assisted with drafting this README, reading the supplied subject and source files, explaining the existing algorithm and data structures, and checking the build and usage example. No project source code was modified by AI agents.
