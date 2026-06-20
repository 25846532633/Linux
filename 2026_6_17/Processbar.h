#pragma once
#include <unistd.h>
#include <stdio.h>

typedef void (*callback_t)(double,double);


void ProcBar(double total,double current);
