export module cppism.logging:writers.ConsoleWriter;
import :writers.Writer;

import std;

namespace cppism::logging::writers {

export class ConsoleWriter : public Writer {
  void write(
      LogLevel level,
      const std::string_view &message
  ) const override;
};

}