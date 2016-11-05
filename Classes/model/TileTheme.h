#include "cocos2d.h"

class TileTheme {
public:

  static TileTheme getThemeByName(std::string themeName);

  TileTheme();
  TileTheme(std::string fileName, std::vector<std::string> animations);
  ~TileTheme();

  std::string _fileName;
  std::vector<std::string> _animations;
};
