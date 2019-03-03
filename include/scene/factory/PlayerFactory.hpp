/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.hpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 16:13:05
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERFACTORY_HPP_
#define PLAYERFACTORY_HPP_

#include <gk/scene/SceneObject.hpp>

class PlayerFactory {
	public:
		static gk::SceneObject create(u16 x, u16 y);

	private:
		static void checkCollisions(gk::SceneObject &player);
};

#endif // PLAYERFACTORY_HPP_
