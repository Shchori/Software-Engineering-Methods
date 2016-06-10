#include "Label.h"

int main() {
	Label l("avavavav", 20);
	COORD c = { 2,2 };
	l.setBorder(BorderType::Double);
	l.setCoord(c);
	l.setForegroundColor(Color::Blue);
	l.setBackgroundColor(Color::Red);
	l.draw();
	return 0;

}
