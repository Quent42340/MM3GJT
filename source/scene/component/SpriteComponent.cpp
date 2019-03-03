/*
 * =====================================================================================
 *
 *       Filename:  SpriteComponent.cpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 17:24:48
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(const std::string &resourceName) {
	const SpriteComponent &res = gk::ResourceHandler::getInstance().get<SpriteComponent>(resourceName);
	m_sprite.load(res.sprite());

	m_currentState = res.m_currentState;

	m_states = res.m_states;

	m_isEnabled = res.m_isEnabled;
	m_isAnimated = res.m_isAnimated;
}

void SpriteComponent::addState(const std::string &name, bool isAnimated, u16 animationID, u16 frameID) {
	m_states.emplace(name, SpriteState{isAnimated, animationID, frameID});
}

void SpriteComponent::setState(const std::string &name, gk::SceneObject &object, u16 frameOffset) {
	if (name == m_currentState) return;

	auto it = m_states.find(name);
	if (it == m_states.end())
		throw EXCEPTION("Unable to set current state to an unexistant state:", name, "|", object.name());

	m_sprite.setCurrentAnimation(it->second.animationID);
	m_sprite.setCurrentFrame(it->second.frameID + frameOffset);
	m_sprite.setAnimated(m_isAnimated && it->second.isAnimated);

	m_currentState = name;
}

const SpriteState &SpriteComponent::getState(const std::string &name) const {
	auto it = m_states.find(name);
	if (it == m_states.end())
		throw EXCEPTION("SpriteState not found:", name);
	return it->second;
}

void SpriteComponent::updateAnimations() {
	m_sprite.updateAnimations();
}

