/*
 * =====================================================================================
 *
 *       Filename:  SpriteView.cpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 17:48:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include <gk/scene/component/LifetimeComponent.hpp>
#include <gk/scene/component/PositionComponent.hpp>

#include "SpriteComponent.hpp"
#include "SpriteView.hpp"

void SpriteView::draw(const gk::SceneObject &object, gk::RenderTarget &target, gk::RenderStates states) {
	gk::SpriteView::draw(object, target, states);

	if (object.has<gk::LifetimeComponent>() && object.get<gk::LifetimeComponent>().dead(object))
		return;

	if (object.has<gk::PositionComponent>())
		states.transform.translate({object.get<gk::PositionComponent>(), 0.f});

	if(object.has<SpriteComponent>()) {
		auto &spriteComponent = object.get<SpriteComponent>();
		if (spriteComponent.isEnabled()) {
			spriteComponent.updateAnimations();
			target.draw(spriteComponent.sprite(), states);
		}
	}
}

