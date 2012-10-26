#!/usr/bin/env python
# -*- coding: utf-8 -*-

import re
import sys

translations = (
    (r'(?<!^\w)[ \t]+', r'(); '),
    (r'^(\w)\s+', r'void \1() { '),
    (r'$', r'(); interletter(); }')
)

def translate(line, translations):
    for t in translations:
        line = re.sub(t[0], t[1], line)
    return line

def funcname(line):
    m = re.match(r'^(\w)\s', line)
    if m:
        return m.group(1)
    raise 1 # nenni ekki að finna gott exception.

if __name__ == '__main__':
    funcnames = set();
    for line in sys.stdin.readlines():
        print translate(line.strip(), translations)
        funcnames.add(funcname(line))
    
    print # Empty line to seperate the function from the function pointer array.
    
    print "void (*alphabet[])() = { ",
    print ", ".join("&"+f for f in sorted(funcnames)),
    print " };"