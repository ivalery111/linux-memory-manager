#ifndef MEMORY_MNGR_MNGR_H
#define MEMORY_MNGR_MNGR_H

#include <stddef.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h> /* sysconf */

enum {
  MM_OK = 0,
  MM_ERR_INVALID = -1,
  MM_ERR_RELEASE = -2,
};

typedef struct {
  long    sys_page_size;
  void *  page_start_addr;
  uint8_t pages_num;
} memory_mngr_t;

/**
 * @brief Initialize the memory manager entry
 *
 * @param mngr Memory manager
 *
 * @return MM_OK    on success,
 *         MM_ERR_* on invalid argument
 */
int mm_init(memory_mngr_t *mngr);

/**
 * @brief Request @pages_num number of _contiguos_ pages from a kernel
 *
 * @param pages_num Number of pages to request
 *
 * @return Starting address
 */
void *mm_create_pages(const uint8_t pages_num);

/**
 * @brief Return pages(memory) back to the kernel
 *
 * @param pages_release Pages to release
 * @param pages_num     Number of pages to release
 *
 * @return MM_OK      on success,
 *         MM_RELEASE on error
 */
int mm_release_pages(void *pages_release, const uint8_t pages_num);

#endif

