#include <stdint.h>
#include <unistd.h>

#include "mngr_internal.h"

int mm_init(memory_mngr_t *mngr) {

  int rc = MM_OK;

  if(mngr == NULL){
    rc = MM_ERR_INVALID;
  }

  mngr->sys_page_size = sysconf(_SC_PAGESIZE);

  return rc;
}

