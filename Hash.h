#ifndef _HASH_H_
#define _HASH_H_

#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned long uint32;

#pragma warning(disable: 4996)


class Hash
{
public:

	virtual int PushData(const void* data, uint32 sizeInBytes) = 0;
	virtual bool GetHexString(TCHAR* outString) = 0; 
	virtual ~Hash() = 0 {}

	virtual void PushFile(const char* filename)
	{
		FILE* fp = fopen(filename, "rb");
		if (fp)
		{
			char data[10240];
			unsigned int len;
			while(len = fread(data, 1, 10240, fp))
			{
				PushData(data, len);	
			}

			fclose(fp);
		}
	}
	virtual void PushFile(const wchar_t* filename)
	{
		char filenameA[260];
		wcstombs(filenameA, filename, 260);
		PushFile(filenameA);
	}
};


#pragma warning(default: 4996)

#endif // _HASH_H_