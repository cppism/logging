export module cppism.logging:Logger;
import :writers.Writer;

import std;

using cppism::logging::writers::Writer;

namespace cppism::logging {

export class Logger {
  std::shared_ptr<Writer> _writer;

public:
  explicit Logger(std::shared_ptr<Writer> writer);

  void log(
      LogLevel level,
      const std::string_view &message
  ) const;

  template <typename... TArgs>
  void log(
      const LogLevel level,
      const std::format_string<TArgs...> &message,
      TArgs &&...args
  ) const {
    write(level, std::format(message, std::forward<TArgs>(args)...));
  }

  void debug(std::string_view const &message) const;

  template <typename... TArgs>
  void debug(
      const std::format_string<TArgs...> &message,
      TArgs &&...args
  ) const {
    log(LogLevel::Debug,
        message,
        std::forward<TArgs>(args)...);
  }

  void info(std::string_view const &message) const;

  template <typename... TArgs>
  void info(
      const std::format_string<TArgs...> &message,
      TArgs &&...args
  ) const {
    log(LogLevel::Info,
        message,
        std::forward<TArgs>(args)...);
  }

  void warn(std::string_view const &message) const;

  template <typename... TArgs>
  void warn(
      const std::format_string<TArgs...> &message,
      TArgs &&...args
  ) const {
    log(LogLevel::Warning,
        message,
        std::forward<TArgs>(args)...);
  }

  void error(std::string_view const &message) const;

  template <typename... TArgs>
  void error(
      const std::format_string<TArgs...> &message,
      TArgs &&...args
  ) const {
    log(LogLevel::Error,
        message,
        std::forward<TArgs>(args)...);
  }

private:
  void write(
      LogLevel level,
      const std::string_view &message
  ) const;
};

}