#include "ft_printf.h"
int main()
{
    int my_result = ft_putnbr(-1234);
    int result = printf("%d", -1234);
    printf("printf %d characters were written\n", result);
    printf("my printf %d characters were written", my_result);
}
