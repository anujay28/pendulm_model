function [ma] = dma(theta)
%MYRK4 Summary of this function goes here
%   Detailed explanation goes here

    hip = theta(1);
    knee = theta(2);
    ankle = theta(3);
    
    ma = zeros(9,3);
    ma(1,1) = (1/3)*0.00233*hip^3 - (1/2)*0.00223*hip^2 - 0.0275*hip;
    ma(2,1) = -(1/3)*0.0098*hip^3 - (1/2)*0.0054*hip^2 + 0.0413*hip;
    ma(3,1) = -(1/3)*0.020*hip^3 - (1/2)*0.024*hip^2 + 0.055*hip;
    ma(5,1) = (1/3)*0.025*hip^2 + (1/2)*0.41*hip^2 - 0.040*hip;
    
    ma(3,2) =  -(1/3)*0.0098*knee^3 + (1/2)*0.021*knee^2 + 0.028*knee;
    ma(4,2) =  -(1/3)*0.008*knee^3 +  (1/2)*0.027*knee^2 + 0.014*knee;
    ma(5,2) = -(1/7)*0.02740063*knee^7 + (1/6)*0.1636204*knee^6 -(1/5)*0.35701346*knee^5 -(1/4)*0.31503559*knee^4 -(1/3)*0.04757875*knee^3 -(1/2)*0.0531528*knee^2 - 0.02851741*knee;
    ma(6,2) = -(1/7)*0.033069738*knee^7 + (1/6)*0.1974729*knee^6 - (1/5)*0.43087832*knee^5+ (1/4)*0.38021537*knee^4 -(1/3)*0.05742263*knee^3 -(1/2)*0.06414993*knee^2 -0.0251417*knee
    ma(7,2) = 0.018*knee;
    
    ma(7,3) = 0.053*ankle;
    ma(8,3) = 0.035*ankle;
    ma(9,3) = 0.013*ankle^2 - 0.035*ankle;
end

