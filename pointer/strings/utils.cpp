void string_copy(char* t, char* str) {
	char* pd = t;
	char* ps = str;
	for (;*pd = *ps;) {
		pd++;
		ps++;
	};
}
int len(const char* s) {
	int i = 0;
	while (s[i]!=0)
	{
		i++;
	}
	return i;
}
int compare(const char* s, const char* t) {
	for (;*s != 0  && *t != 0 && *s==*t;) {
		s++;
		t++;
	}
	return *s - *t;
}