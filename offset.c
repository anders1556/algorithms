//C's offsetof() macro is an ANSI C library feature found in stddef.h.
//It evaluates to the offset(in bytes) of a given member within a struct or union type,
//an expression of type size_t.
//The offsetof() macor takes two parameters, the first being a structure name, 
//and the second being the name of a member within the structure.
//It cannot be desribed as a C prototype.


// Implementation

#define offsetof(st, m) ((size_t)(&((st*)0)->m))
