#include "TilesetedMap.h"
#include "TextureHolder.h"
#include "pugixml\pugixml.hpp"
#include <fstream>

TileSetedMap::TileSetedMap() : m_TileSize(70), m_Size(0, 0)
{

}

sf::Vector2f TileSetedMap::size() const {
	sf::Vector2f Buff;
	Buff.x = m_Size.x*m_TileSize;
	Buff.y = m_Size.y*m_TileSize;
	return Buff;
}

void  TileSetedMap::loadMap(const std::string& filename)
{
	Tile* buffer;
	pugi::xml_document doc;
	b2BodyDef def;
	if (!doc.load_file(filename.c_str())){
	}
	pugi::xml_node tile = doc.child("Map");
	m_Size = sf::Vector2i(tile.attribute("x").as_int(), tile.attribute("y").as_int());
	m_TileSize = tile.attribute("tilesize").as_int();
	tile = tile.child("Tile");
	while (tile){
		def.position = b2Vec2(tile.attribute("x").as_int() * m_TileSize / PhysicalEntity::SCALE, tile.attribute("y").as_int() * m_TileSize /PhysicalEntity::SCALE);
		def.type = b2_staticBody;
		buffer = new Tile(&def);
		buffer->setTexture(TextureHolder::getTexture(tile.attribute("texture").as_string()));
		m_Tiles.push_back(buffer);
		tile = tile.next_sibling();
	}
	
}

void TileSetedMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	for (auto it = m_Tiles.begin(); it < m_Tiles.end(); it++){
		target.draw(**it);
	}
}

sf::FloatRect TileSetedMap::getBounds(){
	return sf::FloatRect(0, 0, m_Size.x * m_TileSize, m_Size.y * m_TileSize);
}