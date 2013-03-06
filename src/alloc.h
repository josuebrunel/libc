#ifndef __ALLOC_H
#define __ALLOC_H

/*! \brief Minimal block size */
#define MALLOC_MINSIZE 16

/*! \brief Block header (32 bits) */
struct malloc_header_t
{
     unsigned int size : 31; /*!< Block size */
     unsigned int used : 1;  /*!< If the block is used or free */
};

#endif /* __ALLOC_H */
