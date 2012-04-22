#define CHECK_COMMAND(expectedName) \
	if (strcmp(#expectedName, name) == 0) { \
		return new expectedName(this); \
	}

//CHECK_COMMAND(Visit)
CHECK_COMMAND(Send)