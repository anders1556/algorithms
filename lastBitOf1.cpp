//找出一个正整数的二进制表示中最后一位1的位置
//11110110最后一位1在倒数第二位

int lastBitOf1(int number)
{
  return number & ^(number-1);
}
