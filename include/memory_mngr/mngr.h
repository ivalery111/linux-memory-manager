#ifndef MEMORY_MNGR_MNGR_H
#define MEMORY_MNGR_MNGR_H

enum {
  MM_OK = 0,
  MM_ERR_INVALID = -1,
  MM_ERR_RELEASE = -2,
};

typedef struct memory_mngr_s memory_mngr_t;

/**
 * @brief Create the manager entry
 *
 * @return Pointer to the new manager on success,
 *         NULL                       on error
 */
memory_mngr_t *mm_create_mngr();

int mm_release_mngr(memory_mngr_t *mngr);

#endif

