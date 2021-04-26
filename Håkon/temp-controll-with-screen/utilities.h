#pragma once

#include <Arduino.h>

#define enA 9
#define in1 6
#define in2 7



void reactOnTemp(double temperature, double maxTemp=200);
void MConOFF(String set);
