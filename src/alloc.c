#include "alloc.h"

static char *HeapStart = 0;
static char *HeapEnd   = 0;

void *malloc (size_t sz)
{
     struct malloc_header_t *bl = NULL;

     /* total size of data */
     size_t realsize = sz + sizeof (struct malloc_header_t);

     /* align size on 8 bytes */
     size_t i = realsize % MALLOC_MINSIZE;

     if (i != 0)
     {
          realsize = realsize - i + MALLOC_MINSIZE;
     }

     /* initialize the heap if not done */
     if (HeapStart == 0)
     {
          HeapStart = sbrk (realsize);

          if (HeapStart == (char *) -1)
          {
               return NULL;
          }

          /* define end of heap */
          HeapEnd = realsize;

          /* define first block */
          bl       = (struct malloc_header_t *) HeapStart;
          bl->size = realsize;
          bl->used = 0; /* allocation is done at the end */
     }
     else
     {
          /* search the first free block of equal or superior size */
          bl = (struct malloc_header_t *) HeapStart;

          while (bl->used || bl->size < realsize)
          {
               /* next block */
               bl = (struct malloc_header_t *) (bl + bl->size);

               /* end of heap, allocate more */
               if (bl == (struct malloc_header_t *) HeapEnd)
               {
                    HeapEnd = sbrk (realsize);

                    if (HeapEnd == (char *) -1)
                    {
                         return NULL;
                    }

                    /* create new block */
                    bl       = (struct malloc_header_t *) HeapEnd;
                    bl->size = realsize;
                    bl->used = 0; /* allocate is done at the end */

                    /* redefine end of heap */
                    HeapEnd += realsize;
               }
          }
     }

     /* a block was found */


     /* if the difference between the block size and the allocation size is
      * superior to the minimal size of a block, split it to have more free
      * space on the heap.
      */
     if (bl->size - realsize > MALLOC_MINSIZE)
     {
          struct malloc_header_t *newbl = NULL;

          newbl       = (struct malloc_header_t *) ((char *) bl + realsize);
          newbl->size = bl->size - realsize;
          newbl->used = 0;

          /* redefine actual block */
          bl->size = realsize;
     }

     /* allocate */
     bl->used = 1;

     /* return a pointer on the memory just after the block header */
     return (char *) (bl + sizeof (struct malloc_header_t));
};

void free (void *addr)
{
     struct malloc_header_t *bl     = NULL;
     struct malloc_header_t *nextbl = NULL;

     /* get back the header */
     bl = (struct malloc_header_t *) ((char *) addr - sizeof (struct malloc_header_t));

     /* fusion the freed block with the next if it's free too */
     while ((nextbl = (struct malloc_header_t *) ((char *) bl + bl->size))
               && nextbl < (struct malloc_header_t *) HeapEnd
               && nextbl->used == 0)
     {
          bl->size += nextbl->size;
     }

     /* free block */
     bl->used = 0;
}

void *realloc (void *addr, size_t new_sz)
{
     void *new_ptr = NULL;

     if (addr == NULL)
     {
          return malloc (new_sz);
     }

     if (new_sz == 0)
     {
          free (addr);
          return NULL;
     }

     /* allocate new memory */
     new_ptr = malloc (new_sz);

     if (new_ptr != NULL)
     {
          struct malloc_header_t *bl = NULL;

          /* get the size of the previous pointer */
          bl = (struct malloc_header_t *) (addr - sizeof (struct malloc_header_t));

          /* copy memory in the new space */
          memcpy (new_ptr, addr, bl->size - sizeof (struct malloc_header_t));

          /* free old memory */
          free (addr);
     }

     return new_ptr;
}

void *calloc (size_t nmemb, size_t membsz)
{
     void *ptr = malloc (nmemb * membsz);

     if (ptr != NULL)
     {
          memset (ptr, 0, nmemb * membsz);
     }

     return ptr;
}
