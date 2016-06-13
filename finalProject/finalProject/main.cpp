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


void main() {

	BorderType b = BorderType::Double;
	Label t("jj", 4);
	COORD f = { 12, 13 };
	t.setCoord(f);
	t.setBorder(b);

	Label text("hey", 4);
	COORD c = { 2,3 };
	text.setCoord(c);
	text.setBorder(b);


	Panel main(20,30);
	main.setBorder(b);
	main.AddControl(t, t.getCoord().X, t.getCoord().Y);
	main.AddControl(text, text.getCoord().X, text.getCoord().Y);
	main.draw();

	getchar();

}