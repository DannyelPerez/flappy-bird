#ifndef SPRITE_H
#define SPRITE_H

class Sprite
{
    public:
        int width;
        int height;
        int x;
        int y;
        bool movement;
        char direction;
        unsigned char* PixelMap;
        int movementRate;
        int movementCounter;
        Sprite();
        virtual ~Sprite();
        virtual void move();
        void setMovement(char direction);
        void setPositions(int x, int y);
        bool isCollidingWith(Sprite* sprite);
    protected:
    private:
};

#endif // SPRITE_H
