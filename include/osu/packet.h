#ifndef _H_LIB_OSU_PACKET
#define _H_LIB_OSU_PACKET

#include "_err/err.h"
#include "buffer.h"
#include "packet_id.h"

#ifdef __cplusplus
namespace osu {
extern "C" {
#endif

typedef struct
{
    packet_id  id;
    osu_buffer* data;
} osu_packet;

// This will also free the packet!
HRESULT buff_write_packet(osu_buffer* pBuff,
    osu_packet* pPacket);

HRESULT packet_free(osu_packet** pPacket);

#ifdef __cplusplus
}
}
#endif

#endif