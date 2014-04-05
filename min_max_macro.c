/*
*min()/max macros that also do
*"strict type-checkin"	
*/

#define min(x,y)({/
typeof(x) _x = (x);/
typeof(y) _y = (y);/
(void)(&_x == &_y);/
_x < _y ? _x : _y;})



#define max(x,y)({/
typeof(x) _x = (x);/
typeof(y) _y = (y);/
(void)(&_x == &_y);/
_x > _y ? _x : _y;})
