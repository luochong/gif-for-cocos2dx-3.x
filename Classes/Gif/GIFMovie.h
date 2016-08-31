#ifndef GIFMovie_H
#define GIFMovie_H

#include "Movie.h"
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <assert.h>
#include "cocos2d.h"

class DataBuff
{
	public: 
		DataBuff(cocos2d::Data data);
		virtual ~DataBuff();
		size_t readData(void *buffer, size_t size);
	private:
		size_t pos;
		cocos2d::Data data;

};

class GIFMovie : public Movie {
public:
	virtual ~GIFMovie();
	GIFMovie();
	CREATE_WITH_PARAM(GIFMovie, const char*);

    virtual bool init(const char*);

	int getGifCount()
	{
		return fGIF == NULL ? 0 : fGIF->ImageCount;
	};

	int getCurrentIndex()
	{
		return fCurrIndex;
	};
	GifFrame getGifFrameByIndex(unsigned int frameIndex);
protected:
	virtual bool onGetInfo(Info*);
	virtual bool onSetTime(uint32_t);
	virtual bool onGetBitmap(Bitmap*);

private:
	GifFileType* fGIF;
	int fCurrIndex;
	int fLastDrawIndex;
	Bitmap fBackup;
};

#endif
