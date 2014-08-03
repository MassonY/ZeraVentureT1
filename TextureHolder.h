#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "log.h"
class TextureHolder
{
public:
	virtual ~TextureHolder(){};
	static sf::Texture* getTexture(const std::string&);
	static void			addTexture(const std::string&, const sf::Texture&);
private:
	static std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
};

#endif