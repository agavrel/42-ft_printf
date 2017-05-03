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
1) wildcard_length_modifier : replaces precision and field_width with parameter in va_list ap.
2) print_len (refer to ft_printf.c : *va_arg(ap, int *) = p->len;)
3) ft_printf_putstr(strerror(errno), p)
4) colors with {}
5) fF for floats
6) 23% speed of original printf


## Sources
* https://linux.die.net/man/3/printf

## Installation
```
$> make
$> gcc libftprintf.a srcs/main.c && ./a.out
```

## Contact & contribute
To contact me and helping me to (fix bugs || improve) FDF, feel free to e-mail me at **angavrel at student dot 42 dot fr**
