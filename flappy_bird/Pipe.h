#ifndef PIPE_H
#define PIPE_H
#include "Sprite.h"

class Pipe: public Sprite
{
	public:
		Pipe(int x, int y, int width, int height, unsigned char* enemyImage);
        virtual ~Pipe();
		void move();
	protected:
	private:
};

#endif // PIPE_H
