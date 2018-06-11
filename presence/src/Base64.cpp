/*
 * Base64.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: xavi
 */

#include "Base64.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


static char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


CBase64::CBase64() {

}

CBase64::~CBase64() {
	// TODO Auto-generated destructor stub
}

std::string CBase64::encode(std::string str){

	char* buffer = (char*)malloc( str.length());
	unsigned int bufferLength = this->EncryptBase64(str.c_str(), str.length(), buffer);

	std::string b64Value;
	b64Value.append(buffer, bufferLength);
	//free(buffer);
	return b64Value;
}


std::string CBase64::decode(std::string str){
	//char* decoded = (char*)malloc(str.length() + 1);
	   //this->EncryptBase64( const_cast<char*>(&str), lin, decoded);
	//this->DecryptBase64( const_cast<std::string*>(&str) , decoded);
	std::string decoded = this->base64_decode(str);
	return decoded;
}


inline bool CBase64::is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string CBase64::base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;

}
std::string CBase64::base64_decode(std::string const& encoded_string) {
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}


unsigned int CBase64::EncryptBase64(const char* in, unsigned int lin, char* out)
{
    unsigned int n = 0, x;

	while( lin )
    {
        /* first 6 bits, all from in[0] */
        out[n++] = b64[(in[0] & 0xfc) >> 2];
        x = (in[0] & 3) << 4;

        /* next 6 bits, 2 from in[0] and 4 from in[1] */
		if( lin == 1 )
        {
            out[n++] = b64[x];
            out[n++] = '=';
            out[n++] = '=';
            break;
        }
        out[n++] = b64[ x | ( (in[1]&0xf0) >> 4 ) ];
        x = ( in[1] & 0x0f ) << 2;

        /* next 6 bits 4 from in[1] and 2 from in[2] */
		if( lin == 2 )
        {
            out[n++] = b64[x];
            out[n++] = '=';
            break;
        }
        out[n++] = b64[ x | ( (in[2]&0xc0 ) >> 6 ) ];

        /* last 6 bits, all from in [2] */
        out[n++] = b64[ in[2] & 0x3f ];
        in += 3;
		lin -= 3;
    }
    out[n] = 0;
    return n;
}


unsigned int CBase64::DecryptBase64(const std::string* inp, char* outp)
{
	unsigned int bit_offset, byte_offset, idx, i, n;
	char* p;
	char* in = outp;
	strcpy(in, inp->c_str());
	unsigned char *d = (unsigned char *)in;

	n = i = 0;

	while(*in && (p=strchr(b64,*in)))
	{
		idx = (unsigned int)(p - b64);
		byte_offset = (i*6)/8;
		bit_offset = (i*6)%8;
		d[byte_offset] &= ~((1<<(8-bit_offset))-1);
		if(bit_offset < 3)
		{
			d[byte_offset] |= (idx << (2-bit_offset));
			n = byte_offset+1;
		}
		else
		{
			d[byte_offset] |= (idx >> (bit_offset-2));
			d[byte_offset+1] = 0;
			d[byte_offset+1] |= (idx << (8-(bit_offset-2))) & 0xFF;
			n = byte_offset+2;
		}
		in++; i++;
	}
	/* null terminate */
	d[n] = 0;

	return n;
}




unsigned int CBase64::DecryptBase64(const std::string* inp, std::string* out)
{
	unsigned int bit_offset, byte_offset, idx, i, n;
	char* p;
	char* buffer = (char*)malloc(inp->length() + 1);
	char* in = buffer;
	strcpy(in, inp->c_str());
	unsigned char *d = (unsigned char *)in;

	out->clear();

	n = i = 0;

	while(*in && (p=strchr(b64,*in)))
	{
			idx = (unsigned int)(p - b64);
			byte_offset = (i*6)/8;
			bit_offset = (i*6)%8;
			d[byte_offset] &= ~((1<<(8-bit_offset))-1);
			if(bit_offset < 3)
			{
					d[byte_offset] |= (idx << (2-bit_offset));
					n = byte_offset+1;
			}
			else
			{
					d[byte_offset] |= (idx >> (bit_offset-2));
					d[byte_offset+1] = 0;
					d[byte_offset+1] |= (idx << (8-(bit_offset-2))) & 0xFF;
					n = byte_offset+2;
			}
			in++; i++;
	}
	/* null terminate */
	d[n] = 0;

	out->append(buffer);
	free(buffer);

	return n;
}
