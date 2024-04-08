#ifndef TEXTURE_HOLDER_H // Header guard
#define TEXTURE_HOLDER_H
#include <memory>

// Define the texture types first
namespace Textures {
    enum TYPE { PLAYER };
}

class TextureHolder {
    public:
        void load(Textures::TYPE type,
                 const std::string& filename);
        sf::Texture& get(Textures::TYPE type);

    private:
        // A map is like a key, value pair. Similar to a Python dict
        std::map<Textures::TYPE,
                std::unique_ptr<sf::Texture>> mTextureMap;

};

#endif // TEXTURE_HOLDER_H header guard