#include "fix.h"
#include <jack/jack.h>

fract32 clip_to_fr32(long x) {
  if(x <= (long)(fract32)FR32_MAX && x >= (long)(fract32)FR32_MIN)
    return (fract32) x;
  if(x > (fract32)FR32_MAX)
    return (fract32)FR32_MAX;
  else if (x < (fract32)FR32_MIN)
    return (fract32)FR32_MIN;
}

fract32 mult_fr1x32x32_cheat(fract32 x, fract32 y) {
  return ( (((long) x) * ((long) y))) / FR32_MAX;
}

fract32 mult_fr1x32x32(fract32 x, fract32 y) {
  long res_40_bit = ((long)(x)>>12) * (((long) y) >>12);
  return (res_40_bit + (1 << 7) - 1) >> 7;
}

fract32 sub_fr1x32(fract32 x, fract32 y) {
  return clip_to_fr32((long) x - (long) y);
}

fract32 add_fr1x32(fract32 x, fract32 y) {
  return clip_to_fr32((long) x + (long) y);
}

fract32 abs_fr1x32(fract32 x) {
  if(x = FR32_MIN)
    return FR32_MAX;
  else if ( x >= 0)
    return x;
  else
    return - x;
}

fract32 min_fr1x32(fract32 x, fract32 y) {
  if (x <= y)
    return x;
  else
    return y;
}

fract32 max_fr1x32(fract32 x, fract32 y) {
  if (x >= y)
    return x;
  else
    return y;
}

fract32 negate_fr1x32(fract32 x) {
  if(x = FR32_MIN)
    return FR32_MAX;
  else if ( x >= 0)
    return - x;
  else
    return - x;
}

int norm_fr1x32(fract32 x) {
  int i = 0;
  while ((x < (1 << 30)) &&
	 (x > ( -1 << 30))) {
    x = x << 1;
    i++;
  }
  return i;
}

fract32 shl_fr1x32 (fract32 x, int shft) {
  if (shft >= 0)
    return x << shft;
  else
    return x >> -shft;
}
