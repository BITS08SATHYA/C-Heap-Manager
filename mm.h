//
// Created by sathipa on 8/8/25.
//
#ifndef HEAP_MEMORY_MM_H
#define HEAP_MEMORY_MM_H

#include <cstdint>   /* uint32_t */
#include <cstddef>   /* offsetof, size_t */

#define MM_MAX_STRUCT_NAME 32

/* One registered struct family (name + size) */
typedef struct vm_page_family_ {
    char     struct_name[MM_MAX_STRUCT_NAME];
    uint32_t struct_size;          /* bytes for one object of this family */
} vm_page_family_t;

/* A VM page that stores many families; pages are linked when full */
typedef struct vm_page_for_families_ {
    struct vm_page_for_families_ *next;
    vm_page_family_t              vm_page_family[]; /* flexible array */
} vm_page_for_families_t;

/* Set by mm_init() in mm.c using sysconf/getpagesize() */
//extern size_t SYSTEM_PAGE_SIZE;

/* Capacity: how many family entries fit in one VM page */
#define MAX_FAMILIES_PER_VM_PAGE                                                \
    ((SYSTEM_PAGE_SIZE -                                                        \
      offsetof(vm_page_for_families_t, vm_page_family)) /                       \
     sizeof(vm_page_family_t))

/* Helpers to iterate entries stored in a families page.
   Convention: unused slots have struct_size == 0. */

#define ITERATE_PAGE_FAMILIES_BEGIN(pf, curr)                                   \
do {                                                                            \
    uint32_t _count = 0;                                                        \
    for ((curr) = (vm_page_family_t *)((pf)->vm_page_family);                   \
         (curr)->struct_size != 0 &&                                            \
         _count < MAX_FAMILIES_PER_VM_PAGE;                                     \
         (curr)++, _count++) {

#define ITERATE_PAGE_FAMILIES_END()                                             \
    }                                                                           \
} while (0)

#endif /* HEAP_MEMORY_MM_H */
