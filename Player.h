#pragma once 

#include"Renderer.h"

void Play(const char* path) { PlaySound(LPCWSTR(path), NULL, SND_SYNC); };
