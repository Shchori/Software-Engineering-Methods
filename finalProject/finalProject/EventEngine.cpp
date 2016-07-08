#include "EventEngine.h"


EventEngine::EventEngine(DWORD input, DWORD output )
	: _console(GetStdHandle(input)), _graphics(Graphics::getInstance(output))
{
	// Retrieves the current input/output mode of a console's input/output buffer
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
}

void EventEngine::run(Control &c)
{
	vector<IControl*> controls;
	// infinite loop
	if(controls.size() > 0) IControl::setFocused(controls[0]);
	for (bool redraw = true;;)
	{

		controls = c.getAllControls();
		COORD temp = _graphics.getCursorPosition();
		if (redraw)
		{
			_graphics.clearScreen();
				c.draw();
				if(IControl::getFocused())_graphics.setCursorVisibility(IControl::getFocused()->getCruserVisability());
			redraw = false;
		}
		_graphics.setCursorPosition(temp);

		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);//read 1 event each time
		switch (record.EventType)
		{
		case KEY_EVENT:
		{
			auto f = Control::getFocused(); // pointer to function?
			if (f != nullptr && record.Event.KeyEvent.bKeyDown)
			{
				auto code = record.Event.KeyEvent.wVirtualKeyCode;//ascii
				auto chr = record.Event.KeyEvent.uChar.AsciiChar;//val
				if (code == VK_TAB) {
					moveFocus(c, f);//to the next
					redraw = true;
				}
				else
					if (IControlResponser* rb = dynamic_cast<IControlResponser*>(f)) {
						rb->keyDown(code, chr);//any kind of button press
						redraw = true;
					}


			}
			break;
		}
		case MOUSE_EVENT:
		{
			auto button = record.Event.MouseEvent.dwButtonState;
			auto coord = record.Event.MouseEvent.dwMousePosition;
			coord.Y -= 1;
				if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
			{
				vector<IControl*> controls = c.getAllControls();
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < controls.size(); ++j) {
						if (controls[j]->getLayer() == i && controls[j]->isFocus()&& controls[j]->inArea(coord) && controls[j]->getVisability()) {
							if (IControlResponser* rb = dynamic_cast<IControlResponser*>(controls[j])) {
								rb->mousePressed(coord.X, coord.Y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
								redraw = true;
							}
						}
					}
				}
				break;
			}
		}
		}
	}

}

void EventEngine::moveFocus(Control &main, Control *focused)
{
	vector<IControl*> controls = main.getAllControls();
	auto it = find(controls.begin(), controls.end(), focused);
	do
		if (it == controls.end() || ++it == controls.end())
			it = controls.begin();
	while (!(*it)->isFocus() && (*it)->getVisability());
	Control::setFocused(*it);
};