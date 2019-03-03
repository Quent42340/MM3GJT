/*
 * =====================================================================================
 *
 *       Filename:  GameState.cpp
 *
 *    Description:
 *
 *        Created:  13/02/2019 14:56:36
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/input/GamePad.hpp>
#include <gk/resource/ResourceHandler.hpp>
#include <gk/scene/controller/BehaviourController.hpp>
#include <gk/scene/controller/MovementController.hpp>
#include <gk/scene/view/HitboxView.hpp>

#include "GameData.hpp"
#include "GameKey.hpp"
#include "GameState.hpp"
#include "PlayerFactory.hpp"
#include "SpriteView.hpp"

GameState::GameState(gk::ApplicationState *parent) : gk::ApplicationState(parent) {
	m_scene.addController<gk::MovementController>();
	m_scene.addController<gk::BehaviourController>();
	// m_scene.addView<gk::HitboxView>();
	m_scene.addView<SpriteView>();

	// m_scene.addObject(PlayerFactory::create(5, 141));
	m_scene.addObject(PlayerFactory::create(5, 130));

	m_tilemap = &gk::ResourceHandler::getInstance().get<gk::Tilemap>("map-test");
	GameData::currentMap = m_tilemap;
}

void GameState::update() {
	m_scene.update();

	m_tilemap->update();
}

void GameState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.setView(m_view);
	target.draw(*m_tilemap, states);
	target.draw(m_scene, states);
}

