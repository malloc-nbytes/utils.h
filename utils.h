#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define AUTO(id, v) typeof(v) id = v

#define TODO                                                    \
    fprintf(stderr, "!!! TODO: %s() !!!\n", __FUNCTION__);      \
    exit(1);

#define err(msg)                                \
    do {                                        \
        fprintf(stderr, "[Error]: " msg "\n");  \
        exit(1);                                \
    } while (0)

#define err_wargs(msg, ...)                                     \
    do {                                                        \
        fprintf(stderr, "[Error]: " msg "\n", __VA_ARGS__);     \
        exit(1);                                                \
    } while (0)

#define bit_set(bits, bit) (((bits) & (bit)) != 0)

#define set_bit(bits, bit) (bits) |= (bit)

#define unset_bit(bits, bit) (bits) &= ~(bit)

#define SAFE_PEEK(arr, i, el) ((arr)[i] && (arr)[i] == el)

#define s_malloc(b) ({                              \
    void *__p_ = malloc(b);                         \
    if (!__p_) err_wargs("could not allocate %zu bytes", b);    \
    __p_;                                           \
})

#define s_free(ptr)                             \
    do {                                        \
        free(ptr);                              \
        (ptr) = NULL;                           \
    } while (0)

#endif // UTILS_H
