#ifndef _STRING_H_
#define _STRING_H_

void *memcpy (void *dst, const void * src, size_t n);

void *memmove (void *dst, const void * src, size_t n);

void *memccpy (void *dst, const void * src, int c, size_t n);

void *memset (void *src, int c, size_t n);

int memcmp (const void *s1, const void *s2, size_t n);

void *memchr (const void *src, int c, size_t n);

void *memrchr (const void *src, int c, size_t n);

char *strcpy (char *dst, const char *src);

char *strncpy (char *dst, const char *src, size_t n);

char *strcat (char *dst, const char *src);

char *strncat (char *dst, const char *src, size_t n);

int strcmp (const char *s1, const char *s2);

int strncmp (const char *s1, const char *s2, size_t n);

char *strdup (const char *src);

char *strndup (const char *src, size_t n);

char *strchr (const char *src, int c);

char *strrchr (const char *src, int c);

char *strstr (const char *src, const char *find);

char *strtok (char *src, const char *delim);

char *strtok_r (char *src, const char *delim, char **save_ptr);

int strlen (const char *src);

#endif /*_STRING_H_*/
