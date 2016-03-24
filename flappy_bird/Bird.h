#ifndef BIRD_H
#define BIRD_H

class Bird
{
    public:
        int width;
        int height;
        int x;
        int y;
        unsigned char* PixelMap;
        bool dead;
        void jump();
        
        Bird(int x, int y, unsigned char* enemyImage);
        virtual ~Bird();
    protected:
    private:
};

#endif // BIRD_H