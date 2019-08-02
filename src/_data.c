#include <stdlib.h>

#include <osu/packets.h>

pd_channel*
MakeChannel(const char* pChannelName, size_t pChannelNameSize,
            const char* pChannelTopic, size_t pChannelTopicSize,
            short pChannelUserCount) {
    pd_channel* chan = (pd_channel*) malloc(sizeof(pd_channel));

    chan->channel_name = pChannelName;
    chan->channel_name_len = pChannelNameSize;

    chan->channel_topic = pChannelTopic;
    chan->channel_topic_len = pChannelTopicSize;

    chan->channel_user_count = pChannelUserCount;

    return chan;
}

HRESULT
FreeChannel(pd_channel** pChannel) {
    if (pChannel == NULL || *pChannel == NULL)
        return E_INVALID_POINTER;
    
    free(*pChannel);
    *pChannel = NULL;

    return S_OK;
}