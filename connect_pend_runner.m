% system dynamics
m1 = 1.0;
l1 = 1.0;
m2 = 1.0 + m1;
l2 = l1;
g = -9.81;

% connection dyamics
spring = 300;
dampener = 300;


% model 1 gains
Km1 = 30;
Dm1 = 30;

% model 2 gains
Km2 = 20;
Dm2 = 20;

% Addmittance Controller
Kd = 10;
Bd = 10;
Md = 10;
alpha = 10;
beta = 10;


% SMC
lambda = .005;
rho = 0.0150;
