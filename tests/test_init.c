#include <assert.h>
#include <unistd.h>

#include "memory_mngr/mngr.h"

int main(void) {

  memory_mngr_t mngr;

  long rc = mm_init(&mngr);
  assert(rc == MM_OK);
  (void)rc;

  return 0;
}
