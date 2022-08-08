#pragma once

class Border {
public:
	static unsigned int borderVertical, borderHorizontal;

	bool activatedLeft = false, activatedRight = false, activatedTop = false, activatedBottom = false;

	Border();
	void draw();
};

