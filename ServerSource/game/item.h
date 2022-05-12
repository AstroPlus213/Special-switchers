// Search for :

	private:
		void		SetAttribute(int i, BYTE bType, short sValue);

// Replace with :

#ifdef ENABLE_SPECIAL_SWITCHERS
	public:
		void		SetAttribute(int i, BYTE bType, short sValue);
#else
	private:
		void		SetAttribute(int i, BYTE bType, short sValue);
#endif
