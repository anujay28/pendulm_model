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
Km2 = 30;
Dm2 = 30;

% Addmittance Controller
Kd = 20;
Bd = 20;
Md = 10;
alpha = 10;
beta = 10;

% SMC

% SMC
lambda = 50.0;
rho = .50;


lambda2 = 0.005;
rho2 = .001;


% lambda2 = 0.001*1000;
% rho2 = .008*100;
