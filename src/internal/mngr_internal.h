#ifndef MEMORY_MNGR_MNGR_INTERNAL_H
#define MEMORY_MNGR_MNGR_INTERNAL_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h> /* sysconf */

#include "memory_mngr/mngr.h"
#include "vm_page_family.h"
#include "defines.h"

struct memory_mngr_s {
  long    sys_page_size;
  void *  page_start_addr;
  uint8_t pages_num;
  vm_page_family_table_t *vm_page_family_table_head; /* Points to the first vm page in the list */
};

/**
 * @brief Request @pages_num number of _contiguos_ pages from a kernel
 *
 * @param pages_num Number of pages to request
 *
 * @return Starting address
 */
void *_mm_create_pages(const uint8_t pages_num);

int _mm_release_pages(void *pages_release, const uint8_t pages_num);

#endif

