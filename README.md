# Personal
This is a repository for my personal settings for Emacs and the likes.

# Logger
I was trying to make a proxy-server in C++ and tried to find out where the code actually broke, since I got no error message what so ever. That is when I decided to make my own Logger. You know, it's more fun to make your own. Well, it turned out I forgot to bind() to a socket which made the whole thing exit without a good error-message when I tried to send() through that same socket. And that left me with this semi-working Logger, that opens and closes a file too many times. Too many times I say. I didn't know about .flush() at the time, or what it is called... I'll get to it.

# Emacs
Recently I added my current init.el, mostly for safe keeping since my ubuntu disk is truly unreliable.
