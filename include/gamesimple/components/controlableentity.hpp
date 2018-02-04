// File: controlableentity.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018 Murilo Bento
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _CONTROLABLEENTITY_HPP_
#define _CONTROLABLEENTITY_HPP_

// Represents a controlable entity. The entity will have to respond
// to when a key of the keyboard is pressed or released, and the
// method controlEntity will be responsible for doing so.
// e.g.:
//     class Car : public ControlableEntity {
//         void controlEntity(sf::Keyboard::Key key, bool release){
//             switch(key){
//             case sf::Keyboard::Space:
//                 this->accelerate();
//                 break;
//             case sf::Keyboard::LShift:
//                 this->brake();
//                 break;
//             }
//         }
//     }

class ControlableEntity {
public:
  // Defines how the entity will respond to the given key when it is
  // either pressed or released.
  // The bool release is true if the key is released and false if
  // the key is pressed.
  virtual void controlEntity(sf::Keyboard::Key key, bool release) = 0;
};

#endif
