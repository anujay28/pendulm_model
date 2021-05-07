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




% connection dyamics
spring = [50, 0; 0, 50];
dampener = [50, 0; 0, 50];


% model 1 gains
Km1 = [30, 0; 0 30];
Dm1 = [30,0;0,30];



% Addmittance Controller
Kd = [30,0;0,30];
Bd = [30,0;0,30];
Md = [10, 0; 0, 10];


% SMC

lambda2 = [1., 0; 0 5.0];
rho2 = [17, 0; 0, 18];

lambda2 = [0.9, 0; 0 5.2];
rho2 = [16, 0; 0, 50];


Kem = [500, 0; 0, 500];
Ked = [ 500, 0; 0, 500];
