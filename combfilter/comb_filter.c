//滤波器设置
//滤波函数移植  梳状滤波器
#define IIR_L 20 ////1KHz  20阶 21个系数
float IIRBuffer[CHANNELNUM][IIR_L+1] = { 0 };//滤波函数 缓存数组
static float *p0 = &IIRBuffer[0][0];//8个通道数据缓存数组的指针头
static float *p1 = &IIRBuffer[1][0];
//static float *p2 = &IIRBuffer[2][0];
//static float *p3 = &IIRBuffer[3][0];
//static float *p4 = &IIRBuffer[4][0];
//static float *p5 = &IIRBuffer[5][0];
//static float *p6 = &IIRBuffer[6][0];
//static float *p7 = &IIRBuffer[7][0];
////滤波系数
static float Den = -0.8230;
static float Num = 0.9115;


//实现函数 需要自行修改
if(datafilte3){
qDebug()<<"dfdf"<<endl;
switch (i % CHANNELNUM)  //几个case就几个通道的滤波
{
case 0: {
q = p0 + 1;  //将现有指针指向下一位
if (q > &IIRBuffer[0][IIR_L])//循环指针实现
q = q - IIR_L - 1;//指向第一个指针 也就是下标0
*p0 = tempp - (*q) * (Den);  //原有的指针的值更新为下一位的值乘以系数
fSum = (*p0) * Num + (*q) * (-Num);//滤波后的值 前一个值乘以系数加上后一个值乘以系数
p0++;//现有指针指向下一位
if (p0 > &IIRBuffer[0][IIR_L])//p0到底就循环
p0 = &IIRBuffer[0][0];
break;
}
case 1: {
q = p1 + 1;
if (q > &IIRBuffer[1][IIR_L])
q = q - IIR_L - 1;
*p1 = tempp - (*q) * (Den);
fSum = (*p1) * Num + (*q) * (-Num);
p1++;
if (p1 > &IIRBuffer[1][IIR_L])
p1 = &IIRBuffer[1][0];
break;
}
//                      case 2: {
//                                  q = p2 + 1;
//                                  if (q > &IIRBuffer[2][IIR_L])
//                                      q = q - IIR_L - 1;
//                                  *p2 = tempp - (*q) * (Den);
//                                  fSum = (*p2) * Num + (*q) * (-Num);
//                                  p2++;
//                                  if (p2 > &IIRBuffer[2][IIR_L])
//                                      p2 = &IIRBuffer[2][0];
//                                  break;
//                      }
//                      case 3: {
//                                  q = p3 + 1;
//                                  if (q > &IIRBuffer[3][IIR_L])
//                                      q = q - IIR_L - 1;
//                                  *p3 = tempp - (*q) * (Den);
//                                  fSum = (*p3) * Num + (*q) * (-Num);
//                                  p3++;
//                                  if (p3 > &IIRBuffer[3][IIR_L])
//                                      p3 = &IIRBuffer[3][0];
//                                  break;
//                      }
//                      case 4: {
//                                  q = p4 + 1;
//                                  if (q > &IIRBuffer[4][IIR_L])
//                                      q = q - IIR_L - 1;
//                                  *p4 = tempp - (*q) * (Den);
//                                  fSum = (*p4) * Num + (*q) * (-Num);
//                                  p4++;
//                                  if (p4 > &IIRBuffer[4][IIR_L])
//                                      p4 = &IIRBuffer[4][0];
//                                  break;
//                      }
//                      case 5: {
//                                  q = p5 + 1;
//                                  if (q > &IIRBuffer[5][IIR_L])
//                                      q = q - IIR_L - 1;
//                                  *p5 = tempp - (*q) * (Den);
//                                  fSum = (*p5) * Num + (*q) * (-Num);
//                                  p5++;
//                                  if (p5 > &IIRBuffer[5][IIR_L])
//                                      p5 = &IIRBuffer[5][0];
//                                  break;
//                      }
//                      case 6: {
//                                  q = p6 + 1;
//                                  if (q > &IIRBuffer[6][IIR_L])
//                                      q = q - IIR_L - 1;
//                                  *p6 = tempp - (*q) * (Den);
//                                  fSum = (*p6) * Num + (*q) * (-Num);
//                                  p6++;
//                                  if (p6 > &IIRBuffer[6][IIR_L])
//                                      p6 = &IIRBuffer[6][0];
//                                  break;
//                      }
//                      case 7: {
//                                  q = p7 + 1;
//                                  if (q > &IIRBuffer[7][IIR_L])
//                                      q = q - IIR_L - 1;
//                                  *p7 = tempp - (*q) * (Den);
//                                  fSum = (*p7) * Num + (*q) * (-Num);
//                                  p7++;
//                                  if (p7 > &IIRBuffer[7][IIR_L])
//                                      p7 = &IIRBuffer[7][0];
//                                  break;
//                      }
defult:
break;

}

tempp=fSum;
}