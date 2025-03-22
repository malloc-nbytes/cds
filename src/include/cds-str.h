#ifndef CDS_STR_H
#define CDS_STR_H

typedef struct {
        char *data;
        size_t len, cap;
} CDS_Str;

#endif // CDS_STR_H
