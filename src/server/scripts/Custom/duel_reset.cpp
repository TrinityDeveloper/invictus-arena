#include "ScriptPCH.h"

class duel_reset : public PlayerScript
{
    public:
        duel_reset() : PlayerScript("duel_reset") { }

        void OnDuelStart(Player* pl)
        {
        }

        void OnDuelEnd(Player* pl, DuelCompleteType)
        {
          if (pl->GetAreaId() != 441 && pl->GetAreaId() != 2401) return;
            pl->SetHealth(pl->GetMaxHealth());
            pl->SetPower(POWER_MANA, pl->GetMaxPower(POWER_MANA));
            pl->RemoveAllSpellCooldown();
            pl->RemoveAura(41425);
            pl->RemoveAura(25771);
            pl->RemoveAura(57724);
            pl->RemoveAura(57723);
            pl->RemoveAura(66233);
            pl->RemoveAura(11196);

                   }
};

void AddSC_duel_reset()
{
    new duel_reset();
}