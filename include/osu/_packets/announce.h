#ifndef _H_LIB_OSU__PACKETS_ANNOUNCE
#define _H_LIB_OSU__PACKETS_ANNOUNCE

#include "../packet.h"
#include "_packet.hpp"

OSU_NAMESPACE_BEGIN

osu_packet* CreateS0x18Announcement(const char* pStr, size_t pLen);

#ifdef __cplusplus
class S0x18Announce : public SPacket
{
    public:
        inline
        S0x18Announce(const std::string& pStr)
        {
            Packet = CreateS0x18Announcement(pStr.c_str(), pStr.size());
        }

        inline
        ~S0x18Announce() {
            if (Packet != nullptr)
                packet_free(&this->Packet);
            Packet = nullptr;
        }

        inline
        void Write(osu::OsuBuffer* pBuff) override
        {
            if (pBuff == nullptr ||
                pBuff->GetBuffer() == nullptr)
                throw E_INVALID_POINTER;
            
            HRESULT hr = buff_write_packet(pBuff->GetBuffer(), &this->Packet);
            if (hr != S_OK)
                throw hr;
        }
};
#endif

OSU_NAMESPACE_END

#endif
