#pragma once
#include "Panel.h"
#include "Button.h"
#include "Label.h"

class MsgBoxButton;


class MsgBox: public Panel
{
private:
	vector<MsgBoxButton> btns;
	Label text;
	Label title;
	string pressedValue;
protected:
	virtual void addControl(IControl& control, int left, int top);
public:
	MsgBox(int height, int width, string str="", string title="");
	void setText(string text);
	string getText();
	void setTitle(string title);
	string getTitle();
	string getPressedValue();
	void setPressedValue(string value);
	void draw();
	virtual ~MsgBox();

};


class MsgBoxButton : public Button {
protected:

	struct MsgBoxMouseListener : public MouseListener
	{
	public:
		MsgBoxMouseListener() {};
		void mousePressed(Button &b, int x, int y, bool isLeft) {
			if (MsgBoxButton* rb = dynamic_cast<MsgBoxButton*>(&b)) {
				rb->msgBox->setVisability(false);
				rb->msgBox->setPressedValue(b.GetValue());
			}
		};
		~MsgBoxMouseListener() {
		};
	};
	MsgBox* msgBox;
	int index;
	MsgBoxMouseListener* msgListnr;
public:
	void setIndex(int i) {
		index = i;
	};
	MsgBoxButton(MsgBox *r) :MsgBoxButton::Button("", 6), msgBox(r) {
		msgListnr = new MsgBoxMouseListener();
		this->AddListener(*msgListnr);
	};
};