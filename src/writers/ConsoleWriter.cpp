module cppism.logging;

namespace cppism::logging::writers {

void ConsoleWriter::write(
    LogLevel level,
    const std::string_view &message
) const {
  std::ostream &stream(level == LogLevel::Error ? std::cerr : std::cout);
  stream << message << std::endl;
}

}