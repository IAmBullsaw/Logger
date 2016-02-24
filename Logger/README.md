##How to use this:
#Construct logger and start logging to log.txt:
  Logger l{"log.txt"};

#Set log levels:
  l.log_levels(false,true,true)
sets: log_info to false,
      log_warn to true,
      log_error to true.

#Set debug mode: (Will cout everything AND log everything... EVERYTHING!!)
  l.debug_mode(false);
sets: log_debug = false.
default value is true.

#how to log:

Proper logging:
  l.log("Where","Message",int)

Where is to pinpoint exactly where in the code.
Message is the message for quicker felsökning.

int is the appropriate level:
   -1 logs Debug
    0 logs Info
    1 logs warn
    2 logs error

Quick logging:	
  l.info("message")
  l.warn("message")
  l.error("message")
  l.debug("message")

these all call to 
  l.log("","message",level)
with appropriate level set.
