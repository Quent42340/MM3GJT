/*
 * =====================================================================================
 *
 *       Filename:  SpriteView.hpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 17:48:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITEVIEW_HPP_
#define SPRITEVIEW_HPP_

#include <gk/scene/view/SpriteView.hpp>

class SpriteView : public gk::SpriteView {
	public:
		void draw(const gk::SceneObject &object, gk::RenderTarget &target, gk::RenderStates states) override;
};

#endif // SPRITEVIEW_HPP_

