#include "EventEngine.h"


EventEngine::EventEngine(DWORD input, DWORD output )
	: _console(GetStdHandle(input)), _graphics(Graphics::getInstance(output))
{
	// Retrieves the current input/output mode of a console's input/output buffer
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run(Control &c)
{
	// infinite loop
	for (bool redraw = true;;)
	{
		if (redraw)
		{
			c.draw();
		}
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
				if (code == VK_TAB)
					moveFocus(c, f);//to the next
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
			auto x = c.getCoord().X;
			auto y = c.getCoord().Y;
			if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
			{
				vector<IControl*> controls = c.getAllControls();
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < controls.size(); ++j) {
						if (controls[j]->getLayer() == i && controls[j]->isFocus()) {
							if (IControlResponser* rb = dynamic_cast<IControlResponser*>(controls[j])) {
								rb->mousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
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
		if (++it == controls.end())
			it = controls.begin();
	while (!(*it)->isFocus());
	Control::setFocused(*it);
};