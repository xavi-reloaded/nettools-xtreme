/*
 * Base64.h
 *
 *  Created on: Jun 25, 2017
 *      Author: xavi
 */


#ifndef _CBASE64
#define _CBASE64

#include <string>

class CBase64
{
public:
	CBase64();
	virtual ~CBase64();

	std::string encode(std::string str);
	std::string decode(std::string str);

	unsigned int EncryptBase64(const char* in, unsigned int lin, char* out);
	unsigned int DecryptBase64(const std::string* inp, std::string* out);
	unsigned int DecryptBase64(const std::string* inp, char* out);

	inline bool is_base64(unsigned char c);
	std::string base64_decode(std::string const& encoded_string);
	std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);
};

#endif
