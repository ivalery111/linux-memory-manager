#include <stdio.h>

#include "macros.h"
#include "vm_page_family.h"
#include "vm_page_family_internal.h"

int vm_page_family_print(vm_page_family_table_t* table_head) {
  fprintf(stdout, "Page families:\n");

  vm_page_family_t* curr = NULL;
  ITERATE_PAGE_FAMILY_TABLE_BEGIN(table_head, curr) {
    printf("\n");
    printf("  Struct Name -> %s\n  Struct Size -> %zu\n",
           curr->struct_name,
           curr->struct_size);
    printf("\n");
  }
  ITERATE_PAGE_FAMILY_TABLE_END(table_head, curr)

  return MM_OK;
}

