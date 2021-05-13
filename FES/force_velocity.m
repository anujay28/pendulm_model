function [ fv ] = force_velocity( v )
%FORCE_VELOCITY Summary of this function goes here
%   Detailed explanation goes here

    fv = (0.54*atan( 5.69*v + 0.51) + 0.745)';
end

