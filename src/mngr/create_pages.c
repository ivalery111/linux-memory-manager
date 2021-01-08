#include <stddef.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#include "mngr.h"
#include "mngr_internal.h"

void *mm_create_pages(const uint8_t pages_num) {
  const size_t amount_of_memory = ((size_t)sysconf(_SC_PAGESIZE) * pages_num);

  char *vm_page = mmap(NULL,
                       amount_of_memory,
                       PROT_READ | PROT_WRITE | PROT_EXEC,
                       MAP_ANON | MAP_PRIVATE,
                       0,
                       0);

  if (MAP_FAILED == vm_page) {
    fprintf(stdout, "[E]: mmap failed\n");
    vm_page = NULL;
    goto ret;
  }

  memset(vm_page, 0, amount_of_memory);

ret:
  return vm_page;
}

