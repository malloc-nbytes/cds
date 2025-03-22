#ifndef CDS_LIST_H
#define CDS_LIST_H

#include <stdint.h>
#include <stddef.h>

typedef struct __CDS_List_Node {
        uint8_t *data;
        struct __CDS_List_Node *p, *n;
} __CDS_List_Node;

typedef struct {
        __CDS_List_Node *hd, *tl;
        size_t stride;
} CDS_List;

#endif // CDS_LIST_H
