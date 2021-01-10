#ifndef MEMORY_MNGR_DEFINES_H
#define MEMORY_MNGR_DEFINES_H

#include <stdint.h>

enum {
  MM_OK = 0,
  MM_ERR_INVALID = -1,
  MM_ERR_RELEASE = -2,
  MM_ERR_SYS_PAGE_SIZE_OVER = -3,
  MM_ERR_PAGE_CREATE = -4,
  MM_ERR_INTERNAL = -5, /* check the errno */
  MM_ERR_EXIST = -6,
};

#define VM_PAGE_FAMILY_STRCT_NAME_SIZE  32

#endif

