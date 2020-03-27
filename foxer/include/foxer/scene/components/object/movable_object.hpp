// File: movable_object.hpp
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

#ifndef FOX_MOVABLE_OBJECT_HPP_
#define FOX_MOVABLE_OBJECT_HPP_

#include <SFML/Graphics.hpp>

namespace fox {

class MovableObject {
public:
  bool moving_up;
  bool moving_down;
  bool moving_left;
  bool moving_right;

  float collision_offset_left;
  float collision_offset_right;
  float collision_offset_up;
  float collision_offset_down;

  MovableObject();

  sf::Vector2f get_movement() const;
  sf::Vector2f get_current_movement() const;
  void nullfy_movement();

  void set_movement_x(float x);
  void set_movement_y(float y);
  void set_movement(sf::Vector2f movement);

  virtual void move(float delta_time) = 0;
  virtual void move() = 0;

protected:
  sf::Vector2f movement;
  sf::Vector2f current_movement;
};

} // namespace fox

#endif
