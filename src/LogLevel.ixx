export module cppism.logging:LogLevel;

import std;

namespace cppism::logging {
export enum class LogLevel {
  Info,
  Warning,
  Error,
};
}