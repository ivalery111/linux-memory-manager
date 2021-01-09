#include "mngr.h"
#include "mngr_internal.h"

int mm_release_mngr(memory_mngr_t *mngr) {
  if (mngr == NULL) return MM_ERR_INVALID;

  /* mngr->page_start_addr Should be released by munmap ? */
  mngr->pages_num = 0;
  mngr->sys_page_size = 0;

  free(mngr);

  return MM_OK;
}

