 #ifndef BIRD_H
#define BIRD_H
#include "Sprite.h"
class Bird: public Sprite
{
	public:
		bool dead;
        int dropRate;
        int dropCounter;
		Bird(int x, int y, unsigned char* enemyImage);
		virtual ~Bird();
		void move();
	protected:
	private:
};

#endif // BIRD_H
