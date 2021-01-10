#ifndef MEMORY_MNGR_MNGR_H
#define MEMORY_MNGR_MNGR_H

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

