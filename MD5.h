#pragma once
#ifndef _MD5_H_ 
#define _MD5_H_ 

#include "Hash.h"


void MD5String(unsigned char *pData, unsigned long dwlen, TCHAR *outString);

class MD5_CTX;
class MD5 : public Hash
{
public:
	MD5();
	~MD5();

	int PushData(const void* pData, uint32 dwlen);
	bool GetHexString(TCHAR *outString);

	//////////////////////////////////////////////////////////////////////////

	bool Get(unsigned char digest[]); // 16 byte


private:
	MD5_CTX* m_pCtx;
	bool m_bGet;
};

#endif //_MD5_H_ 