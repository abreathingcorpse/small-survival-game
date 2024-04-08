#include <SFML/Graphics.hpp>
#include "TextureHolder.h++"
#include <iostream>

// Takes the type of texture & filename and loads the file
// into the mTextureMap
void TextureHolder::load(Textures::TYPE type,
                        const std::string& filename) {
    // Create a texture that will be destroyed when moved into
    // mTextureMap
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    texture->loadFromFile(filename);

    // The second argument of the mTextureMap is a
    // unique_prt<sf::Texture> as well. std::move() moves the
    // unique_ptr texture into the one that's inside the mTextureMap
    mTextureMap.insert(std::make_pair(type, std::move(texture)));
}

sf::Texture& TextureHolder::get(Textures::TYPE type) {
    auto found = mTextureMap.find(type);
    std::cout << typeid(found).name() << std::endl;
    return *found->second;
}