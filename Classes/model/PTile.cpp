#include "PTile.h"

PTile* PTile::create() {

}

PTile* PTile::create(std::string themeName) {
  PTile* tile = new PTile();
  if (tile->init(themeName)) {
    tile->autorelease();
    return tile;
  }
  return nullptr;
}

bool PTile::init(std::string themeName) {
  TileTheme theme = TileTheme::getThemeByName(themeName);
  if (Sprite::initWithFile(theme._fileName)) {
    // TODO
    return true;
  }
  return false;
}

PTile::PTile(){

}
PTile::~PTile(){

}
