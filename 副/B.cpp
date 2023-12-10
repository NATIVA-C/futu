M7:MA(C,7),COLORGRAY;
M21:MA(C,21),COLORYELLOW;

RSV1:=(CLOSE-LLV(LOW,5))/(HHV(HIGH,5)-LLV(LOW,5))*100;
K1:=SMA(RSV1,6,1);
D1:=SMA(K1,6,1);

RSV2:=(CLOSE-LLV(LOW,9))/(HHV(HIGH,9)-LLV(LOW,9))*100;
K2:=SMA(RSV2,3,1);
D2:=SMA(K2,3,1);

LC:=REF(CLOSE,1);
TEMP1:=MAX(CLOSE-LC,0);
TEMP2:=ABS(CLOSE-LC);
RSI1:=SMA(TEMP1,6,1)/SMA(TEMP2,6,1)*100;
RSI2:=SMA(TEMP1,12,1)/SMA(TEMP2,12,1)*100;

DIFF:=EMA(CLOSE,12)-EMA(CLOSE,26);
DEA:=EMA(DIFF,9);

A1:=BARSLAST(REF(CROSS(DIFF,DEA),1));
B1:=REF(C,A1+1)>C AND REF(DIFF,A1+1)<DIFF AND CROSS(DIFF,DEA);

A2:=BARSLAST(REF(CROSS(K1,D1),1));
B2:=REF(C,A2+1)>C AND REF(K1,A2+1)<K1 AND CROSS(K2,D2);

A3:=BARSLAST(REF(CROSS(RSI1,RSI2),1));
B3:=REF(C,A3+1)>C AND REF(RSI1,A3+1)<RSI1 AND CROSS(RSI1,RSI2);

B4:=CROSS(DIFF,DEA) AND CROSS(K1,D1);

DRAWTEXT(B1,H*1.05,'^'),COLORGRAY;
DRAWTEXT(B1,L*0.98,'M背离'),COLORGRAY;
DRAWTEXT(B2,H*1.05,'O'),COLORFF00FF;
DRAWTEXT(B2,L*0.97,'K背离'), COLORFF00FF;
DRAWTEXT(B3,H*1.05,'$'),COLORYELLOW;
DRAWTEXT(B3,L*0.96,'R背离'),COLORYELLOW;
DRAWTEXT(B4,H*1.05,'●'),COLOR0099FF;
DRAWTEXT(B4,L*0.94,'共振'), COLOR0099FF;

