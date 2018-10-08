#pragma once
#include "Exports.h"
#include <fstream>
static class ENGINEDLL_API Importer
{
	struct BMPheader
	{
		unsigned int dataPos;
		unsigned int width, height;
		unsigned int imageSize;
		unsigned char  * data;
	};

public:
	
	static unsigned char LoadBMP(const char* BMPname);
	static bool RightBMPFormat(const char* BMPname , unsigned char  BMPheader[], FILE * BMPfile);
};

