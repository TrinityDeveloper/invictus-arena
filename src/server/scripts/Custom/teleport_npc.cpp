#include "ScriptPCH.h"
 
#define ORGRIMMAR 1,    1487.261108f,  -4416.255371f,    24.082134f, 0.159400f
#define IRONFORGE  0,   -4954.671387f,   -1005.685425f,   501.441071f, 0.416538f
#define GURUBASHI  0,   -13239.008789f,    229.664322f,   34.073196f,  0.204953f
#define TRIALS     530, -1983.075684f,   6576.570801f,   12.819382f,  2.586493f
#define MAUL       1,   -3747.376221f,   1163.778198f,  128.275238f,  2.330298f
#define DUELZONE   530,    -1524.053955f,    -12499.312500f,    3.904669f,  0.033787f
#define VIPMALL    1,  16232.500000f,  16310.500000f,    20.850901f,  5.533870f
//#define RPMALL       1,  7450.502441f,  -1552.279785f,  177.819031f,  0.190201f
#define HANDLE(action, teleport) case action:\
    Teleport(player, teleport);\
    break;
 
 
class teleport_npc : public CreatureScript
{
    public:
        teleport_npc() : CreatureScript("teleport_npc")
        {
        }
 
        void Teleport(Player* player, uint32 map, float x, float y, float z, float o)
        {
            player->TeleportTo(map, x, y, z, o);
            player->CLOSE_GOSSIP_MENU();
        }
 
        void ShowCitiesMenu(Player* player, Creature* creature)
        {
            player->PlayerTalkClass->ClearMenus();
            if (player->GetTeam() == ALLIANCE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Ironforge", GOSSIP_SENDER_MAIN, 44);
            else
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Orgrimmar", GOSSIP_SENDER_MAIN, 41);
       
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Back", GOSSIP_SENDER_MAIN, -1);
            player->SEND_GOSSIP_MENU(1, creature->GetGUID());
        }
 
        void ShowPvpZonesMenu(Player* player, Creature* creature)
        {
            player->PlayerTalkClass->ClearMenus();
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Gurubashi", GOSSIP_SENDER_MAIN,
                30);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Ring of Trials", GOSSIP_SENDER_MAIN,
                31);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Dire Maul", GOSSIP_SENDER_MAIN,
                32);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Back", GOSSIP_SENDER_MAIN, -1);
            player->SEND_GOSSIP_MENU(1, creature->GetGUID());
        }
 
        void ShowMallsMenu(Player* player, Creature* creature)
        {
            player->PlayerTalkClass->ClearMenus();
            if (player->GetTeam() == ALLIANCE)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Ironforge", GOSSIP_SENDER_MAIN,
                    44);
                         }
            else
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Orgrimmar", GOSSIP_SENDER_MAIN,
                    41);
                           }
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Back", GOSSIP_SENDER_MAIN, -1);
            player->SEND_GOSSIP_MENU(1, creature->GetGUID());
        }
 
        void ShowPetMallMenu(Player* player, Creature* creature)
        {
            player->PlayerTalkClass->ClearMenus();
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Ironforge", GOSSIP_SENDER_MAIN, 44);
            player->SEND_GOSSIP_MENU(1, creature->GetGUID());
        }
               
        void ShowMainMenu(Player* player, Creature* creature)
        {
            player->PlayerTalkClass->ClearMenus();
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, "Cities", GOSSIP_SENDER_MAIN, 1);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, "Malls", GOSSIP_SENDER_MAIN, 3);
         
                        if (player->GetSession()->GetSecurity() >= SEC_MODERATOR)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, "VIP Mall", GOSSIP_SENDER_MAIN, 5);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "PvP Zones", GOSSIP_SENDER_MAIN, 2);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Duel Zone - Arathi Highlands", GOSSIP_SENDER_MAIN, 6);
                               /* if (player->getClass() == CLASS_HUNTER)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Pet Mall", GOSSIP_SENDER_MAIN, 7);
            }
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "RP/Transmog Mall", GOSSIP_SENDER_MAIN,  8);
                player->SEND_GOSSIP_MENU(1, creature->GetGUID());*/
        }
 
        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (player->isInCombat()) return false;
            ShowMainMenu(player, creature);
            return true;
        }
 
        bool OnGossipSelect(Player* player, Creature* creature,
                            uint32 /*sender*/, uint32 action)
        {
            switch (action)
            {
                case -1:
                    ShowMainMenu(player, creature);
                    break;
                case 1:
                    ShowCitiesMenu(player, creature);
                    break;
                case 2:
                    ShowPvpZonesMenu(player, creature);
                    break;
                case 3:
                    ShowMallsMenu(player, creature);
                    break;
              /*  case 7:
                    ShowPetMallMenu(player, creature);
                    break;
             */
                HANDLE(5,   VIPMALL)
                HANDLE(6,   DUELZONE)
            //    HANDLE(8,   RPMALL)
                HANDLE(30,  GURUBASHI)
                HANDLE(31,  TRIALS)
                HANDLE(32,  MAUL)
                HANDLE(41,  ORGRIMMAR)
                HANDLE(44,  IRONFORGE)
             
            }
			return true;
		}
};
 
void AddSC_teleport_npc()
{
    new teleport_npc();
}