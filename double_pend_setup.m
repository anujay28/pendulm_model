% system dynamics

% Assumpotions 
% both pends have the same segmental lenths 
% l1h == l1e => l1, l2h == l2e => l2
% mass do not have to be idential  m1h != m2h != m12 != m2e
% exo masses are larger then the human masses


% human parameters

mh = [2, 1]; 

me = [ 2, 1] + mh;

% other model params
l = [ 1.0, 1.5]

g = -9.81;


% connection dyamics
spring = [100, 0; 0, 100];
dampener = [100, 0; 0, 100];


% model 1 gains
Km1 = [30, 0; 0 30];
Dm1 = [30,0;0,30];



% Addmittance Controller
Kd = [50,0;0,50];
Bd = [50,0;0,50];
Md = [10, 0; 0, 10];


% SMC

lambda2 = [2.8, 0; 0 2.8];
rho2 = [4.5, 0; 0, 4.5];
