#include "App.h"

void main()
{
	App *app = NewApp();
	AppRun(app);
	ReleaseApp(app);
}