#include <unistd.h>

#include "mngr_internal.h"

memory_mngr_t *mm_create_mngr() {
  memory_mngr_t *mngr = calloc(1, sizeof(memory_mngr_t));
  if (mngr == NULL) {
    return NULL;
  }

  mngr->page_start_addr = NULL;
  mngr->pages_num = 0;
  mngr->sys_page_size = sysconf(_SC_PAGESIZE);
  mngr->vm_page_family_table_head = NULL;

  return mngr;
}

