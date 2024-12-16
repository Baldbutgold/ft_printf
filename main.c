#include "ft_printf.h"
int main()
{
    int my_result = ft_putstr("Hello");
    int result = printf("%s", "Hello");
    printf("printf %d characters were written\n", result);
    printf("my printf %d characters were written", my_result);
}
