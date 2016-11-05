#include "TileTheme.h"

static std::map<std::string, TileTheme> _tileThemes =
              { std::pair<std::string, TileTheme> ("default", TileTheme())};

TileTheme TileTheme::getThemeByName(std::string themeName) {
  // TODO
  return _tileThemes.find(themeName)->second;
}

TileTheme::TileTheme() : TileTheme("tile_default.png", std::vector<std::string>()) {

}

TileTheme::TileTheme(std::string fileName, std::vector<std::string> animations) {
  _fileName = fileName;
  _animations = animations;
}

TileTheme::~TileTheme() {

}
