#include <unistd.h>

#include "defines.h"
#include "vm_page_family_internal.h"

int vm_page_family_instantiate(vm_page_family_table_t **table_head,
                               const char *            struct_name,
                               const uint32_t          struct_size) {
  int        rc = MM_OK;

  const long sys_page_size = sysconf(_SC_PAGESIZE);
  if (struct_name == NULL || (struct_size > sys_page_size)) {
    rc = MM_ERR_INVALID;
    goto ret;
  }
  if(sys_page_size == (-1)){
    rc = MM_ERR_INTERNAL;
    goto ret;
  }

  rc = _vm_page_family_instantiate(table_head, struct_name, struct_size);

ret:
  return rc;
}

