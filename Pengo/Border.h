#pragma once

class Border {
private:
	double x, y, width, height, thickness;
	bool activatedLeft = false, activatedRight = false, activatedTop = false, activatedBottom = false;
public:
	Border(double x, double y, double width, double height, double thickness);
	void draw();
};

