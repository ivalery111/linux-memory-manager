#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "../src/internal/mngr_internal.h"
#include "memory_mngr/mngr.h"

int main(void) {
/*  memory_mngr_t mngr;*/
  /*mm_init(&mngr);*/

  memory_mngr_t *mngr = mm_create_mngr();
  assert(mngr != NULL);

  void *addr_one = _mm_create_pages(2);
  assert(addr_one != NULL);

  void *addr_two = _mm_create_pages(3);
  assert(addr_two != NULL);

  int rc = _mm_release_pages(addr_one, 2);
  assert(rc == MM_OK);

  rc = _mm_release_pages(addr_two, 3);
  assert(rc == MM_OK);

  rc = mm_release_mngr(mngr);
  assert(rc == MM_OK);

  (void)rc;
  (void)addr_one;
  (void)addr_two;

  return 0;
}

