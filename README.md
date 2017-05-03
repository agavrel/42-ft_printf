# PRINTF Project

## Project Overview
PRINTF is a 42 Project that aims to mimic libc printf function

* Basic functions:
1) parsing for flags, field_width, precision, length_modifier.
2) parsing for conversion specifier.
3) displaying UTF-8 characters.
4) computing unsigned numbers in base 2, 8, 10 and 16.
5) displaying signed numbers.
6) displaying pointer address

* Bonus:
1) Handles multi fd (use ft_dprintf(int fd, char const format, ...) instead of ft_printf)
2) All flags stored on only 14 bits
3) wildcard_length_modifier : replaces precision and field_width with parameter in va_list ap.
4) print_len with %n (refer to ft_printf.c : *va_arg(ap, int *) = p->len;)
5) ft_printf_putstr(strerror(errno), p) with %m
6) colors with '{' and '}'
7) %f and %F to print double
8) same speed than original libc printf thanks to buffer addition and ft_strlen.


## Sources
* https://linux.die.net/man/3/printf

## Installation
```
$> make
$> gcc libftprintf.a srcs/main.c && ./a.out
```

## Contact & contribute
To contact me and helping me to (fix bugs || improve) FDF, feel free to e-mail me at **angavrel at student dot 42 dot fr**
