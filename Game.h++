#ifndef GAME_H // Header guard
#define GAME_H
#include "TextureHolder.h++"

class Game {
    public:
        Game(); // Default constructor
        void run(); // Public method

    private:
        // Private methods
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
        void processEvents();
        void update(sf::Time deltaTime);
        void render();

        // Private members
        sf::RenderWindow mWindow;
        TextureHolder mTextures;
//        sf::Texture mTexture;
        sf::Sprite mPlayer;
//        sf::RectangleShape mPlayer;
        // Defined outside of a funcion so they should be
        // initialized to false
        bool mIsMovingUp;
        bool mIsMovingDown;
        bool mIsMovingLeft;
        bool mIsMovingRight = false;

};

#endif // GAME_H header guard