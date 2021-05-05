% system dynamics

% Assumpotions 
% both pends have the same segmental lenths 
% l1h == l1e => l1, l2h == l2e => l2
% mass do not have to be idential  m1h != m2h != m12 != m2e
% exo masses are larger then the human masses


% human parameters
mh1 = 2.0;
mh2 = 1.0;

% exo params
me1 = mh1 + 2.0;
me2 = mh2 + 1.0;

% other model params
l1 = 1.0;
l2 = 1.5;
g = -9.81;


% connection dyamics
spring = [100, 0; 0, 100];
dampener = [50, 0; 0, 50];


% model 1 gains
Km1 = [30, 0; 0 30];
Dm1 = [5,0;0,5];



% Addmittance Controller
Kd = 50;
Bd = 50;
Md = 10;


% SMC

% SMC
lambda = 50.0;
rho = .50;


lambda2 = 0.005;
rho2 = .001;

% 
lambda2 = 0.001*1000;
rho2 = .008*100;


lambda2 = 1;
rho2 = .05*100;


lambda2 = 2.8;
rho2 = 4.5;
