#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger{
 public:
  Logger();
  ~Logger();
  Logger(std::string const& filename);
  
  void log(std::string const& where="", std::string const& message="", int const& level=0);
  bool is_it_logging() const;
  void debug_mode(bool const& onOff);
  void set_log(std::string const& filename_in);
  void warn(std::string const& message);
  void err(std::string const& message);
  void info(std::string const& message);
  void debug(std::string const& message);
  void log_levels(bool const& info=true, bool const& warn=true ,bool const& error=true);
 private:

  void cout_log(std::string const& where="", std::string const& message="", int const& level=0);
  std::string make_pretty(std::string const& where="", std::string const& message="", int const& level=0);
  void write_to_log( std::string const& prettyMessage );
  unsigned long int filesize(std::string const& filename);
  
  bool open_current_log();
  bool log_debug{false};
  bool log_info{true};
  bool log_warn{true};
  bool log_error{true};
  std::string current_log;
  std::ofstream file;
};


#endif /* LOGGER_H */
