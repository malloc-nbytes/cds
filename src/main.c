#include <stdio.h>

#include "cds-str.h"

int main(void) {
        CDS_Str s = cds_str_from("hello world");
        cds_str_rm_at(&s, 2);
        printf("%s\n", s.data);

        cds_str_free(&s);

        return 0;
}
