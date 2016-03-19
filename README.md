# Personal
This is a repository for my personal settings for Emacs and the likes.

# Logger
I was trying to make a proxy-server in C++ and tried to find out where the code actually broke, since I got no error message what so ever. That is when I decided to make my own Logger. You know, it's more fun to make your own. Well, it turned out I forgot to bind() to a socket which made the whole thing exit without a good error-message when I tried to send() through that same socket. And that left me with this semi-working Logger, that opens and closes a file too many times. Too many times I say. I didn't know about .flush() at the time, or what it is called... I'll get to it.

# Emacs
So, of course my beautifully crappy Logger needed some coloring set in Emacs. So I tried to make this happen, but I do NOT understand this Emacs/Lisp magic. Trying to mimic others I actually colored the logs, but only after invoking the command: 
     M-x font-lock-fontify-buffer
And yeah. Thats about it.
