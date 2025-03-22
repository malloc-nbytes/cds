#ifndef CDS_STR_H
#define CDS_STR_H

#include <stddef.h>

typedef struct {
        char *data;
        size_t len, cap;
} CDS_Str;

CDS_Str cds_str_create(void);
CDS_Str cds_str_from(const char *s);
void cds_str_push(CDS_Str *s, char c);
void cds_str_append(CDS_Str *str, const char *s);
void cds_str_free(CDS_Str *str);
void cds_str_pop_back(CDS_Str *str);
void cds_str_rm_at(CDS_Str *str, size_t idx);
const char *cds_str_raw(const CDS_Str *const str);

#endif // CDS_STR_H
