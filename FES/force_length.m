function [ fl] = force_length( l )
%FORCE_LENGTH Summary of this function goes here
%   Detailed explanation goes here
   epsilon = [ 0.4, 0.5, 0.4, 0.2, 0.4, 0.45, 0.3, 0.5, 0.4];

   
   temp = l'./epsilon;
    fl = exp(-temp.^2);
end

