#ifndef MEMORY_MNGR_MACROS_H
#define MEMORY_MNGR_MACROS_H

#include "vm_page_family.h"

#define ITERATE_PAGE_FAMILY_TABLE_BEGIN(vm_page_family_table_ptr, curr)      \
  {                                                                          \
    size_t _count = 0;                                                \
    curr = (vm_page_family_t *)&vm_page_family_table_ptr->vm_page_family[0]; \
    for (; curr->struct_size &&                                              \
           (_count < (size_t)(MAX_FAMILIES_PER_VM_PAGE()));           \
         curr++, _count++) { \

#define ITERATE_PAGE_FAMILY_TABLE_END(vm_page_family_table_ptr, curr) \
  }                                                                   \
  }

#endif

