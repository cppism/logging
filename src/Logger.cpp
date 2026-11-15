module cppism.logging;

namespace cppism::logging {

Logger::Logger(std::shared_ptr<Writer> writer) :
    _writer(std::move(writer)) {
}

void Logger::log(
    const LogLevel level,
    const std::string_view &message
) const {
  write(level, message);
}

void Logger::debug(const std::string_view &message) const {
  log(LogLevel::Debug, message);
}

void Logger::info(const std::string_view &message) const {
  log(LogLevel::Info, message);
}

void Logger::warn(const std::string_view &message) const {
  log(LogLevel::Warning, message);
}

void Logger::error(const std::string_view &message) const {
  log(LogLevel::Error, message);
}

void Logger::write(
    LogLevel level,
    const std::string_view &message
) const {
  _writer->write(level, message);
}

}