#pragma once
#include "TextureHolder.h"
#include "Tile.h"
class TileSetedMap : public sf::Drawable
{
public:
	TileSetedMap();
	void  loadMap(const std::string& filename);
	sf::Vector2f size() const;
	sf::FloatRect getBounds();

	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
private:

private:
	sf::Vector2i m_Size;
	int m_TileSize;

	std::vector<Tile*> m_Tiles;
	std::string m_XMLFile;
};