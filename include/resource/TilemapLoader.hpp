/*
 * =====================================================================================
 *
 *       Filename:  TilemapLoader.hpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 19:31:39
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILEMAPLOADER_HPP_
#define TILEMAPLOADER_HPP_

#include <gk/resource/ResourceHandler.hpp>

namespace gk { class Tileset; }

class TilemapLoader : public gk::IResourceLoader {
	public:
		void load(const char *xmlFilename, gk::ResourceHandler &handler) override;

	private:
		void loadMap(const std::string &name, gk::Tileset &tileset, gk::ResourceHandler &handler);
};

#endif // TILEMAPLOADER_HPP_
