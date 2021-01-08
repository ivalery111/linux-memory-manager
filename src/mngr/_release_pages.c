#include <unistd.h>
#include "mngr_internal.h"

int _mm_release_pages(void *pages_release, const uint8_t pages_num) {
  int rc = MM_OK;

  if (pages_release == NULL || pages_num == 0){
    rc = MM_ERR_INVALID;
    goto ret;
  }

  if (munmap(pages_release, (size_t){pages_num * (size_t)sysconf(_SC_PAGESIZE)}) ==
      (-1)) {
    rc = MM_ERR_RELEASE;
    goto ret;
  }

ret:
  return rc;
}

