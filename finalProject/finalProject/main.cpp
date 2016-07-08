#pragma once
#include "allHeader.h"

using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.setForegroundColor(Color::Red);
	}
private:
	Control &_c;
};



int main(int argc, char **argv)
{
Label lName(20);
	lName.setValue("Name: ");

	Label lAddress(20);
	lAddress.setValue("Address:");
	Label lCountry(20);
	lCountry.setValue("Counrty:");
	Label lSex(20);
	lSex.setValue("Sex:");
	Label lInterests(20);
	lInterests.setValue("Interests:");
	Label lAge(20);
	lAge.setValue("Age:");
	TextBox tName(20);
	tName.setValue("");
	tName.setBorder(BorderType::Single);
	tName.setBackgroundColor(Color::Green);
	tName.setForegroundColor(Color::Blue);
	TextBox tAddress(25);
	tAddress.setValue("221B Baker Street, London");
	tAddress.setBorder(BorderType::Single);
	ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
	cCountry.setSelectedIndex(1);
	cCountry.setBorder(BorderType::Single);
	RadioList rSex(2, 15, { "Male", "Female" });
	rSex.setBorder(BorderType::Single);
	CheckList clInterests(3, 15, { "Sports", "Books", "Movies" });
	clInterests.setSelectedIndex(1);
	clInterests.setBorder(BorderType::Single);
	NumericBox nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.setBorder(BorderType::Single);
	MyListener listener(tAddress);
	Button bSubmit("Submit",10);
	bSubmit.AddListener(listener);
	bSubmit.setBorder(BorderType::Double);
	MsgBox msg(5, 20, "Are you Ok?", "hello");
	Panel main(100,100);
	main.addControl(lName, 1, 3);
	main.addControl(lAddress, 1, 6);
	main.addControl(lCountry, 1, 10);
	main.addControl(lSex, 1, 22);
	main.addControl(lInterests, 1, 34);
	main.addControl(lAge, 1, 40);
	main.addControl(tName, 25, 3);
	main.addControl(tAddress, 25, 6);
	main.addControl(cCountry, 25, 10);
	main.addControl(rSex, 25, 22);
	main.addControl(clInterests, 25, 34);
	main.addControl(nAge, 25, 40);
	main.addControl(msg, 10, 10);
	main.addControl(bSubmit, 1, 45);
	Control::setFocused(&tName);
	EventEngine engine;
	engine.run(main);
	return 0;
}


/*

int main() { 
	Graphics g = Graphics::getInstance();
	g.clearScreen();
	BorderType b = BorderType::Double;
	vector<string> ops = { "Hi","You","Fuckers",":-)","<3" };
	ComboBox r(15, ops);
	r.setBorder(BorderType::Double);
	r.setBackgroundColor(Color::Green);
	r.setForegroundColor(Color::Red);
	RadioList r2(15, 15, ops);
	r2.setBorder(BorderType::Single);
	TextBox box(8, "ggggg");
	box.setBorder(b);
	g.clearScreen();
	NumericBox num(30, 0, 4000);
	num.setValue(1000);


	Panel main(60, 60);
	//main.addControl(num, 0, 0);
	main.addControl(r2, 0, 0);
	main.draw();zzz
	handle.run(main);
	getchar();
	
}

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
	

	//numericbox.addEvent(plus);
	//numericbox.addEvent(plus);
	//numericbox.addEvent(minus);
	//vector<string> lab = {"hi","bi"};
	//RadioList n(10, 20,lab );
	//n.draw();
	Graphics g = Graphics::getInstance();
	g.clearScreen();
	g.setCursorPosition(2, 2);
	COORD c2 = g.getCursorPosition();
	BorderType b = BorderType::Double;
	Label t(4,"");
	t.setValue("dfdf");
	t.setBorder(b);
	t.draw();
	/*
	vector < string > vec = {"hi	", "how ", "are", "you"};
	RadioList r(10, 10, vec);
	r.setBorder(BorderType::Double);
	r.setSelectedIndex(3);
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
	
	box.mousePressed(4, 1, true);
	WORD code = VK_BACK;
	char c('B');
	box.keyDown(code,c);
	
	getchar();
	

}*/