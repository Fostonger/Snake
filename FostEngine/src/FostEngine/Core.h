#pragma once

#define FOST_ASSERT(x, ...) { if(!(x)) {FOST_ERROR("Assertion failed: {0}," __VA_ARGS__); __debugbreak(); } }
#define FOST_CORE_ASSERT(x, ...) { if(!(x)) {FOST_CORE_ERROR("Assertion failed: {0}," __VA_ARGS__); __debugbreak(); } }