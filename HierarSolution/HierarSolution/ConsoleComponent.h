#pragma once
#include <windows.h>
#include <string>

using namespace std;

class ConsolComponent
{
private:
	COORD _coord;
	HANDLE _console;
	
public:
	inline ConsolComponent(const COORD c) : _coord(c), _console(GetStdHandle(STD_OUTPUT_HANDLE)) {}
	inline HANDLE GetConsole() { return _console; };
	inline COORD GetCoord() { return _coord; };
	inline void SetCoord(COORD c) { _coord = c; };
	virtual string getString() = 0;
};
string ConsolComponent::getString() {}