//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",	    "util.sh",      	10,	                 13},
	{"",	    "network.sh",      	10,	                 12},
	{"",	    "brightness.sh",	0,	                 11},
	{"",	    "volume.sh",	    0,	                 10},
	{"",	    "mic.sh",	        0,	                 9},
	{"",	    "clock.sh",	        60,	                 1},
};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = "  ";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
