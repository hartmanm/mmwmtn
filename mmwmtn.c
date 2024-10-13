/*
Copyright (c) 2023 Michael Neill Hartman. All rights reserved.
mnh_license@proton.me
https://github.com/hartmanm
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

uint8_t get_price(char* min_Price, char* max_Price) {
    uint8_t number_of_digits = strlen(max_Price);
    char numbers[number_of_digits + 1];
    
    if (number_of_digits == 1) {
        numbers[0] = max_Price[0];
        numbers[number_of_digits] = '\0';
        printf("numbers:\n%s\n\n", numbers);
        return 0;
    }

    uint8_t maxPrice_digit = 0;
    if (number_of_digits == 2) {
        if (min_Price[0] == max_Price[0]) {
            numbers[0] = max_Price[0];
            numbers[1] = max_Price[1];
            numbers[number_of_digits] = '\0';
            printf("numbers:\n%s\n\n", numbers);
            return 0;
        } 
        if (min_Price[0] != max_Price[0]) {
            maxPrice_digit = (uint8_t)(max_Price[0]);
            if (maxPrice_digit > 1) {
                maxPrice_digit--;
                if (maxPrice_digit > 1) {
                    printf("maxPrice_digit=%d\n", maxPrice_digit);
                    numbers[0] = (char)maxPrice_digit; 
                    numbers[1] = '9';
                    numbers[number_of_digits] = '\0';
                    printf("numbers:\n%s\n\n", numbers);
                    return 0;
                }
            } else {
                printf("todo\n");
            }
        }
    }

    uint64_t minPrice = atoll(min_Price);
    uint64_t maxPrice = atoll(max_Price);
    maxPrice_digit = 0;

    uint8_t flag = 0;
    uint8_t max_index = 0;
    uint8_t contains_nine = 0;
    uint8_t non_nine_mapping[number_of_digits];
    memset(non_nine_mapping, 0, number_of_digits);

    for (uint64_t i = 0; i < number_of_digits; i++) {
        if (max_Price[i] != '9') {
            non_nine_mapping[i] = 1; 
            if (i > 0 && non_nine_mapping[i - 1] == 0) max_index = i - 1;
        }
        if (max_Price[i] == '9') contains_nine = 1;
        printf(" %d ", non_nine_mapping[i]);
    }
    
    printf("max_index %d\nnumber_of_digits %d\ncontains_nine %d\n", max_index, number_of_digits, contains_nine);
    printf("min %s\nmax %s\n", min_Price, max_Price);

    uint8_t leading_match_index = 0;
    uint8_t ended = 0;

    for (uint64_t i = 0; i < number_of_digits; i++) {
        if (min_Price[i] == max_Price[i] && !ended) leading_match_index++;
        if (min_Price[i] != max_Price[i]) ended = 1;
    }
    printf("leading_match_index %d\n", leading_match_index);
    
    if (leading_match_index + 1 == number_of_digits) {
        strncpy(numbers, max_Price, number_of_digits);
        numbers[number_of_digits] = '\0';
        printf("numbers:\n%s\n\n", numbers);
        return 0;
    }

    uint8_t done = 0;
    uint64_t i = leading_match_index;

    if (maxPrice_digit == 0) {
        numbers[i - 1] = '0';
        maxPrice_digit = (uint8_t)(max_Price[i]);
        maxPrice_digit--;
        printf("maxPrice_digit=%d\n", maxPrice_digit);
        numbers[i] = (char)maxPrice_digit; 
        i++;

        while (i < number_of_digits) {
            numbers[i] = '9';
            i++;
        }
        numbers[i] = '\0';
        done = 1;
    }

    if (!contains_nine) {
        printf("decrement_leading_digit\n");
        maxPrice_digit = (uint8_t)(max_Price[i]);
        maxPrice_digit--;
        if (maxPrice_digit > 1) {
            printf("maxPrice_digit=%d\n", maxPrice_digit);
            numbers[i] = (char)maxPrice_digit; 
            i++;

            while (i < number_of_digits) {
                numbers[i] = '9';
                i++;
            }
            numbers[i] = '\0';
            done = 1;
        }
    }

    if (!done) {
        printf("todo\n");
    }

    numbers[i] = '\0';
    printf("numbers:\n%s\n\n", numbers);
    return 9;
}

int main(int number_of_parameters, char* parameters[]) {
    if (number_of_parameters > 2) {
        get_price(parameters[1], parameters[2]);
    }
    return 0; 
}

// gcc -o mmwmtn mmwmtn.c 
