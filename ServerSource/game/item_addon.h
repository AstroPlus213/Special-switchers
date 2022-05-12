// After :

		void ApplyAddonTo(int iAddonType, LPITEM pItem);

// Add :

#ifdef ENABLE_SPECIAL_SWITCHERS
		bool SwitchAddonTo(LPITEM pkItem, bool bMaxAttr = false);
#endif
