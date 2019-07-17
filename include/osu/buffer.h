#ifndef _H_LIB_OSU_BUFFER
#define _H_LIB_OSU_BUFFER

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t* bytes;

    size_t position;
    size_t bytes_len;
} osu_buffer;

osu_buffer* make_buffer();
void free_buffer(osu_buffer* pBuffer);

size_t buff_write(osu_buffer* pDst,
    const void* pSrc, size_t pSrcSize);

size_t buff_write_string(osu_buffer* pDst,
    const char* pSrc, size_t pSrcSize, bool pNullable);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>

// C++ Wrapper
class OsuBuffer
{
public:
    inline OsuBuffer()  { this->buff = make_buffer(); }
    inline ~OsuBuffer() { free_buffer(this->buff);    }

    template <class T>
    size_t Write(T pSrc) { return buff_write(this->buff, &pSrc, sizeof(pSrc)); }

    size_t Write(const std::string& pSrc, bool pNullable = false) {
        return buff_write_string(this->buff, pSrc.c_str(), pSrc.length(), pNullable); }

    inline
    size_t Write(const char* pSrc) { return Write(std::string(pSrc)); }

    inline
    void Print() {
        printf("Bytes {\n  ");
        for (size_t i = 0; i < buff->bytes_len; i++)
            printf("0x%02x ", buff->bytes[i] & 0xff);
        printf("\n}\n");
    }

private:
    osu_buffer* buff;
};

#define D_BUFF_PRINTLN(buff) \
    { \
        buff.Print(); \
    }

#else

#define D_BUFF_PRINTLN(buff) \
    { \
        printf("Bytes {\n  "); \
        for (size_t i = 0; i < buff->bytes_len; i++) \
            printf("0x%02x ", buff->bytes[i] & 0xff); \
        printf("\n}\n"); \
    }

#endif

#endif