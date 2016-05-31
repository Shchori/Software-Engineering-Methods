#pragma once
enum class BorderType { Single, Double, None };

class Border
{
public:
	char horizontal;
	char vertical;
	char topLeftCorner;
	char topRightCorner;
	char bottomLeftCorner;
	char bottomRightCorner;
	char leftConnector;
	char rightConnector;
	char topConnector;
	char bottomConnector;
	char middleConnector;
};
class SingleBorder:public  Border
{
public:
	SingleBorder() {
		horizontal = 196;
		vertical = 179;
		topLeftCorner = 218;
		topRightCorner = 191;
		bottomLeftCorner = 192;
		bottomRightCorner = 217;
		leftConnector = 180;
		rightConnector = 195;
		topConnector = 194;
		bottomConnector = 193;
		middleConnector = 197;
	};
	~SingleBorder() {};

};




class DoubleBorder :public Border
{
public:
	DoubleBorder() {

		horizontal = 205;
		vertical = 186;
		topLeftCorner = 201;
		topRightCorner = 187;
		bottomLeftCorner = 200;
		bottomRightCorner = 188;
		leftConnector = 204;
		rightConnector = 185;
		topConnector = 203;
		bottomConnector = 202;
		middleConnector = 206;
	};
	~DoubleBorder() {};
};
