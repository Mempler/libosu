#ifndef _H_LIB_OSU_BUFFER
#define _H_LIB_OSU_BUFFER

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#define S_OK 0x00;
#define E_UNABLE_TO_READ_BEYOND_STREAM 0x05FF6587
#define E_S_IS_NOT_AN_S 0x05FF6588

#ifdef __cplusplus
namespace osu {
extern "C" {
#endif

typedef struct {
    uint8_t* bytes;

    size_t position;
    size_t bytes_len;
} osu_buffer;

osu_buffer* make_buffer();
void free_buffer(osu_buffer* pBuffer);

size_t buff_write(osu_buffer* pBuff,
    const void* pSrc, size_t pSrcSize);

size_t buff_write_string(osu_buffer* pBuff,
    const char* pSrc, size_t pSrcSize, bool pNullable);

int buff_read(osu_buffer* pBuff,
    void* pDst, size_t pSize);

int buff_read_string(osu_buffer* pBuff,
    char** pDst);

#ifdef __cplusplus
}
}
#endif

#ifdef __cplusplus

#include <string>

namespace osu {
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

    template <class T>
    T Read() {
        T t;
        int E = buff_read(this->buff, &t, sizeof(t));

        if (E)
            throw E;

        return t;
    }

    inline
    std::string ReadString() {
        char* cp = nullptr;
        int E = buff_read_string(this->buff, &cp);

        if (E)
            throw E;

        return std::string(cp);
    }

    void SetPosition(int p) {
        this->buff->position = p;
    }

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
}

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