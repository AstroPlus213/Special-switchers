// Add :

#ifdef ENABLE_SPECIAL_SWITCHERS
#include "questmanager.h"
#endif

// At the end of the file add :

#ifdef ENABLE_SPECIAL_SWITCHERS
bool CItemAddonManager::SwitchAddonTo(LPITEM pkItem, bool bMaxAttr)
{
	if (!pkItem)
	{
		sys_err("ITEM pointer null");
		return false;
	}

	int iFKSIndex = pkItem->FindAttribute(APPLY_SKILL_DAMAGE_BONUS);
	int iDSSIndex = pkItem->FindAttribute(APPLY_NORMAL_HIT_DAMAGE_BONUS);
	
	if (iFKSIndex == -1 && iDSSIndex == -1)
		return false;

	int iFKS, iDSS = 0;
	//The value of "e_special_attr" adds to the value of iDSS.
	int iSpecialAttrEvent = quest::CQuestManager::instance().GetEventFlag("e_special_attr");

	if (bMaxAttr)
	{
		iFKS = 30;
		iDSS = 60 + iSpecialAttrEvent;
	}
	else
	{
		iFKS = MINMAX(-30, (int)(gauss_random(0, 5) + 0.5f), 30);
		iDSS = 0;
		if (abs(iFKS) <= 20)
			iDSS = -2 * iFKS + abs(number(-8, 8) + number(-8, 8)) + number(1, 4);
		else
			iDSS = -2 * iFKS + number(1, 5);
	}

	if (iFKSIndex > -1)
		pkItem->SetAttribute(iFKSIndex, APPLY_SKILL_DAMAGE_BONUS, (iFKS == 0 ? 1 : iFKS));

	if (iDSSIndex > -1)
		pkItem->SetAttribute(iDSSIndex, APPLY_NORMAL_HIT_DAMAGE_BONUS, (iDSS == 0 ? 1 : iDSS));

	return true;
}
#endif


