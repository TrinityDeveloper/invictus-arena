#include "ScriptPCH.h"
 
 
 
#define TOKEN 26044
#define TOKENAMOUNT 1
 
class vip_granter : public CreatureScript
{
        public:
                vip_granter() : CreatureScript("vip_granter") {}
 
        bool OnGossipHello(Player* player, Creature* creature)
{
 
if(player->HasItemCount(26044, 1, false) && player->GetSession()->GetSecurity() == SEC_PLAYER)
{
LoginDatabase.PQuery("INSERT INTO account_access (id, gmlevel, RealmID) VALUES (%u, 1, -1)", player->GetSession()->GetAccountId());
 
creature->MonsterWhisper("Your account is now flagged as VIP. Thank you for your contribution.", player->GetGUID());
player->DestroyItemCount(TOKEN, TOKENAMOUNT, true);
return false;
}
 
else
creature->MonsterWhisper("You do not have a VIP Token, or you are already a VIP. Please consult the website at invictusarena.net for more information on how you can obtain VIP Status, or make an ingame ticket and a Gamemaster will assist you.", player->GetGUID());
player->CLOSE_GOSSIP_MENU();
return false;
}
};
 
 
void AddSC_vip_granter()
{
        new vip_granter;
}