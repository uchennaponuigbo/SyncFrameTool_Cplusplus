#pragma once
#include <string>
#include<sstream>

struct Timer
{
	unsigned short hour, minutes, seconds, frames;

	Timer() : hour(0), minutes(0), seconds(0), frames(0) {}

	Timer(unsigned short h, unsigned short m, unsigned short s, unsigned short f)
		: hour(h), minutes(m), seconds(s), frames(f) {}
};

class TimerFrame
{
private:
	std::string _referenceTime;
	signed int _referenceFrame;
	unsigned short _fps;

public:
	//H:MM:SS.FF
	TimerFrame(const std::string&, unsigned short int);

	Timer tokenizeFormat(const std::string&);

	std::string formatTokensToVideoTime(const Timer&);
	Timer convertFrameCountToVideoTime(signed int);
	signed int convertVideoTimeToFrameCount(const Timer&);

	int frameOffset(const std::string&);

	std::string getReferenceVideoTime() const;
	void setReferenceVideoTime(const std::string&);
	long getReferenceFrameCount() const;
	unsigned short getFps() const;
	void setFps(unsigned short);
};

