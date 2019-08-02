#include <stdlib.h>

#include <osu/packets.h>

osu_packet*
CreateS0x18Announcement(const char* pStr, size_t pLen) {
    osu_packet* p = packet_create(ServerAnnounce);

    buff_write_string(p->data, pStr, pLen, false);    
    
    return p;
}

osu_packet*
CreateS0x41ChannelAvailable(const pd_channel* pChannel) {
    osu_packet* p = packet_create(ServerChannelAvailable);

    buff_write_string(p->data, pChannel->channel_name, pChannel->channel_name_len, false);
    buff_write_string(p->data, pChannel->channel_topic, pChannel->channel_topic_len, true);
    buff_write(p->data, &pChannel->channel_user_count, 0x02);

    return p;
}
