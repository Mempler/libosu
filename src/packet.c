#include <osu/packet.h>
#include <stdlib.h>

const char O_ZERO = 0x00;

HRESULT
buff_write_packet(osu_buffer* pBuff,
    osu_packet* pPacket) {
    if (pPacket == NULL)
        return E_INVALID_POINTER;

    uint16_t packetId = pPacket->id;
    buff_write(pBuff, &packetId, 0x02);
    buff_write(pBuff, &O_ZERO, 0x01);
    buff_write(pBuff, &pPacket->data->bytes_len, 0x04);
    buff_write(pBuff, pPacket->data->bytes, pPacket->data->bytes_len);

    // Prevent of the stack being cleared before the execution has finished
    HRESULT hr = packet_free(&pPacket);
    return hr;
}

HRESULT
packet_free(osu_packet** pPacket) {
    if (pPacket == NULL || *pPacket == NULL)
        return E_INVALID_POINTER;
    
    free(*pPacket);
    *pPacket = NULL;
    return S_OK;
}
