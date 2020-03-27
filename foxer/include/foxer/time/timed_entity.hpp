// File: timed_entity.hpp
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

#ifndef TIMED_ENTITY_HPP_
#define TIMED_ENTITY_HPP_

#include "foxer/time/time_handler.hpp"

namespace fox {

class TimedEntity {
public:
  TimedEntity();
  TimedEntity(sf::Time update_rate);
  TimeHandler *get_time_handler();
  void time_trigger();
  virtual void on_update_time() = 0;
  void reset_last_update();
  void ready_to_update();

private:
  TimeHandler time_handler;
};

} // namespace fox

#endif
