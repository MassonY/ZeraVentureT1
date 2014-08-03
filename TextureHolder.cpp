#include "TextureHolder.h"
std::map<std::string, std::unique_ptr<sf::Texture>> TextureHolder::m_textures;

sf::Texture* TextureHolder::getTexture(const std::string& asName){
	if (m_textures.find(asName) != m_textures.end())
		return m_textures.at(asName).get();

	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile("data/" + asName + ".png"))
	{
		m_textures.emplace(asName, std::unique_ptr<sf::Texture>(new sf::Texture(*texture)));
		return texture;
	}
	else
	{
		delete texture;
		return nullptr;
		Log::wp("La Texture n'a pas pu étre trouvée");
	}
}

void		TextureHolder::addTexture(const std::string& Name, const sf::Texture& Tex){
	m_textures.emplace(Name, std::unique_ptr<sf::Texture>(new sf::Texture(Tex)));
}