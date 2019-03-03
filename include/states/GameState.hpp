/*
 * =====================================================================================
 *
 *       Filename:  GameState.hpp
 *
 *    Description:
 *
 *        Created:  13/02/2019 14:51:52
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include <gk/core/ApplicationState.hpp>
#include <gk/graphics/Tilemap.hpp>
#include <gk/scene/Scene.hpp>

class GameState : public gk::ApplicationState {
	public:
		GameState(gk::ApplicationState *parent = nullptr);

		void update() override;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		gk::View m_view{{0, 0, 0}, {24*16, 14*16}};
		gk::Scene m_scene;
		gk::Tilemap *m_tilemap = nullptr;
};

#endif // GAMESTATE_HPP_
