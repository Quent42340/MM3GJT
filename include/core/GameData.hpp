/*
 * =====================================================================================
 *
 *       Filename:  GameData.hpp
 *
 *    Description:
 *
 *        Created:  16/02/2019 12:56:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMEDATA_HPP_
#define GAMEDATA_HPP_

#include <gk/graphics/Tilemap.hpp>

class GameData {
	public:
		static bool inTile(float x, float y, u16 tile);
		static bool isPassable(float x, float y);

		static gk::Tilemap *currentMap;
};

#endif // GAMEDATA_HPP_
