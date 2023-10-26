// SyncFrameTool.cpp : Defines the entry point for the application.
//

#include "SyncFrameTool.h"

void Print(long, const Timer&);
void Test();

//https://youtu.be/nVaQuNXueFw?t=218 here
//others
//https://youtu.be/vWXrFetSH8w?t=724
//https://youtu.be/-NJDxf4XwlQ?t=440
int main()
{
	//Test();
	return 0;
}

void Print(long frameCount, const Timer& timer)
{
	std::cout << "Frame Count: " << frameCount << "\n";
	std::cout << "Hour: " << timer.hour <<
		"\nMinute: " << timer.minutes <<
		"\nSeconds: " << timer.seconds <<
		"\nFrames: " << timer.frames << "\n\n";
}

void Test()
{
	//std::string format = "H:MM:SS.FF";
	TimerFrame frame("00:13:45.29", 30);
	std::cout << "Fps " << frame.getFps() << std::endl;
	std::cout << "Reference Time " << frame.getReferenceVideoTime() << std::endl;
	std::cout << "Reference Frame " << frame.getReferenceFrameCount() << std::endl;

	Timer tokens(0, 26, 59, 15);

	std::cout << "Frame Count as Video Time: " << frame.formatTokensToVideoTime(tokens) << std::endl;
	std::cout << "Video Time as Frame Count: " << frame.convertVideoTimeToFrameCount(tokens) << std::endl;

	std::cout << "Synced: " << frame.frameOffset("0:13:47.29") << std::endl;

	//Print(990, frame.convertFrameCountToVideoTime(990));
	/*Print(9990, frame.convertFrameCountToVideoTime(9990));
	Print(9995, frame.convertFrameCountToVideoTime(9995));
	Print(991795, frame.convertFrameCountToVideoTime(991795));*/
	//Print(991800, frame.convertFrameCountToVideoTime(991800));
	//Print(LONG_MAX, frame.convertFrameCountToVideoTime(LONG_MAX));
	/*Print(0, frame.convertFrameCountToVideoTime(0));
	Print(1, frame.convertFrameCountToVideoTime(1));
	Print(18000, frame.convertFrameCountToVideoTime(18000));

	Print(108001, frame.convertFrameCountToVideoTime(108001));*/

	//Print(1800, frame.convertFrameCountToVideoTime(1800));
}