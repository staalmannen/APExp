#ifndef __LIST_H
#define __LIST_H

struct list_head {
  struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
  struct list_head name = LIST_HEAD_INIT(name)

_GL_INLINE_HEADER_BEGIN
#ifndef LIST_INLINE
# define LIST_INLINE _GL_INLINE
#endif

LIST_INLINE void
INIT_LIST_HEAD (struct list_head *list)
{
  list->next = list;
  list->prev = list;
}

LIST_INLINE void
list_add (struct list_head *entry, struct list_head *head)
{
  struct list_head *next = head->next;
  entry->prev = head;
  entry->next = next;
  next->prev = head->next = entry;
}

LIST_INLINE void
list_del (struct list_head *entry)
{
  struct list_head *next = entry->next;
  struct list_head *prev = entry->prev;
  next->prev = prev;
  prev->next = next;
}

LIST_INLINE void
list_del_init (struct list_head *entry)
{
  list_del (entry);
  INIT_LIST_HEAD (entry);
}

LIST_INLINE bool
list_empty (const struct list_head *head)
{
  return head->next == head;
}

/* Return PTR - OFFSET, ignoring the type of PTR and treating OFFSET
   as a byte offset.  */
LIST_INLINE void *
list_entry (void *ptr, idx_t offset)
{
  char *p = ptr;
  return p - offset;
}

_GL_INLINE_HEADER_END

#endif  /* __LIST_H */
