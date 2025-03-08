#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char *ft_itoa(int n)
{
    int len = 0;
    int temp = n;
    char *result;
    int negative = 0;

    // Handle special case for 0
    if (n == 0)
        return "0";
    // Handle negative numbers
    if (n < 0)
    {
        negative = 1;
        n = -n;
        len++;
    }
    // Calculate the length of the number
    temp = n;
    while (temp)
    {
        len++;
        temp /= 10;
    }
    // Allocate space for the string (including the null-terminator and optional negative sign)
    result = (char *)malloc(len + 1);
    if (!result)
        return NULL;

    result[len] = '\0';
    // Convert integer to string in reverse order
    while (n)
    {
        result[--len] = (n % 10) + '0';  // Convert the digit to a character
        n /= 10;
    }
    // Add the negative sign if necessary
    if (negative)
        result[0] = '-';
    return result;
}

int main()
{
    int test_numbers[] = {123, -123, 0, 42, -2147483648};
    int num_tests = 5;

    for (int i = 0; i < num_tests; i++)
    {
        int num = test_numbers[i];
        char *str = ft_itoa(num);
        printf("ft_itoa(%d) = %s\n", num, str);

        // Only free if the string was dynamically allocated
        if (str != "0")
            free(str);
    }
    return 0;
}
