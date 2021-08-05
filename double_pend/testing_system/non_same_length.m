% system dynamics

% Assumpotions 
% both pends have the same segmental lenths 
% l1h == l1e => l1, l2h == l2e => l2
% mass do not have to be idential  m1h != m2h != m12 != m2e
% exo masses are larger then the human masses



% human parameters
way_points = [ 0 , -pi, 0;  0 -0.5*pi,0 ]

mh = [11.824, 3.848]; 
me = [ 2.11, 1.28]  + mh;

% other model params
lh = [0.324, 0.3900]
le = [0.324, 0.3900] 



myQ = diag([.1 10 0.001 0.001]);
myR = diag([0.001 0.001 0.00 0.00]);


% connection dyamics
spring = [100, 0; 0, 100];
dampener = [100, 0; 0, 100];


% model 1 gains
Km1 = [30, 0; 0 30];
Dm1 = [30,0;0,30];



% Addmittance Controller
Kd = [50,0;0, 50];
Bd = [50,0;0, 50];
Md = [10.0, 0; 0, 10.0];

% Addmittance Controller
% Kd = [15,0;0, 15];
% Bd = [15,0;0, 15];
% Md = [15.0, 0; 0, 15.0];

% 
% Kd = [50,0;0, 50];
% Bd = [50,0;0, 50];
% Md = [10.0, 0; 0, 10.0];


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


%Works well with the lower masses
lambda2 = [1.2, 0; 0 1.25];
rho2 = [100, 0; 0, 450];
exo_sat = 150;
human_sat = 30;
beta = [ 1/8 ; 1/8];


% lambda2 = [1.25, 0; 0 1.8];
% rho2 = [150, 0; 0, 2050];
% exo_sat = 200;
% human_sat = 60;
% 

% 
% lambda2 = [1.3, 0; 0 2.2];
% rho2 = [20000, 0; 0, 65050];
% exo_sat = 250;
% human_sat = 60;
% 
% lambda2 = [1.3, 0; 0 1.5];
% rho2 = [15000, 0; 0, 45000];
% exo_sat = 250;
% human_sat = 60;
% 
% 
% 
% lambda2 = [1.3, 0; 0 1.8];
% rho2 = [9500, 0; 0, 48000];
% exo_sat = 250;
% human_sat = 60;
% 
% 
% lambda2 = [1.3, 0; 0 1.8];
% rho2 = [10500, 0; 0, 48000];
% exo_sat = 250;
% human_sat = 60;
% 
% lambda2 = [2.0, 0; 0 2.0];
% rho2 = [100, 0; 0, 100];
% exo_sat = 250;
% human_sat = 60;


%lambda2 = [9.674952808384424 0;0 16.77094977039503]
%rho2 = [215.7235502020355 0;0 1417.864059445193]
%beta = [0.6364648908802455;0.9]

Kem = [ 50, 0; 0, 50];
Ked = [ 50, 0; 0, 50];


Kp0 = [500 500];
Kn0 = [500  500];
Bp0 = [500  500];
Bn0 = [500  500];
alpha = [15,15];
gamma = [15,15];

% Kp0 = 50*eye(2);
% Kn0 = 50*eye(2);
% Bp0 = 50;
% Bn0 = 50;
% beta_p = 5;
% beta_n = 5;
% alpha_p = 5;
% alpha_n = 5;