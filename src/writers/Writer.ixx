export module cppism.logging:writers.Writer;
import :LogLevel;

import std;

namespace cppism::logging::writers {

export class Writer {
public:
  virtual ~Writer();

  virtual void write(
      LogLevel level,
      const std::string_view &message
  ) const = 0;

protected:
  static std::chrono::sys_time<std::chrono::milliseconds> getTimePoint();
};

}