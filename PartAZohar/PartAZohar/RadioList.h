#pragma once
#include<iostream>
#include<string>
#include <stdio.h>
#include <stdlib.h> 
#include <Windows.h>
using namespace std;


class RadioList
{
private:
	COORD _cord1;
	//short _cord2;
	string _option;
	HANDLE h;
public:
	RadioList(){};
	RadioList(COORD c, string* mystring, int size) :_cord1(c){
		h = GetStdHandle(STD_OUTPUT_HANDLE);

		for (int i = 0; i <size; ++i){
			SetConsoleCursorPosition(h, _cord1);
			cout << "( ) " << mystring[i] << endl;
			_cord1.Y += 2;
		}
	}

	void MouseEventProc(MOUSE_EVENT_RECORD mer, string* mystring, int size);
	void KeyEventProc(KEY_EVENT_RECORD ker, string* mystring, int size);
	~RadioList(){};
	string getOption(){ return _option; }
	void display(COORD tmpcrd, string text, int keyflag);
	void changeDisplay(COORD tmpcrd2, string text, int keyflag);
};

