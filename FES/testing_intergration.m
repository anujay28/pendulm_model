
syms ma hip knee ankle
ma = sym('ma',[9 3])
ma = sym(zeros(9,3));
ma(1,1) = 0.00233*hip^2 - 0.00223*hip - 0.0275;
ma(2,1) = -0.0098*hip^2 - 0.0054*hip + 0.0413;
ma(3,1) = -0.020*hip^2 - 0.024*hip + 0.055;
ma(5,1) = 0.025*hip^2 + 0.41*hip - 0.040;

ma(3,2) = -0.0098*knee^2 + 0.021*knee + 0.028;
ma(4,2) = -0.008*knee^2 +  0.027*knee + 0.014;
ma(5,2) = -0.058*exp(-2.0*knee*knee)*sin(knee) - 0.0284;
ma(6,2) = -0.07*exp(-2.0*knee*knee)*sin(knee) - 0.0250;
ma(7,2) = 0.018;

ma(7,3) = 0.053;
ma(8,3) = 0.035;
ma(9,3) = 0.013*ankle - 0.035;

int_hip = int(ma(:,1),hip);
int_knee = int(ma(:,2),knee);
int_ankle = int(ma(:,3),ankle);


int_joints = [ int_hip, int_knee, int_ankle]
temp = subs(int_joints, [hip, knee, ankle], [30,30,30])
temp = subs(temp, [hip, knee, ankle], [30,30,30])


