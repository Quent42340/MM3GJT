/*
 * =====================================================================================
 *
 *       Filename:  TilemapLoader.cpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 19:32:33
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/graphics/Tilemap.hpp>

#include "TilemapLoader.hpp"

void TilemapLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *mapElement = doc.FirstChildElement("maps").FirstChildElement("map").ToElement();
	while(mapElement) {
		std::string name = mapElement->Attribute("name");
		std::string tilesetName = mapElement->Attribute("tileset");

		gk::Tileset &tileset = handler.get<gk::Tileset>(tilesetName);

		loadMap(name, tileset, handler);

		mapElement = mapElement->NextSiblingElement("map");
	}
}

void TilemapLoader::loadMap(const std::string &name, gk::Tileset &tileset, gk::ResourceHandler &handler) {
	gk::XMLFile doc("resources/maps/" + name + ".tmx");

	tinyxml2::XMLElement *mapElement = doc.FirstChildElement("map").ToElement();

	u16 width = mapElement->IntAttribute("width");
	u16 height = mapElement->IntAttribute("height");

	std::vector<std::vector<u16>> data;
	tinyxml2::XMLElement *layerElement = mapElement->FirstChildElement("layer");
	while (layerElement) {
		tinyxml2::XMLElement *tileElement = layerElement->FirstChildElement("data")->FirstChildElement("tile");

		std::vector<u16> layer;
		while(tileElement) {
			s16 tileID = tileElement->IntAttribute("gid") - 1;

			layer.push_back((tileID >= 0) ? tileID : 0);

			tileElement = tileElement->NextSiblingElement("tile");
		}

		data.emplace_back(std::move(layer));

		layerElement = layerElement->NextSiblingElement("layer");
	}

	handler.add<gk::Tilemap>("map-" + name, width, height, tileset, data);
}


