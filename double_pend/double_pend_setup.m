% system dynamics

% Assumpotions 
% both pends have the same segmental lenths 
% l1h == l1e => l1, l2h == l2e => l2
% mass do not have to be idential  m1h != m2h != m12 != m2e
% exo masses are larger then the human masses


% human parameters

mh = [2, 1]; 

me = [ 5, 5] + mh;

% other model params
l = [ 1.0, 1.5]




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

%Exo Gains
Kp_e = 300;
Kd_e = 300;


% SMC

lambda2 = [1., 0; 0 5.0];
rho2 = [17, 0; 0, 18];

lambda2 = [0.9, 0; 0 1.2];
rho2 = [16, 0; 0, 18];

lambda2 = [1.0, 0; 0 1.0];
rho2 = [20, 0; 0, 20];
sat = 10;

Kem = [500, 0; 0, 500];
Ked = [ 500, 0; 0, 500];
