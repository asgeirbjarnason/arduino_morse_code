#!/usr/bin/env python

import re
import sys

translations = (
    (r'(?<!^\w)[ \t]+', r'(); ')#,
#    (r'^(\w)\s+', r'void $1() {'),
#    (r'$', r'(); interletter(); }')
)

def translate(line, translations):
    for t in translations:
        line = re.sub(t[0], t[1], line)
    return line

if __name__ == '__main__':
    for line in sys.stdin.readlines():
        print translate(line, translations)
        