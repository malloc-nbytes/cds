#ifndef CDS_ARRAY_H
#define CDS_ARRAY_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
        uint8_t *data;
        size_t len, cap;
} CDS_Array;

#endif // CDS_ARRAY_H
