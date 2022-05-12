// At the end of the file and before } Add :

#ifdef ENABLE_SPECIAL_SWITCHERS
	PyModule_AddIntConstant(poModule, "USE_CHANGE_ATTRIBUTE3",		CItemData::USE_CHANGE_ATTRIBUTE3);
#endif

