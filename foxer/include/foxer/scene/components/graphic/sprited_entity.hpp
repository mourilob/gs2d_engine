// File: sprited_entity.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018-2020 Murilo Bento
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef FOX_SPRITED_ENTITY_HPP_
#define FOX_SPRITED_ENTITY_HPP_

#include <SFML/Graphics.hpp>

// Sprited entities are entities that have a sprite.
// This is useful to encapsulate all operations over
// a sprite of an entity without having to get its member
// sprite.

namespace fox {

class SpritedEntity : public sf::Drawable {
public:
  // Constructor. It takes the texture, the X and Y positions,
  // and the width and height of this sprite.
  SpritedEntity(sf::Texture const &texture, sf::Vector2i sprite_dimensions,
                sf::Vector2i sprite_pos_at_tex = sf::Vector2i(0, 0));

  // Empty constructor. This is important so the user of the
  // animated sprite can choose to initialize it later (but it's
  // important to not forget to do so).
  SpritedEntity();

  // Configure the rect of the sprite, so it can turn into another
  // one in its texture. This method also requires the width and
  // height of the new sprite, in case of different dimensions.
  void configure_sprite_rect(int x, int y, int w, int h);

  // Configure the rect of the sprite, so it can turn into another
  // one in its texture. This method uses the current width and
  // height of the sprite to load the next one. Useful with animation
  // and standardized dimensions.
  void configure_sprite_rect(int x, int y);

  // Set the position of the sprite to the position of the
  // given two-dimensional float vector.
  void set_sprite_position(sf::Vector2f position);

  // Set the position of the sprite to the position of the
  // given X and Y coordinates.
  void set_sprite_position(float x, float y);

  // Scale the sprite in the X and Y axis.
  void set_sprite_scale(float x, float y);

  // Move the sprite. This method adds the current position
  // of the sprite to the given two-dimensional vector.
  void move_sprite(sf::Vector2f movement);

  // Set the color of the sprite to the given color.
  void set_sprite_color(sf::Color color);

  sf::Sprite get_sprite() const;
  sf::Vector2f get_sprite_position() const;
  sf::Vector2i get_sprite_dimensions() const;
  sf::FloatRect get_sprite_global_bounds() const;
  sf::FloatRect get_sprite_local_bounds() const;

  sf::RectangleShape get_rectangle_shape() const;

private:
  // The sprite of the entity.
  sf::Sprite sprite;

  // The dimensions of the entity. This is a two-dimensional
  // vector of int which contains, respectively, the width and
  // the height of the sprite.
  sf::Vector2i sprite_dimensions;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

} // namespace fox

#endif
