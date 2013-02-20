# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
Custom/Title_NPC.cpp
#Custom/title_rewarder.cpp
#Custom/duel_reset.cpp
Custom/vipcommands.cpp
Custom/teleport_npc.cpp
Custom/zone_lock.cpp
Custom/npc_hunterpetvendor.cpp
Custom/TransmogDisplayVendorConf.h
Custom/TransmogDisplayVendor.cpp
Custom/vip_granter.cpp
Custom/utility_commandscript.cpp
)

message("  -> Prepared: Custom")
