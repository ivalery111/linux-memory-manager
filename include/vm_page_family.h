#ifndef MEMORY_MNGR_VM_PAGE_FAMILY_H
#define MEMORY_MNGR_VM_PAGE_FAMILY_H

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

#include "defines.h"
#include "macros.h"

typedef struct {
  char   struct_name[VM_PAGE_FAMILY_STRCT_NAME_SIZE];
  size_t struct_size;
} vm_page_family_t;

typedef struct vm_page_family_table_s {
  struct vm_page_family_table_s *next;
  vm_page_family_t               vm_page_family[];
} vm_page_family_table_t;

static inline long MAX_FAMILIES_PER_VM_PAGE() {
  long sys_page_size = sysconf(_SC_PAGESIZE);
  if (sys_page_size == (-1)) {
    return (-1);
  }

  const long rc =
      (long)(((size_t)(sys_page_size) - sizeof(vm_page_family_table_t *)) /
             sizeof(vm_page_family_t));
  return rc;
}

/**
 * @brief Register new page family with Memory Manager
 *
 * @return MM_OK                on succes
 *         MM_ERR_INST_PAGE_FAM on error
 */
int vm_page_family_instantiate(vm_page_family_table_t **table_head,
                               const char *            struct_name,
                               const uint32_t          struct_size);

int vm_page_family_print(vm_page_family_table_t *table_head);

#endif

