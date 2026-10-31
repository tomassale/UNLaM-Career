#include "copiaMemmove.h"
#include <stdlib.h>

void *mi_memmove(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    // Si el destino está antes que el origen, podemos copiar de adelante hacia atrás
    if (d < s) {
        size_t i = 0;
        while (i < n) {
            d[i] = s[i];
            i++;
        }
    }
    // Si el destino está después que el origen y hay solapamiento, copiamos de atrás hacia adelante
    else if (d > s) {
        size_t i = n;
        while (i > 0) {
            i--;
            d[i] = s[i];
        }
    }

    return dest;
}
