#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Logger.h"

using namespace std;

Logger::Logger()
  :log_debug{false},log_info{true},log_warn{true},log_error{true},current_log{},file{}
{
}

Logger::Logger(string const& filename)
  :log_debug{false},current_log{filename},file{}
{
}

Logger::~Logger(){
  file.close();
}

bool Logger::open_current_log(){
  
  file.open( current_log ,ios::out | ios::app );
  if ( !file.is_open() ) {
    cerr << " Logger couldn't open file: '" << current_log << "'" << endl;
  }  
  return file.is_open();
}

void Logger::log( string const& where, string const& message , int const& level) {
  write_to_log( make_pretty( where, message, level) );
  if (log_cout) {
    cout_log(where,message,level); 
  }
}

void Logger::warn(string const& message) {
  if (log_debug || log_warn)
    log("",message,1);
}

void Logger::info(string const& message) {
  if (log_debug || log_info)
    log("",message);
}

void Logger::err(string const& message) {
  if (log_debug || log_error)
    log("",message,2);
}

void Logger::debug(string const& message) {
  if (log_debug)
    log("",message,-1);
}

bool Logger::is_it_logging() const {
  return this->file.is_open();
}

void Logger::cout_log(std::string const& where, std::string const& message, int const& level) {
  int indent = 9 + message.length();
  string divider = "+------------------------------------------------------------+\n";
  
  if (level <= 0 && (log_debug || log_info )){
    cout << divider 
	   << "Message: "  
	 << where << endl
	 << setw(indent)
	 << message << endl
	 << divider;
  } else if (level == 1 && (log_debug || log_warn )) {
    cerr << divider 
	 << "Warning: " 
	   << where << endl
	 << setw(10) 
	 << message << endl
	 << divider;
  } else if (level == 2 && (log_debug || log_error )) {
    cerr << divider 
	 << "ERROR: " 
	   << where << endl
	 << setw(10) 
	 << message << endl
	 << divider;
  }
}


void Logger::debug_mode(bool const& onOff) {
  log_debug = onOff;
  if (log_debug == true) {
    log_info = true;
    log_warn = true;
    log_error = true;
  }
}

void Logger::cout_mode(bool const& onOff) {
  log_cout = onOff;
}

void Logger::log_levels(bool const& info, bool const& warn ,bool const& error ) {
  log_info = info;
  log_warn = warn;
  log_error = error;
}

string Logger::make_pretty(string const& where, string const& message, int const& level) {
  time_t t = time(0);   // get time now

  string prettyMessage;
  if (level == -1) {
    prettyMessage += "[DBUG ";
  } else if (level == 0) {
    prettyMessage += "[INFO ";
  } else if (level == 1) {
    prettyMessage += "[WARN ";
  } else {
    prettyMessage += "[*ERR ";
  }

  struct tm * now = localtime( & t );
  char logtime[80];
  strftime( logtime, sizeof(logtime) , "%Y-%m-%d %H:%M:%S] ", now);
 
  prettyMessage += logtime;
  

  string new_where{""};
  if (where != "") {
    new_where = "Where: " + where + "  ";
  }
  string new_message{""};  
  if (message != "") {
    new_message = "Message: " + message + "  ";
  }

  string divider = ("\n                           ");
  if (new_where != "") {
    prettyMessage += new_where;
    if (new_message !="") {
      prettyMessage += ( divider + new_message + '\n');
    } else {prettyMessage += '\n';}
    
  } else {
    if (new_message !="") {
      prettyMessage += (new_message + '\n') ;
    } else {
      prettyMessage += "No messages\n";
    }
  }

  return prettyMessage;
}


void Logger::write_to_log(string const& prettyMessage ){
  if ( open_current_log() ) {
    file << prettyMessage;
    file.close();
  }
}

unsigned long int Logger::filesize(string const& filename)
{
  unsigned long int size{0};
  std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
  size = static_cast<unsigned long int>( in.tellg() );
  return size; 
}

void Logger::set_log(string const& filename_in) {
  current_log = filename_in;
}
