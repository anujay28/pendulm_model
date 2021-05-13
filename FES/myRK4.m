function ma = myRK4(prev_ma, theta)
%MYRK4 Summary of this function goes here
%   Detailed explanation goes here


    h = 0.1
    k1 = calc_ma(theta)
    k2 = calc_ma(theta + 0.5 * h)
    k3 = calc_ma(theta + 0.5 * h)
    k4 = calc_ma(theta + h)

     ma = prev_ma + (h / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4)
end

