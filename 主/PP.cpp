FLAG:=IF((PERIOD>=5 AND PERIOD<=7 ) OR (PERIOD>=9 AND PERIOD<=11),0,1);
CHANGEDAY:=DAY!=REF(DAY,1);
OPENBARS:=SUMBARS(CHANGEDAY,1);
ISTHEBAR:=(HOUR-REF(HOUR,OPENBARS-1))*60+MINUTE-REF(MINUTE, OPENBARS-1)=0;
COND1:=FLAG=1 AND ISTHEBAR

PERIOD_LASTBAR:=BARSLAST(REF(COND1,1))+1;
PCLOSE:=REF(CLOSE,1);
PHIGH:=REF(HHV(HIGH, PERIOD_LASTBAR),1);
PLOW:=REF(LLV(LOW, PERIOD_LASTBAR),1);

PIVOT:=(PHIGH+PLOW+PCLOSE)/3;
S1:=2*PIVOT-PHIGH;
S2:= PIVOT-(PHIGH-PLOW);
S3:=PLOW-(2*(PHIGH-PIVOT));

R1:=2* PIVOT-PLOW;
R2:= PIVOT+(PHIGH-PLOW);
R3:=PHIGH-(2*(PLOW-PIVOT));

DRAWLINE(COND1, PIVOT,REFX(COND1,1),REF(PIVOT,PERIOD_LASTBAR),0), COLOR22C57E,LINETHICK2;
DRAWLINE(COND1,PIVOT,ISLASTBAR,REF(PIVOT,PERIOD_LASTBAR),0), COLOR22C57E,LINETHICK2;
DRAWTEXT(COND1,PIVOT*1.001,'P'), COLOR22C57E;

DRAWLINE(COND1, S1,REFX(COND1,1),REF(S1,PERIOD_LASTBAR),0),COLORYELLOW,LINETHICK2;
DRAWLINE(COND1,S1,ISLASTBAR,REF(S1,PERIOD_LASTBAR),0), COLORYELLOW,LINETHICK2;
DRAWTEXT(COND1,S1*1.001,'S1'), COLORYELLOW;

DRAWLINE(COND1, S1,REFX(COND1,1),REF(S1,PERIOD_LASTBAR),0),COLORYELLOW,LINETHICK2;
DRAWLINE(COND1,S1,ISLASTBAR,REF(S1,PERIOD_LASTBAR),0), COLORYELLOW,LINETHICK2;
DRAWTEXT(COND1,S1*1.001,'S1'), COLORYELLOW;

DRAWLINE(COND1, R1,REFX(COND1,1),REF(R1,PERIOD_LASTBAR),0),COLORYELLOW,LINETHICK2;
DRAWLINE(COND1,R1,ISLASTBAR,REF(R1,PERIOD_LASTBAR),0), COLORYELLOW,LINETHICK2;
DRAWTEXT(COND1,R1*1.001,'R1'), COLORYELLOW;

DRAWLINE(COND1, S2,REFX(COND1,1),REF(S2,PERIOD_LASTBAR),0),COLORYELLOW,LINETHICK2;
DRAWLINE(COND1,S2,ISLASTBAR,REF(S2,PERIOD_LASTBAR),0), COLORYELLOW,LINETHICK2;
DRAWTEXT(COND1,S2*1.001,'S2'), COLORYELLOW;

DRAWLINE(COND1, R2,REFX(COND1,1),REF(R2,PERIOD_LASTBAR),0),COLORYELLOW,LINETHICK2;
DRAWLINE(COND1,R2,ISLASTBAR,REF(R2,PERIOD_LASTBAR),0), COLORYELLOW,LINETHICK2;
DRAWTEXT(COND1,R2*1.001,'R2'), COLORYELLOW;

DRAWLINE(COND1, S3,REFX(COND1,1),REF(S3,PERIOD_LASTBAR),0),COLORYELLOW,LINETHICK2;
DRAWLINE(COND1,S3,ISLASTBAR,REF(S3,PERIOD_LASTBAR),0), COLORYELLOW,LINETHICK2;
DRAWTEXT(COND1,S3*1.001,'S3'), COLORYELLOW;