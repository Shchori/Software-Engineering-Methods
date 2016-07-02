#pragma once
#include "Panel.h"
#include "Button.h"
#include "Label.h"

class MsgBoxButton;


class MsgBox: public Panel
{
	//vector<Button> btns;
	vector<MsgBoxButton> btns;
	Label text;
public:
	MsgBox(int height, int width);
	void setText(string text);
	string getText();
	void draw();
	virtual ~MsgBox();
protected:
	virtual void addControl(IControl& control, int left, int top);

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