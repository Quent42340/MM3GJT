/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.cpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 16:14:07
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>
#include <gk/scene/behaviour/EasyBehaviour.hpp>
#include <gk/scene/component/BehaviourComponent.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/component/MovementComponent.hpp>
#include <gk/scene/component/PositionComponent.hpp>

#include "GameData.hpp"
#include "GamePadMovement.hpp"
#include "PlayerFactory.hpp"
#include "SpriteComponent.hpp"

#include <gk/core/input/GamePad.hpp>
#include "GameKey.hpp"

gk::SceneObject PlayerFactory::create(u16 x, u16 y) {
	gk::SceneObject object;
	object.set<gk::PositionComponent>(x, y);
	object.set<gk::HitboxComponent>(12, 14, 9, 18);
	object.set<gk::MovementComponent>(new GamePadMovement).speed = 0.6f;

	auto &spriteComponent = object.set<SpriteComponent>("sprite-characters-player");
	spriteComponent.setState("Standing", object);
	spriteComponent.sprite().setColor(gk::Color{225, 225, 225});

	auto &collisionComponent = object.set<gk::CollisionComponent>();
	collisionComponent.addChecker(&checkCollisions);

	object.set<gk::BehaviourComponent>().addBehaviour<gk::EasyBehaviour>("animation", [](gk::SceneObject &object) {
		auto &movement = object.get<gk::MovementComponent>();
		auto &sprite = object.get<SpriteComponent>();
		if (movement.v.y != 0) {
			sprite.setState("Jumping", object);
		}
		else if (movement.isMoving && movement.v.x != 0) {
			sprite.sprite().setFlip(movement.v.x < 0);
			sprite.setState("Moving", object);
		}
		else if (gk::GamePad::isKeyPressed(GameKey::B)) {
			sprite.setState("Attack", object);
		}
		else {
			sprite.setState("Standing", object);
		}
	});

	return object;
}

void PlayerFactory::checkCollisions(gk::SceneObject &player) {
	auto &position = player.get<gk::PositionComponent>();
	auto &movement = player.get<gk::MovementComponent>();

	const gk::FloatRect &hitbox = *player.get<gk::HitboxComponent>().currentHitbox();

	float hitboxX1 = position.x + hitbox.x;
	float hitboxY1 = position.y + hitbox.y;

	float hitboxX2 = hitboxX1 + hitbox.width - 1.0f;
	float hitboxY2 = hitboxY1 + hitbox.height - 1.0f;

	gk::Vector2f sides[4][4] = {
		{{hitboxX2, hitboxY1}, {hitboxX2, hitboxY2}},
		{{hitboxX1, hitboxY1}, {hitboxX1, hitboxY2}},
		{{hitboxX1, hitboxY1}, {hitboxX2, hitboxY1}},
		{{hitboxX1, hitboxY2}, {hitboxX2, hitboxY2}}
	};

	for(u8 i = 0 ; i < 4 ; i++) {
		bool test;

		switch(i) {
			case 0: test = movement.v.x > 0; break;
			case 1: test = movement.v.x < 0; break;
			case 2: test = movement.v.y < 0; break;
			case 3: test = movement.v.y > 0; break;
		}

		float vx = (i < 2) ? movement.v.x : 0.0f;
		float vy = (i > 1) ? movement.v.y : 0.0f;

		if(test
		&& (!GameData::isPassable(sides[i][0].x + vx, ceil(sides[i][0].y + vy))
		 || !GameData::isPassable(sides[i][1].x + vx, ceil(sides[i][1].y + vy)))) {
			if(i < 2) {
				movement.v.x = 0;

				movement.isBlocked.x = true;
			}
			else if(i == 2) {
				movement.v.y = 0;
			}
			else if(i == 3) {
				movement.v.y = 0;

				movement.isBlocked.y = true;
			}
		}
	}
}

