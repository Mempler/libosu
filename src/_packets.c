#include <stdlib.h>

#include <osu/_packets/announce.h>

osu_packet*
CreateS0x18Announcement(const char* pStr, size_t pLen) {
    osu_packet* p = packet_create(ServerAnnounce);

    buff_write_string(p->data, pStr, pLen, false);    
    
    return p;
}
