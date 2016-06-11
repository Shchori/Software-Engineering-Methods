#pragma once
#include "constants.h" //include all project constants
#include<Windows.h>
#include <vector>
#include "Graphics.h"
#include "border.h"
#include "IControl.h"
#include "Lable.h"
#include "Panel.h"


void main() {

	Lable text("hey",4);
	text.draw();
	Panel main(20,30);
	//main.setBorder(Double);
	main.draw();
	main.AddControl(text, 2, 3);

	getchar();

}