#include "Frame.h"


TimerFrame::TimerFrame(const std::string& referenceTime, unsigned short int frameRate)
	:_fps(frameRate), _referenceTime(referenceTime)
{
	Timer time = tokenizeFormat(referenceTime);

	_referenceFrame = convertVideoTimeToFrameCount(time);
}

Timer TimerFrame::tokenizeFormat(const std::string& time)
{ //https://stackoverflow.com/a/63959785/9521550
	std::stringstream stringStream(time);
	std::string line = "";
	unsigned short int values[4] = {0};
	int i = 0;

	while (std::getline(stringStream, line))
	{
		std::size_t prev = 0, pos;
		while ((pos = line.find_first_of(":.", prev)) != std::string::npos)  // only look for : and .
		{
			if (pos > prev)
			{			
				values[i] = std::stoi(line.substr(prev, pos - prev));
				i++;
			}
				
			//words.push_back(line.substr(pos, 1));               // add delimiter in split
			prev = pos + 1;
		}
		if (prev < line.length())
		{
			values[i] = std::stoi(line.substr(prev, std::string::npos));
			i++;
		}
			
	}

	return Timer(values[0], values[1], values[2], values[3]);
}

/*timeInFrames += videoTime.hour * 3600 + (videoTime.minutes * 60)
		+ (videoTime.seconds * _fps) + videoTime.frames;*/
Timer TimerFrame::convertFrameCountToVideoTime(signed int frameCount)
{
	unsigned short seconds = frameCount / _fps;
	unsigned short frames = frameCount % _fps;
	unsigned short minutes = 0;
	unsigned short hours = 0;

	if (seconds >= 60)
	{
		minutes = seconds / 60;
		seconds -= minutes * 60;
	}

	if (minutes >= 60)
	{
		hours = minutes / 60;
		minutes -= hours * 60;
	}

	return Timer(hours, minutes, seconds, frames);	
}

signed int TimerFrame::convertVideoTimeToFrameCount(const Timer& timer)
{
	signed int frameCount = 0;
	frameCount += timer.hour * 3600 + (timer.minutes * 60)
		+ (timer.seconds * _fps) + timer.frames;
	return frameCount;
}

std::string TimerFrame::formatTokensToVideoTime(const Timer& tokens)
{
	std::string time = "";
	time += std::to_string(tokens.hour) + ":" + std::to_string(tokens.minutes) + ":"
		+ std::to_string(tokens.seconds) + "." + std::to_string(tokens.frames);
	return time;
}

int TimerFrame::frameOffset(const std::string& time)
{
	Timer tokens = tokenizeFormat(time);
	signed int endTime = convertVideoTimeToFrameCount(tokens);
	return endTime - _referenceFrame;
}

unsigned short TimerFrame::getFps() const { return _fps; }

std::string TimerFrame::getReferenceVideoTime() const { return _referenceTime; }

long TimerFrame::getReferenceFrameCount() const { return _referenceFrame; }

void TimerFrame::setReferenceVideoTime(const std::string& referenceTime)
{
	_referenceTime = referenceTime;
	Timer time = tokenizeFormat(referenceTime);
	_referenceFrame = convertVideoTimeToFrameCount(time);
}

void TimerFrame::setFps(unsigned short fps) { _fps = fps; }