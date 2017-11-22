#ifndef HUMAN_HPP
#define HUMAN_HPP

# include "humangl.hpp"
# include "cube.hpp"
# include "shaders.hpp"

class Human {
private:
	Cube _parts[10];
	Vec3 _colors[10];
public:
	Human(void);
	void		render(Shaders &shader);
	void 		update(float delta);
};

#endif
