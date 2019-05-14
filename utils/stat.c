#include <board.h>
#include <errno.h>
#include <string.h>
#include <vfs.h>

/*
 * open - search for an entry specified by pathname and open it
 *
 * @pathname - the path to a file/device
 * @flags    - open flags
 *
 *  Open a node and save the information in the current TCB.
 *
 */
int open(const char *pathname, int flags)
{

  /* 1. Look through VFS and find the node identified by pathname */

  size_t name_len = strlen(pathname);
  struct vfs_node_s *node = vfs_get_matching_node(pathname,
                                                  name_len);
  if (node == NULL)
  {
    return -ENOENT;
  }

  /* Call the vfs open method */

  if (node->ops != NULL && node->ops->open != NULL) {
    return node->ops->open(pathname, flags, 0);
  }

  return -ENOSYS;
}
