#include "ft_printf.h"
int main()
{
    printf("%d\n", ft_putchar('c'));
    int result = printf("%d\n", -214748368);
    printf("%d characters were written", result);
}
