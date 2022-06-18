#pragma once

class Border {
private:
	const double x = 0, y = 0.75, width = 14.0, height = 16.0, thickness = 0.5;
	bool activatedLeft = false, activatedRight = false, activatedTop = false, activatedBottom = false;
public:
	Border();
	void draw();
};

