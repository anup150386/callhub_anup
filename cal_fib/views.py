# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.shortcuts import render
import ctypes
import os
import ast
import pymemcache
from callhub_anup.settings import client
from django.http import HttpResponse
import json

# Create your views here.
def index(request):

	context = {}
	return render(request, 'call_fib/index.html', context)


def calculate(request):
	number = request.POST.get('number');

	result = client.get(number)



	if result is None:
	    	# The cache is empty, need to get the value
	    	# from the shared library written in C. The actual fibonacci implementation is there.
			csl = ctypes.cdll.LoadLibrary(os.path.abspath("c_prog_fib.o"))
			result = ast.literal_eval(csl.calculate(c_int(number)))

			# Cache the result for next time:
			result['all_the_numbers'] = ' '.join(map(str, result['result']))

			client.set(number, ast.literal_eval(result))

	return HttpResponse(json.dumps(result), content_type="application/json")