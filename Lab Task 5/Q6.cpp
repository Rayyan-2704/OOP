#include <iostream>
using namespace std;

class GraphicsRenderEngine
{
public:
    GraphicsRenderEngine()
    {
        cout << "Graphics Render Engine has been created." << endl;
    }

    ~GraphicsRenderEngine()
    {
        cout << "Graphics Render Engine has been destroyed." << endl;
    }
};

class InputHandler
{
public:
    InputHandler()
    {
        cout << "Input Handler has been created." << endl;
    }

    ~InputHandler()
    {
        cout << "Input Handler has been destroyed." << endl;
    }
};

class PhysicsEngine
{
public:
    PhysicsEngine()
    {
        cout << "Physics Engine has been created." << endl;
    }

    ~PhysicsEngine()
    {
        cout << "Physics Engine has been destroyed." << endl;
    }
};

class GameEngine
{
    GraphicsRenderEngine renderEngine;
    InputHandler input;
    PhysicsEngine phyEngine;

public:
    GameEngine()
    {
        cout << "Game Engine has been created." << endl;
    }

    ~GameEngine()
    {
        cout << "Game Engine has been destroyed." << endl;
    }
};

int main()
{
    GameEngine game;
    return 0;
}