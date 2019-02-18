#ifndef NUMBERREP_H
#define NUMBERREP_H

#include <inttypes.h>

void validate(char *, uint32_t);
uint64_t convert_to_decimal(char *, uint32_t);
char *decimal_to_base(uint64_t, uint32_t);
char *convert_base(char *, uint32_t, uint32_t);

#endif
