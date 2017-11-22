#ifndef HUMAN_HPP
#define HUMAN_HPP

# include "humangl.hpp"
# include "cube.hpp"
# include "shaders.hpp"

class Human {
private:
	Cube _body;
	Cube _head;
	Cube _leftArmUp;
	Cube _leftArmDown;
	Cube _leftLegUp;
	Cube _leftLegDown;
	Cube _rightArmUp;
	Cube _rightArmDown;
	Cube _rightLegUp;
	Cube _rightLegDown;
public:
	Human(void);
	void		render(Shaders &shader);
	void 		update(float delta);
};

#endif
