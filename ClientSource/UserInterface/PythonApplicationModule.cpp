// At the end of the file and before } Add :

#ifdef ENABLE_SPECIAL_SWITCHERS
	PyModule_AddIntConstant(poModule, "ENABLE_SPECIAL_SWITCHERS", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SPECIAL_SWITCHERS", 0);
#endif

