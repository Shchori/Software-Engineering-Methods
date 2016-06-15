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
#include <stdio.h>
#include <string>
#include <iostream>
#include "Button.h"
#include "NumericBox.h"

using namespace std;


void main() {

	BorderType b = BorderType::Double;
	Label t("jj", 4);
	COORD f = { 15, 17 };
	t.setCoord(f);
	t.setBorder(b);

	Label text("hey", 4);
	COORD c = { 2,3 };
	text.setCoord(c);
	text.setBorder(b);


	Panel main(25,30);
	main.setBorder(b);
	main.AddControl(t, t.getCoord().X, t.getCoord().Y);
	main.AddControl(text, text.getCoord().X, text.getCoord().Y);
	//main.draw();

	string plus = "plus";
	string minus = "minus";
	COORD numeric_c = { 6,7 };
	NumericBox numericbox(10, 20, 0, 100, 1, 4, numeric_c);
	numericbox.setBorder(b);
	main.AddControl(numericbox, numericbox.getCoord().X, numericbox.getCoord().Y);

	numericbox.draw();

	main.draw();


	numericbox.addEvent(plus);
	numericbox.addEvent(plus);
	numericbox.addEvent(minus);



	getchar();

}