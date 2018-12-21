/*! 
\file define_m0.h
\brief Element definations and HEAP.
*/
#ifdef HAVE_CONFIG_H
#include <config.h>
#else
#define MAX_HEAP 0
#define MAX_STACK 0
#define MAX_REGISTERS 0
#endif
#pragma once


/*! 
\enum Tags 

Describes the internal representation for terms.  The Tags are used in the \ref HEAP to represent arbitrary terms.

\author Brian Brietzke
\addtogroup M0
*/
typedef enum  {
    STR,                        //!< Structure
    REF,                        //!< Reference
    V                           //!< Value
} TAGS;

/*! 
\union memory_cell

Represents an individual member in the \ref HEAP and is used to distinguish between types of \ref HEAP data
\author Brian Brietzke
\addtogroup M0
*/
union memory_cell {
    struct V {
        TAGS tag;                      //!< indentifies the type of variable cell 
        int address;                    //!< index inside the \ref HEAP 
    } variable;                         //!< established reference for a term 
    struct S {
        char* name;                     //!< functor name 
        int airty;                      //!< The arity of a functor is the number of arguments it takes 
    } structure;                        //!< non-variable term that represents a structure or functor 
};

/*! 
\struct HEAP

Global block storage as an array of data cells.
\author Brian Brietzke
\addtogroup M0
*/
typedef struct  {
    int index;                          //!<  current top of the \ref HEAP
    union memory_cell cells[MAX_HEAP];  //!<  elements saved in the current heap
} HEAP;

typedef struct {
    int index;                           //!<  next available variable index
} REGISTERS;