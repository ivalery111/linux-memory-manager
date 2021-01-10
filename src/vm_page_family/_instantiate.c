#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "defines.h"
#include "mngr_internal.h"

#include "vm_page_family.h"
#include "vm_page_family_internal.h"

/* NOTE: Since this function is internal so the arguments are valid */
int _vm_page_family_instantiate(vm_page_family_table_t **table_head,
                                const char *             struct_name,
                                const uint32_t           struct_size) {
  int rc = MM_OK;

  /* The table is empty */
  if ((*table_head) == NULL) {
    (*table_head) = (vm_page_family_table_t *)_mm_create_pages(1);
    if (*(table_head) == NULL) {
      rc = MM_ERR_PAGE_CREATE;
      goto ret;
    }

    (*table_head)->next = NULL;
    strncpy((*table_head)->vm_page_family[0].struct_name,
            struct_name,
            VM_PAGE_FAMILY_STRCT_NAME_SIZE - 1);
    (*table_head)->vm_page_family[0].struct_size = struct_size;

    rc = MM_OK;
    goto ret;
  }

  /* Verify that the struct_name is not exist in the list */
  size_t            count = 0;
  vm_page_family_t *page_family_curr = NULL;

  ITERATE_PAGE_FAMILY_TABLE_BEGIN((*table_head), page_family_curr) {
    if (strncmp(page_family_curr->struct_name,
                struct_name,
                VM_PAGE_FAMILY_STRCT_NAME_SIZE) != 0) {
      count++;
      continue;
    }

    rc = MM_ERR_EXIST;
    goto ret;
  }
  ITERATE_PAGE_FAMILY_TABLE_END((*table_head), page_family_curr);

  /* case: current page is full */
  vm_page_family_table_t *page_family_table_new = NULL;

  if (count == (size_t)(MAX_FAMILIES_PER_VM_PAGE())) {
    page_family_table_new = (vm_page_family_table_t *)_mm_create_pages(1);

    page_family_table_new->next = (*table_head);
    (*table_head) = page_family_table_new;

    page_family_curr = &(*table_head)->vm_page_family[0];
  }

  /* case: append new page_family to the list */
  strncpy(page_family_curr->struct_name,
          struct_name,
          VM_PAGE_FAMILY_STRCT_NAME_SIZE);
  page_family_curr->struct_size = struct_size;

ret:
  return rc;
}

