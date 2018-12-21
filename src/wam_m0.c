/*! 
\file wam_m0.c
\brief WAM Instructions.

Contains the WAM instructions for MO abstract machine.
*/
#include <stdio.h>
#include "define_m0.h"


/*! 
\fn put_structure(char *funcName, int arity, int variableIdx)
\author Brian Brietzke
\addtogroup M0
\brief Push a new functor cell containing \a funcName onto the heap and set registerAi to an STR cell pointing to that functor cell. Continue execution with the following instruction.
\param funcName name of the functor being called
\param arity arity of the functor
\param variableIdx index on the heap
 */
void put_structure(HEAP* h, char *funcName, int airty, int variableIdx) {
    int index = h->index;

    h->cells[index].variable.tag = STR;
    h->cells[index].variable.address = index + 1;
    h->cells[index + 1].structure.name = funcName;
    h->cells[index + 1].structure.airty = airty;

    h->index = index + 2;
}

/*! 
\fn set_variable(int variableIdx)
\author Brian Brietzke
\addtogroup M0
\brief Push a new unbound REF cell onto the heap and copy it into variable \a variableIdx. Continue execution with the following instruction.
\param variableIdx index on the heap
\bug missing the handling of variables
 */
void set_variable(HEAP* h, int variableIdx) {
    int index = h->index;

    h->cells[index].variable.tag = REF;
    h->cells[index].variable.address = index;

    h->index = index + 1;
}

/*! 
\fn set_value(int variableIdx)
\author Brian Brietzke
\addtogroup M0
\brief Push \a variableIdx value onto the heap. Continue execution with the following instruction.
\param variableIdx index on the heap
 */
void set_value(HEAP* h, int variableIdx) {
    int index = h->index;

    h->cells[index].variable.tag = V;
    h->cells[index].variable.address = variableIdx;

    h->index = index + 1;
}