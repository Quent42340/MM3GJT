/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.hpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 15:59:40
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef KEYBOARDHANDLER_HPP_
#define KEYBOARDHANDLER_HPP_

#include <map>

#include <gk/core/input/InputHandler.hpp>
#include <gk/core/SDLHeaders.hpp>

class KeyboardHandler : public gk::InputHandler {
	public:
		void loadKeysFromFile(const std::string &filename);

		bool isKeyPressed(gk::GameKey key);

	private:
		std::map<gk::GameKey, SDL_Keycode> m_keys;
};

#endif // KEYBOARDHANDLER_HPP_
