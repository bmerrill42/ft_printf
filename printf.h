
#include <stdarg.h>
#include "libft/libft.h"
#define FLAG_SIG(x)                                             \
    x == '-' || x == '+' || x == ' ' || x == '#' || x == '0'
#define LENGTH_SIG(x)                               \
    x == 'h' || x == 'l' || x == 'j' || x == 'z'

enum flag {MINUS_FLAG = 0x0001, PLUS_FLAG = 0x0002, SPACE_FLAG = 0x0004, HASH_FLAG = 0x0008, ZERO_FLAG = 0x0010, HH_FLAG = 0x0020, H_FLAG = 0x0040, L_FLAG = 0x0080, LL_FLAG = 0x0100, J_FLAG = 0x0200, Z_FLAG = 0x0400, WIDTH_FLAG = 0x0800, PRECISION_FLAG = 0x1000, C_NULL_FLAG = 0x2000};

typedef unsigned short t_flags;

typedef struct s_optional {
    t_flags flags;
    unsigned int width;
    unsigned int precision;
} t_optional;

typedef struct s_fmt{
    char c;
    char *(*fn)(va_list, t_optional*);

} t_fmt;

int ft_printf(char *fmt, ...);
