/*! 
    \file wam_m0.c
    \brief WAM Instruction header file.

    Contains the WAM instructions for MO abstract machine.
*/
#pragma once

void put_structure(HEAP* h, char *funcName, int airty, int variableIdx);

void set_variable(HEAP* h, int variableIdx);

void set_value(HEAP* h, int variableIdx);