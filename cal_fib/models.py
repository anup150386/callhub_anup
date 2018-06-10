# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models

# Create your models here.

class result(models.Model):
	number = models.IntegerField(),
	result = models.CharField(max_length=10000);
	time_taken = models.FloatField();


