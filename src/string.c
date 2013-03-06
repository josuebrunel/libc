#include "alloc.h"
#include "string.h"

void *memcpy (void *dst, const void * src, size_t n)
{
     const char * source = src;
     char *dest = dst;

     size_t i = 0;

     for (i = 0 ; i < n ; ++i)
     {
          dest[i] = source[i];
     }

     return dest;
}

void *memmove (void *dst, const void * src, size_t n)
{
     char *buf  = malloc (n);
     char *dest = NULL;

     if (buf != NULL)
     {
          buf  = memcpy (buf, src, n);
          dest = memcpy (dst, buf, n);

          free (buf);
     }

     return dest;
}

void *memccpy (void *dst, const void * src, int c, size_t n)
{
     const char * source = src;
     char *dest = dst;
     void *ret  = NULL;

     size_t i = 0;

     for (i = 0 ; i < n ; ++i)
     {
          if (source[i] != c)
          {
               dest[i] = source[i];
          }
          else
          {
               ret = &(dest[i + 1]);
               break;
          }
     }

     return ret;
}

void *memset (void *src, int c, size_t n)
{
     char *source = src;

     size_t i = 0;

     for (i = 0 ; i < n ; ++i)
     {
          source[i] = c;
     }

     return source;
}

int memcmp (const void *s1, const void *s2, size_t n)
{
     ;
}

void *memchr (const void *src, int c, size_t n)
{
     ;
}

void *memrchr (const void *src, int c, size_t n)
{
     ;
}

char *strcpy (char *dst, const char *src)
{
     ;
}

char *strncpy (char *dst, const char *src, size_t n)
{
     ;
}

char *strcat (char *dst, const char *src)
{
     ;
}

char *strncat (char *dst, const char *src, size_t n)
{
     ;
}

int strcmp (const char *s1, const char *s2)
{
     ;
}

int strncmp (const char *s1, const char *s2, size_t n)
{
     ;
}

char *strdup (const char *src)
{
     ;
}

char *strndup (const char *src, size_t n)
{
     ;
}

char *strchr (const char *src, int c)
{
     ;
}

char *strrchr (const char *src, int c)
{
     ;
}

char *strstr (const char *src, const char *find)
{
     ;
}

char *strtok (char *src, const char *delim)
{
     ;
}

char *strtok_r (char *src, const char *delim, char **save_ptr)
{
     ;
}

int strlen (const char *src)
{
     ;
}
