


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
spring = [2000, 0; 0, 2000];
dampener = [1000, 0; 0, 1000];

% spring = [100, 0; 0, 100];
% dampener = [100, 0; 0, 100];

Dm1 = [496.569821348200,0;0,100];
Km1 = [6017.73151361233,0;0,2898.16820260871];


% Addmittance Controller
Kd = [50,0;0, 50];
Bd = [50,0;0, 50];
Md = [10.0, 0; 0, 10.0];


%Works well with the lower masses
lambda2 = [1.2, 0; 0 1.25];
rho2 = [100, 0; 0, 450];
exo_sat = 150;
human_sat = 30;
beta = [ 1/8 ; 1/8];



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