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
		try:
			os.execvp(prog, args)
		except FileNotFoundError:
			print("Unknown program "+prog)
			os.killpg(os.getpgid(0), signal.SIGKILL)
	try:
		time.sleep(timeout)
	except ValueError:
		print("Unrecognized timeout (must be positive)", file=sys.stderr)
		os.killpg(os.getpgid(child), signal.SIGKILL)
	timelapse = time.time() - startime
	print("\nkilling "+sprog+" after "+str(round(timelapse,2))+" seconds")
	os.killpg(os.getpgid(child), signal.SIGKILL)
	exit(0)

main()
