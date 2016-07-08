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
struct MyListener2 : public MouseListener
{
	MyListener2(Control &c) : _c(c) { }
	void mousePressed(Button &b, int x, int y, bool isLeft)
	{
		EventEngine e;
		e.run(_c);
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
	Button next("next page", 12);
	next.setBorder(BorderType::Double);
	Panel page2(50, 50);
	MsgBox msg2(5, 20, "Are you Ok?", "hello");
	page2.addControl(msg2,20,20);
	page2.addControl(tName, 2, 2);
	MyListener2 listener2(page2);
	next.AddListener(listener2);
	next.setBackgroundColor(Color::Purple);
	bSubmit.setBorder(BorderType::Double);
	MsgBox msg(5, 20, "Are you Ok?", "hello");
	Panel main(100,100);
	main.addControl(lName, 1, 3);
	main.addControl(lAddress, 1, 6);
	main.addControl(lCountry, 1, 10);
	main.addControl(lSex, 1, 15);
	main.addControl(lInterests, 1, 20);
	main.addControl(lAge, 1, 27);
	main.addControl(tName, 25, 3);
	main.addControl(tAddress, 25, 6);
	main.addControl(cCountry, 25, 10);
	main.addControl(rSex, 25, 15);
	main.addControl(clInterests, 25, 20);
	main.addControl(nAge, 25, 27);
	main.addControl(msg, 15, 10);
	main.addControl(bSubmit, 1, 32);
	main.addControl(next, 65, 3);
	EventEngine engine;

	engine.run(main);
	return 0;
}

