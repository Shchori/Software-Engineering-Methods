#pragma once
#include <Windows.h>
#include "Graphics.h"
#include <string>

#pragma once

enum class Color { Cyan,Orange, Red, Blue, Green, Purple, Teal, Yellow, White, Black };
using namespace std;

class Graphics {
	private:
		static Graphics *instance;
		HANDLE _console;
		Color _background;
		Color _foreground;
		Graphics(DWORD  stdHandle);
	public:	
		static Graphics& getInstance(DWORD  stdHandle);
		static Graphics& getInstance();
		void clearScreen();
		void moveTo(int x, int y);
		void setBackground(Color color);
		void setForeground(Color color);
		void write(string s);
		void write(wstring s);
		void write(int x, int y, string s);
		void write(int x, int y, wstring s);
		void setCursorVisibility(bool isVisible);
		void updateConsoleAttributes();
		~Graphics();
};
