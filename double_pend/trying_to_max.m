force = [40;40]
l = [0.324,0.390]

%f = @(x)[cos(x(1)), cos(x(2)); sin(x(1)), sin(x(2))]*force
f = @(x) force(1)*(cos(x(1)) + cos(x(2))) +force(2)*(sin(x(1)) + sin(x(2)))
g = @(x)-f(x);
x0 = [0;0];
[q,gmin] = fminsearch(g,x0)

y = [l(1)*cos(q(1)), l(2)*cos(q(2)) ; l(1)*sin(q(1)), l(2)*sin(q(2)) ]