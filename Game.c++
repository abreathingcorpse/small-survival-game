#include <SFML/Graphics.hpp>
#include "Game.h++"
#include "TextureHolder.h++"
#include <iostream>

// Constructor Initializer List
Game::Game() : mWindow(sf::VideoMode(640,480),
                        "The Dark Side of this Planet"),
                mTextures(),
                mPlayer() {
                    mTextures.load(Textures::PLAYER,
                                "Iceman.png");
                    mPlayer.setTexture(mTextures.get(Textures::PLAYER));
                    // Loads the texture from path and if it fails
                    // it prints an error on the terminal 
/*                    if (!mTexture.loadFromFile("Iceman.png"))
                    {
                        std::cout << "Iceman.png not found"
                        << std::endl;
                    }
                    mPlayer.setTexture(mTexture);
                    */
                    mPlayer.setPosition(100.f, 100.f);
                } // {} is the function body

void Game::handlePlayerInput(sf::Keyboard::Key key,
    bool isPressed) {
        if ((key == sf::Keyboard::W) || (key == sf::Keyboard::Up))
            mIsMovingUp = isPressed;
        if ((key == sf::Keyboard::S) || (key == sf::Keyboard::Down))
            mIsMovingDown = isPressed;
        if ((key == sf::Keyboard::A) || (key == sf::Keyboard::Left))
            mIsMovingLeft = isPressed;
        if ((key == sf::Keyboard::D) || (key == sf::Keyboard::Right))
            mIsMovingRight = isPressed;

    }

void Game::processEvents() {
    sf::Event event; // Holds all the info about a system event


    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time elapsedTime) {
    sf::Vector2f movement(0.f, 0.f);
    const float unitaryVel = 20000.f;
    // By using if instead of else if, it takes into account more
    // than one key being pressed
    if (mIsMovingUp)
        movement.y -= unitaryVel; 
    if (mIsMovingDown)
        movement.y += unitaryVel;
    if (mIsMovingLeft)
        movement.x -= unitaryVel;
    if (mIsMovingRight) {
        movement.x += unitaryVel;
    }

    mPlayer.move(movement * elapsedTime.asSeconds());
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::run() {
    sf::Clock clock;
    sf::Time elapsedTime;
    
    // You want a float in the division, so that it's not truncated
    // to 0
    const sf::Time framerate = sf::seconds(1.f/60);

    while(mWindow.isOpen()) {
        elapsedTime += clock.restart();
        while (elapsedTime > framerate) {
            elapsedTime -= framerate;
            processEvents();
            update(elapsedTime);
        }
        render();
    }
}