#ifndef UTILS_H_
#define UTILS_H_

namespace PUtils {
  std::string to_string(int num) {
    std::ostringstream convert;
    convert << num;
    return convert.str();
  }
}
#endif
