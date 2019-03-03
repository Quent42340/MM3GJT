/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:
 *
 *        Created:  13/02/2019 14:47:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/input/GamePad.hpp>

#include "Application.hpp"
#include "GameState.hpp"
#include "SpriteLoader.hpp"
#include "TextureLoader.hpp"
#include "TilemapLoader.hpp"
#include "TilesetLoader.hpp"

void Application::init() {
	gk::CoreApplication::init();

	createWindow(24*16*4, 14*16*4, "game");

	m_shader.loadFromFile("resources/shaders/game.v.glsl", "resources/shaders/game.f.glsl");
	m_renderStates.shader = &m_shader;

	m_resourceHandler.loadConfigFile<TextureLoader>("resources/config/textures.xml");
	m_resourceHandler.loadConfigFile<SpriteLoader>("resources/config/sprites.xml");
	m_resourceHandler.loadConfigFile<TilesetLoader>("resources/config/tilesets.xml");
	m_resourceHandler.loadConfigFile<TilemapLoader>("resources/config/maps.xml");

	m_keyboardHandler.loadKeysFromFile("resources/config/keys.xml");
	gk::GamePad::init(m_keyboardHandler);

	m_clock.setTimestep(8);

	m_stateStack.push<GameState>();
}

void Application::onEvent(const SDL_Event &event) {
	gk::CoreApplication::onEvent(event);

	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
		m_window.close();
	}
}

