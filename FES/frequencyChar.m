function [a_f] = frequencyChar(f)
%FREQUENCYCHAR Summary of this function goes here
%   Detailed explanation goes here
    alpha = 0.1;
    temp = (alpha*f).^2;
    a_f = temp./(1+temp);

end

