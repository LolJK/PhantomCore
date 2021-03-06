/*
 * Copyright (C) 2009 - 2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "ScriptedPch.h"
#include "icecrown_citadel.h"

/*HACK*/
struct boss_blood_elf_ValanarAI : public ScriptedAI
{
    boss_blood_elf_ValanarAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
		m_pInstance = pCreature->GetInstanceData();
    }
    
    ScriptedInstance* m_pInstance;


    void Reset()
    {

		if(m_pInstance)
		m_pInstance->SetData(DATA_BLOOD_PRINCE_COUNCIL_EVENT, NOT_STARTED);  
    }

    void JustDied(Unit* pKiller)
    {
		if(m_pInstance)
		m_pInstance->SetData(DATA_BLOOD_PRINCE_COUNCIL_EVENT, DONE);  
    }

    void EnterCombat(Unit* who)
    {
		if(m_pInstance)
		m_pInstance->SetData(DATA_BLOOD_PRINCE_COUNCIL_EVENT, IN_PROGRESS);  
    }

    void JustReachedHome()
    {
		if(m_pInstance)
		m_pInstance->SetData(DATA_BLOOD_PRINCE_COUNCIL_EVENT, FAIL);  
    }

    void KilledUnit(Unit *victim)
    {
    }

	void UpdateAI(const uint32 diff)
	{
		if (!UpdateVictim())
			return;


		DoMeleeAttackIfReady();
	}
};

struct boss_blood_elf_TaldaramAI : public ScriptedAI
{
    boss_blood_elf_TaldaramAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
		m_pInstance = pCreature->GetInstanceData();
    }
    
    ScriptedInstance* m_pInstance;


    void Reset()
    {
    }

    void EnterCombat(Unit* who)
    {
    }

    void KilledUnit(Unit *victim)
    {
    }

	void UpdateAI(const uint32 diff)
	{
		if (!UpdateVictim())
			return;

		DoMeleeAttackIfReady();
	}
};

struct boss_blood_elf_KelesetAI : public ScriptedAI
{
    boss_blood_elf_KelesetAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
		m_pInstance = pCreature->GetInstanceData();
    }
    
    ScriptedInstance* m_pInstance;


    void Reset()
    {
    }

    void EnterCombat(Unit* who)
    {
    }

    void KilledUnit(Unit *victim)
    {
    }

	void UpdateAI(const uint32 diff)
	{
		if (!UpdateVictim())
			return;
		DoMeleeAttackIfReady();
	}
};

CreatureAI* GetAI_boss_blood_elf_Valanar(Creature* pCreature)
{
    return new boss_blood_elf_ValanarAI(pCreature);
}

CreatureAI* GetAI_boss_blood_elf_Taldaram(Creature* pCreature)
{
    return new boss_blood_elf_TaldaramAI(pCreature);
}

CreatureAI* GetAI_boss_blood_elf_Keleset(Creature* pCreature)
{
    return new boss_blood_elf_KelesetAI(pCreature);
}

void AddSC_boss_rat_des_blutes()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "boss_blood_elf_Valanar";
    NewScript->GetAI = &GetAI_boss_blood_elf_Valanar;
    NewScript->RegisterSelf();

	NewScript = new Script;
    NewScript->Name = "boss_blood_elf_Taldaram";
    NewScript->GetAI = &GetAI_boss_blood_elf_Taldaram;
    NewScript->RegisterSelf();

	NewScript = new Script;
    NewScript->Name = "boss_blood_elf_Keleset";
    NewScript->GetAI = &GetAI_boss_blood_elf_Keleset;
    NewScript->RegisterSelf();
}
