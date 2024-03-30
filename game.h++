#ifndef GAME_H // GAME_H header guard
#define GAME_H

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
        sf::RectangleShape mPlayer;
        // Defined outside of a funcion so they should be
        // initialized to false
        bool mIsMovingUp;
        bool mIsMovingDown;
        bool mIsMovingLeft;
        bool mIsMovingRight = false;

};

#endif // GAME_H header guard