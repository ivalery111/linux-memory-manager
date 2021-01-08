#include <unistd.h>
#include "mngr_internal.h"

int _mm_release_pages(void *pages_release, const uint8_t pages_num) {
  if (munmap(pages_release, (size_t){pages_num * (size_t)sysconf(_SC_PAGESIZE)}) ==
      (-1)) {
    return MM_ERR_RELEASE;
  }

  return MM_OK;
}

