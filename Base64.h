#pragma once
class Base64 {

public:
	Base64();

	std::string ChangeAll(std::string Original); //¸ü»»È«²¿×Ö·û
	
	std::string Restore(std::string translation);

private:
	const char list[65] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int decode_table[257] = { 0 };
};