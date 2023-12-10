Sub Chart

VA:=IF(CLOSE>REF(CLOSE,1),VOL,IF(CLOSE<REF(CLOSE,1),-VOL,0));
OBV:=EMA(SUM(VA,TOTALBARSCOUNT)/1000,2);
OBVE:=EMA(OBV,3);

DIFF:(EMA(OBVE,12)-EMA(OBVE,26)),COLORYELLOW;
DEA:EMA(DIFF,9),COLORGREEN;
MACD:=2*(DIFF-DEA);

STICKLINE(DIFF >=REF(DIFF,1) AND DEA > REF(DEA,1),DIFF,DEA,1,0),LINETHICK4,COLOR0089FF;
STICKLINE(DIFF > DEA,DIFF,DEA,1,0),COLOR0089FF;
STICKLINE(MACD < REF(MACD,1) AND MACD > 0,0,MACD,0.8,0),COLORYELLOW;
STICKLINE(MACD < REF(MACD,1) AND MACD < 0,0,MACD,0.8,0),COLORGREEN;
STICKLINE(MACD > REF(MACD,1) AND MACD < 0,0,MACD,0.8,0),COLOR0099FF;
STICKLINE(MACD > REF(MACD,1) AND MACD >0,0,MACD,0.8,0),COLORPURPLE;

DRAWICON(CROSS(DIFF,DEA) AND DEA<0,DIFF,1);
DRAWICON(CROSS(DEA,DIFF) AND DEA>0,DIFF,2);
