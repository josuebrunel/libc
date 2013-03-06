#ifndef __STDLIB_H
#define __STDLIB_H

extern void *malloc (size_t sz);
extern void *calloc (size_t nmemb, size_t membsz);
extern void *realloc (void *addr, size_t newsz);
extern void free (void *addr);

#endif /* __STDLIB_H */
