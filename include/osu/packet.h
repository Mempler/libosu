#ifndef _H_LIB_OSU_PACKET
#define _H_LIB_OSU_PACKET

#include "_err/err.h"
#include "buffer.h"
#include "packet_id.h"
#include "inc.h"

OSU_NAMESPACE_BEGIN

typedef struct
{
    packet_id   id;
    osu_buffer* data;
} osu_packet;

// This will also free the packet!
HRESULT buff_write_packet(osu_buffer* pBuff, osu_packet** pPacket);

osu_packet* packet_create(packet_id pId);
HRESULT packet_free(osu_packet** pPacket);

OSU_NAMESPACE_END

#endif