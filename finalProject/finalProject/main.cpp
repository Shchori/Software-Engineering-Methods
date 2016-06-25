#pragma once
#include "constants.h" //include all project constants
#include<Windows.h>
#include "border.h"
#include <vector>
#include "Graphics.h"
#include "border.h"
#include "IControl.h"
#include "Label.h"
#include "Panel.h"
#include "TextBox.h"
#include <iostream>
#include "Button.h"
#include "NumericBox.h"
#include "RadioList.h"
#include "TextBox.h"

using namespace std;
void main() {

	/*
	BorderType b = BorderType::Double;
	Label t(4);
	t.setValue("dfdf");
	COORD f = { 15, 17 };
	t.setCoord(f);
	t.setBorder(b);

	Label text(4);
	text.setValue("dddfd");
	COORD c = { 2,3 };
	text.setCoord(c);
	text.setBorder(b);


	TextBox te(30);
	te.setValue("hi");
	COORD d = { 10,3 };
	te.setCoord(d);
	te.setBorder(b);

	Panel main(25, 40);
	main.setBorder(b);
	main.addControl(te, te.getCoord().X, te.getCoord().Y);
	main.addControl(t, t.getCoord().X, t.getCoord().Y);
	main.addControl(text, text.getCoord().X, text.getCoord().Y);

	//main.draw();

	string plus = "plus";
	string minus = "minus";
	COORD numeric_c = { 6,7 };
	NumericBox numericbox(10, 20, 0, 100, 1, 4, numeric_c);
	numericbox.setBorder(b);
	main.addControl(numericbox, numericbox.getCoord().X, numericbox.getCoord().Y);

	numericbox.draw();

	main.draw();
	*/

	//numericbox.addEvent(plus);
	//numericbox.addEvent(plus);
	//numericbox.addEvent(minus);
	//vector<string> lab = {"hi","bi"};
	//RadioList n(10, 20,lab );
	//n.draw();
	Graphics g = Graphics::getInstance();
	g.clearScreen();

	BorderType b = BorderType::Double;
	Label t(4,"");
	t.setValue("dfdf");
	t.setBorder(b);
	t.draw();
	vector < string > vec = {"hi	", "how ", "are", "you"};
	RadioList r(10, 10, vec);
	COORD C1 = {4,4};
	r.setCoord(C1);
	g.clearScreen();
	r.draw();
	Label text(1,"");
	text.setValue("d");
	text.setBorder(b);
	text.draw();
	COORD v = { 16,30 };

	Panel minP(10, 10);
	minP.setBorder(b);
	minP.setCoord(v);
	minP.addControl(t, 2, 1);
	Panel main(40, 45);
	main.setBorder(b);
	COORD d = { 0,0 };
	main.setCoord(d);
	//main.addControl(text, 8,9);
	//main.addControl(t, t.getCoord().X, t.getCoord().Y);

	TextBox box(8, "ggggg");
	box.setBorder(b);


	main.addControl(box, 0, 0);
	g.clearScreen();


	main.draw();
	
	box.mousePressed(3, 2, true);
	
	getchar();
	

}