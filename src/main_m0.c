/*! 
\file main_m0.c
\brief Small M0 implemented with a few commands to see if things explode.
\author Brian Brietzke
\addtogroup M0
*/
#include <stdio.h>
#include "define_m0.h"
#include "wam_m0.h"
#include "utils.h"


int main() {
    HEAP heap = { .index = 0, .cells = {{0}} };

    put_structure(&heap, "h", 2, 3);
    set_variable(&heap, 2);
    set_variable(&heap, 5);
    put_structure(&heap, "f", 1, 4);
    set_value(&heap, 5);
    put_structure(&heap, "p", 3, 1);
    set_value(&heap, 2);
    set_value(&heap, 3);
    set_value(&heap, 4);

    int l = sizeof(heap);
    printf("HEAP size: %d\n", l);
    dump_heap(&heap);
    return 0;
}