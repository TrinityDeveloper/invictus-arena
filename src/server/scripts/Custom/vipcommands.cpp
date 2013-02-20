#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Common.h"
#include "Group.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Player.h"


class vipcommands : public CommandScript
{
public:
    vipcommands() : CommandScript("vipcommands") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand vipCommandTable[] =

        {
            { "mall",	    SEC_MODERATOR,     true, &HandleVipMallCommand,         "", NULL },
            { "chat",	    SEC_MODERATOR,     true, &HandleVipChatCommand,         "", NULL },
           // { "changerace",    SEC_PLAYER,  false, &HandleChangeRaceCommand,             "", NULL },
	   // { "changefaction",	SEC_PLAYER,  false, &HandleChangeFactionCommand,		"", NULL },
	   // { "maxskills",	SEC_PLAYER,  false, &HandleMaxSkillsCommand,		"", NULL },
	    //{ "customize",	SEC_PLAYER,  false, &HandleCustomizeCommand,		"", NULL },
	    //{ "tele",           SEC_MODERATOR,  false, &HandleTeleCommand,		"", NULL },
 
            { NULL,             0,                     false, NULL,                                           "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "vip",	    SEC_MODERATOR,   true, NULL,      "",  vipCommandTable},
	       { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }


/*static bool HandleTeleCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player* me = handler->GetSession()->GetPlayer();

        // id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
        GameTele const* tele = handler->extractGameTeleFromLink((char*)args);

        if (!tele)
        {
            handler->SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (me->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        MapEntry const* map = sMapStore.LookupEntry(tele->mapId);
        if (!map || map->IsBattlegroundOrArena())
        {
            handler->SendSysMessage(LANG_CANNOT_TELE_TO_BG);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (me->isInFlight())
        {
            me->GetMotionMaster()->MovementExpired();
            me->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            me->SaveRecallPosition();

        me->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
        return true;
		}
		*/
static bool HandlevipCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();

            me->Say("Vip Command?", LANG_UNIVERSAL);
            return true;
    }

/*static bool HandleChangeRaceCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
		handler->PSendSysMessage("Relog to change the race of your character.");
        return true;
    }*/

/*static bool HandleChangeFactionCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
		handler->PSendSysMessage("Relog to change the faction of your character.");
        return true;
    }*/

/*static bool HandleMaxSkillsCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->UpdateSkillsForLevel();
		handler->PSendSysMessage("Your weapon skills have been maxed.");
        return true;
    }*/

/*static bool HandleCustomizeCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
		handler->PSendSysMessage("Relog to customize your character.");
        return true;
    }*/

static bool HandleVipMallCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();

        if (me->isInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (me->isInFlight())
        {
            me->GetMotionMaster()->MovementExpired();
            me->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            me->SaveRecallPosition();

		me->TeleportTo(1,	16233.732422f,	16308.127930f,	20.844587f,	5.647734f); // MapId, X, Y, Z, O
                return true;
    }


static bool HandleVipChatCommand(ChatHandler * handler, const char * args)
	{
		if (!args)
			return false;

		std::string msg = "";
		Player * player = handler->GetSession()->GetPlayer();

		switch(player->GetSession()->GetSecurity())
		{
 			case SEC_MODERATOR: // VIP
				msg += "|cffff0000[VIP|r |cff18be00Chat:|r [";
				msg += player->GetName();
				msg += "]: |CFF7BBEF7";
				break;

				
			case SEC_GAMEMASTER: // GM
				msg += "|CFF520084[Gamemaster|r |cff18be00Chat:|r [";
				msg += player->GetName();
				msg += "]: |CFF7BBEF7";
				break;
				
						
			case SEC_ADMINISTRATOR: // EGM
				msg += "|cfffa9900[Administrator|r |cff18be00Chat:|r [";
				msg += player->GetName();
				msg += "]: |CFF7BBEF7";
				break;
				
			case SEC_CONSOLE: // ADMIN
				msg += "|CFF18E7BD[Administrator|r |cff18be00Chat:|r [";
				msg += player->GetName();
				msg += "]: |CFF7BBEF7";
				break;
								
		}
			
		msg += args;
		sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), 0);	

		return true;
	}
	
};

void AddSC_vipcommands()
{
    new vipcommands();
}