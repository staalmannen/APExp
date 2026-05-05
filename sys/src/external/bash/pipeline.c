#include <config.h>
#include <bashansi.h>
#include "jobs.h"
#include "general.h"
#include "trap.h"

extern PROCESS *the_pipeline;
extern int already_making_children;
extern struct pipeline_saver *saved_pipeline;

static struct pipeline_saver *alloc_pipeline_saver (void);

static struct pipeline_saver *
alloc_pipeline_saver (void)
{
  struct pipeline_saver *ret;

  ret = (struct pipeline_saver *)xmalloc (sizeof (struct pipeline_saver));
  ret->pipeline = 0;
  ret->already_making_children = 0;
  ret->next = 0;
  return ret;
}

void
save_pipeline (int clear)
{
  sigset_t set, oset;
  struct pipeline_saver *saver;

  BLOCK_CHILD (set, oset);
  saver = alloc_pipeline_saver ();
  saver->pipeline = the_pipeline;
  saver->already_making_children = already_making_children;
  saver->next = saved_pipeline;
  saved_pipeline = saver;
  if (clear)
    the_pipeline = (PROCESS *)NULL;
  UNBLOCK_CHILD (oset);
}

PROCESS *
restore_pipeline (int discard)
{
  PROCESS *old_pipeline;
  sigset_t set, oset;
  struct pipeline_saver *saver;

  BLOCK_CHILD (set, oset);
  old_pipeline = the_pipeline;
  the_pipeline = saved_pipeline->pipeline;
  already_making_children = saved_pipeline->already_making_children;
  saver = saved_pipeline;
  saved_pipeline = saved_pipeline->next;
  free (saver);
  UNBLOCK_CHILD (oset);

  if (discard && old_pipeline)
    {
      discard_pipeline (old_pipeline);
      return ((PROCESS *)NULL);
    }
  return old_pipeline;
}
