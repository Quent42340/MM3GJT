/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.cpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 19:37:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/XMLFile.hpp>
#include <gk/graphics/Tileset.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "TilesetLoader.hpp"

void TilesetLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *tilesetElement = doc.FirstChildElement("tilesets").FirstChildElement("tileset").ToElement();
	while(tilesetElement) {
		std::string name = tilesetElement->Attribute("name");
		std::string filename = "resources/graphics/tilesets/" + name + ".png";

		std::string configFile = "resources/tilesets/" + name + ".tsx";

		handler.add<gk::Tileset>(name, filename, configFile);

		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}

