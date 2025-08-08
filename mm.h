//
// Created by sathipa on 8/8/25.
//

//#ifndef HEAP_MEMORY_MM_H
//#define HEAP_MEMORY_MM_H

typedef struct vm_page_family_{

    char struct_name[MM_MAX_STRUCT_NAME];
    uint32_t struct_size;

} vm_page_family_t;

typedef struct vm_page_for_families_{

    struct vm_page_for_families_ *next;
    vm_page_familt_t vm_page_family[0];

} typedef struct vm_page_for_families_t;


//#endif //HEAP_MEMORY_MM_H

#define MAX_FAMILIES_PER_VM_PAGE (SYSTEM_PAGE_SIZE - sizeof(vm_page_for_families_t *) / sizeof (vm_page_family_t))


