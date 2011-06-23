#pragma once
//PI
extern float const PI;
//PI*2
extern float const Two_PI;
//PI/2
extern float const Half_PI;
//PI/4
extern float const Quarter_PI;
//Rounding
extern float const TOL;
//Rounding
extern float const TOLSQ;
//IDK
//extern int const DataFieldMax;

//SIN and COS Constant Table Refrence
extern double  const SinTable[360];
//
enum behavior_type
  {
    none               = 0x00000,
    seek               = 0x00002,
    flee               = 0x00004,
    arrive             = 0x00008,
    wander             = 0x00010,
    cohesion           = 0x00020,
    separation         = 0x00040,
    allignment         = 0x00080,
    obstacle_avoidance = 0x00100,
    wall_avoidance     = 0x00200,
    follow_ath        = 0x00400,
    pursuit            = 0x00800,
    evade              = 0x01000,
    interpose          = 0x02000,
    hide               = 0x04000,
    flock              = 0x08000,
    offset_ursuit     = 0x10000,
  };
//Used for Debug
enum RetStat {SUCCESS, FAIL, DUPLICATE_ERROR };