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
	for (u8 i = 0 ; i < currentMap->layerCount() ; ++i) {
		u16 tile = currentMap->getTile(x / currentMap->tileset().tileWidth(),
		                               y / currentMap->tileset().tileHeight(), i);
		if (currentMap->tileset().getTile(tile).type() == 1)
			return false;
	}

	return true;
}

