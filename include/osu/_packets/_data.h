#ifndef _H_LIB_OSU__PACKETS__DATA
#define _H_LIB_OSU__PACKETS__DATA

#include "../inc.h"

OSU_NAMESPACE_BEGIN

#include <stddef.h>

typedef struct {

    const char*  channel_name;
    size_t channel_name_len;
    
    const char*  channel_topic;
    size_t channel_topic_len;

    short  channel_user_count;

} pd_channel;

pd_channel* MakeChannel(const char* pChannelName, size_t pChannelNameSize,
                        const char* pChannelTopic, size_t pChannelTopicSize,
                        short pChannelUserCount);

HRESULT FreeChannel(pd_channel** pChannel);

OSU_NAMESPACE_END

#endif