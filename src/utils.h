
#include <stdio.h>
#include "define_m0.h"
#include "wam_m0.h"

#pragma once

void dump_heap(HEAP* h) {
    int index = h->index;
    int i = 0;

    while(i < index) {
        printf("%10d : ", i);
        switch(h->cells[i].variable.tag) {
            case REF:
                printf("REF :: %d\n", h->cells[i].variable.address);
                break;
            case STR: 
                printf("STR :: %d\n", h->cells[i].variable.address);
                break;
            case V: 
                printf("VAR :: %d\n", h->cells[i].variable.address);
                break;
            default:
                printf("functor %s/%d\n", h->cells[i].structure.name, h->cells[i].structure.airty);
        }

        i = i + 1;
    }
}