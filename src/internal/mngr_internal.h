#ifndef MEMORY_MNGR_MNGR_INTERNAL_H
#define MEMORY_MNGR_MNGR_INTERNAL_H

#include <stdio.h>
#include <string.h>

#include "memory_mngr/mngr.h"

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

