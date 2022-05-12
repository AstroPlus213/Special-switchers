// Add :

#ifdef ENABLE_SPECIAL_SWITCHERS
#include "item_addon.h"
#endif


// Search for :

					case USE_ADD_ATTRIBUTE:
					case USE_ADD_ATTRIBUTE2:

// Add :

#ifdef ENABLE_SPECIAL_SWITCHERS
					case USE_CHANGE_ATTRIBUTE3:
#endif

// Before :

								case USE_ADD_ACCESSORY_SOCKET:

// Add :

#ifdef ENABLE_SPECIAL_SWITCHERS
								case USE_CHANGE_ATTRIBUTE3:
									{
										if (CItemAddonManager::instance().SwitchAddonTo(item2, item->GetValue(0) == 1 ? true : false))
											item->SetCount(item->GetCount() - 1);
										else
											ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You cannot change the upgrade of this item."));
									}
									break;
#endif

