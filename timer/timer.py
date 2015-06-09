#! /usr/local/bin/python3

import sys
import os
import time
import locale
import signal
import string

def main():
	if (len(sys.argv) < 3):
		print("Usage: timer <timeout (sec)> <program> [program arguments]", file=sys.stderr)
		exit(1)
	try:
		timeout = locale.atoi(sys.argv[1])
	except ValueError:
		print("Unrecognized timeout", file=sys.stderr)
		print("Usage: timer <timeout (sec)> <program> [program arguments]", file=sys.stderr)
		exit(1)
	prog 	= sys.argv[2]
	sprog   = prog
	args 	= [prog]
	for i in range(len(sys.argv) - 3):
		args.append(sys.argv[i + 3])
		sprog += " "+sys.argv[i + 3] 
	child = os.fork()
	startime = time.time()
	if (child == 0):
		os.execvp(prog, args)
	time.sleep(timeout)
	timelapse = time.time() - startime
	print("\nkilling "+sprog+" after "+str(round(timelapse,2))+" seconds")
	os.killpg(os.getpgid(child), signal.SIGKILL)
	exit(0)

main()
