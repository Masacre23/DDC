#include "auxiliar.h"


void Tokenize(string s, vector <string>& v) //Separate words
{
	char str[1024];
	strncpy_s(str, s.c_str(), sizeof(str));
	str[sizeof(str) - 1] = 0;
	string aux = "";
	int numWords = 0;

	for (unsigned i = 0; i < s.size(); ++i)
	{
		if (str[i] != ' ')
		{
			aux = aux + str[i];
		}
		else {
			v.push_back(aux);
			aux = "" + NULL;
		}
	}
	v.push_back(aux);
}
