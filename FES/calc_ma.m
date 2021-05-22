function [ma ] = calc_ma( theta)
%MOMENTARM Summary of this function goes here
%   Detailed explanation goes here
    hip = theta(1);
    knee = theta(2);
    ankle = theta(3);
    
    ma = zeros(9,3);
    ma(1,1) = 0.00233*hip^2 - 0.00223*hip - 0.0275;
    ma(2,1) = -0.0098*hip^2 - 0.0054*hip + 0.0413;
    ma(3,1) = -0.020*hip^2 - 0.024*hip + 0.055;
    ma(5,1) = 0.025*hip^2 + 0.41*hip - 0.040;
    
    ma(3,2) = -0.0098*knee^2 + 0.021*knee + 0.028;
    ma(4,2) = -0.008*knee^2 +  0.027*knee + 0.014;
    ma(5,2) = -0.02740063*knee^6 + 0.1636204*knee^5 -0.35701346*knee^4 -0.31503559*knee^3 -0.04757875*knee^2 -0.0531528*knee-0.02851741;
    ma(6,2) = -0.033069738*knee^6 + 0.1974729*knee^5 -0.43087832*knee^4+ 0.38021537*knee^3 -0.05742263*knee^2 -0.06414993*knee -0.0251417
    ma(7,2) = 0.018;
    
    ma(7,3) = 0.053;
    ma(8,3) = 0.035;
    ma(9,3) = 0.013*ankle - 0.035;

end

