#!/usr/bin/env ruby

# Read from either a list of files or stdin and output the lines in reverse.

lines = ARGF.readlines
lines.reverse.each { |line| puts line }
