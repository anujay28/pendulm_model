
params = load('/home/nathanielgoldfarb/pendulm_model/double_pend/testing_system/modifed_model/tests/all_cost/parameters.mat')

% human parameters
way_points = [ 0 , -pi, 0;  0 -0.5*pi,0 ]

mh = [11.824, 3.848]; 
me = [ 2.11, 1.28]  + mh;

% other model params
lh = [0.324, 0.3900]
le = lh;



myQ = diag([.1 10 0.001 0.001]);
myR = diag([0.001 0.001 0.00 0.00]);


spring = [2000, 0; 0, 2000];
dampener = [1000, 0; 0, 1000];

% spring = [100, 0; 0, 100];
% dampener = [100, 0; 0, 100];

Dm1 = [496.569821348200,0;0,100];
Km1 = [6017.73151361233,0;0,2898.16820260871];


% model 1 gains
% Km1 = [300, 0; 0 300];
% Dm1 = [300,0;0,300];
% 
% 
% Dm1 = [496.569821348200,0;0,100]
% Km1 = [6017.73151361233,0;0,2898.16820260871]

% Addmittance Controller
Kd = [50,0;0, 50];
Bd = [50,0;0, 50];
Md = [10.0, 0; 0, 10.0];


%Works well with the lower masses
lambda2 = params.all_cost_parameters(9,1).Value;
rho2 = params.all_cost_parameters(8,1).Value;
exo_sat = 150;
human_sat = 150.0;
beta = params.all_cost_parameters(6,1).Value;


Kem = [ 50, 0; 0, 50];
Ked = [ 50, 0; 0, 50];


Kp0 = params.all_cost_parameters(4,1).Value;
Kn0 = params.all_cost_parameters(3,1).Value;
Bp0 = params.all_cost_parameters(2,1).Value;
Bn0 = params.all_cost_parameters(1,1).Value;
alpha = params.all_cost_parameters(5,1).Value;
gamma = params.all_cost_parameters(7,1).Value;

