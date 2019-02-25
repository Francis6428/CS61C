#include "numberrep.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("Sanity checks for number base converter\n");
    
    assert(convert_to_decimal("11Z", 36) == 1367);
    assert(convert_to_decimal("101", 2) == 5);
    assert(convert_to_decimal("ABC", 16) == 2748);
    printf("convert_to_decimal passes the tests\n");
    
    assert(strcmp(decimal_to_base(1367, 36), "11Z") == 0);
    assert(strcmp(decimal_to_base(5, 2), "101") == 0);
    assert(strcmp(decimal_to_base(2748, 16), "ABC") == 0);
    printf("decimal_to_base passes the tests\n");

    assert(strcmp(convert_base("11Z", 36, 2), "10101010111") == 0);
    assert(strcmp(convert_base("ABC", 16, 36), "24C") == 0);
    printf("convert_base passes the tests\n");

    return 0;
}
