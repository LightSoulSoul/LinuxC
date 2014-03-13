#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2013-12-19 12:55:30
# @Author  : Your Name (you@example.org)
# @Link    : http://example.org
# @Version : $Id$

import os

def fac(n):
	if n == 1 or n == 0:
		return 1
	else:
		return fac(n-1) * n

if __name__ == '__main__':
	print fac(5)