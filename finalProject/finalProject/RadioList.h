#pragma once
#include <iostream>
#include <vector>
#include "Panel.h"
#include "Label.h"
#include "Button.h"

using namespace std;

class RadioList: public Panel
{
protected:
	class RadioListButton : public Button {
	protected:
		struct RadiolistMouseListener :MouseListener
		{
			virtual void MousePressed(Button &b, int x, int y, bool isLeft) {
				if (RadioListButton* rb = dynamic_cast<RadioListButton*>(&b)) {
					rb->radioList->setSelectedIndex(rb->index);
				}
			};

		};
		RadioList* radioList;
		int index;

	public:
		void setValue(string s, int i) {
			Button::setValue(s);
			index = i;
		};
		RadioListButton(RadioList *r) :RadioListButton::Button("( )", 3), radioList(r) {};
		
	};
	int size;
	int selectedIndex;
	vector<Label> ops;
	vector<RadioListButton> btn;
public:
	RadioList(int height, int width, vector<string> options);
	void draw();
	int getSelectedIndex();
	void setSelectedIndex(int index);
	int mouseEvent(MOUSE_EVENT_RECORD mer, HANDLE output);
	int keyPress(KEY_EVENT_RECORD ker, HANDLE output);
	~RadioList();
};

