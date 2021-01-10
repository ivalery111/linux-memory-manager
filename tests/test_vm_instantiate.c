#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "../src/internal/mngr_internal.h"
#include "defines.h"
#include "macros.h"
#include "vm_page_family.h"

typedef struct {
  size_t number;
  char   name[16];
} test_t;

typedef struct {
  size_t id;
  size_t town;
  char   name[32];
} student_t;

int main(void) {
  memory_mngr_t *mngr = mm_create_mngr();
  assert(mngr);

  int rc = vm_page_family_instantiate(&(mngr->vm_page_family_table_head),
                                      "test_t",
                                      sizeof(test_t));

  assert(rc == MM_OK);

  /* Is the table_head was initialized? */
  assert(mngr->vm_page_family_table_head != NULL);

  {
    vm_page_family_t *curr = NULL;
    ITERATE_PAGE_FAMILY_TABLE_BEGIN(mngr->vm_page_family_table_head, curr) {
      rc =
          strncmp(curr->struct_name, "test_t", VM_PAGE_FAMILY_STRCT_NAME_SIZE);
      assert(rc == 0);

      assert(curr->struct_size == 24);
    }
    ITERATE_PAGE_FAMILY_TABLE_END(table_head, curr)
  }

  rc = vm_page_family_instantiate(&mngr->vm_page_family_table_head,
                                  "student_t",
                                  sizeof(student_t));

  {
    vm_page_family_t *f =
        (vm_page_family_t *)&mngr->vm_page_family_table_head->vm_page_family[0];

    rc = strcmp(f->struct_name, "test_t");
    assert(rc == 0);

    f++;
    rc = -1;
    rc = strcmp(f->struct_name, "student_t");
    assert(rc == 0);
  }

  vm_page_family_print(mngr->vm_page_family_table_head);

  fprintf(stdout, "Test VM Instantiate Done!\n");

  rc = mm_release_mngr(mngr);
  assert(rc == MM_OK);

  (void)mngr;
  (void)rc;

  return 0;
}
