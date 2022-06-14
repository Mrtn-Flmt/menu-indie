/*
** EPITECH PROJECT, 2022
** menu-indie
** File description:
** tools
*/

#include <stdio.h>
#include <stdlib.h>

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        std::swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

char* my_itoa(int num, char* str, int base)
{
    int i = 0;
    bool is_negative = false;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (num < 0 && base == 10) {
        is_negative = true;
        num = -num;
    }
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    if (is_negative)
        str[i++] = '-';
    str[i] = '\0';
    reverse(str, i);
    return str;
}
