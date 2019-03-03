/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.hpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 16:17:45
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMEPADMOVEMENT_HPP_
#define GAMEPADMOVEMENT_HPP_

#include <gk/scene/movement/Movement.hpp>

class GamePadMovement : public gk::Movement {
	public:
		void process(gk::SceneObject &object);

		enum class JumpState : u8 {
			Landed,
			Jumping,
			Falling
		};

	private:
		float m_jumpSpeed = 2.5f;

		JumpState m_jumpState = JumpState::Landed;
};

#endif // GAMEPADMOVEMENT_HPP_
