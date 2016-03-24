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
        Sprite();
        virtual ~Sprite();
        virtual void move();
        void setMovement(char direction);
        void stopMovement();
    protected:
    private:
};

#endif // SPRITE_H
