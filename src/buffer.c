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
write_uleb128 (osu_buffer* pBuffer, size_t pVal) {
    if ( pBuffer == NULL )
        return 0;

    size_t t = 0;
    do {
        uint8_t byte;
        byte = (uint8_t) (pVal & 0x7F);
        if ((pVal >>= 0x07) != 0)
            byte |= 0x80;

        buff_write(pBuffer, &byte, 1);
        t++;
    } while(pVal > 0);

    return t;
}

size_t
read_uleb128 (osu_buffer* pBuffer) {
    if ( pBuffer == NULL )
        return 0;

    size_t total = 0;
    size_t shift = 0;

    while(true) {
        uint8_t byte = 0;
        buff_read(pBuffer, &byte, 1);

        total |= (byte & 0x7F) << shift;

        if ((byte & 0x80) == 0)
            break;

        shift += 7;
    }

    return total;
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
buff_write_string(osu_buffer* pBuff,
    const char* pSrc, size_t pSrcSize,
    bool pNullable) {

    if ( pBuff == NULL )
        return 0;

    size_t dstSize = 0;

    if ((pNullable && pSrc == NULL) ||
        (pNullable && pSrcSize == 0) ||
        (pNullable && strlen(pSrc) == 0))
        return buff_write(pBuff, &nullbyte, 1);
    else
    {
        dstSize += buff_write(pBuff, &strbyte, 1);
        dstSize += write_uleb128(pBuff, pSrcSize);
        dstSize += buff_write(pBuff, pSrc, pSrcSize);

        return dstSize;
    }
}

uint8_t
seek_next(osu_buffer* pBuff) {
    if ( pBuff->position + 1 > pBuff->bytes_len )
        return 0;
    
    return pBuff->bytes[pBuff->position + 1];
}

int
buff_read(osu_buffer* pBuff,
    void* pDst, size_t pSize) {
    if ( pBuff->position + pSize > pBuff->bytes_len )
        return E_UNABLE_TO_READ_BEYOND_STREAM;
    
    memcpy(pDst, pBuff->bytes + pBuff->position, pSize);

    pBuff->position += pSize;
    return S_OK;
}

int
buff_read_string(osu_buffer* pBuff,
    char** pDst) {

    if ( pBuff->position + 1 > pBuff->bytes_len )
        return E_UNABLE_TO_READ_BEYOND_STREAM;

    uint8_t peekedByte = seek_next(pBuff);
    if ( peekedByte != 0x00 && peekedByte != 0x0b )
        return E_S_IS_NOT_AN_S;
    
    pBuff->position++;

    size_t sLen = read_uleb128(pBuff);
    if ( pBuff->position + sLen > pBuff->bytes_len )
        return E_UNABLE_TO_READ_BEYOND_STREAM;

    if (*pDst == NULL)
        *pDst = malloc(sLen);
    else
        *pDst = realloc(*pDst, sLen);

    return buff_read(pBuff, *pDst, sLen);
}
