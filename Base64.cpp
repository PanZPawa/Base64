#include <iostream>
#include "Base64.h"

Base64::Base64()
{
	for (int i = 0; i < 64; i++) {
		decode_table[list[i]] = i;
	}
}

std::string Base64::ChangeAll(std::string Original) {
	std::string translation;

	int val = 0;
	int valb = 0;
	for (char& c : Original) {
		val = (val << 8) + c;
		valb += 8;
		while (valb >= 6) {
			valb -= 6;
			translation.push_back(list[(val >> valb  ) & 0x3f]);
		}
		if (valb == 0) val = 0;
	}
	if (valb > 0) {
		translation.push_back(list[(val <<  (6-valb) ) & 0x3f]);
	}

	while(translation.size() % 4) {
		translation.push_back('=');
	}

	return translation;
}

std::string Base64::Restore(std::string translation)
{
	std::string Original;
	int val = 0;
	int valb = 0;
	for (char& c : translation) {
		if (c == '=') break;
		int d = decode_table[c];
		val = (val << 6) + d;
		valb += 6;
		if (valb >= 8) {
			valb -= 8;
			Original.push_back(char((val >> valb) & 0xff) );
		}
		if (valb == 0) val = 0;
	}
	return Original;
}




/*
int main() {
	Base64 base;
	std::string ss;
	std::cin >> ss;
	std::string r = base.ChangeAll(ss); //º”√‹
	std::cout << r<<std::endl;

	std::cout << base.Restore(r) << std::endl; //Ω‚√‹
}
*/
