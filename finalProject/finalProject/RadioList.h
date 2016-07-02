#pragma once
#include <iostream>
#include <vector>
#include "Panel.h"
#include "Label.h"
#include "Button.h"

using namespace std;
class RadioListButton;


class RadioList : public Panel
{
	friend RadioListButton;
public:
	RadioList(int height, int width, vector<string> options);
	void draw();
	int getSelectedIndex();
	virtual void setSelectedIndex(int index);
	void clearSelection();
	string getValue();
	~RadioList();
protected:
	virtual void addControl(IControl& control, int left, int top);
	int size;
	int selectedIndex;
	vector<Label> ops;
	vector<RadioListButton> btn;
};

class RadioListButton : public Button {
protected:
	
	struct RadiolistMouseListener : public MouseListener
	{
	public:
		RadiolistMouseListener() {};
		void mousePressed(Button &b, int x, int y, bool isLeft) {
			if (RadioListButton* rb = dynamic_cast<RadioListButton*>(&b)) {
				if (rb->index == rb->radioList->selectedIndex) rb->radioList->clearSelection();
				else	rb->radioList->setSelectedIndex(rb->index+1);
			}
		};
		~RadiolistMouseListener() {
		};
	};
	RadioList* radioList;
	int index;
	RadiolistMouseListener* l;
public:
	void setIndex(int i) {
		index = i;
	};
	RadioListButton(RadioList *r) :RadioListButton::Button("( )", 3), radioList(r) {
		this->AddListener(l);
	};
	void keyDown(WORD code, char c) {
		Button::keyDown(code, c);
		int size = this->radioList->size;
		switch (code)
		{
		case VK_UP:
			if (this->index == 0) IControl::setFocused(&radioList->btn[size - 1]);
			else IControl::setFocused(&radioList->btn[index - 1]);
			break;
		case VK_DOWN:
			if (this->index == size - 1) IControl::setFocused(&radioList->btn[0]);
			else IControl::setFocused(&radioList->btn[index + 1]);
			break;
		}

	}
};
