#ifndef _H_LIB_OSU__PACKETS_CHAT_CHANNEL_CHANNEL_AVAILABLE
#define _H_LIB_OSU__PACKETS_CHAT_CHANNEL_CHANNEL_AVAILABLE

#include "../../_packet.hpp"

OSU_NAMESPACE_BEGIN

osu_packet* CreateS0x41ChannelAvailable(const pd_channel* pChannel);

#ifdef __cplusplus
class S0x41ChannelAvailable : public SPacket
{
    public:
        explicit
        inline
        S0x41ChannelAvailable(pd_channel* pChannel)
        {
            Packet = CreateS0x41ChannelAvailable(pChannel);
        }

        inline
        ~S0x41ChannelAvailable() {
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
