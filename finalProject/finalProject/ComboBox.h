#pragma once
#include "Panel.h"
#include "Label.h"
#include "button.h"

class ComboBoxButton;

class ComboBox: public Panel{
	friend ComboBoxButton;
private:
	Button master;
	vector<ComboBoxButton> options;
	int selectedIndex;
	
public:
	ComboBox(int width, vector<string> options);
	void setSelectedIndex(int index);
	int getSelectedIndex();
	~ComboBox();
};


class ComboBoxButton : public Button {
protected:

	struct ComboBoxMouseListener : public MouseListener
	{
	public:
		ComboBoxMouseListener() {};
		void mousePressed(Button &b, int x, int y, bool isLeft) {
			if (ComboBoxButton* rb = dynamic_cast<ComboBoxButton*>(&b)) {
		//		if (rb->index == rb->comboBox->selectedIndex) rb->radioList->clearSelection();
		//		else	rb->radioList->setSelectedIndex(rb->index + 1);
			}
		};
		~ComboBoxMouseListener() {
		};
	};
	ComboBox* comboBox;
	int index;
	ComboBoxMouseListener* l;
public:
	void setIndex(int i) {
		index = i;
	};

	ComboBoxButton(ComboBox *r) :ComboBoxButton::Button("( )", 3), comboBox(r) {
		l = new ComboBoxMouseListener();
		this->AddListener(*l);
	};
	void keyDown(WORD code, char c) {
		Button::keyDown(code, c);
		//int size = this->radioList->size;
		switch (code)
		{
		case VK_UP:
		//	if (this->index == 0) IControl::setFocused(&radioList->btn[size - 1]);
			//else IControl::setFocused(&radioList->btn[index - 1]);
			break;
		case VK_DOWN:
			//if (this->index == size - 1) IControl::setFocused(&radioList->btn[0]);
			//else IControl::setFocused(&radioList->btn[index + 1]);
			break;
		}

	}
};


