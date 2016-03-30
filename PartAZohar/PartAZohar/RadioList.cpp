#include "RadioList.h"

//using namespace System;
void MarkFunc(int flag);
bool selected = false;//chks if the option this option or onother option was selected
bool selected2 = false;
bool selected3 = false;
bool selected4 = false;
int flag = 0;
int curnt_slct = 0;
COORD tmpcrd;

COORD pressCourd;
POINT pt;                  // cursor location  
CONSOLE_SCREEN_BUFFER_INFO cbi;
COORD crd = { 1, 0 };
int keyflag = 0;
COORD tmpcrd2;
int k = 0;


/*
void RadioList::PrintClass(){
cout << "( )"<< getOption() << endl;

}*/

void RadioList::KeyEventProc(KEY_EVENT_RECORD ker, string* mystring, int size){
	//satrt here i need to rewrite the row that was selsected befor just like the mouse event
	tmpcrd2 = { 1, keyflag };
	if (ker.bKeyDown) {
		//checks the key value
		switch (ker.wVirtualKeyCode) {
			//GetCursorPos(&pt);
		case VK_DOWN:
			crd.Y += 1;
			if (crd.Y == 1){

				if (keyflag != 1 && keyflag != 0){
					changeDisplay(tmpcrd2, mystring[keyflag - k], keyflag);
				}
				tmpcrd = { 1, 1 };
				display(tmpcrd, mystring[0], keyflag);

				keyflag = 1;
				k = 1;
			}
			else if (crd.Y == 3){

				if (keyflag != 3 && keyflag != 0){
					changeDisplay(tmpcrd2, mystring[keyflag - k], keyflag);
				}

				tmpcrd = { 1, 3 };
				display(tmpcrd, mystring[1], keyflag);
				keyflag = 3;
				k = 2;
			}
			else if (crd.Y == 5){
				if (keyflag != 5 && keyflag != 0){
					changeDisplay(tmpcrd2, mystring[keyflag - k], keyflag);
				}
				tmpcrd = { 1, 5 };
				display(tmpcrd, mystring[2], keyflag);
				keyflag = 5;
				k = 3;
			}
			else if (crd.Y == 7){

				if (keyflag != 7 && keyflag != 0){
					changeDisplay(tmpcrd2, mystring[keyflag - k], keyflag);
				}
				tmpcrd = { 1, 7 };
				display(tmpcrd, mystring[3], keyflag);
				keyflag = 7;
				k = 4;

			}
			break;
			/*if (pt.x >= 1 && pt.x <= 13 && pt.y == 1){
			GetConsoleScreenBufferInfo(h, &cbi);
			DWORD wAttr2 = (BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
			SetConsoleTextAttribute(h, wAttr2);
			printf("nbhbjbjkjhkhkl\n");
			}*/


		case VK_UP:
			crd.Y -= 1;
			if (crd.Y == 1){

				if (keyflag != 1 && keyflag != 0){
					changeDisplay(tmpcrd2, mystring[keyflag - k], keyflag);
				}
				tmpcrd = { 1, 1 };
				display(tmpcrd, mystring[0], keyflag);

				keyflag = 1;
				k = 1;
			}
			else if (crd.Y == 3){

				if (keyflag != 3 && keyflag != 0){
					changeDisplay(tmpcrd2, mystring[keyflag - k], keyflag);
				}

				tmpcrd = { 1, 3 };
				display(tmpcrd, mystring[1], keyflag);
				keyflag = 3;
				k = 2;
			}
			else if (crd.Y == 5){
				if (keyflag != 5 && keyflag != 0){
					changeDisplay(tmpcrd2, mystring[keyflag - k], keyflag);
				}
				tmpcrd = { 1, 5 };
				display(tmpcrd, mystring[2], keyflag);
				keyflag = 5;
				k = 3;
			}
			else if (crd.Y == 7){

				if (keyflag != 7 && keyflag != 0){
					changeDisplay(tmpcrd2, mystring[keyflag - k], keyflag);
				}
				tmpcrd = { 1, 7 };
				display(tmpcrd, mystring[3], keyflag);
				keyflag = 7;
				k = 4;

			}
			break;

		case VK_RETURN:
			if (keyflag == 1){
				tmpcrd = { 1, 1 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
				cout << "(x) " << mystring[0];
			}

			if (keyflag == 3){
				tmpcrd = { 1, 3 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
				cout << "(x) " << mystring[1];
			}
			if (keyflag == 5){
				tmpcrd = { 1, 5 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
				cout << "(x) " << mystring[2];
			}
			if (keyflag == 7){
				tmpcrd = { 1, 7 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
				cout << "(x) " << mystring[3];
			}

			break;
		}
	}
}


void RadioList::display(COORD tmpcrd, string text, int keyflag){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
	GetConsoleScreenBufferInfo(h, &cbi);
	DWORD wAttr2 = (BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	SetConsoleTextAttribute(h, wAttr2);
	cout << "( ) " << text;
}

void RadioList::changeDisplay(COORD tmpcrd2, string text, int keyflag){

	WORD Attributes = cbi.wAttributes | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(h, Attributes);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd2);
	cout << "( ) " << text;
}

void RadioList::MouseEventProc(MOUSE_EVENT_RECORD mer, string* mystring, int size){
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif

	int i = 0;
	int t = 0;

	pressCourd = mer.dwMousePosition;
	//printf("%d", pressCourd);

	//printf("Mouse event: ");

	switch (mer.dwEventFlags)
	{

	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED || mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED){
			if (pressCourd.X >= 1 && pressCourd.X <= 13 && pressCourd.Y == 1){

				if (flag != 1 && flag != 0){ //delete x from privious slection
					MarkFunc(flag);
				}
				tmpcrd = { 2, 1 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
				if (selected == false){ //chk if this was markd already
					cout << 'x';
					selected = true;
				}
				else{
					cout << ' ';
					selected = false;
				}
				flag = 1;
			}
			if (pressCourd.X >= 1 && pressCourd.X <= 13 && pressCourd.Y == 3){
				//printf("button press seconed option\n");
				if (flag != 2 && flag != 0){
					MarkFunc(flag);
				}
				tmpcrd = { 2, 3 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
				if (selected2 == false){
					cout << 'x';
					selected2 = true;
				}
				else{
					cout << ' ';
					selected2 = false;
				}
				flag = 2;
			}


			if (pressCourd.X >= 1 && pressCourd.X <= 13 && pressCourd.Y == 5){
				if (flag != 3 && flag != 0){
					MarkFunc(flag);
				}
				tmpcrd = { 2, 5 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
				if (selected3 == false){ //chk if this was markd already
					cout << 'x';
					selected3 = true;
				}
				else{
					cout << ' ';
					selected3 = false;
				}
				flag = 3;
			}

			if (pressCourd.X >= 1 && pressCourd.X <= 13 && pressCourd.Y == 7){
				if (flag != 4 && flag != 0){
					MarkFunc(flag);
				}
				tmpcrd = { 2, 7 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
				if (selected4 == false){ //chk if this was markd already
					cout << 'x';
					selected4 = true;
				}
				else{
					cout << ' ';
					selected4 = false;

				}
				flag = 4;
			}
		}
		break;

		/*case DOUBLE_CLICK:
		printf("double click\n");
		break;
		case MOUSE_HWHEELED:
		printf("horizontal mouse wheel\n");
		break;*/
		//case MOUSE_MOVED:
		//printf("mouse moved\n");
		//if (pressCourd.X >= 1 && pressCourd.X <= 13 && pressCourd.Y == 1)


		//break;
		/*case MOUSE_WHEELED:
		printf("vertical mouse wheel\n");
		break;
		default:
		printf("unknown\n");
		break;*/
	}

}
void MarkFunc2(int flag){
	//delete the x from the previous position

	switch (flag)
	{

	case 1:
		tmpcrd = { 2, 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
		cout << ' ';
		break;

	case 2:
		tmpcrd = { 2, 3 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
		cout << ' ';
		break;

	case 3:
		tmpcrd = { 2, 5 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
		cout << ' ';
		break;

	case 4:
		tmpcrd = { 2, 7 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
		cout << ' ';
		break;

	default:
		break;
	}

}




void MarkFunc(int flag){
	//delete the x from the previous position

	switch (flag)
	{

	case 1:
		tmpcrd = { 2, 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
		cout << ' ';
		break;

	case 2:
		tmpcrd = { 2, 3 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
		cout << ' ';
		break;

	case 3:
		tmpcrd = { 2, 5 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
		cout << ' ';
		break;

	case 4:
		tmpcrd = { 2, 7 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpcrd);
		cout << ' ';
		break;

	default:
		break;
	}

}



