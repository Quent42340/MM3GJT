/*
 * =====================================================================================
 *
 *       Filename:  SpriteComponent.hpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 17:24:23
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include <functional>
#include <map>

#include <gk/graphics/Sprite.hpp>
#include <gk/scene/SceneObject.hpp>

struct SpriteState {
	SpriteState(bool _isAnimated, u16 _animationID, u16 _frameID)
		: isAnimated(_isAnimated), animationID(_animationID), frameID(_frameID) {}

	bool isAnimated;

	u16 animationID;
	u16 frameID;
};

class SpriteComponent {
	public:
		SpriteComponent(const std::string &resourceName);
		SpriteComponent(const std::string &textureName, u16 frameWidth, u16 frameHeight)
			: m_textureName(textureName), m_sprite(textureName, frameWidth, frameHeight) {}

		void addState(const std::string &name, bool isAnimated, u16 animationID, u16 frameID = 0);
		void setState(const std::string &name, gk::SceneObject &object, u16 frameOffset = 0);
		const SpriteState &getState(const std::string &name) const;
		const SpriteState &getCurrentState() const { return getState(m_currentState); }
		bool hasCurrentState() const { return !m_currentState.empty(); }

		void updateAnimations();

		const gk::Sprite &sprite() const { return m_sprite; }
		gk::Sprite &sprite() { return m_sprite; }

		bool isEnabled() const { return m_isEnabled; }
		void setEnabled(bool isEnabled) { m_isEnabled = isEnabled; }
		void setAnimated(bool isAnimated) { m_isAnimated = isAnimated; }

	private:
		std::string m_textureName;

		gk::Sprite m_sprite;

		std::string m_currentState;

		std::map<std::string, SpriteState> m_states;

		bool m_isEnabled = true;
		bool m_isAnimated = true;
};

#endif // SPRITECOMPONENT_HPP_
