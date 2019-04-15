#include "gs2d/game/level/threaded_level_loader.hpp"

namespace gs {

ThreadedLevelLoader::~ThreadedLevelLoader() {
  if (level_loader.joinable())
    level_loader.join();
}

void ThreadedLevelLoader::load_level() { level->load(); }

void ThreadedLevelLoader::run(Level *level) {
  this->level = std::shared_ptr<Level>(level);
  level_loader = std::thread(&ThreadedLevelLoader::load_level, this);
}

std::shared_ptr<Level> ThreadedLevelLoader::get_level() {
  level_loader.join();
  return level;
}

} // namespace gs
