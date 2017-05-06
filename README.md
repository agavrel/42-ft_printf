# PRINTF Project

## Project Overview
PRINTF is a 42 Project that aims to mimic libc printf function

Basics, requested from subject:
* 1) parsing for flags, field_width, precision, length_modifier.
* 2) parsing for conversion specifier.
* 3) displaying UTF-8 characters.
* 4) computing unsigned numbers in base 2, 8, 10 and 16.
* 5) displaying signed numbers.
* 6) displaying pointer address

Bonus:
* 1) Handles multi fd (use ft_dprintf(int fd, char const format, ...) instead of ft_printf)
* 2) All flags stored on only 14 bits
* 3) wildcard_length_modifier : replaces precision and field_width with parameter in va_list ap.
* 4) print_len with %n (refer to ft_printf.c : *va_arg(ap, int *) = p->len;)
* 5) ft_printf_putstr(strerror(errno), p) with %m
* 6) colors with '{' and '}'
* 7) %f and %F to print double
* 8) <strong>At 125% of libc printf speed</strong> thanks to buffer addition and functions' optimization.

## Sources
* https://linux.die.net/man/3/printf

## Installation & Tests
```
$> make
$> gcc libftprintf.a srcs/main.c && ./a.out
```

## How to use examples
```
#include "ft_printf.h"
ft_printf("string : %s, dec : %d, binary nb: %b, octal nb: %o, unsigned nb: %u, hexadecimal nb: %x, with uppercase: %X\n", "42", 42, 42, 42, 42, 42, 42);
ft_printf("%S\n", L"잘했지 ?");
```

## Resulting outputs
```
$> string : 42, dec : 42, binary nb: 101010, octal nb: 52, unsigned nb: 42, hexadecimal nb: 2a, with uppercase: 2A
$> 잘했지 ?
```

## Contact & contribute
To contact me and helping me to (fix bugs || improve) FDF, feel free to e-mail me at **angavrel at student dot 42 dot fr**
