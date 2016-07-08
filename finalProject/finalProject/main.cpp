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
	EventEngine engine;
	engine.run(main);
	return 0;
}

