#ifndef _H_LIB_OSU_PACKET_ID
#define _H_LIB_OSU_PACKET_ID

#include "inc.h"

OSU_NAMESPACE_BEGIN

typedef enum {
    ClientSendUserStatus             = 0x00,
    ClientSendIrcMessage             = 0x01,
    ClientExit                       = 0x02,
    ClientRequestStatusUpdate        = 0x03,
    ClientPong                       = 0x04,
    ServerLoginResponse              = 0x05,
    ServerCommandError               = 0x06,
    ServerSendMessage                = 0x07,
    ServerPing                       = 0x08,
    ServerHandleIrcChangeUsername    = 0x09,
    ServerHandleIrcQuit              = 0x0A,
    ServerHandleOsuUpdate            = 0x0B,
    ServerHandleUserQuit             = 0x0C,
    ServerSpectatorJoined            = 0x0D,
    ServerSpectatorLeft              = 0x0E,
    ServerSpectateFrames             = 0x0F,
    ClientStartSpectating            = 0x10,
    ClientStopSpectating             = 0x11,
    ClientSpectateFrames             = 0x12,
    ServerVersionUpdate              = 0x13,
    ClientErrorReport                = 0x14,
    ClientCantSpectate               = 0x15,
    ServerSpectatorCantSpectate      = 0x16,
    ServerGetAttention               = 0x17,
    ServerAnnounce                   = 0x18,
    ClientSendIrcMessagePrivate      = 0x19,
    ServerMatchUpdate                = 0x1A,
    ServerMatchNew                   = 0x1B,
    ServerMatchDisband               = 0x1C,
    ClientLobbyPart                  = 0x1D,
    ClientLobbyJoin                  = 0x1E,
    ClientMatchCreate                = 0x1F,
    ClientMatchJoin                  = 0x20,
    ClientMatchPart                  = 0x21,
    ServerMatchJoinSuccess           = 0x24,
    ServerMatchJoinFail              = 0x25,
    ClientMatchChangeSlot            = 0x26,
    ClientMatchReady                 = 0x27,
    ClientMatchLock                  = 0x28,
    ClientMatchChangeSettings        = 0x29,
    ServerFellowSpectatorJoined      = 0x2A,
    ServerFellowSpectatorLeft        = 0x2B,
    ClientMatchStart                 = 0x2C,
    ServerMatchStart                 = 0x2E,
    ClientMatchScoreUpdate           = 0x2F,
    ServerMatchScoreUpdate           = 0x30,
    ClientMatchComplete              = 0x31,
    ServerMatchTransferHost          = 0x32,
    ClientMatchChangeMods            = 0x33,
    ClientMatchLoadComplete          = 0x34,
    ServerMatchAllPlayersLoaded      = 0x35,
    ClientMatchNoBeatmap             = 0x36,
    ClientMatchNotReady              = 0x37,
    ClientMatchFailed                = 0x38,
    ServerMatchPlayerFailed          = 0x39,
    ServerMatchComplete              = 0x3A,
    ClientMatchHasBeatmap            = 0x3B,
    ClientMatchSkipRequest           = 0x3C,
    ServerMatchSkip                  = 0x3D,
    ServerUnauthorised               = 0x3E,
    ClientChannelJoin                = 0x3F,
    ServerChannelJoinSuccess         = 0x40,
    ServerChannelAvailable           = 0x41,
    ServerChannelRevoked             = 0x42,
    ServerChannelAvailableAutojoin   = 0x43,
    ClientBeatmapInfoRequest         = 0x44,
    ServerBeatmapInfoReply           = 0x45,
    ClientMatchTransferHost          = 0x46,
    ServerLoginPermissions           = 0x47,
    ServerFriendsList                = 0x48,
    ClientFriendAdd                  = 0x49,
    ClientFriendRemove               = 0x4A,
    ServerProtocolNegotiation        = 0x4B,
    ServerTitleUpdate                = 0x4C,
    ClientMatchChangeTeam            = 0x4D,
    ClientChannelLeave               = 0x4E,
    ClientReceiveUpdates             = 0x4F,
    ServerMonitor                    = 0x50,
    ServerMatchPlayerSkipped         = 0x51,
    ClientSetIrcAwayMessage          = 0x52,
    ServerUserPresence               = 0x53,
    ClientUserStatsRequest           = 0x55,
    ServerRestart                    = 0x56,
    ClientInvite                     = 0x57,
    ServerInvite                     = 0x58,
    ServerChannelListingComplete     = 0x59,
    ClientMatchChangePassword        = 0x5A,
    ServerMatchChangePassword        = 0x5B,
    ServerBanInfo                    = 0x5C,
    ClientSpecialMatchInfoRequest    = 0x5D,
    ServerUserSilenced               = 0x5E,
    ServerUserPresenceSingle         = 0x5F,
    ServerUserPresenceBundle         = 0x60,
    ClientUserPresenceRequest        = 0x61,
    ClientUserPresenceRequestAll     = 0x62,
    ClientUserToggleBlockNonFriendPm = 0x63,
    ServerUserPmBlocked              = 0x64,
    ServerTargetIsSilenced           = 0x65,
    ServerVersionUpdateForced        = 0x66,
    ServerSwitchServer               = 0x67,
    ServerAccountRestricted          = 0x68,
    ServerRtx                        = 0x69,
    ClientMatchAbort                 = 0x6A,
    ServerSwitchTourneyServer        = 0x6B,
    ClientSpecialJoinMatchChannel    = 0x6C,
    ClientSpecialLeaveMatchChannel   = 0x6D
} packet_id;

#endif

OSU_NAMESPACE_END
