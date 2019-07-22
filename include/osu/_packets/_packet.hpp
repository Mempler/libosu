#ifndef _H_LIB_OSU__PACKETS__PACKET
#define _H_LIB_OSU__PACKETS__PACKET

#include "../inc.h"
#include "../packet.h"

OSU_NAMESPACE_BEGIN

#ifdef __cplusplus
class SPacket
{
    public:
        inline
        ~SPacket() {
            if (Packet != nullptr)
                packet_free(&this->Packet);
            Packet = nullptr;
        }

        virtual
        inline
        void Write(osu::OsuBuffer* pBuff) = 0;

    protected:
        osu_packet* Packet = nullptr;
};
#endif

OSU_NAMESPACE_END

#endif
