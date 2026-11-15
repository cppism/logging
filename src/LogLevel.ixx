export module cppism.logging:LogLevel;

import std;

namespace cppism::logging {
export enum class LogLevel : std::uint8_t {
  Debug,
  Info,
  Warning,
  Error,
};
}

using cppism::logging::LogLevel;

template <>
struct std::formatter<LogLevel, char> {
  enum class Padding : std::uint8_t {
    None,
    Left,
    Right
  };

  Padding padding;

  constexpr formatter() :
      padding(Padding::None) {
  }

  [[nodiscard]]
  constexpr auto parse(const std::format_parse_context &ctx) {
    for (auto i(ctx.begin()); i != ctx.end(); ++i) {
      switch (*i) {
        case '<':
          padding = Padding::Left;
          break;
        case '>':
          padding = Padding::Right;
          break;
        default:
          return i;
      }
    }
    return ctx.end();
  }

  [[nodiscard]]
  auto format(
      const LogLevel &value,
      auto &ctx
  ) const {
    return std::format_to(
        ctx.out(),
        getFormat(padding),
        getString(value)
    );
  }

private:
  static std::format_string<std::string_view> getFormat(const Padding padding) {
    switch (padding) {
      case Padding::None:
        return "{}";
      case Padding::Left:
        return "{:<5}";
      case Padding::Right:
        return "{:>5}";
    }
    return "";
  }

  static constexpr std::string_view getString(const LogLevel level) {
    switch (level) {
      case LogLevel::Debug:
        return "DEBUG";
      case LogLevel::Info:
        return "INFO";
      case LogLevel::Warning:
        return "WARN";
      case LogLevel::Error:
        return "ERROR";
    }
    return "";
  }
};