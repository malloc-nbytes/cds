#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cds-str.h"

const char *cds_str_raw(const CDS_Str *const str) {
        return str->data;
}

void cds_str_rm_at(CDS_Str *str, size_t idx) {
        if (idx >= str->len) {
                fprintf(stderr, "[Error] cds_str_rm_at: index %zu is out of range of length %zu\n",
                        idx, str->len);
                exit(1);
        }
        for (size_t i = idx; i < str->len-1; ++i) {
                str->data[i] = str->data[i+1];
        }
        str->data[--str->len] = '\0';
}

void cds_str_pop_back(CDS_Str *str) {
        cds_str_rm_at(str, str->len-1);
}

void cds_str_free(CDS_Str *str) {
        if (str->data) {
                free(str->data);
        }
        str->len = str->cap = 0;
}

void cds_str_append(CDS_Str *str, const char *s) {
        for (size_t i = 0; s[i]; ++i) {
                cds_str_push(str, s[i]);
        }
}

void cds_str_push(CDS_Str *str, char c) {
        if (str->len >= str->cap) {
                str->cap = str->cap ? str->cap * 2 : 2;
                void *res = realloc(str->data, str->cap);
                if (res) {
                        str->data = (char *)res;
                } else {
                        perror("realloc");
                        exit(1);
                }
                (void)memset(str->data + str->len, '\0', str->cap - str->len);
        }
        str->data[str->len++] = c;
}

CDS_Str cds_str_from(const char *s) {
        CDS_Str str = cds_str_create();
        for (size_t i = 0; s[i]; ++i) {
                cds_str_push(&str, s[i]);
        }
        return str;
}

CDS_Str cds_str_create(void) {
        return (CDS_Str) {
                .data = NULL,
                .len = 0,
                .cap = 0,
        };
}
