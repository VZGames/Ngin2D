#ifndef GAMEMAPS_H
#define GAMEMAPS_H


class GameMaps
{
    // IObject interface
public:
    static GameMaps *instance();
    void draw();
    void update();
    void clean();

private:
    GameMaps();
    static GameMaps *s_instance;

};

#endif // GAMEMAPS_H
