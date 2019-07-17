#include <osu/buffer.h>

#include <stdlib.h>
#include <string.h>

static const uint8_t nullbyte = 0x00;
static const uint8_t strbyte  = 0x0b;

osu_buffer*
make_buffer() {
    osu_buffer* ret;

    ret = malloc(sizeof(osu_buffer));

    return ret;
}

void
free_buffer(osu_buffer* pBuffer) {
    if ( pBuffer == NULL )
        return;

    if ( pBuffer->bytes != NULL )
        free(pBuffer->bytes);

    free (pBuffer);
}

size_t
write_uleb128 (osu_buffer* pDst, uint64_t pVal) {
    if ( pDst == NULL )
        return 0;

    size_t t = 0;
    do {
        uint8_t byte;
        byte = (uint8_t) (pVal & 0x7F);
        if ((pVal >>= 0x07) != 0)
            byte |= 0x80;

        buff_write(pDst, &byte, 1);
        t++;
    } while(pVal > 0);

    return t;
}

size_t
buff_write(osu_buffer* pDst,
    const void* pSrc, size_t pSrcSize) {
    
    if ( pDst == NULL )
        return 0;

    size_t dstSize = 0;

    pDst->bytes = realloc(pDst->bytes, pDst->bytes_len + pSrcSize);    
    memcpy(pDst->bytes + pDst->position, pSrc, pSrcSize);

    dstSize += pSrcSize;

    pDst->bytes_len += dstSize;
    pDst->position += dstSize;

    return pSrcSize;
}

size_t
buff_write_string(osu_buffer* pDst,
    const char* pSrc, size_t pSrcSize,
    bool pNullable) {

    if ( pDst == NULL )
        return 0;

    size_t dstSize = 0;

    if ((pNullable && pSrc == NULL) ||
        (pNullable && pSrcSize == 0) ||
        (pNullable && strlen(pSrc) == 0))
        return buff_write(pDst, &nullbyte, 1);
    else
    {
        dstSize += buff_write(pDst, &strbyte, 1);
        dstSize += write_uleb128(pDst, pSrcSize);
        dstSize += buff_write(pDst, pSrc, pSrcSize);

        return dstSize;
    }
}