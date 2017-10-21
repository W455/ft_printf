#include "./includes/libftprintf.h"

int main(void)
{
    int a = 5;
    int *ptr_a = &a;
    //printf(".%10.-2'i.\n", 1);
    //ft_printf(".%10.2'-0-0+20.5Li.\n", 1);
    //printf(".%10.2'-0-0+20.5Li.\n", 1);
    //ft_printf(".%10.2'Li.\n", 12);
    //ft_printf(".%10.2'Li.\n", 123);
    //ft_printf(".%10.2'Li.\n", 1234);
    //ft_printf(".%10.2'Li.\n", 12345);
    //ft_printf(".%10.2'Li.\n", 123456);
    //ft_printf(".%10.2'Li.\n", 1234567);
    //ft_printf(".%10.2'Li.\n", 12345678);
    //ft_printf(".%10.2'Li.\n", 123456789);
    //ft_printf(".%10.2'Li.\n", 1234567890);
    //ft_printf(".%10.2'Li.\n", 12345678901);
    //ft_printf(".%10.2'Li.\n", 123456789012);
    //ft_printf(".%10.2'Li.\n", 1234567890123);
    //printf(".%+10.2i.\n", 123456);
    //ft_printf(".%=,+10u.\n", 12345);
    //ft_printf("my .%#15o.\n", 16);
    //printf("tf .%#15o.\n", 16);
    //ft_printf("my .%08x.\n", 16);
    //printf("tf .%08x.\n", 16);
    ft_printf("my : .%.2c.\n", 0);
    printf("ft : .%.2c.\n", 0);
    //ft_printf("my .%15X.\n", 16);
    //printf("tf .%15X.\n", 16);
    //printf("tf .%10%.\n", '4');
   //// ft_printf("my .%#010o.\n", 42);
    //printf("tf .%#.o %#.0o.\n", 0, 0);
    //ft_printf("my .%#.o %#.0o.\n", 0, 0);
    ////printf(".%10.4s.\n", "loremipsum");
    ////printf(".%10.2c.\n", 123);
    ////printf(".%10.2c.\n", 123);
    /*
    ft_printf(".%5d.\n", 42);
    ft_printf(".%15.2s.\n", "lorem ipsum");
    printf("__________________\n\n");
    printf(".%15.2s.\n", "lorem ipsum");
    printf("__________________\n\n");
    ft_printf("01234%10.005s5678%05.15s9 ca vaut %5.15d\n", "test", "lorem ipsum", 42);
    printf("01234%10.005s5678%05.15s9 ca vaut %5.15d\n", "test", "lorem ipsum", 42);
    */
}
