module cppism.logging;

namespace cppism::logging::writers {

Writer::~Writer() = default;

std::chrono::sys_time<std::chrono::milliseconds> Writer::getTimePoint() {
  return std::chrono::floor<std::chrono::milliseconds>(std::chrono::system_clock::now());
}

}