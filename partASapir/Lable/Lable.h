
#include <Windows.h>
#include <stdio.h>
#include <string>


using namespace std;

class Lable: public ConsolComponent {

private:
	
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	COORD setPosition;
	HANDLE console;
	string text;

public:

	Lable(string txt, COORD pos = currPosition, DWORD color = currColor);
	~Lable();
	void SetCursorPosition(HANDLE h, COORD pos);
	void Draw();

	static COORD currPosition; // if we'll want to add runtime lable - in the future
	static DWORD currColor;
};

