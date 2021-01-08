#include "mngr.h"
#include "mngr_internal.h"

int mm_release_pages(void *pages_release, const uint8_t pages_num) {
  if (pages_release == NULL || pages_num == 0) return MM_ERR_INVALID;

  return _mm_release_pages(pages_release, pages_num);
}

