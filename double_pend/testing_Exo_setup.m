% system dynamics

% Assumpotions 
% both pends have the same segmental lenths 
% l1h == l1e => l1, l2h == l2e => l2
% mass do not have to be idential  m1h != m2h != m12 != m2e
% exo masses are larger then the human masses


% human parameters

mh = [11.824, 3.848]; 

me = [ 2.11, 1.28] + mh;

% other model params
l = [0.324, 0.3900]

myQ = diag([.1 .5 0.001 .001]);
myR = diag([0.001 0.001 0.00 0.00]);


% connection dyamics
spring = [100, 0; 0, 100];
dampener = [100, 0; 0, 100];


% model 1 gains
Km1 = [30, 0; 0 30];
Dm1 = [30,0;0,30];



% Addmittance Controller
% Kd = [50,0;0, 50];
% Bd = [50,0;0, 50];
% Md = [2.0, 0; 0, 2.0];

% Addmittance Controller
Kd = [50,0;0, 50];
Bd = [50,0;0, 50];
Md = [10.0, 0; 0, 10.0];


% lambda2 = [ 1.2, 0; 0 25.0];
% rho2 = [100, 0; 0, 250];
% exo_sat = 150;



% lambda2 = [ 0.9, 0; 0 0.9];
% rho2 = [15000, 0; 0, 2500];
% exo_sat = 120;
% human_sat = 30;


% lambda2 = [1.25, 0; 0 1.5];
% rho2 = [17500, 0; 0, 21500];
% exo_sat = 200;
% human_sat = 30;


% Works well with the lower masses
% lambda2 = [1.0, 0; 0 2.3];
% rho2 = [105, 0; 0, 350];
% exo_sat = 2000;
% human_sat = 30;


Kem = [ 50, 0; 0, 50];
Ked = [ 50, 0; 0, 50];


Kp0 = 25*eye(2);
Kn0 = 25*eye(2);
Bp0 = 25;
Bn0 = 25;
beta_p = 5;
beta_n = 5;
alpha_p = 5;
alpha_n = 5;