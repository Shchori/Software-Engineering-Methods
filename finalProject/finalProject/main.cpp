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
#include "MsgBox.h"
#include "NumericBox.h"
#include "RadioList.h"
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
	BorderType b = BorderType::Single;
/*	vector<string> values = { "hi", "bi" };
	COORD c = { 0,0 };
	RadioList r(20,40,values);
	r.setBorder(b);
	*/
	//r.setCoord(c);
	MsgBox m(10,10);
	COORD c = { 0,0 };
	m.SetText("check");
	m.setCoord(c);

	Panel main(50, 40);
	main.setBorder(b);
	main.addControl(m,0,0);
	main.draw();
	getchar();
	

}