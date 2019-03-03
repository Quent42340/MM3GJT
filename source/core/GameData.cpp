/*
 * =====================================================================================
 *
 *       Filename:  GameData.cpp
 *
 *    Description:
 *
 *        Created:  16/02/2019 12:56:47
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "GameData.hpp"

gk::Tilemap *GameData::currentMap = nullptr;

bool GameData::inTile(float x, float y, u16 tile) {
	for (u8 i = 0 ; i < currentMap->layerCount() ; ++i) {
		if (currentMap->getTile(x / currentMap->tileset().tileWidth(),
		                        y / currentMap->tileset().tileHeight(), i) == tile) {
			return true;
		}
	}

	return false;
}

bool GameData::isPassable(float x, float y) {
	return !inTile(x, y, 2) && !inTile(x, y, 48) && !inTile(x, y, 1) && !inTile(x, y, 3) && !inTile(x, y, 52);
}

