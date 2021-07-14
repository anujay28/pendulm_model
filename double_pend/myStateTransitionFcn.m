function x = myStateTransitionFcn(x ,u)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
   
q = x(1:2);
qd = x(3:4);

m = [1.1824, 0.3848]; 

% other model params
l = [0.324, 0.3900];
temp = pinv(M(m, l, q))*(u - C(m, l, q, qd) - G(m, q) - [100 0; 0 100]*qd.^2);

x= [qd(1); temp(1); qd(2); temp(2)]; 

end

